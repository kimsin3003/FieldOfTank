// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

ATankPlayerController::ATankPlayerController()
{
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetControlledTank();
	if (tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing : %s"), *tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing tank"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
		return;

	FVector hitLocation;
	if (GetSightRayHitLocation(hitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocatioin: %s"), *hitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation)
{
	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);
	auto screenLocation = FVector2D(viewportSizeX * m_crosshairXRatio, viewportSizeY * m_crosshairYRatio);
	FVector lookDirection;
	if (GetLookDirection(screenLocation, lookDirection))
	{
		return true;
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection)
{
	FVector worldLocation;
	if (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, lookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("World Directioin: %s"), *lookDirection.ToString());
		return true;
	}
	return false;
}
