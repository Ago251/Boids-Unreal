// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SteeringControlWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChanged, float, NewValue);

UCLASS()
class BOIDS_API USteeringControlWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Steering")
	FOnValueChanged OnValueChangedDelegate;
	
	UPROPERTY(meta = (BindWidget))
	class USlider* StrengthSlider;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* StrengthText;
	
	UFUNCTION(BlueprintCallable)
	void OnStrengthValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void SetTextLabel(FText Text);

protected:
	virtual void NativeConstruct() override;
};
