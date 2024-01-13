// Copyright EdrSantandr

#include "Essential/Public/EssentialBaseCharacter.h"

// Sets default values
AEssentialBaseCharacter::AEssentialBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEssentialBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEssentialBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEssentialBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

