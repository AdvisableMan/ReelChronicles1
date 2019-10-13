// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "RotatorExpression.h"
#include "MakeRotatorExpression.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UMakeRotatorExpression : public URotatorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UFloatExpression* InPitch, UFloatExpression* InYaw, UFloatExpression* InRoll);

	virtual FRotator Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
		UFloatExpression* Pitch = nullptr;

	UPROPERTY()
		UFloatExpression* Yaw = nullptr;

	UPROPERTY()
		UFloatExpression* Roll = nullptr;

};