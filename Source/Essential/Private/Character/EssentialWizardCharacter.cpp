// Copyright EdrSantandr


#include "Character/EssentialWizardCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/EssentialAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/EssentialPlayerController.h"
#include "Player/EssentialPlayerState.h"
#include "UI/HUD/EssentialHUD.h"

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
	// Init for the server
	InitAbilityActorInfo();
}

void AEssentialWizardCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init for the client
	InitAbilityActorInfo();
}

int32 AEssentialWizardCharacter::GetPlayerLevel()
{
	if (const AEssentialPlayerState* EssentialPlayerState = GetPlayerState<AEssentialPlayerState>())
	{
		return EssentialPlayerState->GetPlayerLevel();		
	}
	return 0;
}

void AEssentialWizardCharacter::InitAbilityActorInfo()
{
	if (AEssentialPlayerState* EssentialPlayerState = GetPlayerState<AEssentialPlayerState>())
	{
		EssentialPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(EssentialPlayerState, this);
		AbilitySystemComponent = EssentialPlayerState->GetAbilitySystemComponent();
		Cast<UEssentialAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
		AttributeSet = EssentialPlayerState->GetAttributeSet();

		if (AEssentialPlayerController* EssentialPlayerController = Cast<AEssentialPlayerController>(GetController()))
		{
			if (AEssentialHUD* EssentialHUD = Cast<AEssentialHUD>(EssentialPlayerController->GetHUD()))
			{
				EssentialHUD->InitOverlay(EssentialPlayerController, EssentialPlayerState, AbilitySystemComponent, AttributeSet);
			}
		}
		InitializeAttributes();
	}
}
