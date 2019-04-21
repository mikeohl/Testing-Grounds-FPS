// Fill out your copyright notice in the Description page of Project Settings.


#include "BTWaypointDirector.h"

#include "BehaviorTree\BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UBTWaypointDirector::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	auto AIOwner = OwnerComp.GetAIOwner();
	if (!ensure(AIOwner)) { return EBTNodeResult::Aborted; }

	auto PatrollingPawn = AIOwner->GetPawn();
	if (!ensure(PatrollingPawn)) { return EBTNodeResult::Aborted; }

	auto PatrolRoute = PatrollingPawn->FindComponentByClass<UPatrolRoute>();

	auto Waypoint = PatrolRoute->GetPatrolPoint(Index);
	if (!ensure(Waypoint)) { return EBTNodeResult::Aborted; }

	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, Waypoint);

	Index++;
	Index %= PatrolRoute->GetPatrolPointsLength();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	UE_LOG(LogTemp, Warning, TEXT("AIActor Name: %s"), *AIOwner->GetPawn()->GetName());
	UE_LOG(LogTemp, Warning, TEXT("Current index: %i"), Index);

	return EBTNodeResult::Succeeded;
}


/**
 * Saved Logging and Debug code
 ********************************
 * UE_LOG(LogTemp, Warning, TEXT("Execute task called"))
 * IndexKey.SelectedKeyName
 */