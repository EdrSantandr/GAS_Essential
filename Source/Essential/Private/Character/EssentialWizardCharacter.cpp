// Copyright EdrSantandr


#include "Character/EssentialWizardCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AEssentialWizardCharacter::AEssentialWizardCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, RotationRate, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
