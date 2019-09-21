// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "WeightedAverage3.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UWeightedAverage3 : public UFloatExpression
{
	GENERATED_BODY()
	
public:

	void SetInputs(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
		UFloatExpression* A = nullptr;

	UPROPERTY()
		UFloatExpression* Aa = nullptr;

	UPROPERTY()
		UFloatExpression* B = nullptr;

	UPROPERTY()
		UFloatExpression* Ba = nullptr;

	UPROPERTY()
		UFloatExpression* C = nullptr;

	UPROPERTY()
		UFloatExpression* Ca = nullptr;
};