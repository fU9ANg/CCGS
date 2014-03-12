// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protos/proto.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "protos/proto.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* ccgs_header_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ccgs_header_reflection_ = NULL;
const ::google::protobuf::Descriptor* packet_test_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  packet_test_reflection_ = NULL;
const ::google::protobuf::Descriptor* packet_user_login_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  packet_user_login_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_protos_2fproto_2eproto() {
  protobuf_AddDesc_protos_2fproto_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "protos/proto.proto");
  GOOGLE_CHECK(file != NULL);
  ccgs_header_descriptor_ = file->message_type(0);
  static const int ccgs_header_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ccgs_header, identifier_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ccgs_header, tid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ccgs_header, flags_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ccgs_header, mid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ccgs_header, length_),
  };
  ccgs_header_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ccgs_header_descriptor_,
      ccgs_header::default_instance_,
      ccgs_header_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ccgs_header, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ccgs_header, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ccgs_header));
  packet_test_descriptor_ = file->message_type(1);
  static const int packet_test_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_test, uivalue_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_test, ivalue_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_test, svalue_),
  };
  packet_test_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      packet_test_descriptor_,
      packet_test::default_instance_,
      packet_test_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_test, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_test, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(packet_test));
  packet_user_login_descriptor_ = file->message_type(2);
  static const int packet_user_login_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_user_login, susername_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_user_login, spassword_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_user_login, iflags_),
  };
  packet_user_login_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      packet_user_login_descriptor_,
      packet_user_login::default_instance_,
      packet_user_login_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_user_login, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(packet_user_login, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(packet_user_login));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_protos_2fproto_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ccgs_header_descriptor_, &ccgs_header::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    packet_test_descriptor_, &packet_test::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    packet_user_login_descriptor_, &packet_user_login::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_protos_2fproto_2eproto() {
  delete ccgs_header::default_instance_;
  delete ccgs_header_reflection_;
  delete packet_test::default_instance_;
  delete packet_test_reflection_;
  delete packet_user_login::default_instance_;
  delete packet_user_login_reflection_;
}

void protobuf_AddDesc_protos_2fproto_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\022protos/proto.proto\"a\n\013ccgs_header\022\022\n\ni"
    "dentifier\030\001 \002(\r\022\013\n\003TID\030\002 \002(\r\022\024\n\014flags_st"
    "atus\030\003 \002(\r\022\013\n\003MID\030\004 \002(\r\022\016\n\006length\030\005 \002(\r\""
    ">\n\013packet_test\022\017\n\007uiValue\030\001 \002(\r\022\016\n\006iValu"
    "e\030\002 \002(\005\022\016\n\006sValue\030\003 \002(\t\"I\n\021packet_user_l"
    "ogin\022\021\n\tsUserName\030\001 \002(\t\022\021\n\tsPassword\030\002 \002"
    "(\t\022\016\n\006iFlags\030\003 \002(\005", 258);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "protos/proto.proto", &protobuf_RegisterTypes);
  ccgs_header::default_instance_ = new ccgs_header();
  packet_test::default_instance_ = new packet_test();
  packet_user_login::default_instance_ = new packet_user_login();
  ccgs_header::default_instance_->InitAsDefaultInstance();
  packet_test::default_instance_->InitAsDefaultInstance();
  packet_user_login::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_protos_2fproto_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_protos_2fproto_2eproto {
  StaticDescriptorInitializer_protos_2fproto_2eproto() {
    protobuf_AddDesc_protos_2fproto_2eproto();
  }
} static_descriptor_initializer_protos_2fproto_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ccgs_header::kIdentifierFieldNumber;
const int ccgs_header::kTIDFieldNumber;
const int ccgs_header::kFlagsStatusFieldNumber;
const int ccgs_header::kMIDFieldNumber;
const int ccgs_header::kLengthFieldNumber;
#endif  // !_MSC_VER

ccgs_header::ccgs_header()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ccgs_header::InitAsDefaultInstance() {
}

ccgs_header::ccgs_header(const ccgs_header& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ccgs_header::SharedCtor() {
  _cached_size_ = 0;
  identifier_ = 0u;
  tid_ = 0u;
  flags_status_ = 0u;
  mid_ = 0u;
  length_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ccgs_header::~ccgs_header() {
  SharedDtor();
}

void ccgs_header::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ccgs_header::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ccgs_header::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ccgs_header_descriptor_;
}

const ccgs_header& ccgs_header::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protos_2fproto_2eproto();
  return *default_instance_;
}

ccgs_header* ccgs_header::default_instance_ = NULL;

ccgs_header* ccgs_header::New() const {
  return new ccgs_header;
}

void ccgs_header::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    identifier_ = 0u;
    tid_ = 0u;
    flags_status_ = 0u;
    mid_ = 0u;
    length_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ccgs_header::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 identifier = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &identifier_)));
          set_has_identifier();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_TID;
        break;
      }

      // required uint32 TID = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_TID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &tid_)));
          set_has_tid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_flags_status;
        break;
      }

      // required uint32 flags_status = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_flags_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &flags_status_)));
          set_has_flags_status();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_MID;
        break;
      }

      // required uint32 MID = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_MID:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &mid_)));
          set_has_mid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_length;
        break;
      }

      // required uint32 length = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_length:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &length_)));
          set_has_length();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ccgs_header::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 identifier = 1;
  if (has_identifier()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->identifier(), output);
  }

  // required uint32 TID = 2;
  if (has_tid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->tid(), output);
  }

  // required uint32 flags_status = 3;
  if (has_flags_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->flags_status(), output);
  }

  // required uint32 MID = 4;
  if (has_mid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->mid(), output);
  }

  // required uint32 length = 5;
  if (has_length()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->length(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ccgs_header::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 identifier = 1;
  if (has_identifier()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->identifier(), target);
  }

  // required uint32 TID = 2;
  if (has_tid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->tid(), target);
  }

  // required uint32 flags_status = 3;
  if (has_flags_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->flags_status(), target);
  }

  // required uint32 MID = 4;
  if (has_mid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->mid(), target);
  }

  // required uint32 length = 5;
  if (has_length()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->length(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ccgs_header::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 identifier = 1;
    if (has_identifier()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->identifier());
    }

    // required uint32 TID = 2;
    if (has_tid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->tid());
    }

    // required uint32 flags_status = 3;
    if (has_flags_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->flags_status());
    }

    // required uint32 MID = 4;
    if (has_mid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->mid());
    }

    // required uint32 length = 5;
    if (has_length()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->length());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ccgs_header::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ccgs_header* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ccgs_header*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ccgs_header::MergeFrom(const ccgs_header& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_identifier()) {
      set_identifier(from.identifier());
    }
    if (from.has_tid()) {
      set_tid(from.tid());
    }
    if (from.has_flags_status()) {
      set_flags_status(from.flags_status());
    }
    if (from.has_mid()) {
      set_mid(from.mid());
    }
    if (from.has_length()) {
      set_length(from.length());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ccgs_header::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ccgs_header::CopyFrom(const ccgs_header& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ccgs_header::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;

  return true;
}

void ccgs_header::Swap(ccgs_header* other) {
  if (other != this) {
    std::swap(identifier_, other->identifier_);
    std::swap(tid_, other->tid_);
    std::swap(flags_status_, other->flags_status_);
    std::swap(mid_, other->mid_);
    std::swap(length_, other->length_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ccgs_header::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ccgs_header_descriptor_;
  metadata.reflection = ccgs_header_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int packet_test::kUiValueFieldNumber;
const int packet_test::kIValueFieldNumber;
const int packet_test::kSValueFieldNumber;
#endif  // !_MSC_VER

packet_test::packet_test()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void packet_test::InitAsDefaultInstance() {
}

packet_test::packet_test(const packet_test& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void packet_test::SharedCtor() {
  _cached_size_ = 0;
  uivalue_ = 0u;
  ivalue_ = 0;
  svalue_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

packet_test::~packet_test() {
  SharedDtor();
}

void packet_test::SharedDtor() {
  if (svalue_ != &::google::protobuf::internal::kEmptyString) {
    delete svalue_;
  }
  if (this != default_instance_) {
  }
}

void packet_test::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* packet_test::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return packet_test_descriptor_;
}

const packet_test& packet_test::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protos_2fproto_2eproto();
  return *default_instance_;
}

packet_test* packet_test::default_instance_ = NULL;

packet_test* packet_test::New() const {
  return new packet_test;
}

void packet_test::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    uivalue_ = 0u;
    ivalue_ = 0;
    if (has_svalue()) {
      if (svalue_ != &::google::protobuf::internal::kEmptyString) {
        svalue_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool packet_test::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 uiValue = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &uivalue_)));
          set_has_uivalue();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_iValue;
        break;
      }

      // required int32 iValue = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_iValue:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &ivalue_)));
          set_has_ivalue();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_sValue;
        break;
      }

      // required string sValue = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_sValue:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_svalue()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->svalue().data(), this->svalue().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void packet_test::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 uiValue = 1;
  if (has_uivalue()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->uivalue(), output);
  }

  // required int32 iValue = 2;
  if (has_ivalue()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->ivalue(), output);
  }

  // required string sValue = 3;
  if (has_svalue()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->svalue().data(), this->svalue().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->svalue(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* packet_test::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 uiValue = 1;
  if (has_uivalue()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->uivalue(), target);
  }

  // required int32 iValue = 2;
  if (has_ivalue()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->ivalue(), target);
  }

  // required string sValue = 3;
  if (has_svalue()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->svalue().data(), this->svalue().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->svalue(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int packet_test::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 uiValue = 1;
    if (has_uivalue()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->uivalue());
    }

    // required int32 iValue = 2;
    if (has_ivalue()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->ivalue());
    }

    // required string sValue = 3;
    if (has_svalue()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->svalue());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void packet_test::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const packet_test* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const packet_test*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void packet_test::MergeFrom(const packet_test& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_uivalue()) {
      set_uivalue(from.uivalue());
    }
    if (from.has_ivalue()) {
      set_ivalue(from.ivalue());
    }
    if (from.has_svalue()) {
      set_svalue(from.svalue());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void packet_test::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void packet_test::CopyFrom(const packet_test& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool packet_test::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void packet_test::Swap(packet_test* other) {
  if (other != this) {
    std::swap(uivalue_, other->uivalue_);
    std::swap(ivalue_, other->ivalue_);
    std::swap(svalue_, other->svalue_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata packet_test::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = packet_test_descriptor_;
  metadata.reflection = packet_test_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int packet_user_login::kSUserNameFieldNumber;
const int packet_user_login::kSPasswordFieldNumber;
const int packet_user_login::kIFlagsFieldNumber;
#endif  // !_MSC_VER

packet_user_login::packet_user_login()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void packet_user_login::InitAsDefaultInstance() {
}

packet_user_login::packet_user_login(const packet_user_login& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void packet_user_login::SharedCtor() {
  _cached_size_ = 0;
  susername_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  spassword_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  iflags_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

packet_user_login::~packet_user_login() {
  SharedDtor();
}

void packet_user_login::SharedDtor() {
  if (susername_ != &::google::protobuf::internal::kEmptyString) {
    delete susername_;
  }
  if (spassword_ != &::google::protobuf::internal::kEmptyString) {
    delete spassword_;
  }
  if (this != default_instance_) {
  }
}

void packet_user_login::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* packet_user_login::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return packet_user_login_descriptor_;
}

const packet_user_login& packet_user_login::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protos_2fproto_2eproto();
  return *default_instance_;
}

packet_user_login* packet_user_login::default_instance_ = NULL;

packet_user_login* packet_user_login::New() const {
  return new packet_user_login;
}

void packet_user_login::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_susername()) {
      if (susername_ != &::google::protobuf::internal::kEmptyString) {
        susername_->clear();
      }
    }
    if (has_spassword()) {
      if (spassword_ != &::google::protobuf::internal::kEmptyString) {
        spassword_->clear();
      }
    }
    iflags_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool packet_user_login::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string sUserName = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_susername()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->susername().data(), this->susername().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_sPassword;
        break;
      }

      // required string sPassword = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_sPassword:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_spassword()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->spassword().data(), this->spassword().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_iFlags;
        break;
      }

      // required int32 iFlags = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_iFlags:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &iflags_)));
          set_has_iflags();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void packet_user_login::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string sUserName = 1;
  if (has_susername()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->susername().data(), this->susername().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->susername(), output);
  }

  // required string sPassword = 2;
  if (has_spassword()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->spassword().data(), this->spassword().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->spassword(), output);
  }

  // required int32 iFlags = 3;
  if (has_iflags()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->iflags(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* packet_user_login::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string sUserName = 1;
  if (has_susername()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->susername().data(), this->susername().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->susername(), target);
  }

  // required string sPassword = 2;
  if (has_spassword()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->spassword().data(), this->spassword().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->spassword(), target);
  }

  // required int32 iFlags = 3;
  if (has_iflags()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->iflags(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int packet_user_login::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string sUserName = 1;
    if (has_susername()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->susername());
    }

    // required string sPassword = 2;
    if (has_spassword()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->spassword());
    }

    // required int32 iFlags = 3;
    if (has_iflags()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->iflags());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void packet_user_login::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const packet_user_login* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const packet_user_login*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void packet_user_login::MergeFrom(const packet_user_login& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_susername()) {
      set_susername(from.susername());
    }
    if (from.has_spassword()) {
      set_spassword(from.spassword());
    }
    if (from.has_iflags()) {
      set_iflags(from.iflags());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void packet_user_login::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void packet_user_login::CopyFrom(const packet_user_login& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool packet_user_login::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void packet_user_login::Swap(packet_user_login* other) {
  if (other != this) {
    std::swap(susername_, other->susername_);
    std::swap(spassword_, other->spassword_);
    std::swap(iflags_, other->iflags_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata packet_user_login::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = packet_user_login_descriptor_;
  metadata.reflection = packet_user_login_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
