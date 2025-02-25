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
// source: google/cloud/vmmigration/v1/vmmigration.proto

#include "google/cloud/vmmigration/v1/internal/vm_migration_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/vmmigration/v1/vmmigration.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace vmmigration_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

VmMigrationLogging::VmMigrationLogging(std::shared_ptr<VmMigrationStub> child,
                                       TracingOptions tracing_options,
                                       std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::vmmigration::v1::ListSourcesResponse>
VmMigrationLogging::ListSources(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListSourcesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::vmmigration::v1::ListSourcesRequest const& request) {
        return child_->ListSources(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::Source> VmMigrationLogging::GetSource(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::GetSourceRequest const& request) {
        return child_->GetSource(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateSource(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::CreateSourceRequest const& request) {
        return child_->AsyncCreateSource(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncUpdateSource(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::UpdateSourceRequest const& request) {
        return child_->AsyncUpdateSource(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncDeleteSource(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::DeleteSourceRequest const& request) {
        return child_->AsyncDeleteSource(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::FetchInventoryResponse>
VmMigrationLogging::FetchInventory(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::FetchInventoryRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::FetchInventoryRequest const&
                 request) { return child_->FetchInventory(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListUtilizationReportsResponse>
VmMigrationLogging::ListUtilizationReports(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListUtilizationReportsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::vmmigration::v1::ListUtilizationReportsRequest const&
              request) {
        return child_->ListUtilizationReports(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::UtilizationReport>
VmMigrationLogging::GetUtilizationReport(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetUtilizationReportRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::GetUtilizationReportRequest const&
                 request) {
        return child_->GetUtilizationReport(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateUtilizationReport(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateUtilizationReportRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::CreateUtilizationReportRequest const&
              request) {
        return child_->AsyncCreateUtilizationReport(cq, std::move(context),
                                                    request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncDeleteUtilizationReport(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteUtilizationReportRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::DeleteUtilizationReportRequest const&
              request) {
        return child_->AsyncDeleteUtilizationReport(cq, std::move(context),
                                                    request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListDatacenterConnectorsResponse>
VmMigrationLogging::ListDatacenterConnectors(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListDatacenterConnectorsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::vmmigration::v1::ListDatacenterConnectorsRequest const&
              request) {
        return child_->ListDatacenterConnectors(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::DatacenterConnector>
VmMigrationLogging::GetDatacenterConnector(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetDatacenterConnectorRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::vmmigration::v1::GetDatacenterConnectorRequest const&
              request) {
        return child_->GetDatacenterConnector(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateDatacenterConnector(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateDatacenterConnectorRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::
                 CreateDatacenterConnectorRequest const& request) {
        return child_->AsyncCreateDatacenterConnector(cq, std::move(context),
                                                      request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncDeleteDatacenterConnector(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteDatacenterConnectorRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::
                 DeleteDatacenterConnectorRequest const& request) {
        return child_->AsyncDeleteDatacenterConnector(cq, std::move(context),
                                                      request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncUpgradeAppliance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpgradeApplianceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::UpgradeApplianceRequest const&
                 request) {
        return child_->AsyncUpgradeAppliance(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateMigratingVm(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateMigratingVmRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::CreateMigratingVmRequest const&
                 request) {
        return child_->AsyncCreateMigratingVm(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListMigratingVmsResponse>
VmMigrationLogging::ListMigratingVms(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListMigratingVmsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::ListMigratingVmsRequest const&
                 request) {
        return child_->ListMigratingVms(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::MigratingVm>
VmMigrationLogging::GetMigratingVm(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetMigratingVmRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::GetMigratingVmRequest const&
                 request) { return child_->GetMigratingVm(context, request); },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncUpdateMigratingVm(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateMigratingVmRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::UpdateMigratingVmRequest const&
                 request) {
        return child_->AsyncUpdateMigratingVm(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncDeleteMigratingVm(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteMigratingVmRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::DeleteMigratingVmRequest const&
                 request) {
        return child_->AsyncDeleteMigratingVm(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncStartMigration(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::StartMigrationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::StartMigrationRequest const&
                 request) {
        return child_->AsyncStartMigration(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncResumeMigration(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::ResumeMigrationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::ResumeMigrationRequest const&
                 request) {
        return child_->AsyncResumeMigration(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncPauseMigration(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::PauseMigrationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::PauseMigrationRequest const&
                 request) {
        return child_->AsyncPauseMigration(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncFinalizeMigration(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::FinalizeMigrationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::FinalizeMigrationRequest const&
                 request) {
        return child_->AsyncFinalizeMigration(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateCloneJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateCloneJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::CreateCloneJobRequest const&
                 request) {
        return child_->AsyncCreateCloneJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCancelCloneJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CancelCloneJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::CancelCloneJobRequest const&
                 request) {
        return child_->AsyncCancelCloneJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListCloneJobsResponse>
VmMigrationLogging::ListCloneJobs(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListCloneJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::vmmigration::v1::ListCloneJobsRequest const& request) {
        return child_->ListCloneJobs(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::CloneJob>
VmMigrationLogging::GetCloneJob(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetCloneJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::vmmigration::v1::GetCloneJobRequest const& request) {
        return child_->GetCloneJob(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateCutoverJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateCutoverJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::CreateCutoverJobRequest const&
                 request) {
        return child_->AsyncCreateCutoverJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCancelCutoverJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CancelCutoverJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::CancelCutoverJobRequest const&
                 request) {
        return child_->AsyncCancelCutoverJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListCutoverJobsResponse>
VmMigrationLogging::ListCutoverJobs(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListCutoverJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::ListCutoverJobsRequest const&
                 request) { return child_->ListCutoverJobs(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::CutoverJob>
VmMigrationLogging::GetCutoverJob(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetCutoverJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::vmmigration::v1::GetCutoverJobRequest const& request) {
        return child_->GetCutoverJob(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListGroupsResponse>
VmMigrationLogging::ListGroups(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListGroupsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::ListGroupsRequest const& request) {
        return child_->ListGroups(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::Group> VmMigrationLogging::GetGroup(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::GetGroupRequest const& request) {
        return child_->GetGroup(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::CreateGroupRequest const& request) {
        return child_->AsyncCreateGroup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncUpdateGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::UpdateGroupRequest const& request) {
        return child_->AsyncUpdateGroup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncDeleteGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::vmmigration::v1::DeleteGroupRequest const& request) {
        return child_->AsyncDeleteGroup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncAddGroupMigration(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::AddGroupMigrationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::AddGroupMigrationRequest const&
                 request) {
        return child_->AsyncAddGroupMigration(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncRemoveGroupMigration(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::RemoveGroupMigrationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::RemoveGroupMigrationRequest const&
                 request) {
        return child_->AsyncRemoveGroupMigration(cq, std::move(context),
                                                 request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListTargetProjectsResponse>
VmMigrationLogging::ListTargetProjects(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListTargetProjectsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::ListTargetProjectsRequest const&
                 request) {
        return child_->ListTargetProjects(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::TargetProject>
VmMigrationLogging::GetTargetProject(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetTargetProjectRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::GetTargetProjectRequest const&
                 request) {
        return child_->GetTargetProject(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncCreateTargetProject(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::CreateTargetProjectRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::CreateTargetProjectRequest const&
                 request) {
        return child_->AsyncCreateTargetProject(cq, std::move(context),
                                                request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncUpdateTargetProject(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::UpdateTargetProjectRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::UpdateTargetProjectRequest const&
                 request) {
        return child_->AsyncUpdateTargetProject(cq, std::move(context),
                                                request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncDeleteTargetProject(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmmigration::v1::DeleteTargetProjectRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::vmmigration::v1::DeleteTargetProjectRequest const&
                 request) {
        return child_->AsyncDeleteTargetProject(cq, std::move(context),
                                                request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ListReplicationCyclesResponse>
VmMigrationLogging::ListReplicationCycles(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::ListReplicationCyclesRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::ListReplicationCyclesRequest const&
                 request) {
        return child_->ListReplicationCycles(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::vmmigration::v1::ReplicationCycle>
VmMigrationLogging::GetReplicationCycle(
    grpc::ClientContext& context,
    google::cloud::vmmigration::v1::GetReplicationCycleRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::vmmigration::v1::GetReplicationCycleRequest const&
                 request) {
        return child_->GetReplicationCycle(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
VmMigrationLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<Status> VmMigrationLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vmmigration_v1_internal
}  // namespace cloud
}  // namespace google
