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
UCLASS()
class ESSENTIAL_API UEssentialAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UEssentialAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

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
	
};
