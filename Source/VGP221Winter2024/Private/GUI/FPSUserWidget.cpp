// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
    SetHealthBar(1.0f);
    SetScore(0);
    SetCountdown(0);
}

void UFPSUserWidget::SetHealthBar(float Percentage)
{
    if (!HealthBar) return;

    HealthBar->SetPercent(Percentage);
}

void UFPSUserWidget::SetScore(int NewScore)
{
    if (!ScoreText) return;

    UIScore = NewScore;
    ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}

void UFPSUserWidget::SetCountdown(int CountdownValue)
{
    if (!CountdownText) return;

    CountdownText->SetText(FText::FromString("Countdown: " + FString::FromInt(CountdownValue)));
}
