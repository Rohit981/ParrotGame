// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FishCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef SEAADVENTURE_FishCharacter_generated_h
#error "FishCharacter.generated.h already included, missing '#pragma once' in FishCharacter.h"
#endif
#define SEAADVENTURE_FishCharacter_generated_h

#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_SPARSE_DATA
#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_ACCESSORS
#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFishCharacter(); \
	friend struct Z_Construct_UClass_AFishCharacter_Statics; \
public: \
	DECLARE_CLASS(AFishCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SeaAdventure"), NO_API) \
	DECLARE_SERIALIZER(AFishCharacter)


#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAFishCharacter(); \
	friend struct Z_Construct_UClass_AFishCharacter_Statics; \
public: \
	DECLARE_CLASS(AFishCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SeaAdventure"), NO_API) \
	DECLARE_SERIALIZER(AFishCharacter)


#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFishCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFishCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFishCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFishCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFishCharacter(AFishCharacter&&); \
	NO_API AFishCharacter(const AFishCharacter&); \
public: \
	NO_API virtual ~AFishCharacter();


#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFishCharacter(AFishCharacter&&); \
	NO_API AFishCharacter(const AFishCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFishCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFishCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFishCharacter) \
	NO_API virtual ~AFishCharacter();


#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_11_PROLOG
#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_SPARSE_DATA \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_RPC_WRAPPERS \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_ACCESSORS \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_INCLASS \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_SPARSE_DATA \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_ACCESSORS \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_INCLASS_NO_PURE_DECLS \
	FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SEAADVENTURE_API UClass* StaticClass<class AFishCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
