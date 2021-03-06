// © Copyrigth Olivia Mikler 2021

#pragma once

#include "CoreMinimal.h"
#include "MachineBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PawnTank.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOONTANKS_API APawnTank : public AMachineBase
{
	GENERATED_BODY()
	

private: 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;

		

	FVector MoveDirection;
	FQuat RotationDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
		float MoveSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta= (AllowPrivateAccess ="true"))
		float RotateSpeed = 100.0f;

	APlayerController* PlayerControllerRef;

	void CalculateMoveInput(float value);
	void CalculateRotateInput(float value);

	void Move();
	void Rotate();


public: 
	APawnTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void HandleDestruction() override;

};
