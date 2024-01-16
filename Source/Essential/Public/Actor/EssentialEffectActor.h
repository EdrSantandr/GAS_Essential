// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EssentialEffectActor.generated.h"

class USphereComponent;

UCLASS()
class ESSENTIAL_API AEssentialEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AEssentialEffectActor();
	
	UFUNCTION()
	virtual void OnBeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshComponent;
};
