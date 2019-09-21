// Fill out your copyright notice in the Description page of Project Settings.

#include "SmoothFloat.h"

void USmoothFloat::SetInputs(UFloatExpression* InTarget, float InSpeed)
{
    Speed = InSpeed;
    Target = InTarget;
}

float USmoothFloat::Evaluate(const FEvaluationContext& InContext)
{
    auto TargetValue = Target->Evaluate(InContext);

    if (!InContext.DoReset)
    {
        Current = FMath::FInterpTo(Current, TargetValue, InContext.DeltaTime, Speed);
    }
    else
    {
        Current = TargetValue;
    }

    return Current;
}
