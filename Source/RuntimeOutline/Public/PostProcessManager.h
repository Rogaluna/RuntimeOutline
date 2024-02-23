// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PostProcessManager.generated.h"

class APostProcessVolume;

/**
 * 
 */
UCLASS()
class RUNTIMEOUTLINE_API UPostProcessManager : public UObject
{
	GENERATED_BODY()
	
public:
	static UPostProcessManager* GetInstance();

private:
	UPostProcessManager() {};

	static UPostProcessManager* SingletonInstance; 

	// 持有的PostProcessVolume指针  
	APostProcessVolume* PostProcessVolume;

	// 持有的后处理材质引用  
	UMaterialInterface* PostProcessMaterial;

private:
	bool LoadPostProcessMaterial();
	void CreatePostProcessVolume(UWorld* World, FVector Location);
};
