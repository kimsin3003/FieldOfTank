// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FIELDOFTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	ATankPlayerController();
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& hitLocation);

	bool GetLookDirection(FVector2D screenLocation, FVector & lookDirection);

	UPROPERTY(EditAnywhere)
	float m_crosshairXRatio;
	UPROPERTY(EditAnywhere)
	float m_crosshairYRatio;

};
