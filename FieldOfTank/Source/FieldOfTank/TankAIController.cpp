// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	APawn* playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(playerPawn);
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

	ATank* playerTank = GetPlayerTank();
	if (tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Found Player : %s"), *playerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not Found Player"));
	}
}