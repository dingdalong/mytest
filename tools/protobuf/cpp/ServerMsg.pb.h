// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ServerMsg.proto

#ifndef PROTOBUF_ServerMsg_2eproto__INCLUDED
#define PROTOBUF_ServerMsg_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_ServerMsg_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsPingImpl();
void InitDefaultsPing();
void InitDefaultsServerRegisterImpl();
void InitDefaultsServerRegister();
void InitDefaultsServerRegisterRetImpl();
void InitDefaultsServerRegisterRet();
void InitDefaultsAddNewClientImpl();
void InitDefaultsAddNewClient();
void InitDefaultsClientTokenImpl();
void InitDefaultsClientToken();
inline void InitDefaults() {
  InitDefaultsPing();
  InitDefaultsServerRegister();
  InitDefaultsServerRegisterRet();
  InitDefaultsAddNewClient();
  InitDefaultsClientToken();
}
}  // namespace protobuf_ServerMsg_2eproto
namespace svrData {
class AddNewClient;
class AddNewClientDefaultTypeInternal;
extern AddNewClientDefaultTypeInternal _AddNewClient_default_instance_;
class ClientToken;
class ClientTokenDefaultTypeInternal;
extern ClientTokenDefaultTypeInternal _ClientToken_default_instance_;
class Ping;
class PingDefaultTypeInternal;
extern PingDefaultTypeInternal _Ping_default_instance_;
class ServerRegister;
class ServerRegisterDefaultTypeInternal;
extern ServerRegisterDefaultTypeInternal _ServerRegister_default_instance_;
class ServerRegisterRet;
class ServerRegisterRetDefaultTypeInternal;
extern ServerRegisterRetDefaultTypeInternal _ServerRegisterRet_default_instance_;
}  // namespace svrData
namespace svrData {

enum ServerRegisterRet_EC {
  ServerRegisterRet_EC_EC_OTHER = 0,
  ServerRegisterRet_EC_EC_SUCC = 1,
  ServerRegisterRet_EC_EC_SERVER_ID_EXIST = 2,
  ServerRegisterRet_EC_EC_TO_CONNECT_ID_NOT_EQUAL = 3,
  ServerRegisterRet_EC_ServerRegisterRet_EC_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ServerRegisterRet_EC_ServerRegisterRet_EC_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ServerRegisterRet_EC_IsValid(int value);
const ServerRegisterRet_EC ServerRegisterRet_EC_EC_MIN = ServerRegisterRet_EC_EC_OTHER;
const ServerRegisterRet_EC ServerRegisterRet_EC_EC_MAX = ServerRegisterRet_EC_EC_TO_CONNECT_ID_NOT_EQUAL;
const int ServerRegisterRet_EC_EC_ARRAYSIZE = ServerRegisterRet_EC_EC_MAX + 1;

const ::google::protobuf::EnumDescriptor* ServerRegisterRet_EC_descriptor();
inline const ::std::string& ServerRegisterRet_EC_Name(ServerRegisterRet_EC value) {
  return ::google::protobuf::internal::NameOfEnum(
    ServerRegisterRet_EC_descriptor(), value);
}
inline bool ServerRegisterRet_EC_Parse(
    const ::std::string& name, ServerRegisterRet_EC* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ServerRegisterRet_EC>(
    ServerRegisterRet_EC_descriptor(), name, value);
}
// ===================================================================

class Ping : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:svrData.Ping) */ {
 public:
  Ping();
  virtual ~Ping();

  Ping(const Ping& from);

  inline Ping& operator=(const Ping& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Ping(Ping&& from) noexcept
    : Ping() {
    *this = ::std::move(from);
  }

  inline Ping& operator=(Ping&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Ping& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Ping* internal_default_instance() {
    return reinterpret_cast<const Ping*>(
               &_Ping_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Ping* other);
  friend void swap(Ping& a, Ping& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Ping* New() const PROTOBUF_FINAL { return New(NULL); }

  Ping* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Ping& from);
  void MergeFrom(const Ping& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Ping* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:svrData.Ping)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct ::protobuf_ServerMsg_2eproto::TableStruct;
  friend void ::protobuf_ServerMsg_2eproto::InitDefaultsPingImpl();
};
// -------------------------------------------------------------------

class ServerRegister : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:svrData.ServerRegister) */ {
 public:
  ServerRegister();
  virtual ~ServerRegister();

  ServerRegister(const ServerRegister& from);

  inline ServerRegister& operator=(const ServerRegister& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ServerRegister(ServerRegister&& from) noexcept
    : ServerRegister() {
    *this = ::std::move(from);
  }

  inline ServerRegister& operator=(ServerRegister&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ServerRegister& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ServerRegister* internal_default_instance() {
    return reinterpret_cast<const ServerRegister*>(
               &_ServerRegister_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ServerRegister* other);
  friend void swap(ServerRegister& a, ServerRegister& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ServerRegister* New() const PROTOBUF_FINAL { return New(NULL); }

  ServerRegister* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ServerRegister& from);
  void MergeFrom(const ServerRegister& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ServerRegister* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 nServerID = 1;
  void clear_nserverid();
  static const int kNServerIDFieldNumber = 1;
  ::google::protobuf::int32 nserverid() const;
  void set_nserverid(::google::protobuf::int32 value);

  // int32 nServerType = 2;
  void clear_nservertype();
  static const int kNServerTypeFieldNumber = 2;
  ::google::protobuf::int32 nservertype() const;
  void set_nservertype(::google::protobuf::int32 value);

  // int32 nConnectID = 3;
  void clear_nconnectid();
  static const int kNConnectIDFieldNumber = 3;
  ::google::protobuf::int32 nconnectid() const;
  void set_nconnectid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:svrData.ServerRegister)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 nserverid_;
  ::google::protobuf::int32 nservertype_;
  ::google::protobuf::int32 nconnectid_;
  mutable int _cached_size_;
  friend struct ::protobuf_ServerMsg_2eproto::TableStruct;
  friend void ::protobuf_ServerMsg_2eproto::InitDefaultsServerRegisterImpl();
};
// -------------------------------------------------------------------

class ServerRegisterRet : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:svrData.ServerRegisterRet) */ {
 public:
  ServerRegisterRet();
  virtual ~ServerRegisterRet();

  ServerRegisterRet(const ServerRegisterRet& from);

  inline ServerRegisterRet& operator=(const ServerRegisterRet& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ServerRegisterRet(ServerRegisterRet&& from) noexcept
    : ServerRegisterRet() {
    *this = ::std::move(from);
  }

  inline ServerRegisterRet& operator=(ServerRegisterRet&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ServerRegisterRet& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ServerRegisterRet* internal_default_instance() {
    return reinterpret_cast<const ServerRegisterRet*>(
               &_ServerRegisterRet_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(ServerRegisterRet* other);
  friend void swap(ServerRegisterRet& a, ServerRegisterRet& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ServerRegisterRet* New() const PROTOBUF_FINAL { return New(NULL); }

  ServerRegisterRet* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ServerRegisterRet& from);
  void MergeFrom(const ServerRegisterRet& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ServerRegisterRet* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef ServerRegisterRet_EC EC;
  static const EC EC_OTHER =
    ServerRegisterRet_EC_EC_OTHER;
  static const EC EC_SUCC =
    ServerRegisterRet_EC_EC_SUCC;
  static const EC EC_SERVER_ID_EXIST =
    ServerRegisterRet_EC_EC_SERVER_ID_EXIST;
  static const EC EC_TO_CONNECT_ID_NOT_EQUAL =
    ServerRegisterRet_EC_EC_TO_CONNECT_ID_NOT_EQUAL;
  static inline bool EC_IsValid(int value) {
    return ServerRegisterRet_EC_IsValid(value);
  }
  static const EC EC_MIN =
    ServerRegisterRet_EC_EC_MIN;
  static const EC EC_MAX =
    ServerRegisterRet_EC_EC_MAX;
  static const int EC_ARRAYSIZE =
    ServerRegisterRet_EC_EC_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  EC_descriptor() {
    return ServerRegisterRet_EC_descriptor();
  }
  static inline const ::std::string& EC_Name(EC value) {
    return ServerRegisterRet_EC_Name(value);
  }
  static inline bool EC_Parse(const ::std::string& name,
      EC* value) {
    return ServerRegisterRet_EC_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // int32 nRetCode = 1;
  void clear_nretcode();
  static const int kNRetCodeFieldNumber = 1;
  ::google::protobuf::int32 nretcode() const;
  void set_nretcode(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:svrData.ServerRegisterRet)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 nretcode_;
  mutable int _cached_size_;
  friend struct ::protobuf_ServerMsg_2eproto::TableStruct;
  friend void ::protobuf_ServerMsg_2eproto::InitDefaultsServerRegisterRetImpl();
};
// -------------------------------------------------------------------

class AddNewClient : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:svrData.AddNewClient) */ {
 public:
  AddNewClient();
  virtual ~AddNewClient();

  AddNewClient(const AddNewClient& from);

  inline AddNewClient& operator=(const AddNewClient& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AddNewClient(AddNewClient&& from) noexcept
    : AddNewClient() {
    *this = ::std::move(from);
  }

  inline AddNewClient& operator=(AddNewClient&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AddNewClient& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AddNewClient* internal_default_instance() {
    return reinterpret_cast<const AddNewClient*>(
               &_AddNewClient_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(AddNewClient* other);
  friend void swap(AddNewClient& a, AddNewClient& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AddNewClient* New() const PROTOBUF_FINAL { return New(NULL); }

  AddNewClient* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const AddNewClient& from);
  void MergeFrom(const AddNewClient& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(AddNewClient* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 nClientCountNow = 1;
  void clear_nclientcountnow();
  static const int kNClientCountNowFieldNumber = 1;
  ::google::protobuf::int32 nclientcountnow() const;
  void set_nclientcountnow(::google::protobuf::int32 value);

  // int32 nClientCountMax = 2;
  void clear_nclientcountmax();
  static const int kNClientCountMaxFieldNumber = 2;
  ::google::protobuf::int32 nclientcountmax() const;
  void set_nclientcountmax(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:svrData.AddNewClient)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 nclientcountnow_;
  ::google::protobuf::int32 nclientcountmax_;
  mutable int _cached_size_;
  friend struct ::protobuf_ServerMsg_2eproto::TableStruct;
  friend void ::protobuf_ServerMsg_2eproto::InitDefaultsAddNewClientImpl();
};
// -------------------------------------------------------------------

class ClientToken : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:svrData.ClientToken) */ {
 public:
  ClientToken();
  virtual ~ClientToken();

  ClientToken(const ClientToken& from);

  inline ClientToken& operator=(const ClientToken& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ClientToken(ClientToken&& from) noexcept
    : ClientToken() {
    *this = ::std::move(from);
  }

  inline ClientToken& operator=(ClientToken&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ClientToken& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ClientToken* internal_default_instance() {
    return reinterpret_cast<const ClientToken*>(
               &_ClientToken_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(ClientToken* other);
  friend void swap(ClientToken& a, ClientToken& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ClientToken* New() const PROTOBUF_FINAL { return New(NULL); }

  ClientToken* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ClientToken& from);
  void MergeFrom(const ClientToken& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ClientToken* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string sEtoken = 1;
  void clear_setoken();
  static const int kSEtokenFieldNumber = 1;
  const ::std::string& setoken() const;
  void set_setoken(const ::std::string& value);
  #if LANG_CXX11
  void set_setoken(::std::string&& value);
  #endif
  void set_setoken(const char* value);
  void set_setoken(const char* value, size_t size);
  ::std::string* mutable_setoken();
  ::std::string* release_setoken();
  void set_allocated_setoken(::std::string* setoken);

  // bytes sSecret = 2;
  void clear_ssecret();
  static const int kSSecretFieldNumber = 2;
  const ::std::string& ssecret() const;
  void set_ssecret(const ::std::string& value);
  #if LANG_CXX11
  void set_ssecret(::std::string&& value);
  #endif
  void set_ssecret(const char* value);
  void set_ssecret(const void* value, size_t size);
  ::std::string* mutable_ssecret();
  ::std::string* release_ssecret();
  void set_allocated_ssecret(::std::string* ssecret);

  // @@protoc_insertion_point(class_scope:svrData.ClientToken)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr setoken_;
  ::google::protobuf::internal::ArenaStringPtr ssecret_;
  mutable int _cached_size_;
  friend struct ::protobuf_ServerMsg_2eproto::TableStruct;
  friend void ::protobuf_ServerMsg_2eproto::InitDefaultsClientTokenImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Ping

// -------------------------------------------------------------------

// ServerRegister

// int32 nServerID = 1;
inline void ServerRegister::clear_nserverid() {
  nserverid_ = 0;
}
inline ::google::protobuf::int32 ServerRegister::nserverid() const {
  // @@protoc_insertion_point(field_get:svrData.ServerRegister.nServerID)
  return nserverid_;
}
inline void ServerRegister::set_nserverid(::google::protobuf::int32 value) {
  
  nserverid_ = value;
  // @@protoc_insertion_point(field_set:svrData.ServerRegister.nServerID)
}

// int32 nServerType = 2;
inline void ServerRegister::clear_nservertype() {
  nservertype_ = 0;
}
inline ::google::protobuf::int32 ServerRegister::nservertype() const {
  // @@protoc_insertion_point(field_get:svrData.ServerRegister.nServerType)
  return nservertype_;
}
inline void ServerRegister::set_nservertype(::google::protobuf::int32 value) {
  
  nservertype_ = value;
  // @@protoc_insertion_point(field_set:svrData.ServerRegister.nServerType)
}

// int32 nConnectID = 3;
inline void ServerRegister::clear_nconnectid() {
  nconnectid_ = 0;
}
inline ::google::protobuf::int32 ServerRegister::nconnectid() const {
  // @@protoc_insertion_point(field_get:svrData.ServerRegister.nConnectID)
  return nconnectid_;
}
inline void ServerRegister::set_nconnectid(::google::protobuf::int32 value) {
  
  nconnectid_ = value;
  // @@protoc_insertion_point(field_set:svrData.ServerRegister.nConnectID)
}

// -------------------------------------------------------------------

// ServerRegisterRet

// int32 nRetCode = 1;
inline void ServerRegisterRet::clear_nretcode() {
  nretcode_ = 0;
}
inline ::google::protobuf::int32 ServerRegisterRet::nretcode() const {
  // @@protoc_insertion_point(field_get:svrData.ServerRegisterRet.nRetCode)
  return nretcode_;
}
inline void ServerRegisterRet::set_nretcode(::google::protobuf::int32 value) {
  
  nretcode_ = value;
  // @@protoc_insertion_point(field_set:svrData.ServerRegisterRet.nRetCode)
}

// -------------------------------------------------------------------

// AddNewClient

// int32 nClientCountNow = 1;
inline void AddNewClient::clear_nclientcountnow() {
  nclientcountnow_ = 0;
}
inline ::google::protobuf::int32 AddNewClient::nclientcountnow() const {
  // @@protoc_insertion_point(field_get:svrData.AddNewClient.nClientCountNow)
  return nclientcountnow_;
}
inline void AddNewClient::set_nclientcountnow(::google::protobuf::int32 value) {
  
  nclientcountnow_ = value;
  // @@protoc_insertion_point(field_set:svrData.AddNewClient.nClientCountNow)
}

// int32 nClientCountMax = 2;
inline void AddNewClient::clear_nclientcountmax() {
  nclientcountmax_ = 0;
}
inline ::google::protobuf::int32 AddNewClient::nclientcountmax() const {
  // @@protoc_insertion_point(field_get:svrData.AddNewClient.nClientCountMax)
  return nclientcountmax_;
}
inline void AddNewClient::set_nclientcountmax(::google::protobuf::int32 value) {
  
  nclientcountmax_ = value;
  // @@protoc_insertion_point(field_set:svrData.AddNewClient.nClientCountMax)
}

// -------------------------------------------------------------------

// ClientToken

// string sEtoken = 1;
inline void ClientToken::clear_setoken() {
  setoken_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ClientToken::setoken() const {
  // @@protoc_insertion_point(field_get:svrData.ClientToken.sEtoken)
  return setoken_.GetNoArena();
}
inline void ClientToken::set_setoken(const ::std::string& value) {
  
  setoken_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:svrData.ClientToken.sEtoken)
}
#if LANG_CXX11
inline void ClientToken::set_setoken(::std::string&& value) {
  
  setoken_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:svrData.ClientToken.sEtoken)
}
#endif
inline void ClientToken::set_setoken(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  setoken_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:svrData.ClientToken.sEtoken)
}
inline void ClientToken::set_setoken(const char* value, size_t size) {
  
  setoken_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:svrData.ClientToken.sEtoken)
}
inline ::std::string* ClientToken::mutable_setoken() {
  
  // @@protoc_insertion_point(field_mutable:svrData.ClientToken.sEtoken)
  return setoken_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ClientToken::release_setoken() {
  // @@protoc_insertion_point(field_release:svrData.ClientToken.sEtoken)
  
  return setoken_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ClientToken::set_allocated_setoken(::std::string* setoken) {
  if (setoken != NULL) {
    
  } else {
    
  }
  setoken_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), setoken);
  // @@protoc_insertion_point(field_set_allocated:svrData.ClientToken.sEtoken)
}

// bytes sSecret = 2;
inline void ClientToken::clear_ssecret() {
  ssecret_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ClientToken::ssecret() const {
  // @@protoc_insertion_point(field_get:svrData.ClientToken.sSecret)
  return ssecret_.GetNoArena();
}
inline void ClientToken::set_ssecret(const ::std::string& value) {
  
  ssecret_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:svrData.ClientToken.sSecret)
}
#if LANG_CXX11
inline void ClientToken::set_ssecret(::std::string&& value) {
  
  ssecret_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:svrData.ClientToken.sSecret)
}
#endif
inline void ClientToken::set_ssecret(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  ssecret_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:svrData.ClientToken.sSecret)
}
inline void ClientToken::set_ssecret(const void* value, size_t size) {
  
  ssecret_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:svrData.ClientToken.sSecret)
}
inline ::std::string* ClientToken::mutable_ssecret() {
  
  // @@protoc_insertion_point(field_mutable:svrData.ClientToken.sSecret)
  return ssecret_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ClientToken::release_ssecret() {
  // @@protoc_insertion_point(field_release:svrData.ClientToken.sSecret)
  
  return ssecret_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ClientToken::set_allocated_ssecret(::std::string* ssecret) {
  if (ssecret != NULL) {
    
  } else {
    
  }
  ssecret_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ssecret);
  // @@protoc_insertion_point(field_set_allocated:svrData.ClientToken.sSecret)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace svrData

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::svrData::ServerRegisterRet_EC> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::svrData::ServerRegisterRet_EC>() {
  return ::svrData::ServerRegisterRet_EC_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ServerMsg_2eproto__INCLUDED
