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
// source: google/devtools/clouddebugger/v2/debugger.proto

#include "google/cloud/debugger/internal/debugger2_option_defaults.h"
#include "google/cloud/debugger/debugger2_connection.h"
#include "google/cloud/debugger/debugger2_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace debugger_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options Debugger2DefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_DEBUGGER2_ENDPOINT", "",
      "clouddebugger.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<debugger::Debugger2RetryPolicyOption>()) {
    options.set<debugger::Debugger2RetryPolicyOption>(
        debugger::Debugger2LimitedTimeRetryPolicy(std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<debugger::Debugger2BackoffPolicyOption>()) {
    options.set<debugger::Debugger2BackoffPolicyOption>(
        ExponentialBackoffPolicy(std::chrono::seconds(1),
                                 std::chrono::minutes(5), kBackoffScaling)
            .clone());
  }
  if (!options.has<debugger::Debugger2ConnectionIdempotencyPolicyOption>()) {
    options.set<debugger::Debugger2ConnectionIdempotencyPolicyOption>(
        debugger::MakeDefaultDebugger2ConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace debugger_internal
}  // namespace cloud
}  // namespace google
