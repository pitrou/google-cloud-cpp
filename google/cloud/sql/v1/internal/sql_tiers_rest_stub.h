// Copyright 2023 Google LLC
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
// source: google/cloud/sql/v1/cloud_sql_tiers.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQL_V1_INTERNAL_SQL_TIERS_REST_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQL_V1_INTERNAL_SQL_TIERS_REST_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/internal/rest_client.h"
#include "google/cloud/internal/rest_context.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/sql/v1/cloud_sql_tiers.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace sql_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SqlTiersServiceRestStub {
 public:
  virtual ~SqlTiersServiceRestStub() = default;

  virtual StatusOr<google::cloud::sql::v1::TiersListResponse> List(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::sql::v1::SqlTiersListRequest const& request) = 0;
};

class DefaultSqlTiersServiceRestStub : public SqlTiersServiceRestStub {
 public:
  ~DefaultSqlTiersServiceRestStub() override = default;

  explicit DefaultSqlTiersServiceRestStub(Options options);
  DefaultSqlTiersServiceRestStub(
      std::shared_ptr<rest_internal::RestClient> service, Options options);

  StatusOr<google::cloud::sql::v1::TiersListResponse> List(
      google::cloud::rest_internal::RestContext& rest_context,
      google::cloud::sql::v1::SqlTiersListRequest const& request) override;

 private:
  std::shared_ptr<rest_internal::RestClient> service_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sql_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQL_V1_INTERNAL_SQL_TIERS_REST_STUB_H
