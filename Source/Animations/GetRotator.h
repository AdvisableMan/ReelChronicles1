// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RotatorExpression.h"
#include "GetRotator.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UGetRotator : public URotatorExpression
{
	GENERATED_BODY()
	
public:

	void SetInputs(FRotator* InSource);

	virtual FRotator Evaluate(const FEvaluationContext& InContext) override;

private:

	FRotator* Source = nullptr;

};

/**
 *
 */
UCLASS()
class ANIMATIONS_API UGetRotatorImmediate : public URotatorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(FRotator InValue);

	virtual FRotator Evaluate(const FEvaluationContext& InContext) override;

private:

	FRotator Value = FRotator::ZeroRotator;

};

