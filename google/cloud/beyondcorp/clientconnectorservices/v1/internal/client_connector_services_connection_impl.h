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
// source:
// google/cloud/beyondcorp/clientconnectorservices/v1/client_connector_services_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_CLIENTCONNECTORSERVICES_V1_INTERNAL_CLIENT_CONNECTOR_SERVICES_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_CLIENTCONNECTORSERVICES_V1_INTERNAL_CLIENT_CONNECTOR_SERVICES_CONNECTION_IMPL_H

#include "google/cloud/beyondcorp/clientconnectorservices/v1/client_connector_services_connection.h"
#include "google/cloud/beyondcorp/clientconnectorservices/v1/client_connector_services_connection_idempotency_policy.h"
#include "google/cloud/beyondcorp/clientconnectorservices/v1/client_connector_services_options.h"
#include "google/cloud/beyondcorp/clientconnectorservices/v1/internal/client_connector_services_retry_traits.h"
#include "google/cloud/beyondcorp/clientconnectorservices/v1/internal/client_connector_services_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace beyondcorp_clientconnectorservices_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ClientConnectorServicesServiceConnectionImpl
    : public beyondcorp_clientconnectorservices_v1::
          ClientConnectorServicesServiceConnection {
 public:
  ~ClientConnectorServicesServiceConnectionImpl() override = default;

  ClientConnectorServicesServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<beyondcorp_clientconnectorservices_v1_internal::
                          ClientConnectorServicesServiceStub>
          stub,
      Options options);

  Options options() override { return options_; }

  StreamRange<google::cloud::beyondcorp::clientconnectorservices::v1::
                  ClientConnectorService>
  ListClientConnectorServices(
      google::cloud::beyondcorp::clientconnectorservices::v1::
          ListClientConnectorServicesRequest request) override;

  StatusOr<google::cloud::beyondcorp::clientconnectorservices::v1::
               ClientConnectorService>
  GetClientConnectorService(
      google::cloud::beyondcorp::clientconnectorservices::v1::
          GetClientConnectorServiceRequest const& request) override;

  future<StatusOr<google::cloud::beyondcorp::clientconnectorservices::v1::
                      ClientConnectorService>>
  CreateClientConnectorService(
      google::cloud::beyondcorp::clientconnectorservices::v1::
          CreateClientConnectorServiceRequest const& request) override;

  future<StatusOr<google::cloud::beyondcorp::clientconnectorservices::v1::
                      ClientConnectorService>>
  UpdateClientConnectorService(
      google::cloud::beyondcorp::clientconnectorservices::v1::
          UpdateClientConnectorServiceRequest const& request) override;

  future<StatusOr<google::cloud::beyondcorp::clientconnectorservices::v1::
                      ClientConnectorServiceOperationMetadata>>
  DeleteClientConnectorService(
      google::cloud::beyondcorp::clientconnectorservices::v1::
          DeleteClientConnectorServiceRequest const& request) override;

 private:
  std::unique_ptr<beyondcorp_clientconnectorservices_v1::
                      ClientConnectorServicesServiceRetryPolicy>
  retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<beyondcorp_clientconnectorservices_v1::
                        ClientConnectorServicesServiceRetryPolicyOption>()) {
      return options
          .get<beyondcorp_clientconnectorservices_v1::
                   ClientConnectorServicesServiceRetryPolicyOption>()
          ->clone();
    }
    return options_
        .get<beyondcorp_clientconnectorservices_v1::
                 ClientConnectorServicesServiceRetryPolicyOption>()
        ->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<beyondcorp_clientconnectorservices_v1::
                        ClientConnectorServicesServiceBackoffPolicyOption>()) {
      return options
          .get<beyondcorp_clientconnectorservices_v1::
                   ClientConnectorServicesServiceBackoffPolicyOption>()
          ->clone();
    }
    return options_
        .get<beyondcorp_clientconnectorservices_v1::
                 ClientConnectorServicesServiceBackoffPolicyOption>()
        ->clone();
  }

  std::unique_ptr<beyondcorp_clientconnectorservices_v1::
                      ClientConnectorServicesServiceConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<
            beyondcorp_clientconnectorservices_v1::
                ClientConnectorServicesServiceConnectionIdempotencyPolicyOption>()) {
      return options
          .get<
              beyondcorp_clientconnectorservices_v1::
                  ClientConnectorServicesServiceConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_
        .get<
            beyondcorp_clientconnectorservices_v1::
                ClientConnectorServicesServiceConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<PollingPolicy> polling_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<beyondcorp_clientconnectorservices_v1::
                        ClientConnectorServicesServicePollingPolicyOption>()) {
      return options
          .get<beyondcorp_clientconnectorservices_v1::
                   ClientConnectorServicesServicePollingPolicyOption>()
          ->clone();
    }
    return options_
        .get<beyondcorp_clientconnectorservices_v1::
                 ClientConnectorServicesServicePollingPolicyOption>()
        ->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<beyondcorp_clientconnectorservices_v1_internal::
                      ClientConnectorServicesServiceStub>
      stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace beyondcorp_clientconnectorservices_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BEYONDCORP_CLIENTCONNECTORSERVICES_V1_INTERNAL_CLIENT_CONNECTOR_SERVICES_CONNECTION_IMPL_H
