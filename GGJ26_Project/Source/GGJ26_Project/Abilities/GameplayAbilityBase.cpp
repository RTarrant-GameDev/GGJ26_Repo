// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbilityBase.h"
#include "GGJ26_ProjectCharacter.h"

UGameplayAbilityBase::UGameplayAbilityBase()
{
	// keep this; even if instances are per activation, we no longer store state here
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

bool UGameplayAbilityBase::CheckAbilityUsable(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo) const
{
	if (AbilityLimit > 0 && GetUseCountForHandle(Handle, ActorInfo) >= AbilityLimit)
	{
		return false;
	}
	return true;
}

bool UGameplayAbilityBase::CanActivateAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayTagContainer* SourceTags, 
	const FGameplayTagContainer* TargetTags, 
	FGameplayTagContainer* OptionalRelevantTags) const
{
	// GAS checks first (cooldown, cost, tags, etc.)
	if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	UE_LOG(LogTemp, Display, TEXT("Can activate ability: %s"), *FString(CheckAbilityUsable(Handle, ActorInfo) ? "True" : "False"));

	return CheckAbilityUsable(Handle, ActorInfo); 
}

bool UGameplayAbilityBase::CommitAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	FGameplayTagContainer* OptionalRelevantTags)
{
	const bool bCommitted =
		Super::CommitAbility(Handle, ActorInfo, ActivationInfo, OptionalRelevantTags);

	UE_LOG(LogTemp, Warning,
		TEXT("Ability=%s this=%p CDO=%d Instancing=%d PersistentUseCount=%d"),
		*GetNameSafe(this),
		this,
		HasAnyFlags(RF_ClassDefaultObject) ? 1 : 0,
		(int32)GetInstancingPolicy(),
		GetUseCountForHandle(Handle, ActorInfo)
	);

	if (bCommitted && AbilityLimit > 0)
	{
		IncrementUseCountForHandle(Handle, ActorInfo);               

		UE_LOG(LogTemp, Display,
			TEXT("Uses for %s (%s): %d / %d"),
			*GetNameSafe(this),
			*Handle.ToString(),
			GetUseCountForHandle(Handle, ActorInfo),
			AbilityLimit
		);
	}

	return bCommitted;
}

int32 UGameplayAbilityBase::GetUseCountForHandle(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo) const
{
	const AActor* OwnerActor = ActorInfo ? ActorInfo->OwnerActor.Get() : nullptr;
	const AGGJ26_ProjectCharacter* Character = Cast<AGGJ26_ProjectCharacter>(OwnerActor);
	if (!Character)
	{
		return 0;
	}

	if (const int32* Found = Character->AbilityUseCounts.Find(Handle))
	{
		return *Found;
	}

	return 0;
}

void UGameplayAbilityBase::IncrementUseCountForHandle(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo) const
{
	AActor* OwnerActor = ActorInfo ? ActorInfo->OwnerActor.Get() : nullptr;
	AGGJ26_ProjectCharacter* Character = Cast<AGGJ26_ProjectCharacter>(OwnerActor);
	if (!Character)
	{
		return;
	}

	int32& Count = Character->AbilityUseCounts.FindOrAdd(Handle);
	++Count;
}
