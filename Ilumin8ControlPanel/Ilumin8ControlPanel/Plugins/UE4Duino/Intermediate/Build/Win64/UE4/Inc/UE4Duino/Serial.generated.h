// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ELineEnd : uint8;
class USerial;
#ifdef UE4DUINO_Serial_generated_h
#error "Serial.generated.h already included, missing '#pragma once' in Serial.h"
#endif
#define UE4DUINO_Serial_generated_h

#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_SPARSE_DATA
#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLineEndToStr) \
	{ \
		P_GET_ENUM(ELineEnd,Z_Param_LineEnd); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->LineEndToStr(ELineEnd(Z_Param_LineEnd)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBaud) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBaud(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPort) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPort(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsOpened) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsOpened(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFlush) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Flush(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteBytes) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_Buffer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteBytes(Z_Param_Buffer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteInt) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteInt(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPrintln) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Println(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPrint) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Print(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Limit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->ReadBytes(Z_Param_Limit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadByte) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->ReadByte(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadInt) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ReadInt(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadFloat) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->ReadFloat(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadln) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Readln(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadString) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ReadString(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClose) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Close(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpen) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BaudRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Open(Z_Param_Port,Z_Param_BaudRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloatToBytes) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Float); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=USerial::FloatToBytes(Z_Param_Out_Float); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToFloat) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_Bytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USerial::BytesToFloat(Z_Param_Bytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIntToBytes) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Int); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=USerial::IntToBytes(Z_Param_Out_Int); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToInt) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_Bytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=USerial::BytesToInt(Z_Param_Bytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenComPort) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bOpened); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BaudRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USerial**)Z_Param__Result=USerial::OpenComPort(Z_Param_Out_bOpened,Z_Param_Port,Z_Param_BaudRate); \
		P_NATIVE_END; \
	}


#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLineEndToStr) \
	{ \
		P_GET_ENUM(ELineEnd,Z_Param_LineEnd); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->LineEndToStr(ELineEnd(Z_Param_LineEnd)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBaud) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetBaud(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPort) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetPort(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsOpened) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsOpened(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFlush) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Flush(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteBytes) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_Buffer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteBytes(Z_Param_Buffer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteByte) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteByte(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteInt) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteInt(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execWriteFloat) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Value); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->WriteFloat(Z_Param_Value); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPrintln) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Println(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPrint) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_String); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Print(Z_Param_String); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadBytes) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Limit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->ReadBytes(Z_Param_Limit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadByte) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(uint8*)Z_Param__Result=P_THIS->ReadByte(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadInt) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->ReadInt(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadFloat) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->ReadFloat(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadln) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->Readln(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReadString) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bSuccess); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ReadString(Z_Param_Out_bSuccess); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execClose) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Close(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpen) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BaudRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->Open(Z_Param_Port,Z_Param_BaudRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFloatToBytes) \
	{ \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Float); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=USerial::FloatToBytes(Z_Param_Out_Float); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToFloat) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_Bytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USerial::BytesToFloat(Z_Param_Bytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIntToBytes) \
	{ \
		P_GET_PROPERTY_REF(UIntProperty,Z_Param_Out_Int); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=USerial::IntToBytes(Z_Param_Out_Int); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBytesToInt) \
	{ \
		P_GET_TARRAY(uint8,Z_Param_Bytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=USerial::BytesToInt(Z_Param_Bytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOpenComPort) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bOpened); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Port); \
		P_GET_PROPERTY(UIntProperty,Z_Param_BaudRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USerial**)Z_Param__Result=USerial::OpenComPort(Z_Param_Out_bOpened,Z_Param_Port,Z_Param_BaudRate); \
		P_NATIVE_END; \
	}


#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSerial(); \
	friend struct Z_Construct_UClass_USerial_Statics; \
public: \
	DECLARE_CLASS(USerial, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UE4Duino"), NO_API) \
	DECLARE_SERIALIZER(USerial)


#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_INCLASS \
private: \
	static void StaticRegisterNativesUSerial(); \
	friend struct Z_Construct_UClass_USerial_Statics; \
public: \
	DECLARE_CLASS(USerial, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UE4Duino"), NO_API) \
	DECLARE_SERIALIZER(USerial)


#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USerial(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USerial) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USerial); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USerial); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USerial(USerial&&); \
	NO_API USerial(const USerial&); \
public:


#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USerial(USerial&&); \
	NO_API USerial(const USerial&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USerial); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USerial); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USerial)


#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_PRIVATE_PROPERTY_OFFSET
#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_28_PROLOG
#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_PRIVATE_PROPERTY_OFFSET \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_SPARSE_DATA \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_RPC_WRAPPERS \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_INCLASS \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_PRIVATE_PROPERTY_OFFSET \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_SPARSE_DATA \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_INCLASS_NO_PURE_DECLS \
	A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UE4DUINO_API UClass* StaticClass<class USerial>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID A__Libraries_Documents_Dev_Unreal_Projects_UE4DuinoDev_Package_UE4Duino_HostProject_Plugins_UE4Duino_Source_UE4Duino_Public_Serial_h


#define FOREACH_ENUM_ELINEEND(op) \
	op(ELineEnd::rn) \
	op(ELineEnd::n) \
	op(ELineEnd::r) \
	op(ELineEnd::nr) 

enum class ELineEnd : uint8;
template<> UE4DUINO_API UEnum* StaticEnum<ELineEnd>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
