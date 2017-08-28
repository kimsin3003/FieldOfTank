// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * barrelToSet)
{
	m_barrel = barrelToSet;
}

void UTankAimingComponent::AimAt(FVector & hitLocation, float launchSpeed)
{
	if (!m_barrel) return;
	auto barrelLocation = m_barrel->GetSocketLocation(FName("Projectile"));
	FVector outLaunchVelocity;
	if (UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, barrelLocation, hitLocation, launchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto aimDirection = outLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(aimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
	FRotator barrelRotator = m_barrel->GetForwardVector().Rotation();
	FRotator aimAsRotator = aimDirection.Rotation();
	FRotator deltaRotator = aimAsRotator - barrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *deltaRotator.ToString());

	m_barrel->SetWorldRotation(aimAsRotator, false);
}
