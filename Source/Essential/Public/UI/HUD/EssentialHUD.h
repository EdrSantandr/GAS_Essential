// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "EssentialHUD.generated.h"

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

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UEssentialUserWidget> OverlayWidgetClass;
};
