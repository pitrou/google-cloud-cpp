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
// source: google/cloud/networkconnectivity/v1/hub.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_HUB_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_HUB_CLIENT_H

#include "google/cloud/networkconnectivity/hub_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace networkconnectivity {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Network Connectivity Center is a hub-and-spoke abstraction for network
/// connectivity management in Google Cloud. It reduces operational complexity
/// through a simple, centralized connectivity management model.
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
class HubServiceClient {
 public:
  explicit HubServiceClient(std::shared_ptr<HubServiceConnection> connection,
                            Options opts = {});
  ~HubServiceClient();

  //@{
  // @name Copy and move support
  HubServiceClient(HubServiceClient const&) = default;
  HubServiceClient& operator=(HubServiceClient const&) = default;
  HubServiceClient(HubServiceClient&&) = default;
  HubServiceClient& operator=(HubServiceClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(HubServiceClient const& a, HubServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(HubServiceClient const& a, HubServiceClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Lists the Network Connectivity Center hubs associated with a given
  /// project.
  ///
  /// @param parent  Required. The parent resource's name.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.ListHubsRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L322}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  StreamRange<google::cloud::networkconnectivity::v1::Hub> ListHubs(
      std::string const& parent, Options opts = {});

  ///
  /// Lists the Network Connectivity Center hubs associated with a given
  /// project.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::ListHubsRequest,google/cloud/networkconnectivity/v1/hub.proto#L322}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.ListHubsRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L322}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  StreamRange<google::cloud::networkconnectivity::v1::Hub> ListHubs(
      google::cloud::networkconnectivity::v1::ListHubsRequest request,
      Options opts = {});

  ///
  /// Gets details about a Network Connectivity Center hub.
  ///
  /// @param name  Required. The name of the hub resource to get.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.GetHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L362}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  StatusOr<google::cloud::networkconnectivity::v1::Hub> GetHub(
      std::string const& name, Options opts = {});

  ///
  /// Gets details about a Network Connectivity Center hub.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::GetHubRequest,google/cloud/networkconnectivity/v1/hub.proto#L362}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.GetHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L362}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  StatusOr<google::cloud::networkconnectivity::v1::Hub> GetHub(
      google::cloud::networkconnectivity::v1::GetHubRequest const& request,
      Options opts = {});

  ///
  /// Creates a new Network Connectivity Center hub in the specified project.
  ///
  /// @param parent  Required. The parent resource.
  /// @param hub  Required. The initial values for a new hub.
  /// @param hub_id  Required. A unique identifier for the hub.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.CreateHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L375}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Hub>> CreateHub(
      std::string const& parent,
      google::cloud::networkconnectivity::v1::Hub const& hub,
      std::string const& hub_id, Options opts = {});

  ///
  /// Creates a new Network Connectivity Center hub in the specified project.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::CreateHubRequest,google/cloud/networkconnectivity/v1/hub.proto#L375}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.CreateHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L375}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Hub>> CreateHub(
      google::cloud::networkconnectivity::v1::CreateHubRequest const& request,
      Options opts = {});

  ///
  /// Updates the description and/or labels of a Network Connectivity Center
  /// hub.
  ///
  /// @param hub  Required. The state that the hub should be in after the
  /// update.
  /// @param update_mask  Optional. In the case of an update to an existing hub,
  /// field mask is used
  ///  to specify the fields to be overwritten. The fields specified in the
  ///  update_mask are relative to the resource, not the full request. A field
  ///  is overwritten if it is in the mask. If the user does not provide a mask,
  ///  then all fields are overwritten.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.UpdateHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L410}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Hub>> UpdateHub(
      google::cloud::networkconnectivity::v1::Hub const& hub,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Updates the description and/or labels of a Network Connectivity Center
  /// hub.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::UpdateHubRequest,google/cloud/networkconnectivity/v1/hub.proto#L410}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Hub,google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  /// [google.cloud.networkconnectivity.v1.UpdateHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L410}
  /// [google.cloud.networkconnectivity.v1.Hub]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L198}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Hub>> UpdateHub(
      google::cloud::networkconnectivity::v1::UpdateHubRequest const& request,
      Options opts = {});

  ///
  /// Deletes a Network Connectivity Center hub.
  ///
  /// @param name  Required. The name of the hub to delete.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::OperationMetadata,google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  /// [google.cloud.networkconnectivity.v1.DeleteHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L441}
  /// [google.cloud.networkconnectivity.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::OperationMetadata>>
  DeleteHub(std::string const& name, Options opts = {});

  ///
  /// Deletes a Network Connectivity Center hub.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::DeleteHubRequest,google/cloud/networkconnectivity/v1/hub.proto#L441}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::OperationMetadata,google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  /// [google.cloud.networkconnectivity.v1.DeleteHubRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L441}
  /// [google.cloud.networkconnectivity.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::OperationMetadata>>
  DeleteHub(
      google::cloud::networkconnectivity::v1::DeleteHubRequest const& request,
      Options opts = {});

  ///
  /// Lists the Network Connectivity Center spokes in a specified project and
  /// location.
  ///
  /// @param parent  Required. The parent resource.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.ListSpokesRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L469}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  StreamRange<google::cloud::networkconnectivity::v1::Spoke> ListSpokes(
      std::string const& parent, Options opts = {});

  ///
  /// Lists the Network Connectivity Center spokes in a specified project and
  /// location.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::ListSpokesRequest,google/cloud/networkconnectivity/v1/hub.proto#L469}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.ListSpokesRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L469}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  StreamRange<google::cloud::networkconnectivity::v1::Spoke> ListSpokes(
      google::cloud::networkconnectivity::v1::ListSpokesRequest request,
      Options opts = {});

  ///
  /// Gets details about a Network Connectivity Center spoke.
  ///
  /// @param name  Required. The name of the spoke resource.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.GetSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L507}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  StatusOr<google::cloud::networkconnectivity::v1::Spoke> GetSpoke(
      std::string const& name, Options opts = {});

  ///
  /// Gets details about a Network Connectivity Center spoke.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::GetSpokeRequest,google/cloud/networkconnectivity/v1/hub.proto#L507}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.GetSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L507}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  StatusOr<google::cloud::networkconnectivity::v1::Spoke> GetSpoke(
      google::cloud::networkconnectivity::v1::GetSpokeRequest const& request,
      Options opts = {});

  ///
  /// Creates a Network Connectivity Center spoke.
  ///
  /// @param parent  Required. The parent resource.
  /// @param spoke  Required. The initial values for a new spoke.
  /// @param spoke_id  Required. Unique id for the spoke to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.CreateSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L519}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Spoke>> CreateSpoke(
      std::string const& parent,
      google::cloud::networkconnectivity::v1::Spoke const& spoke,
      std::string const& spoke_id, Options opts = {});

  ///
  /// Creates a Network Connectivity Center spoke.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::CreateSpokeRequest,google/cloud/networkconnectivity/v1/hub.proto#L519}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.CreateSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L519}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Spoke>> CreateSpoke(
      google::cloud::networkconnectivity::v1::CreateSpokeRequest const& request,
      Options opts = {});

  ///
  /// Updates the parameters of a Network Connectivity Center spoke.
  ///
  /// @param spoke  Required. The state that the spoke should be in after the
  /// update.
  /// @param update_mask  Optional. In the case of an update to an existing
  /// spoke, field mask is used
  ///  to specify the fields to be overwritten. The fields specified in the
  ///  update_mask are relative to the resource, not the full request. A field
  ///  is overwritten if it is in the mask. If the user does not provide a mask,
  ///  then all fields are overwritten.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.UpdateSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L554}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Spoke>> UpdateSpoke(
      google::cloud::networkconnectivity::v1::Spoke const& spoke,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Updates the parameters of a Network Connectivity Center spoke.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::UpdateSpokeRequest,google/cloud/networkconnectivity/v1/hub.proto#L554}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::Spoke,google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  /// [google.cloud.networkconnectivity.v1.UpdateSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L554}
  /// [google.cloud.networkconnectivity.v1.Spoke]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L266}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::Spoke>> UpdateSpoke(
      google::cloud::networkconnectivity::v1::UpdateSpokeRequest const& request,
      Options opts = {});

  ///
  /// Deletes a Network Connectivity Center spoke.
  ///
  /// @param name  Required. The name of the spoke to delete.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::OperationMetadata,google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  /// [google.cloud.networkconnectivity.v1.DeleteSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L585}
  /// [google.cloud.networkconnectivity.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::OperationMetadata>>
  DeleteSpoke(std::string const& name, Options opts = {});

  ///
  /// Deletes a Network Connectivity Center spoke.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::networkconnectivity::v1::DeleteSpokeRequest,google/cloud/networkconnectivity/v1/hub.proto#L585}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::networkconnectivity::v1::OperationMetadata,google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  /// [google.cloud.networkconnectivity.v1.DeleteSpokeRequest]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/hub.proto#L585}
  /// [google.cloud.networkconnectivity.v1.OperationMetadata]:
  /// @googleapis_reference_link{google/cloud/networkconnectivity/v1/common.proto#L40}
  ///
  future<StatusOr<google::cloud::networkconnectivity::v1::OperationMetadata>>
  DeleteSpoke(
      google::cloud::networkconnectivity::v1::DeleteSpokeRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<HubServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace networkconnectivity
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_HUB_CLIENT_H
