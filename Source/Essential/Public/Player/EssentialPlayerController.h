// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EssentialPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
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
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> EssentialContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
