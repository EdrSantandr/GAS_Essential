// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "EssentialAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;
	
	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;
	
	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;
	
	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;
	
	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
	
};


UCLASS()
class ESSENTIAL_API UEssentialAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UEssentialAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	//Vital Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Health", Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxHealth", Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Essence", Category = "Vital Attributes")
	FGameplayAttributeData Essence;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Essence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxEssence", Category = "Vital Attributes")
	FGameplayAttributeData MaxEssence;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, MaxEssence);

	UFUNCTION()
	void OnRep_Essence(const FGameplayAttributeData& OldEssence) const;

	UFUNCTION()
	void OnRep_MaxEssence(const FGameplayAttributeData& OldMaxEssence) const;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	//Primary Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Intelligence", Category = "Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Intelligence);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Strength", Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Dexterity", Category = "Primary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Dexterity);

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;

	//Secondary Attributes
	//Related to Intelligence
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_EssenceRegeneration", Category = "Secondary Attributes")
	FGameplayAttributeData EssenceRegeneration;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, EssenceRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_CooldownTimes", Category = "Secondary Attributes")
	FGameplayAttributeData CooldownTimes;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, CooldownTimes);

	UFUNCTION()
	void OnRep_EssenceRegeneration(const FGameplayAttributeData& OldEssenceRegeneration) const;

	UFUNCTION()
	void OnRep_CooldownTimes(const FGameplayAttributeData& OldCooldownTimes) const;
	
	//Related to Strength
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_HealthRegeneration", Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, HealthRegeneration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Armor", Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Armor);

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	
	//Related to Dexterity
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MovementSpeed", Category = "Secondary Attributes")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, MovementSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_AttackSpeed", Category = "Secondary Attributes")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, AttackSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_TurnSpeed", Category = "Secondary Attributes")
	FGameplayAttributeData TurnSpeed;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, TurnSpeed);

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const;

	UFUNCTION()
	void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed) const;

	UFUNCTION()
	void OnRep_TurnSpeed(const FGameplayAttributeData& OldTurnSpeed) const;

	//Combat Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_CriticalHitChance", Category = "Combat Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, CriticalHitChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_BlockChance", Category = "Combat Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, BlockChance);

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;


	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

private:
	
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props);
};