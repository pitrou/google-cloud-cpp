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
// source: google/cloud/tpu/v2/cloud_tpu.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TPU_V2_INTERNAL_TPU_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TPU_V2_INTERNAL_TPU_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/tpu/v2/cloud_tpu.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace tpu_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TpuStub {
 public:
  virtual ~TpuStub() = 0;

  virtual StatusOr<google::cloud::tpu::v2::ListNodesResponse> ListNodes(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::ListNodesRequest const& request) = 0;

  virtual StatusOr<google::cloud::tpu::v2::Node> GetNode(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::GetNodeRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncCreateNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::CreateNodeRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncDeleteNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::DeleteNodeRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncStopNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::StopNodeRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncStartNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::StartNodeRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncUpdateNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::UpdateNodeRequest const& request) = 0;

  virtual StatusOr<google::cloud::tpu::v2::GenerateServiceIdentityResponse>
  GenerateServiceIdentity(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::GenerateServiceIdentityRequest const&
          request) = 0;

  virtual StatusOr<google::cloud::tpu::v2::ListAcceleratorTypesResponse>
  ListAcceleratorTypes(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::ListAcceleratorTypesRequest const& request) = 0;

  virtual StatusOr<google::cloud::tpu::v2::AcceleratorType> GetAcceleratorType(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::GetAcceleratorTypeRequest const& request) = 0;

  virtual StatusOr<google::cloud::tpu::v2::ListRuntimeVersionsResponse>
  ListRuntimeVersions(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::ListRuntimeVersionsRequest const& request) = 0;

  virtual StatusOr<google::cloud::tpu::v2::RuntimeVersion> GetRuntimeVersion(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::GetRuntimeVersionRequest const& request) = 0;

  virtual StatusOr<google::cloud::tpu::v2::GetGuestAttributesResponse>
  GetGuestAttributes(
      grpc::ClientContext& context,
      google::cloud::tpu::v2::GetGuestAttributesRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultTpuStub : public TpuStub {
 public:
  DefaultTpuStub(
      std::unique_ptr<google::cloud::tpu::v2::Tpu::StubInterface> grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  StatusOr<google::cloud::tpu::v2::ListNodesResponse> ListNodes(
      grpc::ClientContext& client_context,
      google::cloud::tpu::v2::ListNodesRequest const& request) override;

  StatusOr<google::cloud::tpu::v2::Node> GetNode(
      grpc::ClientContext& client_context,
      google::cloud::tpu::v2::GetNodeRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::CreateNodeRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::DeleteNodeRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncStopNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::StopNodeRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncStartNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::StartNodeRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateNode(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::tpu::v2::UpdateNodeRequest const& request) override;

  StatusOr<google::cloud::tpu::v2::GenerateServiceIdentityResponse>
  GenerateServiceIdentity(
      grpc::ClientContext& client_context,
      google::cloud::tpu::v2::GenerateServiceIdentityRequest const& request)
      override;

  StatusOr<google::cloud::tpu::v2::ListAcceleratorTypesResponse>
  ListAcceleratorTypes(
      grpc::ClientContext& client_context,
      google::cloud::tpu::v2::ListAcceleratorTypesRequest const& request)
      override;

  StatusOr<google::cloud::tpu::v2::AcceleratorType> GetAcceleratorType(
      grpc::ClientContext& client_context,
      google::cloud::tpu::v2::GetAcceleratorTypeRequest const& request)
      override;

  StatusOr<google::cloud::tpu::v2::ListRuntimeVersionsResponse>
  ListRuntimeVersions(grpc::ClientContext& client_context,
                      google::cloud::tpu::v2::ListRuntimeVersionsRequest const&
                          request) override;

  StatusOr<google::cloud::tpu::v2::RuntimeVersion> GetRuntimeVersion(
      grpc::ClientContext& client_context,
      google::cloud::tpu::v2::GetRuntimeVersionRequest const& request) override;

  StatusOr<google::cloud::tpu::v2::GetGuestAttributesResponse>
  GetGuestAttributes(grpc::ClientContext& client_context,
                     google::cloud::tpu::v2::GetGuestAttributesRequest const&
                         request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<google::cloud::tpu::v2::Tpu::StubInterface> grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace tpu_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TPU_V2_INTERNAL_TPU_STUB_H
