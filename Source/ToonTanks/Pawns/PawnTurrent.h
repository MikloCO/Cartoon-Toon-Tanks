// © Copyrigth Olivia Mikler 2021

#pragma once

#include "CoreMinimal.h"
#include "MachineBase.h"
#include "PawnTurrent.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurrent : public AMachineBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRange = 500.0f;
	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;

	void CheckFireCondition();
	float ReturnDistanceToPlayer();
public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void HandleDestruction() override;
};
