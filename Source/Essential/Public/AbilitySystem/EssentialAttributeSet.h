// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "EssentialAttributeSet.generated.h"

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

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxHealth", Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Essence", Category = "Vital Attributes")
	FGameplayAttributeData Essence;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxEssence", Category = "Vital Attributes")
	FGameplayAttributeData MaxEssence;
	
	UFUNCTION()
	void OnRep_Essence(const FGameplayAttributeData& OldEssence) const;

	UFUNCTION()
	void OnRep_MaxEssence(const FGameplayAttributeData& OldMaxEssence) const;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
};
