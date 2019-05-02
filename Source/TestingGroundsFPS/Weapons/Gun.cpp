// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "BallProjectile.h"
#include "Animation/AnimInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create the gun mesh component
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	SkeletalMesh->bCastDynamicShadow = true;
	SkeletalMesh->CastShadow = true;

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	MuzzleLocation->SetupAttachment(SkeletalMesh);
	MuzzleLocation->SetRelativeLocation(FVector(0.2f, 60.0f, 11.2f));

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::OnFire()
{
	// Try and fire a projectile
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			const FRotator SpawnRotation = GetActorRotation();

			// MuzzleOffset is in local space, so transform it to world space before offsetting from the gun location to find the final muzzle position
			if (!ensure(MuzzleLocation != nullptr)) { return; }
			const FVector SpawnLocation = MuzzleLocation->GetComponentLocation();

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		}
	}

	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object
		if (ensure(AnimInstance != NULL)) 
		{
			AnimInstance->Montage_Play(FireAnimation, 1.0f);
		}
	}
}