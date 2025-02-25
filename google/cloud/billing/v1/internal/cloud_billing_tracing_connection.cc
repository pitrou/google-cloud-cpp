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

#include "google/cloud/billing/v1/internal/cloud_billing_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace billing_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

CloudBillingTracingConnection::CloudBillingTracingConnection(
    std::shared_ptr<billing_v1::CloudBillingConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingTracingConnection::GetBillingAccount(
    google::cloud::billing::v1::GetBillingAccountRequest const& request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::GetBillingAccount");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetBillingAccount(request));
}

StreamRange<google::cloud::billing::v1::BillingAccount>
CloudBillingTracingConnection::ListBillingAccounts(
    google::cloud::billing::v1::ListBillingAccountsRequest request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::ListBillingAccounts");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListBillingAccounts(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::billing::v1::BillingAccount>(std::move(span),
                                                  std::move(sr));
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingTracingConnection::UpdateBillingAccount(
    google::cloud::billing::v1::UpdateBillingAccountRequest const& request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::UpdateBillingAccount");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateBillingAccount(request));
}

StatusOr<google::cloud::billing::v1::BillingAccount>
CloudBillingTracingConnection::CreateBillingAccount(
    google::cloud::billing::v1::CreateBillingAccountRequest const& request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::CreateBillingAccount");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateBillingAccount(request));
}

StreamRange<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingTracingConnection::ListProjectBillingInfo(
    google::cloud::billing::v1::ListProjectBillingInfoRequest request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::ListProjectBillingInfo");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListProjectBillingInfo(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::billing::v1::ProjectBillingInfo>(std::move(span),
                                                      std::move(sr));
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingTracingConnection::GetProjectBillingInfo(
    google::cloud::billing::v1::GetProjectBillingInfoRequest const& request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::GetProjectBillingInfo");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetProjectBillingInfo(request));
}

StatusOr<google::cloud::billing::v1::ProjectBillingInfo>
CloudBillingTracingConnection::UpdateProjectBillingInfo(
    google::cloud::billing::v1::UpdateProjectBillingInfoRequest const&
        request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::UpdateProjectBillingInfo");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateProjectBillingInfo(request));
}

StatusOr<google::iam::v1::Policy> CloudBillingTracingConnection::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request) {
  auto span =
      internal::MakeSpan("billing_v1::CloudBillingConnection::GetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetIamPolicy(request));
}

StatusOr<google::iam::v1::Policy> CloudBillingTracingConnection::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request) {
  auto span =
      internal::MakeSpan("billing_v1::CloudBillingConnection::SetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->SetIamPolicy(request));
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
CloudBillingTracingConnection::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request) {
  auto span = internal::MakeSpan(
      "billing_v1::CloudBillingConnection::TestIamPermissions");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->TestIamPermissions(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<billing_v1::CloudBillingConnection>
MakeCloudBillingTracingConnection(
    std::shared_ptr<billing_v1::CloudBillingConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<CloudBillingTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace billing_v1_internal
}  // namespace cloud
}  // namespace google
