// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: packet.proto

#ifndef PROTOBUF_packet_2eproto__INCLUDED
#define PROTOBUF_packet_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_packet_2eproto {
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
void InitDefaultsVoidImpl();
void InitDefaultsVoid();
void InitDefaultsBoolResultImpl();
void InitDefaultsBoolResult();
void InitDefaultsSummonerNameImpl();
void InitDefaultsSummonerName();
void InitDefaultsCurrentGameImpl();
void InitDefaultsCurrentGame();
void InitDefaultsSummonerInfoImpl();
void InitDefaultsSummonerInfo();
inline void InitDefaults() {
  InitDefaultsVoid();
  InitDefaultsBoolResult();
  InitDefaultsSummonerName();
  InitDefaultsCurrentGame();
  InitDefaultsSummonerInfo();
}
}  // namespace protobuf_packet_2eproto
class BoolResult;
class BoolResultDefaultTypeInternal;
extern BoolResultDefaultTypeInternal _BoolResult_default_instance_;
class CurrentGame;
class CurrentGameDefaultTypeInternal;
extern CurrentGameDefaultTypeInternal _CurrentGame_default_instance_;
class SummonerInfo;
class SummonerInfoDefaultTypeInternal;
extern SummonerInfoDefaultTypeInternal _SummonerInfo_default_instance_;
class SummonerName;
class SummonerNameDefaultTypeInternal;
extern SummonerNameDefaultTypeInternal _SummonerName_default_instance_;
class Void;
class VoidDefaultTypeInternal;
extern VoidDefaultTypeInternal _Void_default_instance_;

// ===================================================================

class Void : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Void) */ {
 public:
  Void();
  virtual ~Void();

  Void(const Void& from);

  inline Void& operator=(const Void& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Void(Void&& from) noexcept
    : Void() {
    *this = ::std::move(from);
  }

  inline Void& operator=(Void&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Void& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Void* internal_default_instance() {
    return reinterpret_cast<const Void*>(
               &_Void_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Void* other);
  friend void swap(Void& a, Void& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Void* New() const PROTOBUF_FINAL { return New(NULL); }

  Void* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Void& from);
  void MergeFrom(const Void& from);
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
  void InternalSwap(Void* other);
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

  // @@protoc_insertion_point(class_scope:Void)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  mutable int _cached_size_;
  friend struct ::protobuf_packet_2eproto::TableStruct;
  friend void ::protobuf_packet_2eproto::InitDefaultsVoidImpl();
};
// -------------------------------------------------------------------

class BoolResult : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:BoolResult) */ {
 public:
  BoolResult();
  virtual ~BoolResult();

  BoolResult(const BoolResult& from);

  inline BoolResult& operator=(const BoolResult& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BoolResult(BoolResult&& from) noexcept
    : BoolResult() {
    *this = ::std::move(from);
  }

  inline BoolResult& operator=(BoolResult&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const BoolResult& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BoolResult* internal_default_instance() {
    return reinterpret_cast<const BoolResult*>(
               &_BoolResult_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(BoolResult* other);
  friend void swap(BoolResult& a, BoolResult& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BoolResult* New() const PROTOBUF_FINAL { return New(NULL); }

  BoolResult* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const BoolResult& from);
  void MergeFrom(const BoolResult& from);
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
  void InternalSwap(BoolResult* other);
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

  // bool result = 1;
  void clear_result();
  static const int kResultFieldNumber = 1;
  bool result() const;
  void set_result(bool value);

  // @@protoc_insertion_point(class_scope:BoolResult)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool result_;
  mutable int _cached_size_;
  friend struct ::protobuf_packet_2eproto::TableStruct;
  friend void ::protobuf_packet_2eproto::InitDefaultsBoolResultImpl();
};
// -------------------------------------------------------------------

class SummonerName : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SummonerName) */ {
 public:
  SummonerName();
  virtual ~SummonerName();

  SummonerName(const SummonerName& from);

  inline SummonerName& operator=(const SummonerName& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SummonerName(SummonerName&& from) noexcept
    : SummonerName() {
    *this = ::std::move(from);
  }

  inline SummonerName& operator=(SummonerName&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SummonerName& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SummonerName* internal_default_instance() {
    return reinterpret_cast<const SummonerName*>(
               &_SummonerName_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(SummonerName* other);
  friend void swap(SummonerName& a, SummonerName& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SummonerName* New() const PROTOBUF_FINAL { return New(NULL); }

  SummonerName* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SummonerName& from);
  void MergeFrom(const SummonerName& from);
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
  void InternalSwap(SummonerName* other);
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

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // @@protoc_insertion_point(class_scope:SummonerName)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  mutable int _cached_size_;
  friend struct ::protobuf_packet_2eproto::TableStruct;
  friend void ::protobuf_packet_2eproto::InitDefaultsSummonerNameImpl();
};
// -------------------------------------------------------------------

class CurrentGame : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CurrentGame) */ {
 public:
  CurrentGame();
  virtual ~CurrentGame();

  CurrentGame(const CurrentGame& from);

  inline CurrentGame& operator=(const CurrentGame& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CurrentGame(CurrentGame&& from) noexcept
    : CurrentGame() {
    *this = ::std::move(from);
  }

  inline CurrentGame& operator=(CurrentGame&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CurrentGame& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CurrentGame* internal_default_instance() {
    return reinterpret_cast<const CurrentGame*>(
               &_CurrentGame_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(CurrentGame* other);
  friend void swap(CurrentGame& a, CurrentGame& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CurrentGame* New() const PROTOBUF_FINAL { return New(NULL); }

  CurrentGame* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CurrentGame& from);
  void MergeFrom(const CurrentGame& from);
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
  void InternalSwap(CurrentGame* other);
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

  // string val = 1;
  void clear_val();
  static const int kValFieldNumber = 1;
  const ::std::string& val() const;
  void set_val(const ::std::string& value);
  #if LANG_CXX11
  void set_val(::std::string&& value);
  #endif
  void set_val(const char* value);
  void set_val(const char* value, size_t size);
  ::std::string* mutable_val();
  ::std::string* release_val();
  void set_allocated_val(::std::string* val);

  // @@protoc_insertion_point(class_scope:CurrentGame)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr val_;
  mutable int _cached_size_;
  friend struct ::protobuf_packet_2eproto::TableStruct;
  friend void ::protobuf_packet_2eproto::InitDefaultsCurrentGameImpl();
};
// -------------------------------------------------------------------

class SummonerInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:SummonerInfo) */ {
 public:
  SummonerInfo();
  virtual ~SummonerInfo();

  SummonerInfo(const SummonerInfo& from);

  inline SummonerInfo& operator=(const SummonerInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SummonerInfo(SummonerInfo&& from) noexcept
    : SummonerInfo() {
    *this = ::std::move(from);
  }

  inline SummonerInfo& operator=(SummonerInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SummonerInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SummonerInfo* internal_default_instance() {
    return reinterpret_cast<const SummonerInfo*>(
               &_SummonerInfo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(SummonerInfo* other);
  friend void swap(SummonerInfo& a, SummonerInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SummonerInfo* New() const PROTOBUF_FINAL { return New(NULL); }

  SummonerInfo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const SummonerInfo& from);
  void MergeFrom(const SummonerInfo& from);
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
  void InternalSwap(SummonerInfo* other);
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

  // string val = 1;
  void clear_val();
  static const int kValFieldNumber = 1;
  const ::std::string& val() const;
  void set_val(const ::std::string& value);
  #if LANG_CXX11
  void set_val(::std::string&& value);
  #endif
  void set_val(const char* value);
  void set_val(const char* value, size_t size);
  ::std::string* mutable_val();
  ::std::string* release_val();
  void set_allocated_val(::std::string* val);

  // @@protoc_insertion_point(class_scope:SummonerInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr val_;
  mutable int _cached_size_;
  friend struct ::protobuf_packet_2eproto::TableStruct;
  friend void ::protobuf_packet_2eproto::InitDefaultsSummonerInfoImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Void

// -------------------------------------------------------------------

// BoolResult

// bool result = 1;
inline void BoolResult::clear_result() {
  result_ = false;
}
inline bool BoolResult::result() const {
  // @@protoc_insertion_point(field_get:BoolResult.result)
  return result_;
}
inline void BoolResult::set_result(bool value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:BoolResult.result)
}

// -------------------------------------------------------------------

// SummonerName

// string name = 1;
inline void SummonerName::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SummonerName::name() const {
  // @@protoc_insertion_point(field_get:SummonerName.name)
  return name_.GetNoArena();
}
inline void SummonerName::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SummonerName.name)
}
#if LANG_CXX11
inline void SummonerName::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:SummonerName.name)
}
#endif
inline void SummonerName::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SummonerName.name)
}
inline void SummonerName::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SummonerName.name)
}
inline ::std::string* SummonerName::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:SummonerName.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SummonerName::release_name() {
  // @@protoc_insertion_point(field_release:SummonerName.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SummonerName::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:SummonerName.name)
}

// -------------------------------------------------------------------

// CurrentGame

// string val = 1;
inline void CurrentGame::clear_val() {
  val_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& CurrentGame::val() const {
  // @@protoc_insertion_point(field_get:CurrentGame.val)
  return val_.GetNoArena();
}
inline void CurrentGame::set_val(const ::std::string& value) {
  
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CurrentGame.val)
}
#if LANG_CXX11
inline void CurrentGame::set_val(::std::string&& value) {
  
  val_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CurrentGame.val)
}
#endif
inline void CurrentGame::set_val(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CurrentGame.val)
}
inline void CurrentGame::set_val(const char* value, size_t size) {
  
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CurrentGame.val)
}
inline ::std::string* CurrentGame::mutable_val() {
  
  // @@protoc_insertion_point(field_mutable:CurrentGame.val)
  return val_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CurrentGame::release_val() {
  // @@protoc_insertion_point(field_release:CurrentGame.val)
  
  return val_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CurrentGame::set_allocated_val(::std::string* val) {
  if (val != NULL) {
    
  } else {
    
  }
  val_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), val);
  // @@protoc_insertion_point(field_set_allocated:CurrentGame.val)
}

// -------------------------------------------------------------------

// SummonerInfo

// string val = 1;
inline void SummonerInfo::clear_val() {
  val_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SummonerInfo::val() const {
  // @@protoc_insertion_point(field_get:SummonerInfo.val)
  return val_.GetNoArena();
}
inline void SummonerInfo::set_val(const ::std::string& value) {
  
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:SummonerInfo.val)
}
#if LANG_CXX11
inline void SummonerInfo::set_val(::std::string&& value) {
  
  val_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:SummonerInfo.val)
}
#endif
inline void SummonerInfo::set_val(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:SummonerInfo.val)
}
inline void SummonerInfo::set_val(const char* value, size_t size) {
  
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:SummonerInfo.val)
}
inline ::std::string* SummonerInfo::mutable_val() {
  
  // @@protoc_insertion_point(field_mutable:SummonerInfo.val)
  return val_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SummonerInfo::release_val() {
  // @@protoc_insertion_point(field_release:SummonerInfo.val)
  
  return val_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SummonerInfo::set_allocated_val(::std::string* val) {
  if (val != NULL) {
    
  } else {
    
  }
  val_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), val);
  // @@protoc_insertion_point(field_set_allocated:SummonerInfo.val)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_packet_2eproto__INCLUDED
