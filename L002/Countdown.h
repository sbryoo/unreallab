// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/TextRenderComponent.h>
#include "Countdown.generated.h"

UCLASS()
class L002_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	int32 CountdownTime;
	UTextRenderComponent* CountdownText;
	void UpdateTimerDisplay();
	void AdvanceTimer();
	void CountdownHasFinished();
	FTimerHandle CountdownTimerHandle;
};
