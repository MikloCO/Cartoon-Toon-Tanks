// © Copyrigth Olivia Mikler 2021

#include "PawnTurrent.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurrent::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurrent::CheckFireCondition, FireRate, true);
	
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}


// Called every frame
void APawnTurrent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange) {
		return;
	}

	RotateTurrentFunction(PlayerPawn->GetActorLocation());
}

void APawnTurrent::HandleDestruction() 
{
	Super::HandleDestruction();
	Destroy();
}

void APawnTurrent::CheckFireCondition() 
{

	if(!PlayerPawn)  {
		return;
	}


	if (ReturnDistanceToPlayer() <= FireRange) {
		UE_LOG(LogTemp, Warning, TEXT("PawnTurrent Condition sucess"));
		Fire();
	}
}

float APawnTurrent::ReturnDistanceToPlayer() {
	if (!PlayerPawn) {
		return 0.0f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}