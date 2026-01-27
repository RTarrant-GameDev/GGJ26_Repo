// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJ26_ProjectGameMode.h"

AGGJ26_ProjectGameMode::AGGJ26_ProjectGameMode()
{
	// stub
}

int32 AGGJ26_ProjectGameMode::GetMaskCount()
{
	return MaskCount;
}

void AGGJ26_ProjectGameMode::SetMaskCount()
{
	MaskCount++;
}

void AGGJ26_ProjectGameMode::UpdateMaskCount()
{
	SetMaskCount();

	if (GetMaskCount() >= MaskTargetNumber) {
		UE_LOG(LogTemp, Warning, TEXT("All masks collected!"));
	}
}
