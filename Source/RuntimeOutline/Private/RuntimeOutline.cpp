// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeOutline.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"

#define LOCTEXT_NAMESPACE "FRuntimeOutlineModule"

void FRuntimeOutlineModule::StartupModule()
{	
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("RuntimeOutline"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/RuntimeOutline/Shaders"), PluginShaderDir);
}

void FRuntimeOutlineModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRuntimeOutlineModule, RuntimeOutline)