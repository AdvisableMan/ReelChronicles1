// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoidExpression.h"
#include "FloatExpression.h"
#include "SetFloat.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API USetFloat : public UVoidExpression
{
    GENERATED_BODY()

public:

    void SetInputs(float* InTarget, UFloatExpression* InSource);

    virtual void Evaluate(const FEvaluationContext& InContext);

private:

    // Float to write.
    float* Target = nullptr;

    // Float to read.
    UPROPERTY()
    UFloatExpression* Source = nullptr;
};
