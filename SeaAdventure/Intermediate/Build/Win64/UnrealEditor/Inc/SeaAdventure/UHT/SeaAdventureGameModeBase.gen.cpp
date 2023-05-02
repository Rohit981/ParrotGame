// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SeaAdventure/SeaAdventureGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSeaAdventureGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	SEAADVENTURE_API UClass* Z_Construct_UClass_ASeaAdventureGameModeBase();
	SEAADVENTURE_API UClass* Z_Construct_UClass_ASeaAdventureGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SeaAdventure();
// End Cross Module References
	void ASeaAdventureGameModeBase::StaticRegisterNativesASeaAdventureGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASeaAdventureGameModeBase);
	UClass* Z_Construct_UClass_ASeaAdventureGameModeBase_NoRegister()
	{
		return ASeaAdventureGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ASeaAdventureGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASeaAdventureGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SeaAdventure,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASeaAdventureGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SeaAdventureGameModeBase.h" },
		{ "ModuleRelativePath", "SeaAdventureGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASeaAdventureGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASeaAdventureGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASeaAdventureGameModeBase_Statics::ClassParams = {
		&ASeaAdventureGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASeaAdventureGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASeaAdventureGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASeaAdventureGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ASeaAdventureGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASeaAdventureGameModeBase.OuterSingleton, Z_Construct_UClass_ASeaAdventureGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASeaAdventureGameModeBase.OuterSingleton;
	}
	template<> SEAADVENTURE_API UClass* StaticClass<ASeaAdventureGameModeBase>()
	{
		return ASeaAdventureGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASeaAdventureGameModeBase);
	ASeaAdventureGameModeBase::~ASeaAdventureGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_SeaAdventureGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_SeaAdventureGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASeaAdventureGameModeBase, ASeaAdventureGameModeBase::StaticClass, TEXT("ASeaAdventureGameModeBase"), &Z_Registration_Info_UClass_ASeaAdventureGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASeaAdventureGameModeBase), 2507843444U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_SeaAdventureGameModeBase_h_1550460669(TEXT("/Script/SeaAdventure"),
		Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_SeaAdventureGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_SeaAdventureGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
