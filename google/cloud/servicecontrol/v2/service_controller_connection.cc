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
// source: google/api/servicecontrol/v2/service_controller.proto

#include "google/cloud/servicecontrol/v2/service_controller_connection.h"
#include "google/cloud/servicecontrol/v2/internal/service_controller_connection_impl.h"
#include "google/cloud/servicecontrol/v2/internal/service_controller_option_defaults.h"
#include "google/cloud/servicecontrol/v2/internal/service_controller_stub_factory.h"
#include "google/cloud/servicecontrol/v2/internal/service_controller_tracing_connection.h"
#include "google/cloud/servicecontrol/v2/service_controller_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace servicecontrol_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ServiceControllerConnection::~ServiceControllerConnection() = default;

StatusOr<google::api::servicecontrol::v2::CheckResponse>
ServiceControllerConnection::Check(
    google::api::servicecontrol::v2::CheckRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::api::servicecontrol::v2::ReportResponse>
ServiceControllerConnection::Report(
    google::api::servicecontrol::v2::ReportRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<ServiceControllerConnection> MakeServiceControllerConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 ServiceControllerPolicyOptionList>(options,
                                                                    __func__);
  options = servicecontrol_v2_internal::ServiceControllerDefaultOptions(
      std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = servicecontrol_v2_internal::CreateDefaultServiceControllerStub(
      background->cq(), options);
  return servicecontrol_v2_internal::MakeServiceControllerTracingConnection(
      std::make_shared<
          servicecontrol_v2_internal::ServiceControllerConnectionImpl>(
          std::move(background), std::move(stub), std::move(options)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicecontrol_v2
}  // namespace cloud
}  // namespace google
