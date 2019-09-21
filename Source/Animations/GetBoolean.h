// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "GetBoolean.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UGetBoolean : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(bool* InSource);

	virtual float Evaluate(const FEvaluationContext& InContext) override;

private:

	bool* Source = nullptr;

};

/**
 *
 */
UCLASS()
class ANIMATIONS_API UGetBooleanImmediate : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(bool InValue);

	virtual float Evaluate(const FEvaluationContext& InContext) override;

private:

	bool Value = 0.0f;

};
