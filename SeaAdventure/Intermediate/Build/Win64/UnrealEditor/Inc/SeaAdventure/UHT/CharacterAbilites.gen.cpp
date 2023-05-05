// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SeaAdventure/CharacterAbilites.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterAbilites() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	SEAADVENTURE_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	SEAADVENTURE_API UClass* Z_Construct_UClass_ACharacterAbilites();
	SEAADVENTURE_API UClass* Z_Construct_UClass_ACharacterAbilites_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SeaAdventure();
// End Cross Module References
	void ACharacterAbilites::StaticRegisterNativesACharacterAbilites()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACharacterAbilites);
	UClass* Z_Construct_UClass_ACharacterAbilites_NoRegister()
	{
		return ACharacterAbilites::StaticClass();
	}
	struct Z_Construct_UClass_ACharacterAbilites_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MuzzlePoint_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MuzzlePoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShootAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ShootAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DashAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DashAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BulletClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_BulletClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACharacterAbilites_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_SeaAdventure,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACharacterAbilites_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CharacterAbilites.h" },
		{ "ModuleRelativePath", "CharacterAbilites.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_MuzzlePoint_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CharacterAbilites.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_MuzzlePoint = { "MuzzlePoint", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ACharacterAbilites, MuzzlePoint), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_MuzzlePoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_MuzzlePoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** MappingContext */" },
		{ "ModuleRelativePath", "CharacterAbilites.h" },
		{ "ToolTip", "MappingContext" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ACharacterAbilites, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DefaultMappingContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DefaultMappingContext_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_ShootAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Move Input Action */" },
		{ "ModuleRelativePath", "CharacterAbilites.h" },
		{ "ToolTip", "Move Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_ShootAction = { "ShootAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ACharacterAbilites, ShootAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_ShootAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_ShootAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DashAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Release Input Action */" },
		{ "ModuleRelativePath", "CharacterAbilites.h" },
		{ "ToolTip", "Release Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DashAction = { "DashAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ACharacterAbilites, DashAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DashAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DashAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_BulletClass_MetaData[] = {
		{ "Category", "Gun" },
		{ "ModuleRelativePath", "CharacterAbilites.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_BulletClass = { "BulletClass", nullptr, (EPropertyFlags)0x0024080000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ACharacterAbilites, BulletClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ABullet_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_BulletClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_BulletClass_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACharacterAbilites_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_MuzzlePoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_ShootAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_DashAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACharacterAbilites_Statics::NewProp_BulletClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACharacterAbilites_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACharacterAbilites>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACharacterAbilites_Statics::ClassParams = {
		&ACharacterAbilites::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACharacterAbilites_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterAbilites_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACharacterAbilites_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACharacterAbilites_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACharacterAbilites()
	{
		if (!Z_Registration_Info_UClass_ACharacterAbilites.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACharacterAbilites.OuterSingleton, Z_Construct_UClass_ACharacterAbilites_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACharacterAbilites.OuterSingleton;
	}
	template<> SEAADVENTURE_API UClass* StaticClass<ACharacterAbilites>()
	{
		return ACharacterAbilites::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACharacterAbilites);
	ACharacterAbilites::~ACharacterAbilites() {}
	struct Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_CharacterAbilites_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_CharacterAbilites_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACharacterAbilites, ACharacterAbilites::StaticClass, TEXT("ACharacterAbilites"), &Z_Registration_Info_UClass_ACharacterAbilites, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACharacterAbilites), 798500275U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_CharacterAbilites_h_2327968691(TEXT("/Script/SeaAdventure"),
		Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_CharacterAbilites_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_CharacterAbilites_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
