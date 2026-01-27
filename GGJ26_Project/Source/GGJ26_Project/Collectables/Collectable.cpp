// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectables/Collectable.h"
#include "GGJ26_Project/Characters/GGJ26_ProjectCharacter.h"
#include <GGJ26_ProjectGameMode.h>

// Sets default values
ACollectable::ACollectable()
{
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));

	Collider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collider->SetGenerateOverlapEvents(true);

	// Debug-friendly baseline:
	Collider->SetCollisionProfileName(TEXT("Collider"));
	SetRootComponent(Collider);
}

void ACollectable::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Collider->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::BeginOverlap);
}

void ACollectable::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this) return;

	if (AGGJ26_ProjectCharacter* Player = Cast<AGGJ26_ProjectCharacter>(OtherActor))
	{
		AGGJ26_ProjectGameMode* GameMode = Cast<AGGJ26_ProjectGameMode>(GetWorld()->GetAuthGameMode());
		GameMode->UpdateMaskCount();
		this->Destroy();
		GEngine->ForceGarbageCollection();
	}
}

