// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown Text"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);;
	RootComponent = CountdownText;

	CountdownTime = 3;

}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
}

void ACountdown::UpdateTimerDisplay()
{
	int8 result = FMath::Max(CountdownTime, 0);
	FString IntAsString = FString::FromInt(result);
	
	CountdownText->SetText((FText::Format("{0}"), result));
}


void ACountdown::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();
	if (CountdownTime < 1) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ACountdown::CountdownHasFinished()
{
	CountdownText->SetText(TEXT("Go!"));

}