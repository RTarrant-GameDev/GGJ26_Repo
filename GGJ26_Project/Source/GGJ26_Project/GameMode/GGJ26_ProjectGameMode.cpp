// Copyright Epic Games, Inc. All Rights Reserved.

#include "GGJ26_ProjectGameMode.h"
#include <Kismet/GameplayStatics.h>
#include <Timer/LevelTimerObject.h>

AGGJ26_ProjectGameMode::AGGJ26_ProjectGameMode()
{
	// stub
}

FString AGGJ26_ProjectGameMode::GetMaskCountTotalText()
{
	return FString::Printf(TEXT("%d/%d"), MaskCount, MaskTargetNumber);
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
		EndLevel();
	}
}

void AGGJ26_ProjectGameMode::EndLevel()
{
	UE_LOG(LogTemp, Display, TEXT("Level ended!"));

	ALevelTimerObject* TimerActor =
		Cast<ALevelTimerObject>(
			UGameplayStatics::GetActorOfClass(GetWorld(), ALevelTimerObject::StaticClass())
		);

	if (TimerActor)
	{
		TimerActor->Destroy();
	}
}
