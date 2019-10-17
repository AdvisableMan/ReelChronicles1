// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VectorExpression.h"
#include "AddVector.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UAddVector : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UVectorExpression* InA, UVectorExpression* InB);

	FVector Evaluate(const FEvaluationContext& InContext) override;

private:

	UPROPERTY()
		UVectorExpression* A = nullptr;

	UPROPERTY()
		UVectorExpression* B = nullptr;
};
