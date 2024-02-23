// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeOutlineFunctionLibrary.h"
#include "PostProcessManager.h"

void URuntimeOutlineFunctionLibrary::SetOutline(UPrimitiveComponent* Mesh, bool bShow, bool bReloadColor, int32 TemplateValue)
{
	if (!UPostProcessManager::GetInstance())
	{
		return;
	}

	if (Mesh)
	{
		Mesh->SetRenderCustomDepth(bShow);
		if (bReloadColor)
		{
			Mesh->SetCustomDepthStencilValue(TemplateValue);
		}
	}
}
