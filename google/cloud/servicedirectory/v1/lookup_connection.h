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
// source: google/cloud/servicedirectory/v1/lookup_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEDIRECTORY_V1_LOOKUP_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEDIRECTORY_V1_LOOKUP_CONNECTION_H

#include "google/cloud/servicedirectory/v1/internal/lookup_retry_traits.h"
#include "google/cloud/servicedirectory/v1/lookup_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/servicedirectory/v1/lookup_service.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace servicedirectory_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using LookupServiceRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        servicedirectory_v1_internal::LookupServiceRetryTraits>;

using LookupServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        servicedirectory_v1_internal::LookupServiceRetryTraits>;

using LookupServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        servicedirectory_v1_internal::LookupServiceRetryTraits>;

/**
 * The `LookupServiceConnection` object for `LookupServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `LookupServiceClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `LookupServiceClient`.
 *
 * To create a concrete instance, see `MakeLookupServiceConnection()`.
 *
 * For mocking, see `servicedirectory_v1_mocks::MockLookupServiceConnection`.
 */
class LookupServiceConnection {
 public:
  virtual ~LookupServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::cloud::servicedirectory::v1::ResolveServiceResponse>
  ResolveService(
      google::cloud::servicedirectory::v1::ResolveServiceRequest const&
          request);
};

/**
 * A factory function to construct an object of type `LookupServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of LookupServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `LookupServiceConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::servicedirectory_v1::LookupServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `LookupServiceConnection` created by
 * this function.
 */
std::shared_ptr<LookupServiceConnection> MakeLookupServiceConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicedirectory_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEDIRECTORY_V1_LOOKUP_CONNECTION_H
