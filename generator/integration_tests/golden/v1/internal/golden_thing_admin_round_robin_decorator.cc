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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/v1/internal/golden_thing_admin_round_robin_decorator.h"

namespace google {
namespace cloud {
namespace golden_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GoldenThingAdminRoundRobin::GoldenThingAdminRoundRobin(
    std::vector<std::shared_ptr<GoldenThingAdminStub>> children)
    : children_(std::move(children)) {}

StatusOr<google::test::admin::database::v1::ListDatabasesResponse> GoldenThingAdminRoundRobin::ListDatabases(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListDatabasesRequest const& request) {
  return Child()->ListDatabases(context, request);
}

future<StatusOr<google::longrunning::Operation>>
GoldenThingAdminRoundRobin::AsyncCreateDatabase(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::CreateDatabaseRequest const& request) {
  return Child()->AsyncCreateDatabase(cq, std::move(context), request);
}

StatusOr<google::test::admin::database::v1::Database> GoldenThingAdminRoundRobin::GetDatabase(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GetDatabaseRequest const& request) {
  return Child()->GetDatabase(context, request);
}

future<StatusOr<google::longrunning::Operation>>
GoldenThingAdminRoundRobin::AsyncUpdateDatabaseDdl(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::UpdateDatabaseDdlRequest const& request) {
  return Child()->AsyncUpdateDatabaseDdl(cq, std::move(context), request);
}

Status GoldenThingAdminRoundRobin::DropDatabase(
    grpc::ClientContext& context,
    google::test::admin::database::v1::DropDatabaseRequest const& request) {
  return Child()->DropDatabase(context, request);
}

StatusOr<google::test::admin::database::v1::GetDatabaseDdlResponse> GoldenThingAdminRoundRobin::GetDatabaseDdl(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GetDatabaseDdlRequest const& request) {
  return Child()->GetDatabaseDdl(context, request);
}

StatusOr<google::iam::v1::Policy> GoldenThingAdminRoundRobin::SetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  return Child()->SetIamPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> GoldenThingAdminRoundRobin::GetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  return Child()->GetIamPolicy(context, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse> GoldenThingAdminRoundRobin::TestIamPermissions(
    grpc::ClientContext& context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  return Child()->TestIamPermissions(context, request);
}

future<StatusOr<google::longrunning::Operation>>
GoldenThingAdminRoundRobin::AsyncCreateBackup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::CreateBackupRequest const& request) {
  return Child()->AsyncCreateBackup(cq, std::move(context), request);
}

StatusOr<google::test::admin::database::v1::Backup> GoldenThingAdminRoundRobin::GetBackup(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GetBackupRequest const& request) {
  return Child()->GetBackup(context, request);
}

StatusOr<google::test::admin::database::v1::Backup> GoldenThingAdminRoundRobin::UpdateBackup(
    grpc::ClientContext& context,
    google::test::admin::database::v1::UpdateBackupRequest const& request) {
  return Child()->UpdateBackup(context, request);
}

Status GoldenThingAdminRoundRobin::DeleteBackup(
    grpc::ClientContext& context,
    google::test::admin::database::v1::DeleteBackupRequest const& request) {
  return Child()->DeleteBackup(context, request);
}

StatusOr<google::test::admin::database::v1::ListBackupsResponse> GoldenThingAdminRoundRobin::ListBackups(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListBackupsRequest const& request) {
  return Child()->ListBackups(context, request);
}

future<StatusOr<google::longrunning::Operation>>
GoldenThingAdminRoundRobin::AsyncRestoreDatabase(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::RestoreDatabaseRequest const& request) {
  return Child()->AsyncRestoreDatabase(cq, std::move(context), request);
}

StatusOr<google::test::admin::database::v1::ListDatabaseOperationsResponse> GoldenThingAdminRoundRobin::ListDatabaseOperations(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListDatabaseOperationsRequest const& request) {
  return Child()->ListDatabaseOperations(context, request);
}

StatusOr<google::test::admin::database::v1::ListBackupOperationsResponse> GoldenThingAdminRoundRobin::ListBackupOperations(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListBackupOperationsRequest const& request) {
  return Child()->ListBackupOperations(context, request);
}

future<StatusOr<google::longrunning::Operation>>
GoldenThingAdminRoundRobin::AsyncLongRunningWithoutRouting(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::RestoreDatabaseRequest const& request) {
  return Child()->AsyncLongRunningWithoutRouting(cq, std::move(context), request);
}

future<StatusOr<google::test::admin::database::v1::Database>>
GoldenThingAdminRoundRobin::AsyncGetDatabase(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::GetDatabaseRequest const& request) {
  return Child()->AsyncGetDatabase(cq, std::move(context), request);
}

future<Status>
GoldenThingAdminRoundRobin::AsyncDropDatabase(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::DropDatabaseRequest const& request) {
  return Child()->AsyncDropDatabase(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
GoldenThingAdminRoundRobin::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return Child()->AsyncGetOperation(cq, std::move(context), request);
}

future<Status>
GoldenThingAdminRoundRobin::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return Child()->AsyncCancelOperation(cq, std::move(context), request);
}

std::shared_ptr<GoldenThingAdminStub>
GoldenThingAdminRoundRobin::Child() {
  std::unique_lock<std::mutex> lk(mu_);
  auto const current = current_;
  if (++current_ == children_.size()) current_ = 0;
  lk.unlock();
  return children_[current];
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden_v1_internal
}  // namespace cloud
}  // namespace google
