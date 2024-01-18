// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EssentialHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
struct FWidgetControllerParams;
class UEssentialUserWidget;
/**
 * 
 */
UCLASS()
class ESSENTIAL_API AEssentialHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UEssentialUserWidget> OverlayWidget;

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UEssentialUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
