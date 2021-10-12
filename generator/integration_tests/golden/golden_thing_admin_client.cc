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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/golden_thing_admin_client.h"
#include <memory>
#include "generator/integration_tests/golden/golden_thing_admin_options.h"
#include "generator/integration_tests/golden/internal/golden_thing_admin_option_defaults.h"
#include <thread>

namespace google {
namespace cloud {
namespace golden {
inline namespace GOOGLE_CLOUD_CPP_NS {

GoldenThingAdminClient::GoldenThingAdminClient(std::shared_ptr<GoldenThingAdminConnection> connection) : connection_(std::move(connection)) {}
GoldenThingAdminClient::~GoldenThingAdminClient() = default;

StreamRange<google::test::admin::database::v1::Database>
GoldenThingAdminClient::ListDatabases(std::string const& parent) {
  google::test::admin::database::v1::ListDatabasesRequest request;
  request.set_parent(parent);
  return connection_->ListDatabases(request);
}

future<StatusOr<google::test::admin::database::v1::Database>>
GoldenThingAdminClient::CreateDatabase(std::string const& parent, std::string const& create_statement) {
  google::test::admin::database::v1::CreateDatabaseRequest request;
  request.set_parent(parent);
  request.set_create_statement(create_statement);
  return connection_->CreateDatabase(request);
}

StatusOr<google::test::admin::database::v1::Database>
GoldenThingAdminClient::GetDatabase(std::string const& name) {
  google::test::admin::database::v1::GetDatabaseRequest request;
  request.set_name(name);
  return connection_->GetDatabase(request);
}

future<StatusOr<google::test::admin::database::v1::UpdateDatabaseDdlMetadata>>
GoldenThingAdminClient::UpdateDatabaseDdl(std::string const& database, std::vector<std::string> const& statements) {
  google::test::admin::database::v1::UpdateDatabaseDdlRequest request;
  request.set_database(database);
  *request.mutable_statements() = {statements.begin(), statements.end()};
  return connection_->UpdateDatabaseDdl(request);
}

Status
GoldenThingAdminClient::DropDatabase(std::string const& database) {
  google::test::admin::database::v1::DropDatabaseRequest request;
  request.set_database(database);
  return connection_->DropDatabase(request);
}

StatusOr<google::test::admin::database::v1::GetDatabaseDdlResponse>
GoldenThingAdminClient::GetDatabaseDdl(std::string const& database) {
  google::test::admin::database::v1::GetDatabaseDdlRequest request;
  request.set_database(database);
  return connection_->GetDatabaseDdl(request);
}

StatusOr<google::iam::v1::Policy>
GoldenThingAdminClient::SetIamPolicy(std::string const& resource, google::iam::v1::Policy const& policy) {
  google::iam::v1::SetIamPolicyRequest request;
  request.set_resource(resource);
  *request.mutable_policy() = policy;
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy>
GoldenThingAdminClient::SetIamPolicy(std::string const& resource, IamUpdater const& updater, Options options) {
  internal::CheckExpectedOptions<GoldenThingAdminBackoffPolicyOption>(options, __func__);
  options = golden_internal::GoldenThingAdminDefaultOptions(std::move(options));
  auto backoff_policy = options.get<GoldenThingAdminBackoffPolicyOption>()->clone();
  for (;;) {
    auto recent = GetIamPolicy(resource);
    if (!recent) {
      return recent.status();
    }
    auto policy = updater(*std::move(recent));
    if (!policy) {
      return Status(StatusCode::kCancelled, "updater did not yield a policy");
    }
    auto result = SetIamPolicy(resource, *std::move(policy));
    if (result || result.status().code() != StatusCode::kAborted) {
      return result;
    }
    std::this_thread::sleep_for(backoff_policy->OnCompletion());
  }
}

StatusOr<google::iam::v1::Policy>
GoldenThingAdminClient::GetIamPolicy(std::string const& resource) {
  google::iam::v1::GetIamPolicyRequest request;
  request.set_resource(resource);
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
GoldenThingAdminClient::TestIamPermissions(std::string const& resource, std::vector<std::string> const& permissions) {
  google::iam::v1::TestIamPermissionsRequest request;
  request.set_resource(resource);
  *request.mutable_permissions() = {permissions.begin(), permissions.end()};
  return connection_->TestIamPermissions(request);
}

future<StatusOr<google::test::admin::database::v1::Backup>>
GoldenThingAdminClient::CreateBackup(std::string const& parent, google::test::admin::database::v1::Backup const& backup, std::string const& backup_id) {
  google::test::admin::database::v1::CreateBackupRequest request;
  request.set_parent(parent);
  *request.mutable_backup() = backup;
  request.set_backup_id(backup_id);
  return connection_->CreateBackup(request);
}

StatusOr<google::test::admin::database::v1::Backup>
GoldenThingAdminClient::GetBackup(std::string const& name) {
  google::test::admin::database::v1::GetBackupRequest request;
  request.set_name(name);
  return connection_->GetBackup(request);
}

StatusOr<google::test::admin::database::v1::Backup>
GoldenThingAdminClient::UpdateBackup(google::test::admin::database::v1::Backup const& backup, google::protobuf::FieldMask const& update_mask) {
  google::test::admin::database::v1::UpdateBackupRequest request;
  *request.mutable_backup() = backup;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateBackup(request);
}

Status
GoldenThingAdminClient::DeleteBackup(std::string const& name) {
  google::test::admin::database::v1::DeleteBackupRequest request;
  request.set_name(name);
  return connection_->DeleteBackup(request);
}

StreamRange<google::test::admin::database::v1::Backup>
GoldenThingAdminClient::ListBackups(std::string const& parent) {
  google::test::admin::database::v1::ListBackupsRequest request;
  request.set_parent(parent);
  return connection_->ListBackups(request);
}

future<StatusOr<google::test::admin::database::v1::Database>>
GoldenThingAdminClient::RestoreDatabase(std::string const& parent, std::string const& database_id, std::string const& backup) {
  google::test::admin::database::v1::RestoreDatabaseRequest request;
  request.set_parent(parent);
  request.set_database_id(database_id);
  request.set_backup(backup);
  return connection_->RestoreDatabase(request);
}

StreamRange<google::longrunning::Operation>
GoldenThingAdminClient::ListDatabaseOperations(std::string const& parent) {
  google::test::admin::database::v1::ListDatabaseOperationsRequest request;
  request.set_parent(parent);
  return connection_->ListDatabaseOperations(request);
}

StreamRange<google::longrunning::Operation>
GoldenThingAdminClient::ListBackupOperations(std::string const& parent) {
  google::test::admin::database::v1::ListBackupOperationsRequest request;
  request.set_parent(parent);
  return connection_->ListBackupOperations(request);
}

StreamRange<google::test::admin::database::v1::Database>
GoldenThingAdminClient::ListDatabases(google::test::admin::database::v1::ListDatabasesRequest request) {
  return connection_->ListDatabases(std::move(request));
}

future<StatusOr<google::test::admin::database::v1::Database>>
GoldenThingAdminClient::CreateDatabase(google::test::admin::database::v1::CreateDatabaseRequest const& request) {
  return connection_->CreateDatabase(request);
}

StatusOr<google::test::admin::database::v1::Database>
GoldenThingAdminClient::GetDatabase(google::test::admin::database::v1::GetDatabaseRequest const& request) {
  return connection_->GetDatabase(request);
}

future<StatusOr<google::test::admin::database::v1::UpdateDatabaseDdlMetadata>>
GoldenThingAdminClient::UpdateDatabaseDdl(google::test::admin::database::v1::UpdateDatabaseDdlRequest const& request) {
  return connection_->UpdateDatabaseDdl(request);
}

Status
GoldenThingAdminClient::DropDatabase(google::test::admin::database::v1::DropDatabaseRequest const& request) {
  return connection_->DropDatabase(request);
}

StatusOr<google::test::admin::database::v1::GetDatabaseDdlResponse>
GoldenThingAdminClient::GetDatabaseDdl(google::test::admin::database::v1::GetDatabaseDdlRequest const& request) {
  return connection_->GetDatabaseDdl(request);
}

StatusOr<google::iam::v1::Policy>
GoldenThingAdminClient::SetIamPolicy(google::iam::v1::SetIamPolicyRequest const& request) {
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy>
GoldenThingAdminClient::GetIamPolicy(google::iam::v1::GetIamPolicyRequest const& request) {
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
GoldenThingAdminClient::TestIamPermissions(google::iam::v1::TestIamPermissionsRequest const& request) {
  return connection_->TestIamPermissions(request);
}

future<StatusOr<google::test::admin::database::v1::Backup>>
GoldenThingAdminClient::CreateBackup(google::test::admin::database::v1::CreateBackupRequest const& request) {
  return connection_->CreateBackup(request);
}

StatusOr<google::test::admin::database::v1::Backup>
GoldenThingAdminClient::GetBackup(google::test::admin::database::v1::GetBackupRequest const& request) {
  return connection_->GetBackup(request);
}

StatusOr<google::test::admin::database::v1::Backup>
GoldenThingAdminClient::UpdateBackup(google::test::admin::database::v1::UpdateBackupRequest const& request) {
  return connection_->UpdateBackup(request);
}

Status
GoldenThingAdminClient::DeleteBackup(google::test::admin::database::v1::DeleteBackupRequest const& request) {
  return connection_->DeleteBackup(request);
}

StreamRange<google::test::admin::database::v1::Backup>
GoldenThingAdminClient::ListBackups(google::test::admin::database::v1::ListBackupsRequest request) {
  return connection_->ListBackups(std::move(request));
}

future<StatusOr<google::test::admin::database::v1::Database>>
GoldenThingAdminClient::RestoreDatabase(google::test::admin::database::v1::RestoreDatabaseRequest const& request) {
  return connection_->RestoreDatabase(request);
}

StreamRange<google::longrunning::Operation>
GoldenThingAdminClient::ListDatabaseOperations(google::test::admin::database::v1::ListDatabaseOperationsRequest request) {
  return connection_->ListDatabaseOperations(std::move(request));
}

StreamRange<google::longrunning::Operation>
GoldenThingAdminClient::ListBackupOperations(google::test::admin::database::v1::ListBackupOperationsRequest request) {
  return connection_->ListBackupOperations(std::move(request));
}

}  // namespace GOOGLE_CLOUD_CPP_NS
}  // namespace golden
}  // namespace cloud
}  // namespace google
