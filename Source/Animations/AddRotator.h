// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RotatorExpression.h"
#include "AddRotator.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UAddRotator : public URotatorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(URotatorExpression* InA, URotatorExpression* InB);

	FRotator Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
	URotatorExpression* A = nullptr;

	UPROPERTY()
	URotatorExpression* B = nullptr;
};