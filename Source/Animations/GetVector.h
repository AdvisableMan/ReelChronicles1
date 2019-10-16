// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VectorExpression.h"
#include "FloatExpression.h"
#include "GetVector.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UGetVector : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(FVector* InSource);

	virtual FVector Evaluate(const FEvaluationContext& InContext) override;

private:

	FVector* Source = nullptr;

};

UCLASS()
class ANIMATIONS_API UGetVectorImmediate : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(FVector InValue);

	virtual FVector Evaluate(const FEvaluationContext& InContext) override;

private:

	FVector Value = FVector::ZeroVector;

};

UCLASS()
class ANIMATIONS_API UGetVectorX : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UVectorExpression* InValue);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UVectorExpression* Source = nullptr;

};
UCLASS()
class ANIMATIONS_API UGetVectorY : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UVectorExpression* InValue);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UVectorExpression* Source = nullptr;

};
UCLASS()
class ANIMATIONS_API UGetVectorZ : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UVectorExpression* InValue);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	UVectorExpression* Source = nullptr;

};