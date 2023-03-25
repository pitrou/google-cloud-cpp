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
// source: google/cloud/deploy/v1/cloud_deploy.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEPLOY_V1_INTERNAL_CLOUD_DEPLOY_TRACING_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEPLOY_V1_INTERNAL_CLOUD_DEPLOY_TRACING_STUB_H

#include "google/cloud/deploy/v1/internal/cloud_deploy_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"

namespace google {
namespace cloud {
namespace deploy_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

class CloudDeployTracingStub : public CloudDeployStub {
 public:
  ~CloudDeployTracingStub() override = default;

  explicit CloudDeployTracingStub(std::shared_ptr<CloudDeployStub> child);

  StatusOr<google::cloud::deploy::v1::ListDeliveryPipelinesResponse>
  ListDeliveryPipelines(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::ListDeliveryPipelinesRequest const& request)
      override;

  StatusOr<google::cloud::deploy::v1::DeliveryPipeline> GetDeliveryPipeline(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::GetDeliveryPipelineRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateDeliveryPipeline(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::CreateDeliveryPipelineRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateDeliveryPipeline(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::UpdateDeliveryPipelineRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteDeliveryPipeline(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::DeleteDeliveryPipelineRequest const& request)
      override;

  StatusOr<google::cloud::deploy::v1::ListTargetsResponse> ListTargets(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::ListTargetsRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::Target> GetTarget(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::GetTargetRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateTarget(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::CreateTargetRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateTarget(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::UpdateTargetRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteTarget(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::DeleteTargetRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::ListReleasesResponse> ListReleases(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::ListReleasesRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::Release> GetRelease(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::GetReleaseRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateRelease(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::CreateReleaseRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::AbandonReleaseResponse> AbandonRelease(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::AbandonReleaseRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::ApproveRolloutResponse> ApproveRollout(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::ApproveRolloutRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::AdvanceRolloutResponse> AdvanceRollout(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::AdvanceRolloutRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::CancelRolloutResponse> CancelRollout(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::CancelRolloutRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::ListRolloutsResponse> ListRollouts(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::ListRolloutsRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::Rollout> GetRollout(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::GetRolloutRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateRollout(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::deploy::v1::CreateRolloutRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::IgnoreJobResponse> IgnoreJob(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::IgnoreJobRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::RetryJobResponse> RetryJob(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::RetryJobRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::ListJobRunsResponse> ListJobRuns(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::ListJobRunsRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::JobRun> GetJobRun(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::GetJobRunRequest const& request) override;

  StatusOr<google::cloud::deploy::v1::TerminateJobRunResponse> TerminateJobRun(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::TerminateJobRunRequest const& request)
      override;

  StatusOr<google::cloud::deploy::v1::Config> GetConfig(
      grpc::ClientContext& context,
      google::cloud::deploy::v1::GetConfigRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<CloudDeployStub> child_;
};

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

/**
 * Applies the tracing decorator to the given stub.
 *
 * The stub is only decorated if the library has been compiled with
 * OpenTelemetry.
 */
std::shared_ptr<CloudDeployStub> MakeCloudDeployTracingStub(
    std::shared_ptr<CloudDeployStub> stub);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace deploy_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEPLOY_V1_INTERNAL_CLOUD_DEPLOY_TRACING_STUB_H
