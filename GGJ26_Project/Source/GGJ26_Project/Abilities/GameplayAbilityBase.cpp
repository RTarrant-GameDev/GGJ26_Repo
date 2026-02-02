// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/GameplayAbilityBase.h"

bool UGameplayAbilityBase::CheckAbilityUsable() const
{
	if (AbilityLimit > 0 && AbilityUseCount >= AbilityLimit)
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
	// GAS built-in checks first (cooldown/cost/tags/etc.)
	if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	// Your limit rule
	return CheckAbilityUsable();
}

bool UGameplayAbilityBase::CommitAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	FGameplayTagContainer* OptionalRelevantTags)
{
	const bool bCommitted = Super::CommitAbility(Handle, ActorInfo, ActivationInfo, OptionalRelevantTags);

	// Only consume a use if commit succeeded
	if (bCommitted && AbilityLimit > 0)
	{
		++AbilityUseCount;
	}

	return bCommitted;
}
