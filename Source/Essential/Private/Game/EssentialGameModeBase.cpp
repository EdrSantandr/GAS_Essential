// Copyright EdrSantandr


#include "Game/EssentialGameModeBase.h"

#include "Engine/PostProcessVolume.h"
#include "Kismet/GameplayStatics.h"

void AEssentialGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	SetPostProcessVolume();
}

APostProcessVolume* AEssentialGameModeBase::GetPostProcessVolumeActor() const
{
	return PostProcessVolume;
}

void AEssentialGameModeBase::SetPostProcessVolume()
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, APostProcessVolume::StaticClass(), Actors);
	if (Actors.Num() > 0)
	{
		if (APostProcessVolume* PPV = Cast<APostProcessVolume>(Actors[0]))
		{
			PostProcessVolume = PPV;
		}
	}
}
