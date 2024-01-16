// Copyright EdrSantandr


#include "Actor/EssentialEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/EssentialAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AEssentialEffectActor::AEssentialEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(MeshComponent);
	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	SphereComponent->SetupAttachment(GetRootComponent());
}

void AEssentialEffectActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: const_cast should not be used like this 
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UEssentialAttributeSet* EssentialAttributeSet = Cast<UEssentialAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UEssentialAttributeSet::StaticClass()));
		UEssentialAttributeSet* MutableEssenceAttributeSet = const_cast<UEssentialAttributeSet*>(EssentialAttributeSet);
		MutableEssenceAttributeSet->SetHealth(EssentialAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AEssentialEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AEssentialEffectActor::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEssentialEffectActor::OnBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AEssentialEffectActor::OnEndOverlap);
}


