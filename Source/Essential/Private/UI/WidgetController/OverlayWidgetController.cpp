// Copyright EdrSantandr


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/EssentialAbilitySystemComponent.h"
#include "AbilitySystem/EssentialAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	if (const UEssentialAttributeSet* EssentialAttributeSet = CastChecked<UEssentialAttributeSet>(AttributeSet))
	{
		OnHealthChange.Broadcast(EssentialAttributeSet->GetHealth());
		OnMaxHealthChange.Broadcast(EssentialAttributeSet->GetMaxHealth());
		OnEssenceChange.Broadcast(EssentialAttributeSet->GetEssence());
		OnMaxEssenceChange.Broadcast(EssentialAttributeSet->GetMaxEssence());
	}
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UEssentialAttributeSet* EssentialAttributeSet = CastChecked<UEssentialAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(EssentialAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(EssentialAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(EssentialAttributeSet->GetEssenceAttribute()).AddUObject(this, &UOverlayWidgetController::EssenceChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(EssentialAttributeSet->GetMaxEssenceAttribute()).AddUObject(this, &UOverlayWidgetController::MaxEssenceChanged);
	Cast<UEssentialAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTagsDelegate.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for(const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if(Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		});
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChange.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChange.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::EssenceChanged(const FOnAttributeChangeData& Data) const
{
	OnEssenceChange.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxEssenceChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxEssenceChange.Broadcast(Data.NewValue);
}
