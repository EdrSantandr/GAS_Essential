// Copyright EdrSantandr

#pragma once

#include "CoreMinimal.h"
#include "Character/EssentialBaseCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "EssentialEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ESSENTIAL_API AEssentialEnemyCharacter : public AEssentialBaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
