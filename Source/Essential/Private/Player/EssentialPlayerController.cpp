// Copyright EdrSantandr


#include "Player/EssentialPlayerController.h"
#include "EnhancedInputSubsystems.h"

AEssentialPlayerController::AEssentialPlayerController()
{
	bReplicates = true;
}

void AEssentialPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(EssentialContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(EssentialContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
