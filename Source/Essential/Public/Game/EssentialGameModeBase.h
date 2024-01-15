// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EssentialGameModeBase.generated.h"

class APostProcessVolume;
/**
 * 
 */
UCLASS()
class ESSENTIAL_API AEssentialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	APostProcessVolume* GetPostProcessVolumeActor() const;

protected:
	UPROPERTY()
	APostProcessVolume* PostProcessVolume = nullptr;

	void SetPostProcessVolume();
};
