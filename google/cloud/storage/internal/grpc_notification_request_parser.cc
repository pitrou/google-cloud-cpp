// Copyright 2022 Google LLC
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

#include "google/cloud/storage/internal/grpc_notification_request_parser.h"
#include "google/cloud/storage/internal/grpc_bucket_name.h"
#include "google/cloud/storage/internal/grpc_notification_metadata_parser.h"

namespace google {
namespace cloud {
namespace storage_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

google::storage::v2::DeleteNotificationConfigRequest ToProto(
    storage::internal::DeleteNotificationRequest const& rhs) {
  google::storage::v2::DeleteNotificationConfigRequest request;
  request.set_name(GrpcBucketIdToName(rhs.bucket_name()) +
                   "/notificationConfigs/" + rhs.notification_id());
  return request;
}

google::storage::v2::GetNotificationConfigRequest ToProto(
    storage::internal::GetNotificationRequest const& rhs) {
  google::storage::v2::GetNotificationConfigRequest request;
  request.set_name(GrpcBucketIdToName(rhs.bucket_name()) +
                   "/notificationConfigs/" + rhs.notification_id());
  return request;
}

google::storage::v2::CreateNotificationConfigRequest ToProto(
    storage::internal::CreateNotificationRequest const& rhs) {
  google::storage::v2::CreateNotificationConfigRequest request;
  request.set_parent(GrpcBucketIdToName(rhs.bucket_name()));
  *request.mutable_notification_config() =
      storage_internal::ToProto(rhs.metadata());
  return request;
}

google::storage::v2::ListNotificationConfigsRequest ToProto(
    storage::internal::ListNotificationsRequest const& rhs) {
  google::storage::v2::ListNotificationConfigsRequest request;
  request.set_parent(GrpcBucketIdToName(rhs.bucket_name()));
  return request;
}

storage::internal::ListNotificationsResponse FromProto(
    google::storage::v2::ListNotificationConfigsResponse const& rhs) {
  storage::internal::ListNotificationsResponse response;
  for (auto const& i : rhs.notification_configs()) {
    response.items.push_back(storage_internal::FromProto(i));
  }
  return response;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage_internal
}  // namespace cloud
}  // namespace google
