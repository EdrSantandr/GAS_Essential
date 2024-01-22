// Copyright EdrSantandr


#include "Character/EssentialTreeCharacter.h"

#include "AbilitySystem/EssentialAbilitySystemComponent.h"
#include "AbilitySystem/EssentialAttributeSet.h"
#include "Essential/Essential.h"

AEssentialTreeCharacter::AEssentialTreeCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UEssentialAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UEssentialAttributeSet>("AttributeSet");
	
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

void AEssentialTreeCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AEssentialTreeCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UEssentialAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
