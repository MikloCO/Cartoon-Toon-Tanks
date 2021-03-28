// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SceneComponent.h"
#include "MachineBase.generated.h"

class UCapsuleComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOONTANKS_API AMachineBase : public APawn
{
	GENERATED_BODY()
public:
	AMachineBase();
private: 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh ;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurrentMesh ;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint ;

protected:
	void RotateTurrentFunction(FVector LookAtTarget);

	void Fire();

	virtual void HandleDestruction();

	
};
