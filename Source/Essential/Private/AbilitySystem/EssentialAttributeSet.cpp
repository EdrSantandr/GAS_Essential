// Copyright EdrSantandr


#include "AbilitySystem/EssentialAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
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

	//Vital
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Essence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, MaxEssence, COND_None, REPNOTIFY_Always);
	//Primary
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
	//Secondary
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, EssenceRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, CooldownTimes, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, HealthRegeneration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, TurnSpeed, COND_None, REPNOTIFY_Always);
	//Combat
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UEssentialAttributeSet, BlockChance, COND_None, REPNOTIFY_Always);
}

//Just to do clamping
void UEssentialAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetEssenceAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxEssence());
	}
}

void UEssentialAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data,Props);

	if(Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(),0.f, GetMaxHealth()));
	}
	if(Data.EvaluatedData.Attribute == GetEssenceAttribute())
	{
		SetEssence(FMath::Clamp(GetEssence(),0.f, GetMaxEssence()));
	}
}

void UEssentialAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, Intelligence, OldIntelligence);
}

void UEssentialAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, Strength, OldStrength);
}

void UEssentialAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, Dexterity, OldDexterity);
}

void UEssentialAttributeSet::OnRep_EssenceRegeneration(const FGameplayAttributeData& OldEssenceRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, EssenceRegeneration, OldEssenceRegeneration);
}

void UEssentialAttributeSet::OnRep_CooldownTimes(const FGameplayAttributeData& OldCooldownTimes) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, CooldownTimes, OldCooldownTimes);
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

void UEssentialAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, HealthRegeneration, OldHealthRegeneration);
}

void UEssentialAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, Armor, OldArmor);
}

void UEssentialAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, MovementSpeed, OldMovementSpeed);
}

void UEssentialAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, AttackSpeed, OldAttackSpeed);
}

void UEssentialAttributeSet::OnRep_TurnSpeed(const FGameplayAttributeData& OldTurnSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, TurnSpeed, OldTurnSpeed);
}

void UEssentialAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, CriticalHitChance, OldCriticalHitChance);
}

void UEssentialAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UEssentialAttributeSet, BlockChance, OldBlockChance);
}

void UEssentialAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props)
{
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if(IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid() )
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if(Props.SourceController)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC =UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}	
}

