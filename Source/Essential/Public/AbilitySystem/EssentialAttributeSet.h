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

/**
 * 
 */

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

	//Primary Attributes
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Intelligence", Category = "Primery Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Intelligence);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Strength", Category = "Primery Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Dexterity", Category = "Primery Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UEssentialAttributeSet, Dexterity);

	//Secondary Attributes
	//Related to Intelligence
	//Related to Strength
	//Related to Dexterity
	
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;
	
	UFUNCTION()
	void OnRep_Essence(const FGameplayAttributeData& OldEssence) const;

	UFUNCTION()
	void OnRep_MaxEssence(const FGameplayAttributeData& OldMaxEssence) const;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

private:
	
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props);
};