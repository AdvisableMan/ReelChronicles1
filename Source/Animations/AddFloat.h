// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "AddFloat.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UAddFloat : public UFloatExpression
{
    GENERATED_BODY()

public:

    void SetInputs(UFloatExpression* InA, UFloatExpression* InB);

    float Evaluate(const FEvaluationContext& InContext) override;

private:
    
    UPROPERTY()
    UFloatExpression* A = nullptr;

    UPROPERTY()
    UFloatExpression* B = nullptr;
};
