// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"

#include "SActionComponent.h"
#include "SAttributeComponent.h"
#include "SGameplayFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SActionEffect.h"

// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
	SphereComp->SetSphereRadius(20.0f);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ASMagicProjectile::OnActorOverlap);

	InitialLifeSpan = 10.0f;
	
	DamageAmount = 20.0f;
}


void ASMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		//static FGameplayTag Tag = FGameplayTag::RequestGameplayTag("Status.Parrying");
		
		USActionComponent* ActionComp = Cast<USActionComponent>(OtherActor->GetComponentByClass(USActionComponent::StaticClass()));
		if (ActionComp && ActionComp->ActiveGameplayTags.HasTag(ParryTag))
		{
			MoveComp->Velocity = -MoveComp->Velocity;

			SetInstigator(Cast<APawn>(OtherActor));
			return;
		}
		
		// Apply  Damage & Impulse
		if (USGameplayFunctionLibrary::ApplyDirectionalDamage(GetInstigator(), OtherActor, DamageAmount, SweepResult))
		{
			Explode();

			if (ActionComp && HasAuthority())
			{
				ActionComp->AddAction(GetInstigator(), BurningActionClass);
			}
		}
	}
}
