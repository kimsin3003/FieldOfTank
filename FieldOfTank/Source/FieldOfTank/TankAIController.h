// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class FIELDOFTANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

	ATank* GetControlledTank() const;

	void BeginPlay() override;
};
