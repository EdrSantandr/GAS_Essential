// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "Character/EssentialBaseCharacter.h"
#include "EssentialWizardCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class ESSENTIAL_API AEssentialWizardCharacter : public AEssentialBaseCharacter
{
	GENERATED_BODY()

public:
	AEssentialWizardCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual int32 GetPlayerLevel() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;

protected:

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> PostMaterialDynamic = nullptr;

	virtual void InitAbilityActorInfo() override;
};
