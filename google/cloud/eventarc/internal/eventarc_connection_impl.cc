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
// source: google/cloud/eventarc/v1/eventarc.proto

#include "google/cloud/eventarc/internal/eventarc_connection_impl.h"
#include "google/cloud/eventarc/internal/eventarc_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace eventarc_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EventarcConnectionImpl::EventarcConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<eventarc_internal::EventarcStub> stub, Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      EventarcConnection::options())) {}

StatusOr<google::cloud::eventarc::v1::Trigger>
EventarcConnectionImpl::GetTrigger(
    google::cloud::eventarc::v1::GetTriggerRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetTrigger(request),
      [this](grpc::ClientContext& context,
             google::cloud::eventarc::v1::GetTriggerRequest const& request) {
        return stub_->GetTrigger(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::eventarc::v1::Trigger>
EventarcConnectionImpl::ListTriggers(
    google::cloud::eventarc::v1::ListTriggersRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<eventarc::EventarcRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListTriggers(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::eventarc::v1::Trigger>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::eventarc::v1::ListTriggersRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::eventarc::v1::ListTriggersRequest const&
                       request) {
              return stub->ListTriggers(context, request);
            },
            r, function_name);
      },
      [](google::cloud::eventarc::v1::ListTriggersResponse r) {
        std::vector<google::cloud::eventarc::v1::Trigger> result(
            r.triggers().size());
        auto& messages = *r.mutable_triggers();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcConnectionImpl::CreateTrigger(
    google::cloud::eventarc::v1::CreateTriggerRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::Trigger>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::CreateTriggerRequest const& request) {
        return stub->AsyncCreateTrigger(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::Trigger>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateTrigger(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcConnectionImpl::UpdateTrigger(
    google::cloud::eventarc::v1::UpdateTriggerRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::Trigger>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::UpdateTriggerRequest const& request) {
        return stub->AsyncUpdateTrigger(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::Trigger>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateTrigger(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::eventarc::v1::Trigger>>
EventarcConnectionImpl::DeleteTrigger(
    google::cloud::eventarc::v1::DeleteTriggerRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::Trigger>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::DeleteTriggerRequest const& request) {
        return stub->AsyncDeleteTrigger(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::Trigger>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteTrigger(request), polling_policy(), __func__);
}

StatusOr<google::cloud::eventarc::v1::Channel>
EventarcConnectionImpl::GetChannel(
    google::cloud::eventarc::v1::GetChannelRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetChannel(request),
      [this](grpc::ClientContext& context,
             google::cloud::eventarc::v1::GetChannelRequest const& request) {
        return stub_->GetChannel(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::eventarc::v1::Channel>
EventarcConnectionImpl::ListChannels(
    google::cloud::eventarc::v1::ListChannelsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<eventarc::EventarcRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListChannels(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::eventarc::v1::Channel>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::eventarc::v1::ListChannelsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::eventarc::v1::ListChannelsRequest const&
                       request) {
              return stub->ListChannels(context, request);
            },
            r, function_name);
      },
      [](google::cloud::eventarc::v1::ListChannelsResponse r) {
        std::vector<google::cloud::eventarc::v1::Channel> result(
            r.channels().size());
        auto& messages = *r.mutable_channels();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

future<StatusOr<google::cloud::eventarc::v1::Channel>>
EventarcConnectionImpl::CreateChannel(
    google::cloud::eventarc::v1::CreateChannelRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::Channel>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::CreateChannelRequest const& request) {
        return stub->AsyncCreateChannel(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::Channel>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateChannel(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::eventarc::v1::Channel>>
EventarcConnectionImpl::UpdateChannel(
    google::cloud::eventarc::v1::UpdateChannelRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::Channel>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::UpdateChannelRequest const& request) {
        return stub->AsyncUpdateChannel(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::Channel>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateChannel(request), polling_policy(), __func__);
}

future<StatusOr<google::cloud::eventarc::v1::Channel>>
EventarcConnectionImpl::DeleteChannel(
    google::cloud::eventarc::v1::DeleteChannelRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::Channel>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::DeleteChannelRequest const& request) {
        return stub->AsyncDeleteChannel(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::Channel>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteChannel(request), polling_policy(), __func__);
}

StatusOr<google::cloud::eventarc::v1::Provider>
EventarcConnectionImpl::GetProvider(
    google::cloud::eventarc::v1::GetProviderRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetProvider(request),
      [this](grpc::ClientContext& context,
             google::cloud::eventarc::v1::GetProviderRequest const& request) {
        return stub_->GetProvider(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::eventarc::v1::Provider>
EventarcConnectionImpl::ListProviders(
    google::cloud::eventarc::v1::ListProvidersRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<eventarc::EventarcRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListProviders(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::eventarc::v1::Provider>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::eventarc::v1::ListProvidersRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::eventarc::v1::ListProvidersRequest const&
                       request) {
              return stub->ListProviders(context, request);
            },
            r, function_name);
      },
      [](google::cloud::eventarc::v1::ListProvidersResponse r) {
        std::vector<google::cloud::eventarc::v1::Provider> result(
            r.providers().size());
        auto& messages = *r.mutable_providers();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::eventarc::v1::ChannelConnection>
EventarcConnectionImpl::GetChannelConnection(
    google::cloud::eventarc::v1::GetChannelConnectionRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetChannelConnection(request),
      [this](grpc::ClientContext& context,
             google::cloud::eventarc::v1::GetChannelConnectionRequest const&
                 request) {
        return stub_->GetChannelConnection(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::eventarc::v1::ChannelConnection>
EventarcConnectionImpl::ListChannelConnections(
    google::cloud::eventarc::v1::ListChannelConnectionsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<eventarc::EventarcRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListChannelConnections(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::eventarc::v1::ChannelConnection>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::eventarc::v1::ListChannelConnectionsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::eventarc::v1::
                       ListChannelConnectionsRequest const& request) {
              return stub->ListChannelConnections(context, request);
            },
            r, function_name);
      },
      [](google::cloud::eventarc::v1::ListChannelConnectionsResponse r) {
        std::vector<google::cloud::eventarc::v1::ChannelConnection> result(
            r.channel_connections().size());
        auto& messages = *r.mutable_channel_connections();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

future<StatusOr<google::cloud::eventarc::v1::ChannelConnection>>
EventarcConnectionImpl::CreateChannelConnection(
    google::cloud::eventarc::v1::CreateChannelConnectionRequest const&
        request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::ChannelConnection>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::CreateChannelConnectionRequest const&
                 request) {
        return stub->AsyncCreateChannelConnection(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::ChannelConnection>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateChannelConnection(request), polling_policy(),
      __func__);
}

future<StatusOr<google::cloud::eventarc::v1::ChannelConnection>>
EventarcConnectionImpl::DeleteChannelConnection(
    google::cloud::eventarc::v1::DeleteChannelConnectionRequest const&
        request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::eventarc::v1::ChannelConnection>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::eventarc::v1::DeleteChannelConnectionRequest const&
                 request) {
        return stub->AsyncDeleteChannelConnection(cq, std::move(context),
                                                  request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::eventarc::v1::ChannelConnection>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteChannelConnection(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::eventarc::v1::GoogleChannelConfig>
EventarcConnectionImpl::GetGoogleChannelConfig(
    google::cloud::eventarc::v1::GetGoogleChannelConfigRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetGoogleChannelConfig(request),
      [this](grpc::ClientContext& context,
             google::cloud::eventarc::v1::GetGoogleChannelConfigRequest const&
                 request) {
        return stub_->GetGoogleChannelConfig(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::eventarc::v1::GoogleChannelConfig>
EventarcConnectionImpl::UpdateGoogleChannelConfig(
    google::cloud::eventarc::v1::UpdateGoogleChannelConfigRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateGoogleChannelConfig(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::eventarc::v1::UpdateGoogleChannelConfigRequest const&
              request) {
        return stub_->UpdateGoogleChannelConfig(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace eventarc_internal
}  // namespace cloud
}  // namespace google
