// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GUI/MenuWidget.h"
#include "Logging/StructuredLog.h"
#include "LoseGameMode.generated.h"


/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API ALoseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GUI")
	TSubclassOf<UMenuWidget> UserWidgetPrefab;

	UFUNCTION(BlueprintCallable, Category = "GUI")
	void ChangeMenuWidget(TSubclassOf<UMenuWidget> NewWidgetClass);

	UPROPERTY()
	UMenuWidget* CurrentWidget;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Timer")
	int32 CountdownTime = 30;

	FTimerHandle TimerHandle_Countdown;

	void CountdownTick();
	void TransitionToWinScene();
};
