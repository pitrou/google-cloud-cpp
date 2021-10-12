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
// source: google/iam/admin/v1/iam.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_MOCKS_MOCK_IAM_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_MOCKS_MOCK_IAM_CONNECTION_H

#include "google/cloud/iam/iam_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace iam_mocks {
inline namespace GOOGLE_CLOUD_CPP_NS {

class MockIAMConnection : public iam::IAMConnection {
 public:
  MOCK_METHOD(StreamRange<google::iam::admin::v1::ServiceAccount>,
              ListServiceAccounts,
              (google::iam::admin::v1::ListServiceAccountsRequest request),
              (override));

  MOCK_METHOD(StatusOr<google::iam::admin::v1::ServiceAccount>,
              GetServiceAccount,
              (google::iam::admin::v1::GetServiceAccountRequest const& request),
              (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::ServiceAccount>, CreateServiceAccount,
      (google::iam::admin::v1::CreateServiceAccountRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::ServiceAccount>, PatchServiceAccount,
      (google::iam::admin::v1::PatchServiceAccountRequest const& request),
      (override));

  MOCK_METHOD(
      Status, DeleteServiceAccount,
      (google::iam::admin::v1::DeleteServiceAccountRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::UndeleteServiceAccountResponse>,
      UndeleteServiceAccount,
      (google::iam::admin::v1::UndeleteServiceAccountRequest const& request),
      (override));

  MOCK_METHOD(
      Status, EnableServiceAccount,
      (google::iam::admin::v1::EnableServiceAccountRequest const& request),
      (override));

  MOCK_METHOD(
      Status, DisableServiceAccount,
      (google::iam::admin::v1::DisableServiceAccountRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::ListServiceAccountKeysResponse>,
      ListServiceAccountKeys,
      (google::iam::admin::v1::ListServiceAccountKeysRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::ServiceAccountKey>, GetServiceAccountKey,
      (google::iam::admin::v1::GetServiceAccountKeyRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::ServiceAccountKey>,
      CreateServiceAccountKey,
      (google::iam::admin::v1::CreateServiceAccountKeyRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::ServiceAccountKey>,
      UploadServiceAccountKey,
      (google::iam::admin::v1::UploadServiceAccountKeyRequest const& request),
      (override));

  MOCK_METHOD(
      Status, DeleteServiceAccountKey,
      (google::iam::admin::v1::DeleteServiceAccountKeyRequest const& request),
      (override));

  MOCK_METHOD(StatusOr<google::iam::v1::Policy>, GetIamPolicy,
              (google::iam::v1::GetIamPolicyRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::iam::v1::Policy>, SetIamPolicy,
              (google::iam::v1::SetIamPolicyRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::iam::v1::TestIamPermissionsResponse>,
              TestIamPermissions,
              (google::iam::v1::TestIamPermissionsRequest const& request),
              (override));

  MOCK_METHOD(StreamRange<google::iam::admin::v1::Role>, QueryGrantableRoles,
              (google::iam::admin::v1::QueryGrantableRolesRequest request),
              (override));

  MOCK_METHOD(StreamRange<google::iam::admin::v1::Role>, ListRoles,
              (google::iam::admin::v1::ListRolesRequest request), (override));

  MOCK_METHOD(StatusOr<google::iam::admin::v1::Role>, GetRole,
              (google::iam::admin::v1::GetRoleRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::iam::admin::v1::Role>, CreateRole,
              (google::iam::admin::v1::CreateRoleRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::iam::admin::v1::Role>, UpdateRole,
              (google::iam::admin::v1::UpdateRoleRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::iam::admin::v1::Role>, DeleteRole,
              (google::iam::admin::v1::DeleteRoleRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::iam::admin::v1::Role>, UndeleteRole,
              (google::iam::admin::v1::UndeleteRoleRequest const& request),
              (override));

  MOCK_METHOD(StreamRange<google::iam::admin::v1::Permission>,
              QueryTestablePermissions,
              (google::iam::admin::v1::QueryTestablePermissionsRequest request),
              (override));

  MOCK_METHOD(
      StatusOr<google::iam::admin::v1::QueryAuditableServicesResponse>,
      QueryAuditableServices,
      (google::iam::admin::v1::QueryAuditableServicesRequest const& request),
      (override));

  MOCK_METHOD(StatusOr<google::iam::admin::v1::LintPolicyResponse>, LintPolicy,
              (google::iam::admin::v1::LintPolicyRequest const& request),
              (override));
};

}  // namespace GOOGLE_CLOUD_CPP_NS
}  // namespace iam_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_MOCKS_MOCK_IAM_CONNECTION_H
