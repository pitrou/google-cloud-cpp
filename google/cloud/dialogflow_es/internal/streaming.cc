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

#include "google/cloud/dialogflow_es/internal/participants_connection_impl.h"
#include "google/cloud/dialogflow_es/internal/sessions_connection_impl.h"

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::cloud::dialogflow::v2::StreamingDetectIntentRequest,
    google::cloud::dialogflow::v2::StreamingDetectIntentResponse>>
SessionsConnectionImpl::AsyncStreamingDetectIntent() {
  return stub_->AsyncStreamingDetectIntent(
      background_->cq(), std::make_shared<grpc::ClientContext>());
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::cloud::dialogflow::v2::StreamingAnalyzeContentRequest,
    google::cloud::dialogflow::v2::StreamingAnalyzeContentResponse>>
ParticipantsConnectionImpl::AsyncStreamingAnalyzeContent() {
  return stub_->AsyncStreamingAnalyzeContent(
      background_->cq(), std::make_shared<grpc::ClientContext>());
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google
