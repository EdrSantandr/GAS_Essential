// Copyright EdrSantandr


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/EssentialAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	if (const UEssentialAttributeSet* EssentialAttributeSet = CastChecked<UEssentialAttributeSet>(AttributeSet))
	{
		OnHealthChange.Broadcast(EssentialAttributeSet->GetHealth());
		OnMaxHealthChange.Broadcast(EssentialAttributeSet->GetMaxHealth());
	}
}
