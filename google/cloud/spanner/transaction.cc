// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/spanner/transaction.h"
#include "google/cloud/spanner/internal/session.h"
#include "google/cloud/spanner/internal/transaction_impl.h"
#include <google/protobuf/duration.pb.h>

namespace google {
namespace cloud {
namespace spanner {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {

google::protobuf::Duration ToProto(std::chrono::nanoseconds ns) {
  auto s = std::chrono::duration_cast<std::chrono::seconds>(ns);
  ns -= std::chrono::duration_cast<std::chrono::nanoseconds>(s);
  google::protobuf::Duration proto;
  proto.set_seconds(s.count());
  proto.set_nanos(static_cast<int>(ns.count()));
  return proto;
}

google::spanner::v1::TransactionOptions MakeOpts(
    google::spanner::v1::TransactionOptions_ReadOnly ro_opts) {
  google::spanner::v1::TransactionOptions opts;
  *opts.mutable_read_only() = std::move(ro_opts);
  return opts;
}

google::spanner::v1::TransactionOptions MakeOpts(
    google::spanner::v1::TransactionOptions_ReadWrite rw_opts) {
  google::spanner::v1::TransactionOptions opts;
  *opts.mutable_read_write() = std::move(rw_opts);
  return opts;
}

}  // namespace

Transaction::ReadOnlyOptions::ReadOnlyOptions() {
  ro_opts_.set_strong(true);  // only presence matters, not value
  ro_opts_.set_return_read_timestamp(true);
}

Transaction::ReadOnlyOptions::ReadOnlyOptions(Timestamp read_timestamp) {
  *ro_opts_.mutable_read_timestamp() =
      read_timestamp.get<protobuf::Timestamp>().value();
  ro_opts_.set_return_read_timestamp(true);
}

Transaction::ReadOnlyOptions::ReadOnlyOptions(
    std::chrono::nanoseconds exact_staleness) {
  *ro_opts_.mutable_exact_staleness() = ToProto(exact_staleness);
  ro_opts_.set_return_read_timestamp(true);
}

Transaction::ReadWriteOptions::ReadWriteOptions() = default;  // currently none

Transaction::ReadWriteOptions& Transaction::ReadWriteOptions::WithTag(
    absl::optional<std::string> tag) {
  tag_ = std::move(tag);
  return *this;
}

Transaction::SingleUseOptions::SingleUseOptions(ReadOnlyOptions opts) {
  ro_opts_ = std::move(opts.ro_opts_);
}

Transaction::SingleUseOptions::SingleUseOptions(Timestamp min_read_timestamp) {
  *ro_opts_.mutable_min_read_timestamp() =
      min_read_timestamp.get<protobuf::Timestamp>().value();
  ro_opts_.set_return_read_timestamp(true);
}

Transaction::SingleUseOptions::SingleUseOptions(
    std::chrono::nanoseconds max_staleness) {
  *ro_opts_.mutable_max_staleness() = ToProto(max_staleness);
  ro_opts_.set_return_read_timestamp(true);
}

Transaction::Transaction(ReadOnlyOptions opts) {
  google::spanner::v1::TransactionSelector selector;
  *selector.mutable_begin() = MakeOpts(std::move(opts.ro_opts_));
  auto const route_to_leader = false;  // read-only
  impl_ = std::make_shared<spanner_internal::TransactionImpl>(
      std::move(selector), route_to_leader, std::string());
}

Transaction::Transaction(ReadWriteOptions opts) {
  google::spanner::v1::TransactionSelector selector;
  *selector.mutable_begin() = MakeOpts(std::move(opts.rw_opts_));
  auto const route_to_leader = true;  // read-write
  impl_ = std::make_shared<spanner_internal::TransactionImpl>(
      std::move(selector), route_to_leader,
      std::move(opts.tag_).value_or(std::string()));
}

Transaction::Transaction(Transaction const& txn, ReadWriteOptions opts) {
  google::spanner::v1::TransactionSelector selector;
  *selector.mutable_begin() = MakeOpts(std::move(opts.rw_opts_));
  auto const route_to_leader = true;  // read-write
  impl_ = std::make_shared<spanner_internal::TransactionImpl>(
      *txn.impl_, std::move(selector), route_to_leader,
      std::move(opts.tag_).value_or(std::string()));
}

Transaction::Transaction(SingleUseOptions opts) {
  google::spanner::v1::TransactionSelector selector;
  *selector.mutable_single_use() = MakeOpts(std::move(opts.ro_opts_));
  auto const route_to_leader = false;  // read-only
  impl_ = std::make_shared<spanner_internal::TransactionImpl>(
      std::move(selector), route_to_leader, std::string());
}

Transaction::Transaction(std::string session_id, std::string transaction_id,
                         bool route_to_leader, std::string transaction_tag) {
  google::spanner::v1::TransactionSelector selector;
  selector.set_id(std::move(transaction_id));
  impl_ = std::make_shared<spanner_internal::TransactionImpl>(
      spanner_internal::MakeDissociatedSessionHolder(std::move(session_id)),
      std::move(selector), route_to_leader, std::move(transaction_tag));
}

Transaction::~Transaction() = default;

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace spanner

namespace spanner_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

spanner::Transaction TransactionInternals::MakeTransactionFromIds(
    std::string session_id, std::string transaction_id, bool route_to_leader,
    std::string transaction_tag) {
  return spanner::Transaction(std::move(session_id), std::move(transaction_id),
                              route_to_leader, std::move(transaction_tag));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace spanner_internal
}  // namespace cloud
}  // namespace google
