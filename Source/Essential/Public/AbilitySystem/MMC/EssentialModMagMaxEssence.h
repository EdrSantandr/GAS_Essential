// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "EssentialModMagMaxEssence.generated.h"

/**
 * 
 */
UCLASS()
class ESSENTIAL_API UEssentialModMagMaxEssence : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
public:
	UEssentialModMagMaxEssence();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
private:
	FGameplayEffectAttributeCaptureDefinition IntelligenceDef;
};
