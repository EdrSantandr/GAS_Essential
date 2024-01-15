// Copyright EdrSantandr


#include "Character/EssentialWizardCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AEssentialWizardCharacter::AEssentialWizardCharacter()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	
	TopDownCameraComponent= CreateDefaultSubobject<UCameraComponent>("TopDownCameraComponent");
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, RotationRate, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AEssentialWizardCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void AEssentialWizardCharacter::ChangeHighlightMaterial(bool InCharacterType)
{
	if (!IsValid(PostMaterialRed) || !IsValid(PostMaterialGreen)) return;
	
	if (FMath::RandBool())
	{
		UE_LOG(LogTemp, Warning, TEXT("GREEN MATEIAL CALL"));
		// green material
		PostMaterialDynamic = UMaterialInstanceDynamic::Create(PostMaterialGreen, this);
		
		FWeightedBlendable WeightedBlendable = FWeightedBlendable(1.f,PostMaterialDynamic);
		TArray<FWeightedBlendable> WeightMaterials;
		WeightMaterials.Add(WeightedBlendable);

		FPostProcessSettings PostProcessSettings;
		PostProcessSettings.WeightedBlendables = WeightMaterials;

		TopDownCameraComponent->PostProcessSettings = PostProcessSettings;
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("RED MATEIAL CALL"));
		// red material
		PostMaterialDynamic = UMaterialInstanceDynamic::Create(PostMaterialRed, this);
		
		FWeightedBlendable WeightedBlendable = FWeightedBlendable(1.f,PostMaterialDynamic);
		TArray<FWeightedBlendable> WeightMaterials;
		WeightMaterials.Add(WeightedBlendable);

		FPostProcessSettings PostProcessSettings;
		PostProcessSettings.WeightedBlendables = WeightMaterials;

		TopDownCameraComponent->PostProcessSettings = PostProcessSettings;
	}
}

