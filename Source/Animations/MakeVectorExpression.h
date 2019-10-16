// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "VectorExpression.h"
#include "MakeVectorExpression.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UMakeVectorExpression : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UFloatExpression* InX, UFloatExpression* InY, UFloatExpression* InZ);

	virtual FVector Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
		UFloatExpression* X = nullptr;

	UPROPERTY()
		UFloatExpression* Y = nullptr;

	UPROPERTY()
		UFloatExpression* Z = nullptr;

};