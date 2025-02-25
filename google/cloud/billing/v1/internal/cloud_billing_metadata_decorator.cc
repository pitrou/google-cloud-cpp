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
// source: google/cloud/billing/v1/cloud_billing.proto

#include "google/cloud/billing/v1/internal/cloud_billing_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/billing/v1/cloud_billing.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace billing_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudBillingMetadata::CloudBillingMetadata(
    std::shared_ptr<CloudBillingStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingMetadata::GetBillingAccount(
    grpc::ClientContext& context,
    google::cloud::billing::v1::GetBillingAccountRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetBillingAccount(context, request);
}

StatusOr<google::cloud::billing::v1::ListBillingAccountsResponse>
CloudBillingMetadata::ListBillingAccounts(
    grpc::ClientContext& context,
    google::cloud::billing::v1::ListBillingAccountsRequest const& request) {
  SetMetadata(context);
  return child_->ListBillingAccounts(context, request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingMetadata::UpdateBillingAccount(
    grpc::ClientContext& context,
    google::cloud::billing::v1::UpdateBillingAccountRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->UpdateBillingAccount(context, request);
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingMetadata::CreateBillingAccount(
    grpc::ClientContext& context,
    google::cloud::billing::v1::CreateBillingAccountRequest const& request) {
  SetMetadata(context);
  return child_->CreateBillingAccount(context, request);
}

StatusOr<google::cloud::billing::v1::ListProjectBillingInfoResponse>
CloudBillingMetadata::ListProjectBillingInfo(
    grpc::ClientContext& context,
    google::cloud::billing::v1::ListProjectBillingInfoRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->ListProjectBillingInfo(context, request);
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingMetadata::GetProjectBillingInfo(
    grpc::ClientContext& context,
    google::cloud::billing::v1::GetProjectBillingInfoRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetProjectBillingInfo(context, request);
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingMetadata::UpdateProjectBillingInfo(
    grpc::ClientContext& context,
    google::cloud::billing::v1::UpdateProjectBillingInfoRequest const&
        request) {
  SetMetadata(context, "name=" + request.name());
  return child_->UpdateProjectBillingInfo(context, request);
}

StatusOr<google::iam::v1::Policy> CloudBillingMetadata::GetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  SetMetadata(context, "resource=" + request.resource());
  return child_->GetIamPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> CloudBillingMetadata::SetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  SetMetadata(context, "resource=" + request.resource());
  return child_->SetIamPolicy(context, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
CloudBillingMetadata::TestIamPermissions(
    grpc::ClientContext& context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  SetMetadata(context, "resource=" + request.resource());
  return child_->TestIamPermissions(context, request);
}

void CloudBillingMetadata::SetMetadata(grpc::ClientContext& context,
                                       std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void CloudBillingMetadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace billing_v1_internal
}  // namespace cloud
}  // namespace google
