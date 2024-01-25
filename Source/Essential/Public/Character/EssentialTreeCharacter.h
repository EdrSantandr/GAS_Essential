// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "Character/EssentialBaseCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "EssentialTreeCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ESSENTIAL_API AEssentialTreeCharacter : public AEssentialBaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEssentialTreeCharacter();
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;

	virtual int32 GetPlayerLevel() override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character class defaults")
	int32 Level = 1;
	
};
