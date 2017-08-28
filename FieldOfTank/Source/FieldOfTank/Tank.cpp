// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectGlobals.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;
	m_tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Coponent"));
}

void ATank::AimAt(FVector& hitLocation)
{
	auto tankName = GetName();
	m_tankAimingComponent->AimAt(hitLocation, launchSpeed);
}

void ATank::SetBarrelReference(UStaticMeshComponent * barrelToSet)
{
	m_tankAimingComponent->SetBarrelReference(barrelToSet);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

