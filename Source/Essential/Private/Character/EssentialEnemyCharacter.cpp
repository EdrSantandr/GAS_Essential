// Copyright EdrSantandr


#include "Character/EssentialEnemyCharacter.h"
#include "Essential/Essential.h"


AEssentialEnemyCharacter::AEssentialEnemyCharacter()
{
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