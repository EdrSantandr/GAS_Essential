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

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(EditDefaultsOnly, Category="Hightlight")
	TObjectPtr<UMaterial> PostMaterialRed;

	UPROPERTY(EditDefaultsOnly, Category="Hightlight")
	TObjectPtr<UMaterial> PostMaterialGreen;

protected:
	void ChangeHighlightMaterial(bool InCharacterType);

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> PostMaterialDynamic = nullptr;

	
};
