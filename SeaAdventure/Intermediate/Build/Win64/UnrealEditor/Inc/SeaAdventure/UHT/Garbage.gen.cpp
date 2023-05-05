// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SeaAdventure/Garbage.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGarbage() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	SEAADVENTURE_API UClass* Z_Construct_UClass_AGarbage();
	SEAADVENTURE_API UClass* Z_Construct_UClass_AGarbage_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SeaAdventure();
// End Cross Module References
	void AGarbage::StaticRegisterNativesAGarbage()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGarbage);
	UClass* Z_Construct_UClass_AGarbage_NoRegister()
	{
		return AGarbage::StaticClass();
	}
	struct Z_Construct_UClass_AGarbage_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Collider_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Collider;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGarbage_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SeaAdventure,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGarbage_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Garbage.h" },
		{ "ModuleRelativePath", "Garbage.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGarbage_Statics::NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Garbage.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGarbage_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x001000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AGarbage, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGarbage_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGarbage_Statics::NewProp_Mesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGarbage_Statics::NewProp_Collider_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Garbage.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGarbage_Statics::NewProp_Collider = { "Collider", nullptr, (EPropertyFlags)0x001000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AGarbage, Collider), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGarbage_Statics::NewProp_Collider_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGarbage_Statics::NewProp_Collider_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGarbage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGarbage_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGarbage_Statics::NewProp_Collider,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGarbage_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGarbage>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGarbage_Statics::ClassParams = {
		&AGarbage::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGarbage_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGarbage_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGarbage_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGarbage_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGarbage()
	{
		if (!Z_Registration_Info_UClass_AGarbage.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGarbage.OuterSingleton, Z_Construct_UClass_AGarbage_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGarbage.OuterSingleton;
	}
	template<> SEAADVENTURE_API UClass* StaticClass<AGarbage>()
	{
		return AGarbage::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGarbage);
	AGarbage::~AGarbage() {}
	struct Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_Garbage_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_Garbage_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGarbage, AGarbage::StaticClass, TEXT("AGarbage"), &Z_Registration_Info_UClass_AGarbage, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGarbage), 3864518425U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_Garbage_h_170323072(TEXT("/Script/SeaAdventure"),
		Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_Garbage_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SeaAdventure_Source_SeaAdventure_Garbage_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
