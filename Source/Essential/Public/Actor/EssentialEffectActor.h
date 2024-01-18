// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EssentialEffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class ESSENTIAL_API AEssentialEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AEssentialEffectActor();
	
protected:
	virtual void BeginPlay() override;

	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere, Category="Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	
};
