// Copyright EdrSantandr


#include "Character/EssentialTreeCharacter.h"
#include "Essential/Essential.h"

AEssentialTreeCharacter::AEssentialTreeCharacter()
{
	
}

void AEssentialTreeCharacter::HighLightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_GREEN);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_GREEN);
	SetCustomDepthMaterial(OnHighLightMaterial);
}

void AEssentialTreeCharacter::UnHighLightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
