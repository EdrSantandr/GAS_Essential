// Copyright EdrSantandr


#include "Player/EssentialPlayerState.h"

#include "AbilitySystem/EssentialAbilitySystemComponent.h"
#include "AbilitySystem/EssentialAttributeSet.h"
#include "Net/UnrealNetwork.h"

AEssentialPlayerState::AEssentialPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UEssentialAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UEssentialAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;

}

void AEssentialPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEssentialPlayerState, Level);
}

UAbilitySystemComponent* AEssentialPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AEssentialPlayerState::OnRep_Level(int32 OldLevel)
{
}
