// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "GUI/ButtonWidget.h"
#include "FPSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class VGP221WINTER2024_API UFPSUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* HealthBar;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreText;

    UPROPERTY(meta = (BindWidget))
    UVerticalBox* ButtonContainer;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* CountdownText;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UButtonWidget> ButtonWidgetPrefab;

    UFUNCTION()
    void SetHealthBar(float Percentage);

    UFUNCTION()
    void SetScore(int NewScore);

    UFUNCTION()
    void SetCountdown(int CountdownValue);

    UFUNCTION(BlueprintCallable)
    int32 GetScore() const { return UIScore; }

private:
    int UIScore = 0;
};
