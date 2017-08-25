// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetControlledTank();
	if (tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possessing : %s"), *tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possessing tank"));
	}
}