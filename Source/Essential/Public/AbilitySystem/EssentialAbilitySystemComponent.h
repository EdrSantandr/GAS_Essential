// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "EssentialAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class ESSENTIAL_API UEssentialAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();
	
protected:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec&, FActiveGameplayEffectHandle GameplayEffectHandle);
};
