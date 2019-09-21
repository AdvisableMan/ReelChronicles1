// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "SmoothFloat.generated.h"

/**
 *
 */
UCLASS()
class ANIMATIONS_API USmoothFloat : public UFloatExpression
{
    GENERATED_BODY()

public:

    void SetInputs(UFloatExpression* InTarget, float InSpeed);

    virtual float Evaluate(const FEvaluationContext& InContext) override;

private:

    float Speed = 0.0f;

    UPROPERTY()
    UFloatExpression* Target = nullptr;

    float Current = 0.0f;
};