// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RuntimeOutlineFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RUNTIMEOUTLINE_API URuntimeOutlineFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "轮廓线", DisplayName = "设置轮廓线")
	static void SetOutline(UPrimitiveComponent* Mesh, bool bShow, bool bReloadColor, int32 TemplateValue);
};
