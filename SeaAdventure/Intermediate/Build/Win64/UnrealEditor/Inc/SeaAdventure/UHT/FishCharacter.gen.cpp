// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SeaAdventure/FishCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFishCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	SEAADVENTURE_API UClass* Z_Construct_UClass_AFishCharacter();
	SEAADVENTURE_API UClass* Z_Construct_UClass_AFishCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SeaAdventure();
// End Cross Module References
	void AFishCharacter::StaticRegisterNativesAFishCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFishCharacter);
	UClass* Z_Construct_UClass_AFishCharacter_NoRegister()
	{
		return AFishCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AFishCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FishMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FishMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Learned_Shoot_MetaData[];
#endif
		static void NewProp_Learned_Shoot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Learned_Shoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Learned_DoubleJump_MetaData[];
#endif
		static void NewProp_Learned_DoubleJump_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Learned_DoubleJump;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Learned_Glide_MetaData[];
#endif
		static void NewProp_Learned_Glide_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Learned_Glide;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFishCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SeaAdventure,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FishCharacter.h" },
		{ "ModuleRelativePath", "FishCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "// Camera boom positioning the camera behind the character\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FishCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFishCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "// Follow camera \n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FishCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFishCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_FishMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "// Mapping Context\n" },
		{ "ModuleRelativePath", "FishCharacter.h" },
		{ "ToolTip", "Mapping Context" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_FishMappingContext = { "FishMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFishCharacter, FishMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_FishMappingContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_FishMappingContext_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "// Move Input Action\n" },
		{ "ModuleRelativePath", "FishCharacter.h" },
		{ "ToolTip", "Move Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFishCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_MoveAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_MoveAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "// Jump Input Action\n" },
		{ "ModuleRelativePath", "FishCharacter.h" },
		{ "ToolTip", "Jump Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AFishCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_JumpAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_JumpAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Shoot_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Ability" },
		{ "Comment", "// Abilities\n" },
		{ "ModuleRelativePath", "FishCharacter.h" },
		{ "ToolTip", "Abilities" },
	};
#endif
	void Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Shoot_SetBit(void* Obj)
	{
		((AFishCharacter*)Obj)->Learned_Shoot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Shoot = { "Learned_Shoot", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AFishCharacter), &Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Shoot_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Shoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Shoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_DoubleJump_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "FishCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_DoubleJump_SetBit(void* Obj)
	{
		((AFishCharacter*)Obj)->Learned_DoubleJump = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_DoubleJump = { "Learned_DoubleJump", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AFishCharacter), &Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_DoubleJump_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_DoubleJump_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_DoubleJump_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Glide_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "FishCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Glide_SetBit(void* Obj)
	{
		((AFishCharacter*)Obj)->Learned_Glide = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Glide = { "Learned_Glide", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AFishCharacter), &Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Glide_SetBit, METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Glide_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Glide_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFishCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_FishMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Shoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_DoubleJump,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFishCharacter_Statics::NewProp_Learned_Glide,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFishCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFishCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFishCharacter_Statics::ClassParams = {
		&AFishCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFishCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFishCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFishCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFishCharacter()
	{
		if (!Z_Registration_Info_UClass_AFishCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFishCharacter.OuterSingleton, Z_Construct_UClass_AFishCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFishCharacter.OuterSingleton;
	}
	template<> SEAADVENTURE_API UClass* StaticClass<AFishCharacter>()
	{
		return AFishCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFishCharacter);
	AFishCharacter::~AFishCharacter() {}
	struct Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFishCharacter, AFishCharacter::StaticClass, TEXT("AFishCharacter"), &Z_Registration_Info_UClass_AFishCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFishCharacter), 3163353701U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_4086078745(TEXT("/Script/SeaAdventure"),
		Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_FishCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
