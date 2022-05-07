// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "L004.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Error, TEXT("Error Message"));
	UE_LOG(LogTemp, Warning, TEXT("Warning Message"));
	UE_LOG(LogTemp, Display, TEXT("Display Message"));
	
	UE_LOG(MyLogCategory, Error, TEXT("MyError Message"));
	
	FString CharactorName = TEXT("HiWer");

	UE_LOG(LogTemp, Display, TEXT("Charactor Name = %s"), *CharactorName);

	bool isAttackable = true;
	UE_LOG(LogTemp, Display, TEXT("Is Attackable = %s"), isAttackable ? TEXT("true") : TEXT("false"));

	int hp = 100;
	UE_LOG(LogTemp, Display, TEXT("HP = %d"), hp);
	float AttackSpeed = 1.0f;
	UE_LOG(LogTemp, Display, TEXT("Attack Speed = %f"), AttackSpeed);
	FVector CharacterPosition = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("Position = %s"), *CharacterPosition.ToString());


}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

