// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EssentialBaseCharacter.generated.h"

UCLASS(Abstract)
class ESSENTIAL_API AEssentialBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AEssentialBaseCharacter();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(EditAnywhere, Category="Character")
	float RotationRate = 400.f;
};
