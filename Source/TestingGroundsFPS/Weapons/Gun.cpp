// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "BallProjectile.h"
#include "Animation/AnimInstance.h"

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
	MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.8f, -10.6f));
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

