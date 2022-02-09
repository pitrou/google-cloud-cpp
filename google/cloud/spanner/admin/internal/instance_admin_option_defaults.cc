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
// source: google/spanner/admin/instance/v1/spanner_instance_admin.proto

#include "google/cloud/spanner/admin/internal/instance_admin_option_defaults.h"
#include "google/cloud/spanner/admin/instance_admin_connection.h"
#include "google/cloud/spanner/admin/instance_admin_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace spanner_admin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options InstanceAdminDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_SPANNER_DEFAULT_ENDPOINT",
      "SPANNER_EMULATOR_HOST", "spanner.googleapis.com");
  options = google::cloud::internal::PopulateGrpcOptions(
      std::move(options), "SPANNER_EMULATOR_HOST");
  if (!options.has<spanner_admin::InstanceAdminRetryPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminRetryPolicyOption>(
        spanner_admin::InstanceAdminLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<spanner_admin::InstanceAdminBackoffPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminBackoffPolicyOption>(
        ExponentialBackoffPolicy(std::chrono::seconds(1),
                                 std::chrono::minutes(5), kBackoffScaling)
            .clone());
  }
  if (!options.has<spanner_admin::InstanceAdminPollingPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminPollingPolicyOption>(
        GenericPollingPolicy<
            spanner_admin::InstanceAdminRetryPolicyOption::Type,
            spanner_admin::InstanceAdminBackoffPolicyOption::Type>(
            options.get<spanner_admin::InstanceAdminRetryPolicyOption>()
                ->clone(),
            options.get<spanner_admin::InstanceAdminBackoffPolicyOption>()
                ->clone())
            .clone());
  }
  if (!options.has<
          spanner_admin::InstanceAdminConnectionIdempotencyPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminConnectionIdempotencyPolicyOption>(
        spanner_admin::MakeDefaultInstanceAdminConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
namespace gcpcxxV1 = GOOGLE_CLOUD_CPP_NS;  // NOLINT(misc-unused-alias-decls)
}  // namespace spanner_admin_internal
}  // namespace cloud
}  // namespace google
