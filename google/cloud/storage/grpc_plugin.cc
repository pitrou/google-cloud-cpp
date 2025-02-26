// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/storage/grpc_plugin.h"
#include "google/cloud/storage/internal/grpc_client.h"
#include "google/cloud/storage/internal/hybrid_client.h"
#include "google/cloud/internal/getenv.h"

namespace google {
namespace cloud {
namespace storage_experimental {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

google::cloud::storage::Client DefaultGrpcClient(Options opts) {
  using ::google::cloud::internal::GetEnv;
  auto const config = GetEnv("GOOGLE_CLOUD_CPP_STORAGE_GRPC_CONFIG")
                          .value_or(opts.get<GrpcPluginOption>());
  if (config == "none" || config.empty()) {
    return google::cloud::storage::Client(std::move(opts));
  }
  if (config == "metadata") {
    opts = google::cloud::storage_internal::DefaultOptionsGrpc(std::move(opts));
    return storage::internal::ClientImplDetails::CreateClient(
        storage_internal::GrpcClient::Create(opts));
  }
  return storage::internal::ClientImplDetails::CreateClient(
      storage_internal::HybridClient::Create(opts));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage_experimental
}  // namespace cloud
}  // namespace google
