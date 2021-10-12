// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/bigquery/storage/v1/storage.proto

#include "google/cloud/bigquery/internal/bigquery_read_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/internal/streaming_read_rpc_logging.h"
#include "google/cloud/status_or.h"
#include <google/cloud/bigquery/storage/v1/storage.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_internal {
inline namespace GOOGLE_CLOUD_CPP_NS {

BigQueryReadLogging::BigQueryReadLogging(
    std::shared_ptr<BigQueryReadStub> child, TracingOptions tracing_options,
    std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::bigquery::storage::v1::ReadSession>
BigQueryReadLogging::CreateReadSession(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::CreateReadSessionRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::bigquery::storage::v1::CreateReadSessionRequest const&
              request) { return child_->CreateReadSession(context, request); },
      context, request, __func__, tracing_options_);
}

std::unique_ptr<internal::StreamingReadRpc<
    google::cloud::bigquery::storage::v1::ReadRowsResponse>>
BigQueryReadLogging::ReadRows(
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::bigquery::storage::v1::ReadRowsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::bigquery::storage::v1::ReadRowsRequest const& request)
          -> std::unique_ptr<internal::StreamingReadRpc<
              google::cloud::bigquery::storage::v1::ReadRowsResponse>> {
        auto stream = child_->ReadRows(std::move(context), request);
        if (components_.count("rpc-streams") > 0) {
          stream = absl::make_unique<internal::StreamingReadRpcLogging<
              google::cloud::bigquery::storage::v1::ReadRowsResponse>>(
              std::move(stream), tracing_options_,
              internal::RequestIdForLogging());
        }
        return stream;
      },
      std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::storage::v1::SplitReadStreamResponse>
BigQueryReadLogging::SplitReadStream(
    grpc::ClientContext& context,
    google::cloud::bigquery::storage::v1::SplitReadStreamRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::storage::v1::SplitReadStreamRequest const&
                 request) { return child_->SplitReadStream(context, request); },
      context, request, __func__, tracing_options_);
}

}  // namespace GOOGLE_CLOUD_CPP_NS
}  // namespace bigquery_internal
}  // namespace cloud
}  // namespace google
