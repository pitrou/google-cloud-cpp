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
// source: google/cloud/documentai/v1/document_processor_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DOCUMENTAI_DOCUMENT_PROCESSOR_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DOCUMENTAI_DOCUMENT_PROCESSOR_CLIENT_H

#include "google/cloud/documentai/document_processor_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace documentai {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service to call Cloud DocumentAI to process documents according to the
/// processor's definition. Processors are built using state-of-the-art Google
/// AI such as natural language, computer vision, and translation to extract
/// structured information from unstructured or semi-structured documents.
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
class DocumentProcessorServiceClient {
 public:
  explicit DocumentProcessorServiceClient(
      std::shared_ptr<DocumentProcessorServiceConnection> connection,
      Options opts = {});
  ~DocumentProcessorServiceClient();

  //@{
  // @name Copy and move support
  DocumentProcessorServiceClient(DocumentProcessorServiceClient const&) =
      default;
  DocumentProcessorServiceClient& operator=(
      DocumentProcessorServiceClient const&) = default;
  DocumentProcessorServiceClient(DocumentProcessorServiceClient&&) = default;
  DocumentProcessorServiceClient& operator=(DocumentProcessorServiceClient&&) =
      default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(DocumentProcessorServiceClient const& a,
                         DocumentProcessorServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(DocumentProcessorServiceClient const& a,
                         DocumentProcessorServiceClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Processes a single document.
  ///
  /// @param name  Required. The resource name of the
  /// [Processor][google.cloud.documentai.v1.Processor] or
  ///  [ProcessorVersion][google.cloud.documentai.v1.ProcessorVersion]
  ///  to use for processing. If a
  ///  [Processor][google.cloud.documentai.v1.Processor] is specified, the
  ///  server will use its [default
  ///  version][google.cloud.documentai.v1.Processor.default_processor_version].
  ///  Format: `projects/{project}/locations/{location}/processors/{processor}`,
  ///  or
  ///  `projects/{project}/locations/{location}/processors/{processor}/processorVersions/{processorVersion}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessResponse,google/cloud/documentai/v1/document_processor_service.proto#L324}
  ///
  /// [google.cloud.documentai.v1.ProcessRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L254}
  /// [google.cloud.documentai.v1.ProcessResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L324}
  ///
  StatusOr<google::cloud::documentai::v1::ProcessResponse> ProcessDocument(
      std::string const& name, Options opts = {});

  ///
  /// Processes a single document.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::ProcessRequest,google/cloud/documentai/v1/document_processor_service.proto#L254}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessResponse,google/cloud/documentai/v1/document_processor_service.proto#L324}
  ///
  /// [google.cloud.documentai.v1.ProcessRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L254}
  /// [google.cloud.documentai.v1.ProcessResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L324}
  ///
  StatusOr<google::cloud::documentai::v1::ProcessResponse> ProcessDocument(
      google::cloud::documentai::v1::ProcessRequest const& request,
      Options opts = {});

  ///
  /// LRO endpoint to batch process many documents. The output is written
  /// to Cloud Storage as JSON in the [Document] format.
  ///
  /// @param name  Required. The resource name of
  /// [Processor][google.cloud.documentai.v1.Processor] or
  ///  [ProcessorVersion][google.cloud.documentai.v1.ProcessorVersion].
  ///  Format: `projects/{project}/locations/{location}/processors/{processor}`,
  ///  or
  ///  `projects/{project}/locations/{location}/processors/{processor}/processorVersions/{processorVersion}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::BatchProcessResponse,google/cloud/documentai/v1/document_processor_service.proto#L359}
  ///
  /// [google.cloud.documentai.v1.BatchProcessRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L334}
  /// [google.cloud.documentai.v1.BatchProcessResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L359}
  ///
  future<StatusOr<google::cloud::documentai::v1::BatchProcessResponse>>
  BatchProcessDocuments(std::string const& name, Options opts = {});

  ///
  /// LRO endpoint to batch process many documents. The output is written
  /// to Cloud Storage as JSON in the [Document] format.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::BatchProcessRequest,google/cloud/documentai/v1/document_processor_service.proto#L334}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::BatchProcessResponse,google/cloud/documentai/v1/document_processor_service.proto#L359}
  ///
  /// [google.cloud.documentai.v1.BatchProcessRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L334}
  /// [google.cloud.documentai.v1.BatchProcessResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L359}
  ///
  future<StatusOr<google::cloud::documentai::v1::BatchProcessResponse>>
  BatchProcessDocuments(
      google::cloud::documentai::v1::BatchProcessRequest const& request,
      Options opts = {});

  ///
  /// Fetches processor types. Note that we do not use ListProcessorTypes here
  /// because it is not paginated.
  ///
  /// @param parent  Required. The project of processor type to list.
  ///  The available processor types may depend on the allow-listing on
  ///  projects. Format: `projects/{project}/locations/{location}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::FetchProcessorTypesResponse,google/cloud/documentai/v1/document_processor_service.proto#L439}
  ///
  /// [google.cloud.documentai.v1.FetchProcessorTypesRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L426}
  /// [google.cloud.documentai.v1.FetchProcessorTypesResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L439}
  ///
  StatusOr<google::cloud::documentai::v1::FetchProcessorTypesResponse>
  FetchProcessorTypes(std::string const& parent, Options opts = {});

  ///
  /// Fetches processor types. Note that we do not use ListProcessorTypes here
  /// because it is not paginated.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::FetchProcessorTypesRequest,google/cloud/documentai/v1/document_processor_service.proto#L426}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::FetchProcessorTypesResponse,google/cloud/documentai/v1/document_processor_service.proto#L439}
  ///
  /// [google.cloud.documentai.v1.FetchProcessorTypesRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L426}
  /// [google.cloud.documentai.v1.FetchProcessorTypesResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L439}
  ///
  StatusOr<google::cloud::documentai::v1::FetchProcessorTypesResponse>
  FetchProcessorTypes(
      google::cloud::documentai::v1::FetchProcessorTypesRequest const& request,
      Options opts = {});

  ///
  /// Lists the processor types that exist.
  ///
  /// @param parent  Required. The location of processor type to list.
  ///  The available processor types may depend on the allow-listing on
  ///  projects. Format: `projects/{project}/locations/{location}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessorType,google/cloud/documentai/v1/processor_type.proto#L32}
  ///
  /// [google.cloud.documentai.v1.ListProcessorTypesRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L445}
  /// [google.cloud.documentai.v1.ProcessorType]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor_type.proto#L32}
  ///
  StreamRange<google::cloud::documentai::v1::ProcessorType> ListProcessorTypes(
      std::string const& parent, Options opts = {});

  ///
  /// Lists the processor types that exist.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::ListProcessorTypesRequest,google/cloud/documentai/v1/document_processor_service.proto#L445}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessorType,google/cloud/documentai/v1/processor_type.proto#L32}
  ///
  /// [google.cloud.documentai.v1.ListProcessorTypesRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L445}
  /// [google.cloud.documentai.v1.ProcessorType]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor_type.proto#L32}
  ///
  StreamRange<google::cloud::documentai::v1::ProcessorType> ListProcessorTypes(
      google::cloud::documentai::v1::ListProcessorTypesRequest request,
      Options opts = {});

  ///
  /// Lists all processors which belong to this project.
  ///
  /// @param parent  Required. The parent (project and location) which owns this
  /// collection of Processors.
  ///  Format: `projects/{project}/locations/{location}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::Processor,google/cloud/documentai/v1/processor.proto#L113}
  ///
  /// [google.cloud.documentai.v1.ListProcessorsRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L475}
  /// [google.cloud.documentai.v1.Processor]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L113}
  ///
  StreamRange<google::cloud::documentai::v1::Processor> ListProcessors(
      std::string const& parent, Options opts = {});

  ///
  /// Lists all processors which belong to this project.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::ListProcessorsRequest,google/cloud/documentai/v1/document_processor_service.proto#L475}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::Processor,google/cloud/documentai/v1/processor.proto#L113}
  ///
  /// [google.cloud.documentai.v1.ListProcessorsRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L475}
  /// [google.cloud.documentai.v1.Processor]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L113}
  ///
  StreamRange<google::cloud::documentai::v1::Processor> ListProcessors(
      google::cloud::documentai::v1::ListProcessorsRequest request,
      Options opts = {});

  ///
  /// Gets a processor detail.
  ///
  /// @param name  Required. The processor resource name.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::Processor,google/cloud/documentai/v1/processor.proto#L113}
  ///
  /// [google.cloud.documentai.v1.GetProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L505}
  /// [google.cloud.documentai.v1.Processor]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L113}
  ///
  StatusOr<google::cloud::documentai::v1::Processor> GetProcessor(
      std::string const& name, Options opts = {});

  ///
  /// Gets a processor detail.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::GetProcessorRequest,google/cloud/documentai/v1/document_processor_service.proto#L505}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::Processor,google/cloud/documentai/v1/processor.proto#L113}
  ///
  /// [google.cloud.documentai.v1.GetProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L505}
  /// [google.cloud.documentai.v1.Processor]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L113}
  ///
  StatusOr<google::cloud::documentai::v1::Processor> GetProcessor(
      google::cloud::documentai::v1::GetProcessorRequest const& request,
      Options opts = {});

  ///
  /// Gets a processor version detail.
  ///
  /// @param name  Required. The processor resource name.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessorVersion,google/cloud/documentai/v1/processor.proto#L37}
  ///
  /// [google.cloud.documentai.v1.GetProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L516}
  /// [google.cloud.documentai.v1.ProcessorVersion]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L37}
  ///
  StatusOr<google::cloud::documentai::v1::ProcessorVersion> GetProcessorVersion(
      std::string const& name, Options opts = {});

  ///
  /// Gets a processor version detail.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::GetProcessorVersionRequest,google/cloud/documentai/v1/document_processor_service.proto#L516}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessorVersion,google/cloud/documentai/v1/processor.proto#L37}
  ///
  /// [google.cloud.documentai.v1.GetProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L516}
  /// [google.cloud.documentai.v1.ProcessorVersion]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L37}
  ///
  StatusOr<google::cloud::documentai::v1::ProcessorVersion> GetProcessorVersion(
      google::cloud::documentai::v1::GetProcessorVersionRequest const& request,
      Options opts = {});

  ///
  /// Lists all versions of a processor.
  ///
  /// @param parent  Required. The parent (project, location and processor) to
  /// list all versions.
  ///  Format: `projects/{project}/locations/{location}/processors/{processor}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessorVersion,google/cloud/documentai/v1/processor.proto#L37}
  ///
  /// [google.cloud.documentai.v1.ListProcessorVersionsRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L527}
  /// [google.cloud.documentai.v1.ProcessorVersion]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L37}
  ///
  StreamRange<google::cloud::documentai::v1::ProcessorVersion>
  ListProcessorVersions(std::string const& parent, Options opts = {});

  ///
  /// Lists all versions of a processor.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::ListProcessorVersionsRequest,google/cloud/documentai/v1/document_processor_service.proto#L527}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ProcessorVersion,google/cloud/documentai/v1/processor.proto#L37}
  ///
  /// [google.cloud.documentai.v1.ListProcessorVersionsRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L527}
  /// [google.cloud.documentai.v1.ProcessorVersion]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L37}
  ///
  StreamRange<google::cloud::documentai::v1::ProcessorVersion>
  ListProcessorVersions(
      google::cloud::documentai::v1::ListProcessorVersionsRequest request,
      Options opts = {});

  ///
  /// Deletes the processor version, all artifacts under the processor version
  /// will be deleted.
  ///
  /// @param name  Required. The processor version resource name to be deleted.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::DeleteProcessorVersionMetadata,google/cloud/documentai/v1/document_processor_service.proto#L568}
  ///
  /// [google.cloud.documentai.v1.DeleteProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L557}
  /// [google.cloud.documentai.v1.DeleteProcessorVersionMetadata]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L568}
  ///
  future<
      StatusOr<google::cloud::documentai::v1::DeleteProcessorVersionMetadata>>
  DeleteProcessorVersion(std::string const& name, Options opts = {});

  ///
  /// Deletes the processor version, all artifacts under the processor version
  /// will be deleted.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::DeleteProcessorVersionRequest,google/cloud/documentai/v1/document_processor_service.proto#L557}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::DeleteProcessorVersionMetadata,google/cloud/documentai/v1/document_processor_service.proto#L568}
  ///
  /// [google.cloud.documentai.v1.DeleteProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L557}
  /// [google.cloud.documentai.v1.DeleteProcessorVersionMetadata]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L568}
  ///
  future<
      StatusOr<google::cloud::documentai::v1::DeleteProcessorVersionMetadata>>
  DeleteProcessorVersion(
      google::cloud::documentai::v1::DeleteProcessorVersionRequest const&
          request,
      Options opts = {});

  ///
  /// Deploys the processor version.
  ///
  /// @param name  Required. The processor version resource name to be deployed.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::DeployProcessorVersionResponse,google/cloud/documentai/v1/document_processor_service.proto#L585}
  ///
  /// [google.cloud.documentai.v1.DeployProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L574}
  /// [google.cloud.documentai.v1.DeployProcessorVersionResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L585}
  ///
  future<
      StatusOr<google::cloud::documentai::v1::DeployProcessorVersionResponse>>
  DeployProcessorVersion(std::string const& name, Options opts = {});

  ///
  /// Deploys the processor version.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::DeployProcessorVersionRequest,google/cloud/documentai/v1/document_processor_service.proto#L574}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::DeployProcessorVersionResponse,google/cloud/documentai/v1/document_processor_service.proto#L585}
  ///
  /// [google.cloud.documentai.v1.DeployProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L574}
  /// [google.cloud.documentai.v1.DeployProcessorVersionResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L585}
  ///
  future<
      StatusOr<google::cloud::documentai::v1::DeployProcessorVersionResponse>>
  DeployProcessorVersion(
      google::cloud::documentai::v1::DeployProcessorVersionRequest const&
          request,
      Options opts = {});

  ///
  /// Undeploys the processor version.
  ///
  /// @param name  Required. The processor version resource name to be
  /// undeployed.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::UndeployProcessorVersionResponse,google/cloud/documentai/v1/document_processor_service.proto#L607}
  ///
  /// [google.cloud.documentai.v1.UndeployProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L596}
  /// [google.cloud.documentai.v1.UndeployProcessorVersionResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L607}
  ///
  future<
      StatusOr<google::cloud::documentai::v1::UndeployProcessorVersionResponse>>
  UndeployProcessorVersion(std::string const& name, Options opts = {});

  ///
  /// Undeploys the processor version.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::UndeployProcessorVersionRequest,google/cloud/documentai/v1/document_processor_service.proto#L596}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::UndeployProcessorVersionResponse,google/cloud/documentai/v1/document_processor_service.proto#L607}
  ///
  /// [google.cloud.documentai.v1.UndeployProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L596}
  /// [google.cloud.documentai.v1.UndeployProcessorVersionResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L607}
  ///
  future<
      StatusOr<google::cloud::documentai::v1::UndeployProcessorVersionResponse>>
  UndeployProcessorVersion(
      google::cloud::documentai::v1::UndeployProcessorVersionRequest const&
          request,
      Options opts = {});

  ///
  /// Creates a processor from the type processor that the user chose.
  /// The processor will be at "ENABLED" state by default after its creation.
  ///
  /// @param parent  Required. The parent (project and location) under which to
  /// create the processor.
  ///  Format: `projects/{project}/locations/{location}`
  /// @param processor  Required. The processor to be created, requires
  /// [processor_type] and [display_name]
  ///  to be set. Also, the processor is under CMEK if CMEK fields are set.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::Processor,google/cloud/documentai/v1/processor.proto#L113}
  ///
  /// [google.cloud.documentai.v1.CreateProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L621}
  /// [google.cloud.documentai.v1.Processor]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L113}
  ///
  StatusOr<google::cloud::documentai::v1::Processor> CreateProcessor(
      std::string const& parent,
      google::cloud::documentai::v1::Processor const& processor,
      Options opts = {});

  ///
  /// Creates a processor from the type processor that the user chose.
  /// The processor will be at "ENABLED" state by default after its creation.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::CreateProcessorRequest,google/cloud/documentai/v1/document_processor_service.proto#L621}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::Processor,google/cloud/documentai/v1/processor.proto#L113}
  ///
  /// [google.cloud.documentai.v1.CreateProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L621}
  /// [google.cloud.documentai.v1.Processor]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/processor.proto#L113}
  ///
  StatusOr<google::cloud::documentai::v1::Processor> CreateProcessor(
      google::cloud::documentai::v1::CreateProcessorRequest const& request,
      Options opts = {});

  ///
  /// Deletes the processor, unloads all deployed model artifacts if it was
  /// enabled and then deletes all artifacts associated with this processor.
  ///
  /// @param name  Required. The processor resource name to be deleted.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::DeleteProcessorMetadata,google/cloud/documentai/v1/document_processor_service.proto#L648}
  ///
  /// [google.cloud.documentai.v1.DeleteProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L637}
  /// [google.cloud.documentai.v1.DeleteProcessorMetadata]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L648}
  ///
  future<StatusOr<google::cloud::documentai::v1::DeleteProcessorMetadata>>
  DeleteProcessor(std::string const& name, Options opts = {});

  ///
  /// Deletes the processor, unloads all deployed model artifacts if it was
  /// enabled and then deletes all artifacts associated with this processor.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::DeleteProcessorRequest,google/cloud/documentai/v1/document_processor_service.proto#L637}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::DeleteProcessorMetadata,google/cloud/documentai/v1/document_processor_service.proto#L648}
  ///
  /// [google.cloud.documentai.v1.DeleteProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L637}
  /// [google.cloud.documentai.v1.DeleteProcessorMetadata]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L648}
  ///
  future<StatusOr<google::cloud::documentai::v1::DeleteProcessorMetadata>>
  DeleteProcessor(
      google::cloud::documentai::v1::DeleteProcessorRequest const& request,
      Options opts = {});

  ///
  /// Enables a processor
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::EnableProcessorRequest,google/cloud/documentai/v1/document_processor_service.proto#L654}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::EnableProcessorResponse,google/cloud/documentai/v1/document_processor_service.proto#L666}
  ///
  /// [google.cloud.documentai.v1.EnableProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L654}
  /// [google.cloud.documentai.v1.EnableProcessorResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L666}
  ///
  future<StatusOr<google::cloud::documentai::v1::EnableProcessorResponse>>
  EnableProcessor(
      google::cloud::documentai::v1::EnableProcessorRequest const& request,
      Options opts = {});

  ///
  /// Disables a processor
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::DisableProcessorRequest,google/cloud/documentai/v1/document_processor_service.proto#L677}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::DisableProcessorResponse,google/cloud/documentai/v1/document_processor_service.proto#L689}
  ///
  /// [google.cloud.documentai.v1.DisableProcessorRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L677}
  /// [google.cloud.documentai.v1.DisableProcessorResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L689}
  ///
  future<StatusOr<google::cloud::documentai::v1::DisableProcessorResponse>>
  DisableProcessor(
      google::cloud::documentai::v1::DisableProcessorRequest const& request,
      Options opts = {});

  ///
  /// Set the default (active) version of a
  /// [Processor][google.cloud.documentai.v1.Processor] that will be used in
  /// [ProcessDocument][google.cloud.documentai.v1.DocumentProcessorService.ProcessDocument]
  /// and
  /// [BatchProcessDocuments][google.cloud.documentai.v1.DocumentProcessorService.BatchProcessDocuments].
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::SetDefaultProcessorVersionRequest,google/cloud/documentai/v1/document_processor_service.proto#L700}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::SetDefaultProcessorVersionResponse,google/cloud/documentai/v1/document_processor_service.proto#L721}
  ///
  /// [google.cloud.documentai.v1.SetDefaultProcessorVersionRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L700}
  /// [google.cloud.documentai.v1.SetDefaultProcessorVersionResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L721}
  ///
  future<StatusOr<
      google::cloud::documentai::v1::SetDefaultProcessorVersionResponse>>
  SetDefaultProcessorVersion(
      google::cloud::documentai::v1::SetDefaultProcessorVersionRequest const&
          request,
      Options opts = {});

  ///
  /// Send a document for Human Review. The input document should be processed
  /// by the specified processor.
  ///
  /// @param human_review_config  Required. The resource name of the
  /// HumanReviewConfig that the document will be
  ///  reviewed with.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ReviewDocumentResponse,google/cloud/documentai/v1/document_processor_service.proto#L770}
  ///
  /// [google.cloud.documentai.v1.ReviewDocumentRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L733}
  /// [google.cloud.documentai.v1.ReviewDocumentResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L770}
  ///
  future<StatusOr<google::cloud::documentai::v1::ReviewDocumentResponse>>
  ReviewDocument(std::string const& human_review_config, Options opts = {});

  ///
  /// Send a document for Human Review. The input document should be processed
  /// by the specified processor.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::documentai::v1::ReviewDocumentRequest,google/cloud/documentai/v1/document_processor_service.proto#L733}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::documentai::v1::ReviewDocumentResponse,google/cloud/documentai/v1/document_processor_service.proto#L770}
  ///
  /// [google.cloud.documentai.v1.ReviewDocumentRequest]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L733}
  /// [google.cloud.documentai.v1.ReviewDocumentResponse]:
  /// @googleapis_reference_link{google/cloud/documentai/v1/document_processor_service.proto#L770}
  ///
  future<StatusOr<google::cloud::documentai::v1::ReviewDocumentResponse>>
  ReviewDocument(
      google::cloud::documentai::v1::ReviewDocumentRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<DocumentProcessorServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace documentai
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DOCUMENTAI_DOCUMENT_PROCESSOR_CLIENT_H
