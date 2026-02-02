// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class GGJ26_PROJECT_API UGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Ability Name")
	FString AbilityName;

	UPROPERTY(EditAnywhere, Category = "Limits")
	int32 AbilityLimit;

	UPROPERTY(EditAnywhere, Category = "Limits")
	int32 AbilityUseCount;

public:
	/** For UI (and internal use): returns false if limit reached */
	UFUNCTION(BlueprintCallable, Category = "Limits")
	bool CheckAbilityUsable() const;

	virtual bool CanActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayTagContainer* SourceTags = nullptr,
		const FGameplayTagContainer* TargetTags = nullptr,
		FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

protected:
	// increment uses when it successfully commits
	virtual bool CommitAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		FGameplayTagContainer* OptionalRelevantTags = nullptr) override;
};
