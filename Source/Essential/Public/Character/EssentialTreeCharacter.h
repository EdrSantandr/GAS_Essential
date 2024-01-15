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

	AEssentialTreeCharacter();
	
public:
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
};
