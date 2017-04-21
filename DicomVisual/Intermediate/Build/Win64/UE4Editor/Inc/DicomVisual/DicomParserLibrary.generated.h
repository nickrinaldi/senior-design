// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FImageStruct;
#ifdef DICOMVISUAL_DicomParserLibrary_generated_h
#error "DicomParserLibrary.generated.h already included, missing '#pragma once' in DicomParserLibrary.h"
#endif
#define DICOMVISUAL_DicomParserLibrary_generated_h

#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_18_GENERATED_BODY \
	friend DICOMVISUAL_API class UScriptStruct* Z_Construct_UScriptStruct_FImageStruct(); \
	DICOMVISUAL_API static class UScriptStruct* StaticStruct();


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execgetPixels) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FImageStruct>*)Z_Param__Result=UDicomParserLibrary::getPixels(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHelloWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UDicomParserLibrary::HelloWorld(); \
		P_NATIVE_END; \
	}


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execgetPixels) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FImageStruct>*)Z_Param__Result=UDicomParserLibrary::getPixels(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHelloWorld) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UDicomParserLibrary::HelloWorld(); \
		P_NATIVE_END; \
	}


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUDicomParserLibrary(); \
	friend DICOMVISUAL_API class UClass* Z_Construct_UClass_UDicomParserLibrary(); \
	public: \
	DECLARE_CLASS(UDicomParserLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DicomVisual"), NO_API) \
	DECLARE_SERIALIZER(UDicomParserLibrary) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_INCLASS \
	private: \
	static void StaticRegisterNativesUDicomParserLibrary(); \
	friend DICOMVISUAL_API class UClass* Z_Construct_UClass_UDicomParserLibrary(); \
	public: \
	DECLARE_CLASS(UDicomParserLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DicomVisual"), NO_API) \
	DECLARE_SERIALIZER(UDicomParserLibrary) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDicomParserLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDicomParserLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDicomParserLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDicomParserLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDicomParserLibrary(UDicomParserLibrary&&); \
	NO_API UDicomParserLibrary(const UDicomParserLibrary&); \
public:


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDicomParserLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDicomParserLibrary(UDicomParserLibrary&&); \
	NO_API UDicomParserLibrary(const UDicomParserLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDicomParserLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDicomParserLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDicomParserLibrary)


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_PRIVATE_PROPERTY_OFFSET
#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_27_PROLOG
#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_PRIVATE_PROPERTY_OFFSET \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_RPC_WRAPPERS \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_INCLASS \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_PRIVATE_PROPERTY_OFFSET \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_INCLASS_NO_PURE_DECLS \
	DicomVisual_Source_DicomVisual_DicomParserLibrary_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DicomVisual_Source_DicomVisual_DicomParserLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
