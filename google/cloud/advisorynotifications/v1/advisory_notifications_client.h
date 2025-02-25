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
// source: google/cloud/advisorynotifications/v1/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ADVISORYNOTIFICATIONS_V1_ADVISORY_NOTIFICATIONS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ADVISORYNOTIFICATIONS_V1_ADVISORY_NOTIFICATIONS_CLIENT_H

#include "google/cloud/advisorynotifications/v1/advisory_notifications_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace advisorynotifications_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service to manage Security and Privacy Notifications.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class AdvisoryNotificationsServiceClient {
 public:
  explicit AdvisoryNotificationsServiceClient(
      std::shared_ptr<AdvisoryNotificationsServiceConnection> connection,
      Options opts = {});
  ~AdvisoryNotificationsServiceClient();

  ///@{
  /// @name Copy and move support
  AdvisoryNotificationsServiceClient(
      AdvisoryNotificationsServiceClient const&) = default;
  AdvisoryNotificationsServiceClient& operator=(
      AdvisoryNotificationsServiceClient const&) = default;
  AdvisoryNotificationsServiceClient(AdvisoryNotificationsServiceClient&&) =
      default;
  AdvisoryNotificationsServiceClient& operator=(
      AdvisoryNotificationsServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(AdvisoryNotificationsServiceClient const& a,
                         AdvisoryNotificationsServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(AdvisoryNotificationsServiceClient const& a,
                         AdvisoryNotificationsServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  ///
  /// Lists notifications under a given parent.
  ///
  /// @param parent  Required. The parent, which owns this collection of
  /// notifications.
  ///  Must be of the form "organizations/{organization}/locations/{location}".
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::advisorynotifications::v1::Notification,google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  /// [google.cloud.advisorynotifications.v1.ListNotificationsRequest]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L204}
  /// [google.cloud.advisorynotifications.v1.Notification]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  StreamRange<google::cloud::advisorynotifications::v1::Notification>
  ListNotifications(std::string const& parent, Options opts = {});

  ///
  /// Lists notifications under a given parent.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::advisorynotifications::v1::ListNotificationsRequest,google/cloud/advisorynotifications/v1/service.proto#L204}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::advisorynotifications::v1::Notification,google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  /// [google.cloud.advisorynotifications.v1.ListNotificationsRequest]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L204}
  /// [google.cloud.advisorynotifications.v1.Notification]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  StreamRange<google::cloud::advisorynotifications::v1::Notification>
  ListNotifications(
      google::cloud::advisorynotifications::v1::ListNotificationsRequest
          request,
      Options opts = {});

  ///
  /// Gets a notification.
  ///
  /// @param name  Required. A name of the notification to retrieve.
  ///  Format:
  ///  organizations/{organization}/locations/{location}/notifications/{notification}.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::advisorynotifications::v1::Notification,google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  /// [google.cloud.advisorynotifications.v1.GetNotificationRequest]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L251}
  /// [google.cloud.advisorynotifications.v1.Notification]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  StatusOr<google::cloud::advisorynotifications::v1::Notification>
  GetNotification(std::string const& name, Options opts = {});

  ///
  /// Gets a notification.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::advisorynotifications::v1::GetNotificationRequest,google/cloud/advisorynotifications/v1/service.proto#L251}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::advisorynotifications::v1::Notification,google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  /// [google.cloud.advisorynotifications.v1.GetNotificationRequest]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L251}
  /// [google.cloud.advisorynotifications.v1.Notification]:
  /// @googleapis_reference_link{google/cloud/advisorynotifications/v1/service.proto#L109}
  ///
  StatusOr<google::cloud::advisorynotifications::v1::Notification>
  GetNotification(
      google::cloud::advisorynotifications::v1::GetNotificationRequest const&
          request,
      Options opts = {});

 private:
  std::shared_ptr<AdvisoryNotificationsServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace advisorynotifications_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ADVISORYNOTIFICATIONS_V1_ADVISORY_NOTIFICATIONS_CLIENT_H
