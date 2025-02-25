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
// source: google/cloud/datastream/v1/datastream.proto

#include "google/cloud/datastream/v1/internal/datastream_tracing_stub.h"
#include "google/cloud/internal/grpc_opentelemetry.h"

namespace google {
namespace cloud {
namespace datastream_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

DatastreamTracingStub::DatastreamTracingStub(
    std::shared_ptr<DatastreamStub> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::datastream::v1::ListConnectionProfilesResponse>
DatastreamTracingStub::ListConnectionProfiles(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::ListConnectionProfilesRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "ListConnectionProfiles");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListConnectionProfiles(context, request));
}

StatusOr<google::cloud::datastream::v1::ConnectionProfile>
DatastreamTracingStub::GetConnectionProfile(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::GetConnectionProfileRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "GetConnectionProfile");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->GetConnectionProfile(context, request));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncCreateConnectionProfile(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::CreateConnectionProfileRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "CreateConnectionProfile");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncCreateConnectionProfile(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncUpdateConnectionProfile(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::UpdateConnectionProfileRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "UpdateConnectionProfile");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncUpdateConnectionProfile(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncDeleteConnectionProfile(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::DeleteConnectionProfileRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "DeleteConnectionProfile");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncDeleteConnectionProfile(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::datastream::v1::DiscoverConnectionProfileResponse>
DatastreamTracingStub::DiscoverConnectionProfile(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::DiscoverConnectionProfileRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "DiscoverConnectionProfile");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->DiscoverConnectionProfile(context, request));
}

StatusOr<google::cloud::datastream::v1::ListStreamsResponse>
DatastreamTracingStub::ListStreams(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::ListStreamsRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "ListStreams");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListStreams(context, request));
}

StatusOr<google::cloud::datastream::v1::Stream>
DatastreamTracingStub::GetStream(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::GetStreamRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "GetStream");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span, child_->GetStream(context, request));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncCreateStream(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::CreateStreamRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "CreateStream");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncCreateStream(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncUpdateStream(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::UpdateStreamRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "UpdateStream");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncUpdateStream(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncDeleteStream(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::DeleteStreamRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "DeleteStream");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncDeleteStream(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::datastream::v1::StreamObject>
DatastreamTracingStub::GetStreamObject(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::GetStreamObjectRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "GetStreamObject");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->GetStreamObject(context, request));
}

StatusOr<google::cloud::datastream::v1::StreamObject>
DatastreamTracingStub::LookupStreamObject(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::LookupStreamObjectRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "LookupStreamObject");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->LookupStreamObject(context, request));
}

StatusOr<google::cloud::datastream::v1::ListStreamObjectsResponse>
DatastreamTracingStub::ListStreamObjects(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::ListStreamObjectsRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "ListStreamObjects");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListStreamObjects(context, request));
}

StatusOr<google::cloud::datastream::v1::StartBackfillJobResponse>
DatastreamTracingStub::StartBackfillJob(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::StartBackfillJobRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "StartBackfillJob");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->StartBackfillJob(context, request));
}

StatusOr<google::cloud::datastream::v1::StopBackfillJobResponse>
DatastreamTracingStub::StopBackfillJob(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::StopBackfillJobRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "StopBackfillJob");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->StopBackfillJob(context, request));
}

StatusOr<google::cloud::datastream::v1::FetchStaticIpsResponse>
DatastreamTracingStub::FetchStaticIps(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::FetchStaticIpsRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "FetchStaticIps");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->FetchStaticIps(context, request));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncCreatePrivateConnection(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::CreatePrivateConnectionRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "CreatePrivateConnection");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncCreatePrivateConnection(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::datastream::v1::PrivateConnection>
DatastreamTracingStub::GetPrivateConnection(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::GetPrivateConnectionRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "GetPrivateConnection");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->GetPrivateConnection(context, request));
}

StatusOr<google::cloud::datastream::v1::ListPrivateConnectionsResponse>
DatastreamTracingStub::ListPrivateConnections(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::ListPrivateConnectionsRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "ListPrivateConnections");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListPrivateConnections(context, request));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncDeletePrivateConnection(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::DeletePrivateConnectionRequest const&
        request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "DeletePrivateConnection");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncDeletePrivateConnection(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncCreateRoute(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::CreateRouteRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "CreateRoute");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncCreateRoute(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

StatusOr<google::cloud::datastream::v1::Route> DatastreamTracingStub::GetRoute(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::GetRouteRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "GetRoute");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span, child_->GetRoute(context, request));
}

StatusOr<google::cloud::datastream::v1::ListRoutesResponse>
DatastreamTracingStub::ListRoutes(
    grpc::ClientContext& context,
    google::cloud::datastream::v1::ListRoutesRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "ListRoutes");
  auto scope = opentelemetry::trace::Scope(span);
  internal::InjectTraceContext(context, internal::CurrentOptions());
  return internal::EndSpan(context, *span,
                           child_->ListRoutes(context, request));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncDeleteRoute(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datastream::v1::DeleteRouteRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.cloud.datastream.v1.Datastream",
                                     "DeleteRoute");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncDeleteRoute(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<StatusOr<google::longrunning::Operation>>
DatastreamTracingStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  auto span =
      internal::MakeSpanGrpc("google.longrunning.Operations", "GetOperation");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncGetOperation(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

future<Status> DatastreamTracingStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto span = internal::MakeSpanGrpc("google.longrunning.Operations",
                                     "CancelOperation");
  {
    auto scope = opentelemetry::trace::Scope(span);
    internal::InjectTraceContext(*context, internal::CurrentOptions());
  }
  auto f = child_->AsyncCancelOperation(cq, context, request);
  return internal::EndSpan(std::move(context), std::move(span), std::move(f));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<DatastreamStub> MakeDatastreamTracingStub(
    std::shared_ptr<DatastreamStub> stub) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return std::make_shared<DatastreamTracingStub>(std::move(stub));
#else
  return stub;
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datastream_v1_internal
}  // namespace cloud
}  // namespace google
