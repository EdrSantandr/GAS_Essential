// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EssentialPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class ESSENTIAL_API AEssentialPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AEssentialPlayerController();
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> EssentialContext;
};
