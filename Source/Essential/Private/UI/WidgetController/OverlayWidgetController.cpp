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

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UEssentialAttributeSet* EssentialAttributeSet = CastChecked<UEssentialAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(EssentialAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(EssentialAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChange.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChange.Broadcast(Data.NewValue);
}
