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
// source: google/devtools/cloudbuild/v2/repositories.proto

#include "google/cloud/cloudbuild/v2/repository_manager_connection.h"
#include "google/cloud/cloudbuild/v2/internal/repository_manager_connection_impl.h"
#include "google/cloud/cloudbuild/v2/internal/repository_manager_option_defaults.h"
#include "google/cloud/cloudbuild/v2/internal/repository_manager_stub_factory.h"
#include "google/cloud/cloudbuild/v2/internal/repository_manager_tracing_connection.h"
#include "google/cloud/cloudbuild/v2/repository_manager_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace cloudbuild_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

RepositoryManagerConnection::~RepositoryManagerConnection() = default;

future<StatusOr<google::devtools::cloudbuild::v2::Connection>>
RepositoryManagerConnection::CreateConnection(
    google::devtools::cloudbuild::v2::CreateConnectionRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v2::Connection>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::devtools::cloudbuild::v2::Connection>
RepositoryManagerConnection::GetConnection(
    google::devtools::cloudbuild::v2::GetConnectionRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::devtools::cloudbuild::v2::Connection>
RepositoryManagerConnection::ListConnections(
    google::devtools::cloudbuild::v2::
        ListConnectionsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::devtools::cloudbuild::v2::Connection>>();
}

future<StatusOr<google::devtools::cloudbuild::v2::Connection>>
RepositoryManagerConnection::UpdateConnection(
    google::devtools::cloudbuild::v2::UpdateConnectionRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v2::Connection>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::devtools::cloudbuild::v2::OperationMetadata>>
RepositoryManagerConnection::DeleteConnection(
    google::devtools::cloudbuild::v2::DeleteConnectionRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v2::OperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::devtools::cloudbuild::v2::Repository>>
RepositoryManagerConnection::CreateRepository(
    google::devtools::cloudbuild::v2::CreateRepositoryRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v2::Repository>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<
    StatusOr<google::devtools::cloudbuild::v2::BatchCreateRepositoriesResponse>>
RepositoryManagerConnection::BatchCreateRepositories(
    google::devtools::cloudbuild::v2::BatchCreateRepositoriesRequest const&) {
  return google::cloud::make_ready_future<StatusOr<
      google::devtools::cloudbuild::v2::BatchCreateRepositoriesResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::devtools::cloudbuild::v2::Repository>
RepositoryManagerConnection::GetRepository(
    google::devtools::cloudbuild::v2::GetRepositoryRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::devtools::cloudbuild::v2::Repository>
RepositoryManagerConnection::ListRepositories(
    google::devtools::cloudbuild::v2::
        ListRepositoriesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::devtools::cloudbuild::v2::Repository>>();
}

future<StatusOr<google::devtools::cloudbuild::v2::OperationMetadata>>
RepositoryManagerConnection::DeleteRepository(
    google::devtools::cloudbuild::v2::DeleteRepositoryRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::devtools::cloudbuild::v2::OperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::devtools::cloudbuild::v2::FetchReadWriteTokenResponse>
RepositoryManagerConnection::FetchReadWriteToken(
    google::devtools::cloudbuild::v2::FetchReadWriteTokenRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::devtools::cloudbuild::v2::FetchReadTokenResponse>
RepositoryManagerConnection::FetchReadToken(
    google::devtools::cloudbuild::v2::FetchReadTokenRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::devtools::cloudbuild::v2::Repository>
RepositoryManagerConnection::FetchLinkableRepositories(
    google::devtools::cloudbuild::v2::
        FetchLinkableRepositoriesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::devtools::cloudbuild::v2::Repository>>();
}

std::shared_ptr<RepositoryManagerConnection> MakeRepositoryManagerConnection(
    ExperimentalTag, Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 RepositoryManagerPolicyOptionList>(options,
                                                                    __func__);
  options = cloudbuild_v2_internal::RepositoryManagerDefaultOptions(
      std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = cloudbuild_v2_internal::CreateDefaultRepositoryManagerStub(
      background->cq(), options);
  return cloudbuild_v2_internal::MakeRepositoryManagerTracingConnection(
      std::make_shared<cloudbuild_v2_internal::RepositoryManagerConnectionImpl>(
          std::move(background), std::move(stub), std::move(options)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloudbuild_v2
}  // namespace cloud
}  // namespace google
