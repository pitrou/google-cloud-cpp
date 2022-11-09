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
// source: google/cloud/dialogflow/v2/conversation.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATIONS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATIONS_CLIENT_H

#include "google/cloud/dialogflow_es/conversations_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for managing
/// [Conversations][google.cloud.dialogflow.v2.Conversation].
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
class ConversationsClient {
 public:
  explicit ConversationsClient(
      std::shared_ptr<ConversationsConnection> connection, Options opts = {});
  ~ConversationsClient();

  //@{
  // @name Copy and move support
  ConversationsClient(ConversationsClient const&) = default;
  ConversationsClient& operator=(ConversationsClient const&) = default;
  ConversationsClient(ConversationsClient&&) = default;
  ConversationsClient& operator=(ConversationsClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(ConversationsClient const& a,
                         ConversationsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(ConversationsClient const& a,
                         ConversationsClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Creates a new conversation. Conversations are auto-completed after 24
  /// hours.
  ///
  /// Conversation Lifecycle:
  /// There are two stages during a conversation: Automated Agent Stage and
  /// Assist Stage.
  ///
  /// For Automated Agent Stage, there will be a dialogflow agent responding to
  /// user queries.
  ///
  /// For Assist Stage, there's no dialogflow agent responding to user queries.
  /// But we will provide suggestions which are generated from conversation.
  ///
  /// If
  /// [Conversation.conversation_profile][google.cloud.dialogflow.v2.Conversation.conversation_profile]
  /// is configured for a dialogflow agent, conversation will start from
  /// `Automated Agent Stage`, otherwise, it will start from `Assist Stage`. And
  /// during `Automated Agent Stage`, once an
  /// [Intent][google.cloud.dialogflow.v2.Intent] with
  /// [Intent.live_agent_handoff][google.cloud.dialogflow.v2.Intent.live_agent_handoff]
  /// is triggered, conversation will transfer to Assist Stage.
  ///
  /// @param parent  Required. Resource identifier of the project creating the
  /// conversation.
  ///  Format: `projects/<Project ID>/locations/<Location ID>`.
  /// @param conversation  Required. The conversation to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.CreateConversationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L209}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StatusOr<google::cloud::dialogflow::v2::Conversation> CreateConversation(
      std::string const& parent,
      google::cloud::dialogflow::v2::Conversation const& conversation,
      Options opts = {});

  ///
  /// Creates a new conversation. Conversations are auto-completed after 24
  /// hours.
  ///
  /// Conversation Lifecycle:
  /// There are two stages during a conversation: Automated Agent Stage and
  /// Assist Stage.
  ///
  /// For Automated Agent Stage, there will be a dialogflow agent responding to
  /// user queries.
  ///
  /// For Assist Stage, there's no dialogflow agent responding to user queries.
  /// But we will provide suggestions which are generated from conversation.
  ///
  /// If
  /// [Conversation.conversation_profile][google.cloud.dialogflow.v2.Conversation.conversation_profile]
  /// is configured for a dialogflow agent, conversation will start from
  /// `Automated Agent Stage`, otherwise, it will start from `Assist Stage`. And
  /// during `Automated Agent Stage`, once an
  /// [Intent][google.cloud.dialogflow.v2.Intent] with
  /// [Intent.live_agent_handoff][google.cloud.dialogflow.v2.Intent.live_agent_handoff]
  /// is triggered, conversation will transfer to Assist Stage.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::CreateConversationRequest,google/cloud/dialogflow/v2/conversation.proto#L209}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.CreateConversationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L209}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StatusOr<google::cloud::dialogflow::v2::Conversation> CreateConversation(
      google::cloud::dialogflow::v2::CreateConversationRequest const& request,
      Options opts = {});

  ///
  /// Returns the list of all conversations in the specified project.
  ///
  /// @param parent  Required. The project from which to list all conversation.
  ///  Format: `projects/<Project ID>/locations/<Location ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.ListConversationsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L236}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StreamRange<google::cloud::dialogflow::v2::Conversation> ListConversations(
      std::string const& parent, Options opts = {});

  ///
  /// Returns the list of all conversations in the specified project.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::ListConversationsRequest,google/cloud/dialogflow/v2/conversation.proto#L236}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.ListConversationsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L236}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StreamRange<google::cloud::dialogflow::v2::Conversation> ListConversations(
      google::cloud::dialogflow::v2::ListConversationsRequest request,
      Options opts = {});

  ///
  /// Retrieves the specific conversation.
  ///
  /// @param name  Required. The name of the conversation. Format:
  ///  `projects/<Project ID>/locations/<Location
  ///  ID>/conversations/<Conversation ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.GetConversationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L285}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StatusOr<google::cloud::dialogflow::v2::Conversation> GetConversation(
      std::string const& name, Options opts = {});

  ///
  /// Retrieves the specific conversation.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::GetConversationRequest,google/cloud/dialogflow/v2/conversation.proto#L285}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.GetConversationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L285}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StatusOr<google::cloud::dialogflow::v2::Conversation> GetConversation(
      google::cloud::dialogflow::v2::GetConversationRequest const& request,
      Options opts = {});

  ///
  /// Completes the specified conversation. Finished conversations are purged
  /// from the database after 30 days.
  ///
  /// @param name  Required. Resource identifier of the conversation to close.
  ///  Format: `projects/<Project ID>/locations/<Location
  ///  ID>/conversations/<Conversation ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.CompleteConversationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L298}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StatusOr<google::cloud::dialogflow::v2::Conversation> CompleteConversation(
      std::string const& name, Options opts = {});

  ///
  /// Completes the specified conversation. Finished conversations are purged
  /// from the database after 30 days.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::CompleteConversationRequest,google/cloud/dialogflow/v2/conversation.proto#L298}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Conversation,google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  /// [google.cloud.dialogflow.v2.CompleteConversationRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L298}
  /// [google.cloud.dialogflow.v2.Conversation]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L127}
  ///
  StatusOr<google::cloud::dialogflow::v2::Conversation> CompleteConversation(
      google::cloud::dialogflow::v2::CompleteConversationRequest const& request,
      Options opts = {});

  ///
  /// Lists messages that belong to a given conversation.
  /// `messages` are ordered by `create_time` in descending order. To fetch
  /// updates without duplication, send request with filter
  /// `create_time_epoch_microseconds >
  /// [first item's create_time of previous request]` and empty page_token.
  ///
  /// @param parent  Required. The name of the conversation to list messages
  /// for.
  ///  Format: `projects/<Project ID>/locations/<Location
  ///  ID>/conversations/<Conversation ID>`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Message,google/cloud/dialogflow/v2/participant.proto#L261}
  ///
  /// [google.cloud.dialogflow.v2.ListMessagesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L311}
  /// [google.cloud.dialogflow.v2.Message]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/participant.proto#L261}
  ///
  StreamRange<google::cloud::dialogflow::v2::Message> ListMessages(
      std::string const& parent, Options opts = {});

  ///
  /// Lists messages that belong to a given conversation.
  /// `messages` are ordered by `create_time` in descending order. To fetch
  /// updates without duplication, send request with filter
  /// `create_time_epoch_microseconds >
  /// [first item's create_time of previous request]` and empty page_token.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::v2::ListMessagesRequest,google/cloud/dialogflow/v2/conversation.proto#L311}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::v2::Message,google/cloud/dialogflow/v2/participant.proto#L261}
  ///
  /// [google.cloud.dialogflow.v2.ListMessagesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/conversation.proto#L311}
  /// [google.cloud.dialogflow.v2.Message]:
  /// @googleapis_reference_link{google/cloud/dialogflow/v2/participant.proto#L261}
  ///
  StreamRange<google::cloud::dialogflow::v2::Message> ListMessages(
      google::cloud::dialogflow::v2::ListMessagesRequest request,
      Options opts = {});

 private:
  std::shared_ptr<ConversationsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATIONS_CLIENT_H
