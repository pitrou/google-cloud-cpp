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
// source: google/cloud/gaming/v1/game_server_deployments_service.proto

#include "google/cloud/gameservices/v1/internal/game_server_deployments_option_defaults.h"
#include "google/cloud/gameservices/v1/game_server_deployments_connection.h"
#include "google/cloud/gameservices/v1/game_server_deployments_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace gameservices_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options GameServerDeploymentsServiceDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options),
      "GOOGLE_CLOUD_CPP_GAME_SERVER_DEPLOYMENTS_SERVICE_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_GAME_SERVER_DEPLOYMENTS_SERVICE_AUTHORITY",
      "gameservices.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<
          gameservices_v1::GameServerDeploymentsServiceRetryPolicyOption>()) {
    options.set<gameservices_v1::GameServerDeploymentsServiceRetryPolicyOption>(
        gameservices_v1::GameServerDeploymentsServiceLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<
          gameservices_v1::GameServerDeploymentsServiceBackoffPolicyOption>()) {
    options
        .set<gameservices_v1::GameServerDeploymentsServiceBackoffPolicyOption>(
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone());
  }
  if (!options.has<
          gameservices_v1::GameServerDeploymentsServicePollingPolicyOption>()) {
    options
        .set<gameservices_v1::GameServerDeploymentsServicePollingPolicyOption>(
            GenericPollingPolicy<
                gameservices_v1::GameServerDeploymentsServiceRetryPolicyOption::
                    Type,
                gameservices_v1::
                    GameServerDeploymentsServiceBackoffPolicyOption::Type>(
                options
                    .get<gameservices_v1::
                             GameServerDeploymentsServiceRetryPolicyOption>()
                    ->clone(),
                options
                    .get<gameservices_v1::
                             GameServerDeploymentsServiceBackoffPolicyOption>()
                    ->clone())
                .clone());
  }
  if (!options.has<
          gameservices_v1::
              GameServerDeploymentsServiceConnectionIdempotencyPolicyOption>()) {
    options.set<
        gameservices_v1::
            GameServerDeploymentsServiceConnectionIdempotencyPolicyOption>(
        gameservices_v1::
            MakeDefaultGameServerDeploymentsServiceConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace gameservices_v1_internal
}  // namespace cloud
}  // namespace google
