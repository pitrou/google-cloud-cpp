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
// source: google/cloud/dialogflow/cx/v3/deployment.proto

#include "google/cloud/dialogflow_cx/internal/deployments_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

DeploymentsTracingConnection::DeploymentsTracingConnection(
    std::shared_ptr<dialogflow_cx::DeploymentsConnection> child)
    : child_(std::move(child)) {}

StreamRange<google::cloud::dialogflow::cx::v3::Deployment>
DeploymentsTracingConnection::ListDeployments(
    google::cloud::dialogflow::cx::v3::ListDeploymentsRequest request) {
  auto span = internal::MakeSpan(
      "dialogflow_cx::DeploymentsConnection::ListDeployments");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListDeployments(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::dialogflow::cx::v3::Deployment>(std::move(span),
                                                     std::move(sr));
}

StatusOr<google::cloud::dialogflow::cx::v3::Deployment>
DeploymentsTracingConnection::GetDeployment(
    google::cloud::dialogflow::cx::v3::GetDeploymentRequest const& request) {
  auto span =
      internal::MakeSpan("dialogflow_cx::DeploymentsConnection::GetDeployment");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetDeployment(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<dialogflow_cx::DeploymentsConnection>
MakeDeploymentsTracingConnection(
    std::shared_ptr<dialogflow_cx::DeploymentsConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<DeploymentsTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
