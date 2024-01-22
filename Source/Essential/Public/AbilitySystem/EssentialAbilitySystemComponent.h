// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "EssentialAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTagsSignature, const FGameplayTagContainer& /*Asset Tags*/);

/**
 * 
 */
UCLASS()
class ESSENTIAL_API UEssentialAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();

	FEffectAssetTagsSignature EffectAssetTagsDelegate;
	
protected:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle GameplayEffectHandle);
};
