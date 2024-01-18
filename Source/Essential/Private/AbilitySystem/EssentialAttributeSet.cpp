// Copyright EdrSantandr


#include "AbilitySystem/EssentialAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UEssentialAttributeSet::UEssentialAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(200.f);
	InitEssence(100.f);
	InitMaxEssence(100.f);
}

void UEssentialAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Essence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, MaxEssence, COND_None, REPNOTIFY_Always);
}

void UEssentialAttributeSet::OnRep_Essence(const FGameplayAttributeData& OldEssence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, Essence, OldEssence);
}

void UEssentialAttributeSet::OnRep_MaxEssence(const FGameplayAttributeData& OldMaxEssence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, MaxEssence, OldMaxEssence);
}

void UEssentialAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, Health, OldHealth);
}

void UEssentialAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, MaxHealth, OldMaxHealth);
}
