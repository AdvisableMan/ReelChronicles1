// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RotatorExpression.h"
#include "FloatExpression.h"
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

UCLASS()
class ANIMATIONS_API UGetRotatorPitch : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(URotatorExpression* InValue);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	URotatorExpression* Source = nullptr;

};
UCLASS()
class ANIMATIONS_API UGetRotatorYaw : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(URotatorExpression* InValue);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	URotatorExpression* Source = nullptr;

};
UCLASS()
class ANIMATIONS_API UGetRotatorRoll : public UFloatExpression
{
	GENERATED_BODY()

public:

	void SetInputs(URotatorExpression* InValue);

	float Evaluate(const FEvaluationContext& InContext) override;

private:

	URotatorExpression* Source = nullptr;

};