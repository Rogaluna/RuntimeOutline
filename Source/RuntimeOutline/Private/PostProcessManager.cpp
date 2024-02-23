// Fill out your copyright notice in the Description page of Project Settings.


#include "PostProcessManager.h"
#include "Engine/PostProcessVolume.h"
#include "Kismet/KismetMathLibrary.h"  

UPostProcessManager* UPostProcessManager::SingletonInstance = nullptr;

UPostProcessManager* UPostProcessManager::GetInstance()
{
    if (!SingletonInstance)
    {
        SingletonInstance = NewObject<UPostProcessManager>();
        UWorld* World = GEngine->GetWorldFromContextObject(nullptr, EGetWorldErrorMode::ReturnNull);
        if (World)
        {
            SingletonInstance->CreatePostProcessVolume(World, FVector::ZeroVector);
        }
    }
    return SingletonInstance;
}

bool UPostProcessManager::LoadPostProcessMaterial()
{
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("/Script/Engine.MaterialInstanceConstant'/RuntimeOutline/PostProcess/PPI_OutlineShader.PPI_OutlineShader'"));
    if (MaterialAsset.Succeeded())
    {
        PostProcessMaterial = MaterialAsset.Object;
        return true;
    }
    return false;
}

void UPostProcessManager::CreatePostProcessVolume(UWorld* World, FVector Location)
{
    if (World && PostProcessMaterial)
    {
        // 创建PostProcessVolume  
        PostProcessVolume = World->SpawnActor<APostProcessVolume>();
        if (PostProcessVolume)
        {
            // 设置PostProcessVolume的位置（可以根据需要设置旋转和缩放）  
            PostProcessVolume->SetActorLocation(Location);

            if (LoadPostProcessMaterial())
            {
                PostProcessVolume->bUnbound = true;
                PostProcessVolume->bEnabled = true;
                PostProcessVolume->AddOrUpdateBlendable(PostProcessMaterial);
            }
        }
    }
}
