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

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	
};
