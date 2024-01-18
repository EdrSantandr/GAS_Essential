// Copyright EdrSantandr


#include "UI/WidgetController/EssentialWidgetController.h"

void UEssentialWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UEssentialWidgetController::BroadcastInitialValues()
{
}
