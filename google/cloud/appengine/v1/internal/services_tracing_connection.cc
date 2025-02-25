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
// source: google/appengine/v1/appengine.proto

#include "google/cloud/appengine/v1/internal/services_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace appengine_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

ServicesTracingConnection::ServicesTracingConnection(
    std::shared_ptr<appengine_v1::ServicesConnection> child)
    : child_(std::move(child)) {}

StreamRange<google::appengine::v1::Service>
ServicesTracingConnection::ListServices(
    google::appengine::v1::ListServicesRequest request) {
  auto span =
      internal::MakeSpan("appengine_v1::ServicesConnection::ListServices");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListServices(std::move(request));
  return internal::MakeTracedStreamRange<google::appengine::v1::Service>(
      std::move(span), std::move(sr));
}

StatusOr<google::appengine::v1::Service> ServicesTracingConnection::GetService(
    google::appengine::v1::GetServiceRequest const& request) {
  auto span =
      internal::MakeSpan("appengine_v1::ServicesConnection::GetService");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetService(request));
}

future<StatusOr<google::appengine::v1::Service>>
ServicesTracingConnection::UpdateService(
    google::appengine::v1::UpdateServiceRequest const& request) {
  auto span =
      internal::MakeSpan("appengine_v1::ServicesConnection::UpdateService");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(std::move(span), child_->UpdateService(request));
}

future<StatusOr<google::appengine::v1::OperationMetadataV1>>
ServicesTracingConnection::DeleteService(
    google::appengine::v1::DeleteServiceRequest const& request) {
  auto span =
      internal::MakeSpan("appengine_v1::ServicesConnection::DeleteService");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(std::move(span), child_->DeleteService(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<appengine_v1::ServicesConnection> MakeServicesTracingConnection(
    std::shared_ptr<appengine_v1::ServicesConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<ServicesTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace appengine_v1_internal
}  // namespace cloud
}  // namespace google
