// Copyright EdrSantandr


#include "Character/EssentialEnemyCharacter.h"

#include "AbilitySystem/EssentialAbilitySystemComponent.h"
#include "AbilitySystem/EssentialAttributeSet.h"
#include "Essential/Essential.h"


AEssentialEnemyCharacter::AEssentialEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UEssentialAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UEssentialAttributeSet>("AttributeSet");
}

void AEssentialEnemyCharacter::HighLightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	SetCustomDepthMaterial(OnHighLightMaterial);
}

void AEssentialEnemyCharacter::UnHighLightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}