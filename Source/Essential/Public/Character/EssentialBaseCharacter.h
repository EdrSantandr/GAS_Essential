// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interaction/CombatInterface.h"
#include "EssentialBaseCharacter.generated.h"

UCLASS(Abstract)
class ESSENTIAL_API AEssentialBaseCharacter : public ACharacter, public ICombatInterface
{
	GENERATED_BODY()

public:
	
	AEssentialBaseCharacter();
	
	void SetCustomDepthMaterial(UMaterial* InHighLightMaterial);

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(EditAnywhere, Category="Character")
	float RotationRate = 400.f;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	UMaterial* OnHighLightMaterial = nullptr;

	UPROPERTY()
	UMaterialInstanceDynamic* HighLightMaterialDynamic = nullptr;
	
};
