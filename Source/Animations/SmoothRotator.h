// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RotatorExpression.h"
#include "SmoothRotator.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API USmoothRotator : public URotatorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(URotatorExpression* InTarget, float InSpeed);

	virtual FRotator Evaluate(const FEvaluationContext& InContext) override;

private:

	float Speed = 0.0f;

	UPROPERTY()
	URotatorExpression* Target = nullptr;

	FRotator Current = FRotator::ZeroRotator;
};
UCLASS()
class ANIMATIONS_API USmoothRotatorConst : public URotatorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(URotatorExpression* InTarget, float InSpeed);

	virtual FRotator Evaluate(const FEvaluationContext& InContext) override;

private:

	float Speed = 0.0f;

	UPROPERTY()
	URotatorExpression* Target = nullptr;

	FRotator Current = FRotator::ZeroRotator;
};