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

#include "generator/integration_tests/golden/internal/golden_kitchen_sink_auth_decorator.h"
#include <generator/integration_tests/test.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace golden_internal {
inline namespace GOOGLE_CLOUD_CPP_NS {


GoldenKitchenSinkAuth::GoldenKitchenSinkAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<GoldenKitchenSinkStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::test::admin::database::v1::GenerateAccessTokenResponse> GoldenKitchenSinkAuth::GenerateAccessToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateAccessTokenRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GenerateAccessToken(context, request);
}

StatusOr<google::test::admin::database::v1::GenerateIdTokenResponse> GoldenKitchenSinkAuth::GenerateIdToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateIdTokenRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GenerateIdToken(context, request);
}

StatusOr<google::test::admin::database::v1::WriteLogEntriesResponse> GoldenKitchenSinkAuth::WriteLogEntries(
    grpc::ClientContext& context,
    google::test::admin::database::v1::WriteLogEntriesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->WriteLogEntries(context, request);
}

StatusOr<google::test::admin::database::v1::ListLogsResponse> GoldenKitchenSinkAuth::ListLogs(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListLogsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListLogs(context, request);
}

std::unique_ptr<internal::StreamingReadRpc<google::test::admin::database::v1::TailLogEntriesResponse>>
GoldenKitchenSinkAuth::TailLogEntries(
   std::unique_ptr<grpc::ClientContext> context,
   google::test::admin::database::v1::TailLogEntriesRequest const& request) {
  using ErrorStream = ::google::cloud::internal::StreamingReadRpcError<
      google::test::admin::database::v1::TailLogEntriesResponse>;
  auto status = auth_->ConfigureContext(*context);
  if (!status.ok()) return absl::make_unique<ErrorStream>(std::move(status));
  return child_->TailLogEntries(std::move(context), request);
}

StatusOr<google::test::admin::database::v1::ListServiceAccountKeysResponse> GoldenKitchenSinkAuth::ListServiceAccountKeys(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListServiceAccountKeysRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListServiceAccountKeys(context, request);
}
}  // namespace GOOGLE_CLOUD_CPP_NS
}  // namespace golden_internal
}  // namespace cloud
}  // namespace google
