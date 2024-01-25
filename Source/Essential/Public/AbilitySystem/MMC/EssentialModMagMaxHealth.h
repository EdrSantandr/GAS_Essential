// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "EssentialModMagMaxHealth.generated.h"

/**
 * 
 */
UCLASS()
class ESSENTIAL_API UEssentialModMagMaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UEssentialModMagMaxHealth();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	FGameplayEffectAttributeCaptureDefinition StrengthDef;
};
