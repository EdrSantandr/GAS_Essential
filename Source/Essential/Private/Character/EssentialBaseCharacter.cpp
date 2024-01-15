// Copyright EdrSantandr

#include "Character/EssentialBaseCharacter.h"

#include "Engine/PostProcessVolume.h"
#include "Game/EssentialGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMaterialLibrary.h"

// Sets default values
AEssentialBaseCharacter::AEssentialBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEssentialBaseCharacter::SetCustomDepthMaterial(UMaterial* InHighLightMaterial)
{
	//Get the game mode find the post process and set the material
	if (AEssentialGameModeBase* EssentialGameMode = Cast<AEssentialGameModeBase>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		if (APostProcessVolume* PostProcessVolume = EssentialGameMode->GetPostProcessVolumeActor())
		{
			if (InHighLightMaterial)
			{
				FPostProcessSettings& PostProcessSettings = PostProcessVolume->Settings;
				HighLightMaterialDynamic = UKismetMaterialLibrary::CreateDynamicMaterialInstance(this, InHighLightMaterial);
				FWeightedBlendable WeightedBlendable;
				WeightedBlendable.Object = HighLightMaterialDynamic;
				WeightedBlendable.Weight = 1;
				PostProcessSettings.WeightedBlendables.Array.Empty();
				PostProcessSettings.WeightedBlendables.Array.Add(WeightedBlendable);
			}
		}
	}
}

UAbilitySystemComponent* AEssentialBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AEssentialBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}
