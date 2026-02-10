// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer/LevelTimerObject.h"
#include "GameMode/GGJ26_ProjectGameMode.h"

// Sets default values
ALevelTimerObject::ALevelTimerObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int32 ALevelTimerObject::GetLevelCountdownSeconds()
{
	return LevelCountdownSeconds;
}

void ALevelTimerObject::AddToLevelCountdownSeconds(int32 SecondsToAdd)
{
	LevelCountdownSeconds += SecondsToAdd;
}

// Called when the game starts or when spawned
void ALevelTimerObject::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &ALevelTimerObject::OnTimer, 1.0f, true);
}

void ALevelTimerObject::OnTimer() {
	--LevelCountdownSeconds;

	if (LevelCountdownSeconds <= 0) {
		GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
	}
}

void ALevelTimerObject::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
}

