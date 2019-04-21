// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolRoute.h"

// Sets default values for this component's properties
UPatrolRoute::UPatrolRoute()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPatrolRoute::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPatrolRoute::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


AActor* UPatrolRoute::GetPatrolPoint(const int Index) const
{ 
	if (Index > PatrolPoints.Num() - 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Index %i to Patrol Route is out of bounds"), Index);
		return nullptr;
	}
	
	return PatrolPoints[Index]; 
}

