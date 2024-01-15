// Copyright EdrSantandr


#include "Player/EssentialPlayerState.h"

#include "AbilitySystem/EssentialAbilitySystemComponent.h"
#include "AbilitySystem/EssentialAttributeSet.h"

AEssentialPlayerState::AEssentialPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UEssentialAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UEssentialAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;

}

UAbilitySystemComponent* AEssentialPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
