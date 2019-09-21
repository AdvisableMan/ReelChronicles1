// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "GetFloat.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UGetFloat : public UFloatExpression
{
    GENERATED_BODY()

public:

    void SetInputs(float* InSource);

    virtual float Evaluate(const FEvaluationContext& InContext) override;

private:

    float* Source = nullptr;

};

/**
 *
 */
UCLASS()
class ANIMATIONS_API UGetFloatImmediate : public UFloatExpression
{
    GENERATED_BODY()

public:

    void SetInputs(float InValue);

    virtual float Evaluate(const FEvaluationContext& InContext) override;

private:

    float Value = 0.0f;

};

