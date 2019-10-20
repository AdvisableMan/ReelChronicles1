// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "AbsoluteFloat.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UAbsoluteFloat : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UFloatExpression* InValue);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
		UFloatExpression* Value = nullptr;

};