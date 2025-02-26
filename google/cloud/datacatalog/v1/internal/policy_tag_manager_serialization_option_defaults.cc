// Copyright 2022 Google LLC
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
// source: google/cloud/datacatalog/v1/policytagmanagerserialization.proto

#include "google/cloud/datacatalog/v1/internal/policy_tag_manager_serialization_option_defaults.h"
#include "google/cloud/datacatalog/v1/policy_tag_manager_serialization_connection.h"
#include "google/cloud/datacatalog/v1/policy_tag_manager_serialization_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace datacatalog_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options PolicyTagManagerSerializationDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options),
      "GOOGLE_CLOUD_CPP_POLICY_TAG_MANAGER_SERIALIZATION_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_POLICY_TAG_MANAGER_SERIALIZATION_AUTHORITY",
      "datacatalog.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<
          datacatalog_v1::PolicyTagManagerSerializationRetryPolicyOption>()) {
    options.set<datacatalog_v1::PolicyTagManagerSerializationRetryPolicyOption>(
        datacatalog_v1::PolicyTagManagerSerializationLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<
          datacatalog_v1::PolicyTagManagerSerializationBackoffPolicyOption>()) {
    options
        .set<datacatalog_v1::PolicyTagManagerSerializationBackoffPolicyOption>(
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone());
  }
  if (!options.has<
          datacatalog_v1::
              PolicyTagManagerSerializationConnectionIdempotencyPolicyOption>()) {
    options.set<
        datacatalog_v1::
            PolicyTagManagerSerializationConnectionIdempotencyPolicyOption>(
        datacatalog_v1::
            MakeDefaultPolicyTagManagerSerializationConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datacatalog_v1_internal
}  // namespace cloud
}  // namespace google
