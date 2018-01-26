// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DBServer.proto

#include "DBServer.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace SvrData {
class ExecuteDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Execute>
      _instance;
} _Execute_default_instance_;
class ExecuteRetDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ExecuteRet>
      _instance;
} _ExecuteRet_default_instance_;
}  // namespace SvrData
namespace protobuf_DBServer_2eproto {
void InitDefaultsExecuteImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::SvrData::_Execute_default_instance_;
    new (ptr) ::SvrData::Execute();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SvrData::Execute::InitAsDefaultInstance();
}

void InitDefaultsExecute() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsExecuteImpl);
}

void InitDefaultsExecuteRetImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::SvrData::_ExecuteRet_default_instance_;
    new (ptr) ::SvrData::ExecuteRet();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::SvrData::ExecuteRet::InitAsDefaultInstance();
}

void InitDefaultsExecuteRet() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsExecuteRetImpl);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrData::Execute, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrData::Execute, type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrData::Execute, sql_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrData::ExecuteRet, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::SvrData::ExecuteRet, res_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::SvrData::Execute)},
  { 7, -1, sizeof(::SvrData::ExecuteRet)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::SvrData::_Execute_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::SvrData::_ExecuteRet_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "DBServer.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\016DBServer.proto\022\007SvrData\"$\n\007Execute\022\014\n\004"
      "type\030\001 \001(\t\022\013\n\003sql\030\002 \001(\t\"\031\n\nExecuteRet\022\013\n"
      "\003res\030\001 \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 98);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "DBServer.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_DBServer_2eproto
namespace SvrData {

// ===================================================================

void Execute::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Execute::kTypeFieldNumber;
const int Execute::kSqlFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Execute::Execute()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_DBServer_2eproto::InitDefaultsExecute();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:SvrData.Execute)
}
Execute::Execute(const Execute& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.type().size() > 0) {
    type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.type_);
  }
  sql_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.sql().size() > 0) {
    sql_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sql_);
  }
  // @@protoc_insertion_point(copy_constructor:SvrData.Execute)
}

void Execute::SharedCtor() {
  type_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sql_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

Execute::~Execute() {
  // @@protoc_insertion_point(destructor:SvrData.Execute)
  SharedDtor();
}

void Execute::SharedDtor() {
  type_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sql_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Execute::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Execute::descriptor() {
  ::protobuf_DBServer_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DBServer_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Execute& Execute::default_instance() {
  ::protobuf_DBServer_2eproto::InitDefaultsExecute();
  return *internal_default_instance();
}

Execute* Execute::New(::google::protobuf::Arena* arena) const {
  Execute* n = new Execute;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Execute::Clear() {
// @@protoc_insertion_point(message_clear_start:SvrData.Execute)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  type_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sql_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool Execute::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SvrData.Execute)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_type()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->type().data(), static_cast<int>(this->type().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SvrData.Execute.type"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string sql = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sql()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->sql().data(), static_cast<int>(this->sql().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SvrData.Execute.sql"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SvrData.Execute)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SvrData.Execute)
  return false;
#undef DO_
}

void Execute::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SvrData.Execute)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string type = 1;
  if (this->type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->type().data(), static_cast<int>(this->type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrData.Execute.type");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->type(), output);
  }

  // string sql = 2;
  if (this->sql().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->sql().data(), static_cast<int>(this->sql().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrData.Execute.sql");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->sql(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:SvrData.Execute)
}

::google::protobuf::uint8* Execute::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:SvrData.Execute)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string type = 1;
  if (this->type().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->type().data(), static_cast<int>(this->type().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrData.Execute.type");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->type(), target);
  }

  // string sql = 2;
  if (this->sql().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->sql().data(), static_cast<int>(this->sql().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrData.Execute.sql");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->sql(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SvrData.Execute)
  return target;
}

size_t Execute::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SvrData.Execute)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string type = 1;
  if (this->type().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->type());
  }

  // string sql = 2;
  if (this->sql().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->sql());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Execute::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SvrData.Execute)
  GOOGLE_DCHECK_NE(&from, this);
  const Execute* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Execute>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SvrData.Execute)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SvrData.Execute)
    MergeFrom(*source);
  }
}

void Execute::MergeFrom(const Execute& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SvrData.Execute)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.type().size() > 0) {

    type_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.type_);
  }
  if (from.sql().size() > 0) {

    sql_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sql_);
  }
}

void Execute::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SvrData.Execute)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Execute::CopyFrom(const Execute& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SvrData.Execute)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Execute::IsInitialized() const {
  return true;
}

void Execute::Swap(Execute* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Execute::InternalSwap(Execute* other) {
  using std::swap;
  type_.Swap(&other->type_);
  sql_.Swap(&other->sql_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Execute::GetMetadata() const {
  protobuf_DBServer_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DBServer_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void ExecuteRet::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ExecuteRet::kResFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ExecuteRet::ExecuteRet()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_DBServer_2eproto::InitDefaultsExecuteRet();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:SvrData.ExecuteRet)
}
ExecuteRet::ExecuteRet(const ExecuteRet& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  res_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.res().size() > 0) {
    res_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.res_);
  }
  // @@protoc_insertion_point(copy_constructor:SvrData.ExecuteRet)
}

void ExecuteRet::SharedCtor() {
  res_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _cached_size_ = 0;
}

ExecuteRet::~ExecuteRet() {
  // @@protoc_insertion_point(destructor:SvrData.ExecuteRet)
  SharedDtor();
}

void ExecuteRet::SharedDtor() {
  res_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ExecuteRet::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ExecuteRet::descriptor() {
  ::protobuf_DBServer_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DBServer_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ExecuteRet& ExecuteRet::default_instance() {
  ::protobuf_DBServer_2eproto::InitDefaultsExecuteRet();
  return *internal_default_instance();
}

ExecuteRet* ExecuteRet::New(::google::protobuf::Arena* arena) const {
  ExecuteRet* n = new ExecuteRet;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ExecuteRet::Clear() {
// @@protoc_insertion_point(message_clear_start:SvrData.ExecuteRet)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  res_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool ExecuteRet::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:SvrData.ExecuteRet)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string res = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_res()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->res().data(), static_cast<int>(this->res().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "SvrData.ExecuteRet.res"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:SvrData.ExecuteRet)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:SvrData.ExecuteRet)
  return false;
#undef DO_
}

void ExecuteRet::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:SvrData.ExecuteRet)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string res = 1;
  if (this->res().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->res().data(), static_cast<int>(this->res().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrData.ExecuteRet.res");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->res(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:SvrData.ExecuteRet)
}

::google::protobuf::uint8* ExecuteRet::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:SvrData.ExecuteRet)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string res = 1;
  if (this->res().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->res().data(), static_cast<int>(this->res().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "SvrData.ExecuteRet.res");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->res(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:SvrData.ExecuteRet)
  return target;
}

size_t ExecuteRet::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:SvrData.ExecuteRet)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string res = 1;
  if (this->res().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->res());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ExecuteRet::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:SvrData.ExecuteRet)
  GOOGLE_DCHECK_NE(&from, this);
  const ExecuteRet* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ExecuteRet>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:SvrData.ExecuteRet)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:SvrData.ExecuteRet)
    MergeFrom(*source);
  }
}

void ExecuteRet::MergeFrom(const ExecuteRet& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:SvrData.ExecuteRet)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.res().size() > 0) {

    res_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.res_);
  }
}

void ExecuteRet::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:SvrData.ExecuteRet)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ExecuteRet::CopyFrom(const ExecuteRet& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SvrData.ExecuteRet)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ExecuteRet::IsInitialized() const {
  return true;
}

void ExecuteRet::Swap(ExecuteRet* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ExecuteRet::InternalSwap(ExecuteRet* other) {
  using std::swap;
  res_.Swap(&other->res_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ExecuteRet::GetMetadata() const {
  protobuf_DBServer_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DBServer_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace SvrData

// @@protoc_insertion_point(global_scope)