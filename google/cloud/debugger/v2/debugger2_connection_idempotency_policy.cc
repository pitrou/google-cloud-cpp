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

#include "google/cloud/debugger/v2/debugger2_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace debugger_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

Debugger2ConnectionIdempotencyPolicy::~Debugger2ConnectionIdempotencyPolicy() =
    default;

std::unique_ptr<Debugger2ConnectionIdempotencyPolicy>
Debugger2ConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<Debugger2ConnectionIdempotencyPolicy>(*this);
}

Idempotency Debugger2ConnectionIdempotencyPolicy::SetBreakpoint(
    google::devtools::clouddebugger::v2::SetBreakpointRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency Debugger2ConnectionIdempotencyPolicy::GetBreakpoint(
    google::devtools::clouddebugger::v2::GetBreakpointRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency Debugger2ConnectionIdempotencyPolicy::DeleteBreakpoint(
    google::devtools::clouddebugger::v2::DeleteBreakpointRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency Debugger2ConnectionIdempotencyPolicy::ListBreakpoints(
    google::devtools::clouddebugger::v2::ListBreakpointsRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency Debugger2ConnectionIdempotencyPolicy::ListDebuggees(
    google::devtools::clouddebugger::v2::ListDebuggeesRequest const&) {
  return Idempotency::kIdempotent;
}

std::unique_ptr<Debugger2ConnectionIdempotencyPolicy>
MakeDefaultDebugger2ConnectionIdempotencyPolicy() {
  return std::make_unique<Debugger2ConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace debugger_v2
}  // namespace cloud
}  // namespace google
