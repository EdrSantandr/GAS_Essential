// Copyright EdrSantandr


#include "UI/HUD/EssentialHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/EssentialUserWidget.h"


void AEssentialHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
