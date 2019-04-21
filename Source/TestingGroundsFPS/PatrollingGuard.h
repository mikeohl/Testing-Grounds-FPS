// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDSFPS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	AActor* GetPatrolPoint(const int Index) const { return PatrolPoints[Index]; }
	uint32 GetPatrolPointsLength() const { return PatrolPoints.Num(); }

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol")
	TArray<AActor*> PatrolPoints;
	
};
