// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GGJ26_ProjectGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AGGJ26_ProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AGGJ26_ProjectGameMode();

public:

	int32 GetMaskCount();

	void SetMaskCount();

	void UpdateMaskCount();

public:
	UPROPERTY(VisibleAnywhere)
	int32 MaskCount = 0;

	UPROPERTY(EditAnywhere)
	int32 MaskTargetNumber;
};



