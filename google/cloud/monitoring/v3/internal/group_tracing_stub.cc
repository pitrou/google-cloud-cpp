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
// source: google/monitoring/v3/group_service.proto

#include "google/cloud/monitoring/v3/internal/group_tracing_stub.h"
#include "google/cloud/internal/grpc_opentelemetry.h"

namespace google {
namespace cloud {
namespace monitoring_v3_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

GroupServiceTracingStub::GroupServiceTracingStub(
    std::shared_ptr<GroupServiceStub> child)
    : child_(std::move(child)) {}

StatusOr<google::monitoring::v3::ListGroupsResponse>
GroupServiceTracingStub::ListGroups(
    grpc::ClientContext& context,
    google::monitoring::v3::ListGroupsRequest const& request) {
  auto span =
      internal::MakeSpanGrpc("google.monitoring.v3.GroupService", "ListGroups");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListGroups(context, request));
}

StatusOr<google::monitoring::v3::Group> GroupServiceTracingStub::GetGroup(
    grpc::ClientContext& context,
    google::monitoring::v3::GetGroupRequest const& request) {
  auto span =
      internal::MakeSpanGrpc("google.monitoring.v3.GroupService", "GetGroup");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span, child_->GetGroup(context, request));
}

StatusOr<google::monitoring::v3::Group> GroupServiceTracingStub::CreateGroup(
    grpc::ClientContext& context,
    google::monitoring::v3::CreateGroupRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.monitoring.v3.GroupService",
                                     "CreateGroup");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->CreateGroup(context, request));
}

StatusOr<google::monitoring::v3::Group> GroupServiceTracingStub::UpdateGroup(
    grpc::ClientContext& context,
    google::monitoring::v3::UpdateGroupRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.monitoring.v3.GroupService",
                                     "UpdateGroup");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->UpdateGroup(context, request));
}

Status GroupServiceTracingStub::DeleteGroup(
    grpc::ClientContext& context,
    google::monitoring::v3::DeleteGroupRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.monitoring.v3.GroupService",
                                     "DeleteGroup");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->DeleteGroup(context, request));
}

StatusOr<google::monitoring::v3::ListGroupMembersResponse>
GroupServiceTracingStub::ListGroupMembers(
    grpc::ClientContext& context,
    google::monitoring::v3::ListGroupMembersRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.monitoring.v3.GroupService",
                                     "ListGroupMembers");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListGroupMembers(context, request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<GroupServiceStub> MakeGroupServiceTracingStub(
    std::shared_ptr<GroupServiceStub> stub) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return std::make_shared<GroupServiceTracingStub>(std::move(stub));
#else
  return stub;
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_v3_internal
}  // namespace cloud
}  // namespace google
