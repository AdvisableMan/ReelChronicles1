// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "ClampFloat.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UClampFloat : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UFloatExpression* InValue, float InRangeA, float InRangeB);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
	UFloatExpression* Value = nullptr;

	UPROPERTY()
	float RangeA = 0.0f;

	UPROPERTY()
	float RangeB = 0.0f;
};

UCLASS()
class ANIMATIONS_API UClampFloatVariable : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UFloatExpression* InValue, UFloatExpression* InRangeA, UFloatExpression* InRangeB);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
		UFloatExpression* Value = nullptr;

	UPROPERTY()
		UFloatExpression* RangeA = nullptr;

	UPROPERTY()
		UFloatExpression* RangeB = nullptr;
};