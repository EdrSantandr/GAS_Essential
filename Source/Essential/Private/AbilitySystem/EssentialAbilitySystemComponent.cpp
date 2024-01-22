// Copyright EdrSantandr


#include "AbilitySystem/EssentialAbilitySystemComponent.h"

void UEssentialAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UEssentialAbilitySystemComponent::EffectApplied);
}

void UEssentialAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec&, FActiveGameplayEffectHandle GameplayEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1,8.f,FColor::Blue, FString("Effect APPLIED"));
}
