// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "RemapFloat.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API URemapFloat : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UFloatExpression* Value, UFloatExpression* OldA, UFloatExpression* OldB, UFloatExpression*NewA, UFloatExpression* NewB);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
		UFloatExpression* i = nullptr;

	UPROPERTY()
		UFloatExpression* A = nullptr;

	UPROPERTY()
		UFloatExpression* B = nullptr;

	UPROPERTY()
		UFloatExpression* X = nullptr;

	UPROPERTY()
		UFloatExpression* Y = nullptr;
};
