// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EssentialUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ESSENTIAL_API UEssentialUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
