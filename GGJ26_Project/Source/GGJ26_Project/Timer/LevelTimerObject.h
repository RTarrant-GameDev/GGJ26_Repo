// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelTimerObject.generated.h"

UCLASS()
class GGJ26_PROJECT_API ALevelTimerObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelTimerObject();

	FTimerHandle MyTimerHandle;

	UPROPERTY(EditAnywhere, Category = "Time")
	int32 LevelCountdownSeconds;

public:
	UFUNCTION(BlueprintCallable, Category = "LevelTimer")
	int32 GetLevelCountdownSeconds();

	UFUNCTION(BlueprintCallable, Category="LevelTimer")
	void AddToLevelCountdownSeconds(int32 SecondsToAdd);

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OnTimer();
};
