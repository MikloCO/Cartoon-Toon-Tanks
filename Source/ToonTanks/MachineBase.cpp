// Fill out your copyright notice in the Description page of Project Settings.


#include "MachineBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMachineBase::AMachineBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurrentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent Mesh"));
	TurrentMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurrentMesh);

}

void AMachineBase::RotateTurrentFunction(FVector LookAtTarget) {
	
	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurrentMesh->GetComponentLocation().Z);
	FVector StartLocation = TurrentMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();
	TurrentMesh->SetWorldRotation(TurretRotation);

}

void AMachineBase::Fire() {

}
void AMachineBase::HandleDestruction() {

}




