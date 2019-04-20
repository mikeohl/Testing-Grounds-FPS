// Fill out your copyright notice in the Description page of Project Settings.


#include "BTWaypointDirector.h"
#include "BehaviorTree\BlackboardComponent.h"

EBTNodeResult::Type UBTWaypointDirector::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	Index++;

	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	UE_LOG(LogTemp, Warning, TEXT("Current index: %i"), Index);

	return EBTNodeResult::Succeeded;
}


/**
 * Saved Logging and Debug code
 ********************************
 * UE_LOG(LogTemp, Warning, TEXT("Execute task called"))
 * IndexKey.SelectedKeyName
 */