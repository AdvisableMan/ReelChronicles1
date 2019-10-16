// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VectorExpression.h"
#include "SmoothVector.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API USmoothVector : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UVectorExpression* InTarget, float InSpeed);

	virtual FVector Evaluate(const FEvaluationContext& InContext) override;

private:

	float Speed = 0.0f;

	UPROPERTY()
	UVectorExpression* Target = nullptr;

	FVector Current = FVector::ZeroVector;
};
UCLASS()
class ANIMATIONS_API USmoothVectorConst : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UVectorExpression* InTarget, float InSpeed);

	virtual FVector Evaluate(const FEvaluationContext& InContext) override;

private:

	float Speed = 0.0f;

	UPROPERTY()
		UVectorExpression* Target = nullptr;

	FVector Current = FVector::ZeroVector;
};