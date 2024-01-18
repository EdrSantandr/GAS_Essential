// Copyright EdrSantandr


#include "UI/HUD/EssentialHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/EssentialUserWidget.h"
#include "UI/WidgetController/EssentialWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AEssentialHUD::GetOverlayWidgetController(const FWidgetControllerParams WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		return  OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AEssentialHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay widget class uninitialized"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay widget controller class uninitialized"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UEssentialUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	OverlayWidget->SetWidgetController(WidgetController);
	
	Widget->AddToViewport();
}