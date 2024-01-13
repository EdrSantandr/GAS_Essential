// Copyright EdrSantandr

#include "Character/EssentialBaseCharacter.h"

// Sets default values
AEssentialBaseCharacter::AEssentialBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEssentialBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}
