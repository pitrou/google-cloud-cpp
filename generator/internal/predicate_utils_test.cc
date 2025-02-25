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

#include "generator/internal/predicate_utils.h"
#include "generator/testing/error_collectors.h"
#include "generator/testing/fake_source_tree.h"
#include "google/cloud/log.h"
#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/descriptor_database.h>
#include <google/protobuf/text_format.h>
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace generator_internal {
namespace {

using ::google::protobuf::DescriptorPool;
using ::google::protobuf::FileDescriptor;
using ::google::protobuf::FileDescriptorProto;

bool PredicateTrue(int const&) { return true; }
bool PredicateFalse(int const&) { return false; }

TEST(PredicateUtilsTest, GenericNot) {
  int const unused = 0;
  EXPECT_TRUE(GenericNot<int>(PredicateFalse)(unused));
  EXPECT_FALSE(GenericNot<int>(PredicateTrue)(unused));
}

TEST(PredicateUtilsTest, GenericAnd) {
  int const unused = 0;
  EXPECT_TRUE(GenericAnd<int>(PredicateTrue, PredicateTrue)(unused));
  EXPECT_FALSE(GenericAnd<int>(PredicateFalse, PredicateTrue)(unused));
  EXPECT_FALSE(GenericAnd<int>(PredicateTrue, PredicateFalse)(unused));
  EXPECT_FALSE(GenericAnd<int>(PredicateFalse, PredicateFalse)(unused));

  EXPECT_TRUE(
      GenericAnd<int>(PredicateTrue, GenericNot<int>(PredicateFalse))(unused));
  EXPECT_TRUE(
      GenericAnd<int>(GenericNot<int>(PredicateFalse), PredicateTrue)(unused));
  EXPECT_TRUE(
      GenericNot<int>(GenericAnd<int>(PredicateTrue, PredicateFalse))(unused));
}

TEST(PredicateUtilsTest, GenericOr) {
  int const unused = 0;
  EXPECT_TRUE(GenericOr<int>(PredicateTrue, PredicateTrue)(unused));
  EXPECT_TRUE(GenericOr<int>(PredicateFalse, PredicateTrue)(unused));
  EXPECT_TRUE(GenericOr<int>(PredicateTrue, PredicateFalse)(unused));
  EXPECT_FALSE(GenericOr<int>(PredicateFalse, PredicateFalse)(unused));
}

TEST(PredicateUtilsTest, GenericAll) {
  int const unused = 0;
  EXPECT_TRUE(GenericAll<int>(PredicateTrue)(unused));
  EXPECT_FALSE(GenericAll<int>(PredicateFalse)(unused));
  EXPECT_FALSE(GenericAll<int>(PredicateFalse, PredicateFalse)(unused));
  EXPECT_TRUE(GenericAll<int>(PredicateTrue, PredicateTrue)(unused));
  EXPECT_TRUE(
      GenericAll<int>(PredicateTrue, PredicateTrue, PredicateTrue)(unused));
  EXPECT_FALSE(
      GenericAll<int>(PredicateFalse, PredicateTrue, PredicateTrue)(unused));
  EXPECT_FALSE(
      GenericAll<int>(PredicateTrue, PredicateFalse, PredicateTrue)(unused));
  EXPECT_FALSE(
      GenericAll<int>(PredicateFalse, PredicateFalse, PredicateFalse)(unused));

  EXPECT_FALSE(GenericAll<int>(
      PredicateFalse, GenericOr<int>(PredicateFalse, PredicateTrue))(unused));
}

TEST(PredicateUtilsTest, GenericAny) {
  int const unused = 0;
  EXPECT_TRUE(GenericAny<int>(PredicateTrue)(unused));
  EXPECT_FALSE(GenericAny<int>(PredicateFalse)(unused));
  EXPECT_FALSE(GenericAny<int>(PredicateFalse, PredicateFalse)(unused));
  EXPECT_TRUE(GenericAny<int>(PredicateTrue, PredicateTrue)(unused));
  EXPECT_TRUE(
      GenericAny<int>(PredicateTrue, PredicateTrue, PredicateTrue)(unused));
  EXPECT_TRUE(
      GenericAny<int>(PredicateFalse, PredicateTrue, PredicateTrue)(unused));
  EXPECT_TRUE(
      GenericAny<int>(PredicateTrue, PredicateFalse, PredicateTrue)(unused));
  EXPECT_FALSE(
      GenericAny<int>(PredicateFalse, PredicateFalse, PredicateFalse)(unused));
}

TEST(PredicateUtilsTest, IsResponseTypeEmpty) {
  FileDescriptorProto service_file;
  /// @cond
  auto constexpr kServiceText = R"pb(
    name: "google/foo/v1/service.proto"
    package: "google.protobuf"
    message_type { name: "Bar" }
    message_type { name: "Empty" }
    service {
      name: "Service"
      method {
        name: "Empty"
        input_type: "google.protobuf.Bar"
        output_type: "google.protobuf.Empty"
      }
      method {
        name: "NonEmpty"
        input_type: "google.protobuf.Bar"
        output_type: "google.protobuf.Bar"
      }
    }
  )pb";
  /// @endcond
  ASSERT_TRUE(google::protobuf::TextFormat::ParseFromString(kServiceText,
                                                            &service_file));
  DescriptorPool pool;
  FileDescriptor const* service_file_descriptor = pool.BuildFile(service_file);
  EXPECT_TRUE(
      IsResponseTypeEmpty(*service_file_descriptor->service(0)->method(0)));
  EXPECT_FALSE(
      IsResponseTypeEmpty(*service_file_descriptor->service(0)->method(1)));
}

TEST(PredicateUtilsTest, IsNonStreaming) {
  FileDescriptorProto service_file;
  /// @cond
  auto constexpr kServiceText = R"pb(
    name: "google/foo/v1/service.proto"
    package: "google.protobuf"
    message_type { name: "Input" }
    message_type { name: "Output" }
    service {
      name: "Service"
      method {
        name: "NonStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
      }
      method {
        name: "ClientStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        client_streaming: true
      }
      method {
        name: "ServerStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        server_streaming: true
      }
      method {
        name: "BidirectionalStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        client_streaming: true
        server_streaming: true
      }
    }
  )pb";
  /// @endcond
  ASSERT_TRUE(google::protobuf::TextFormat::ParseFromString(kServiceText,
                                                            &service_file));
  DescriptorPool pool;
  FileDescriptor const* service_file_descriptor_lro =
      pool.BuildFile(service_file);
  EXPECT_TRUE(
      IsNonStreaming(*service_file_descriptor_lro->service(0)->method(0)));
  EXPECT_FALSE(
      IsNonStreaming(*service_file_descriptor_lro->service(0)->method(1)));
  EXPECT_FALSE(
      IsNonStreaming(*service_file_descriptor_lro->service(0)->method(2)));
  EXPECT_FALSE(
      IsNonStreaming(*service_file_descriptor_lro->service(0)->method(3)));
}

TEST(PredicateUtilsTest, IsStreamingWrite) {
  FileDescriptorProto service_file;
  /// @cond
  auto constexpr kServiceText = R"pb(
    name: "google/foo/v1/service.proto"
    package: "google.protobuf"
    message_type { name: "Input" }
    message_type { name: "Output" }
    service {
      name: "Service"
      method {
        name: "NonStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
      }
      method {
        name: "ClientStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        client_streaming: true
      }
      method {
        name: "ServerStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        server_streaming: true
      }
      method {
        name: "BidirectionalStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        client_streaming: true
        server_streaming: true
      }
    }
  )pb";
  /// @endcond
  ASSERT_TRUE(google::protobuf::TextFormat::ParseFromString(kServiceText,
                                                            &service_file));
  DescriptorPool pool;
  auto const* file_descriptor = pool.BuildFile(service_file);
  auto const* service = file_descriptor->service(0);
  struct Expected {
    std::string name;
    bool is_bir;
  } methods[] = {
      {"NonStreaming", false},
      {"ClientStreaming", true},
      {"ServerStreaming", false},
      {"BidirectionalStreaming", false},
  };
  ASSERT_EQ(service->method_count(), sizeof(methods) / sizeof(methods[0]));
  for (int i = 0; i != service->method_count(); ++i) {
    ASSERT_EQ(service->method(i)->name(), methods[i].name);
    ASSERT_EQ(IsStreamingWrite(*service->method(i)), methods[i].is_bir)
        << "name=" << methods[i].name;
  }
}

TEST(PredicateUtilsTest, IsBidirStreaming) {
  FileDescriptorProto service_file;
  /// @cond
  auto constexpr kServiceText = R"pb(
    name: "google/foo/v1/service.proto"
    package: "google.protobuf"
    message_type { name: "Input" }
    message_type { name: "Output" }
    service {
      name: "Service"
      method {
        name: "NonStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
      }
      method {
        name: "ClientStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        client_streaming: true
      }
      method {
        name: "ServerStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        server_streaming: true
      }
      method {
        name: "BidirectionalStreaming"
        input_type: "google.protobuf.Input"
        output_type: "google.protobuf.Output"
        client_streaming: true
        server_streaming: true
      }
    }
  )pb";
  /// @endcond
  ASSERT_TRUE(google::protobuf::TextFormat::ParseFromString(kServiceText,
                                                            &service_file));
  DescriptorPool pool;
  auto const* file_descriptor = pool.BuildFile(service_file);
  auto const* service = file_descriptor->service(0);
  struct Expected {
    std::string name;
    bool is_bir;
  } methods[] = {
      {"NonStreaming", false},
      {"ClientStreaming", false},
      {"ServerStreaming", false},
      {"BidirectionalStreaming", true},
  };
  ASSERT_EQ(service->method_count(), sizeof(methods) / sizeof(methods[0]));
  for (int i = 0; i != service->method_count(); ++i) {
    ASSERT_EQ(service->method(i)->name(), methods[i].name);
    ASSERT_EQ(IsBidirStreaming(*service->method(i)), methods[i].is_bir)
        << "name=" << methods[i].name;
  }
}

char const* const kStreamingServiceProto =
    "syntax = \"proto3\";\n"
    "package google.protobuf;\n"
    "// Leading comments about message Foo.\n"
    "message Foo {\n"
    "  string baz = 1;\n"
    "  map<string, string> labels = 2;\n"
    "}\n"
    "// Leading comments about message Empty.\n"
    "message Bar {\n"
    "  int32 x = 1;\n"
    "}\n"
    "// Leading comments about service Service0.\n"
    "service Service0 {\n"
    "  // Leading comments about rpc Method0.\n"
    "  rpc Method0(Foo) returns (stream Bar) {\n"
    "  }\n"
    "  // Leading comments about rpc Method1.\n"
    "  rpc Method1(stream Foo) returns (Bar) {\n"
    "  }\n"
    "  // Leading comments about rpc Method2.\n"
    "  rpc Method2(stream Foo) returns (stream Bar) {\n"
    "  }\n"
    "  // Leading comments about rpc Method3.\n"
    "  rpc Method3(Foo) returns (Bar) {\n"
    "  }\n"
    "}\n"
    "service Service1 {\n"
    "  // Leading comments about rpc Method0.\n"
    "  rpc Method0(stream Foo) returns (Bar) {\n"
    "  }\n"
    "  // Leading comments about rpc Method1.\n"
    "  rpc Method1(stream Foo) returns (stream Bar) {\n"
    "  }\n"
    "  // Leading comments about rpc Method2.\n"
    "  rpc Method2(Foo) returns (Bar) {\n"
    "  }\n"
    "}\n";

class StreamingReadTest : public testing::Test {
 public:
  StreamingReadTest()
      : source_tree_(std::map<std::string, std::string>{
            {std::string("google/cloud/foo/streaming.proto"),
             kStreamingServiceProto}}),
        source_tree_db_(&source_tree_),
        merged_db_(&simple_db_, &source_tree_db_),
        pool_(&merged_db_, &collector_) {
    // we need descriptor.proto to be accessible by the pool
    // since our test file imports it
    FileDescriptorProto::descriptor()->file()->CopyTo(&file_proto_);
    simple_db_.Add(file_proto_);
  }

 private:
  FileDescriptorProto file_proto_;
  generator_testing::ErrorCollector collector_;
  generator_testing::FakeSourceTree source_tree_;
  google::protobuf::SimpleDescriptorDatabase simple_db_;
  google::protobuf::compiler::SourceTreeDescriptorDatabase source_tree_db_;
  google::protobuf::MergedDescriptorDatabase merged_db_;

 protected:
  DescriptorPool pool_;
};

TEST_F(StreamingReadTest, IsStreamingRead) {
  FileDescriptor const* service_file_descriptor =
      pool_.FindFileByName("google/cloud/foo/streaming.proto");
  EXPECT_TRUE(IsStreamingRead(*service_file_descriptor->service(0)->method(0)));
  EXPECT_FALSE(
      IsStreamingRead(*service_file_descriptor->service(0)->method(1)));
  EXPECT_FALSE(
      IsStreamingRead(*service_file_descriptor->service(0)->method(2)));
  EXPECT_FALSE(
      IsStreamingRead(*service_file_descriptor->service(0)->method(3)));
}

TEST(PredicateUtilsTest, PredicatedFragmentTrueString) {
  int const unused = 0;
  PredicatedFragment<int> f = {PredicateTrue, "True", "False"};
  EXPECT_EQ(f(unused), "True");
}

TEST(PredicateUtilsTest, PredicatedFragmentFalseString) {
  int const unused = 0;
  PredicatedFragment<int> f = {PredicateFalse, "True", "False"};
  EXPECT_EQ(f(unused), "False");
}

TEST(PredicateUtilsTest, PredicatedFragmentStringOnly) {
  int const unused = 0;
  PredicatedFragment<int> f = {"True"};
  EXPECT_EQ(f(unused), "True");
}

TEST(Pattern, OperatorParens) {
  int const unused = 0;
  Pattern<int> p({}, PredicateFalse);
  EXPECT_FALSE(p(unused));
}

TEST(Pattern, FragmentsAccessor) {
  int const unused = 0;
  Pattern<int> p({{PredicateFalse, "fragment0_true", "fragment0_false"},
                  {PredicateTrue, "fragment1_true", "fragment1_false"}},
                 PredicateTrue);
  EXPECT_TRUE(p(unused));
  std::string result;
  for (auto const& pf : p.fragments()) {
    result += pf(unused);
  }

  EXPECT_EQ(result, std::string("fragment0_falsefragment1_true"));
}

}  // namespace
}  // namespace generator_internal
}  // namespace cloud
}  // namespace google
