// Fill out your copyright notice in the Description page of Project Settings.

#include "SetFloat.h"

void USetFloat::SetInputs(float* InTarget, UFloatExpression* InSource)
{
    Target = InTarget;
    Source = InSource;
}

void USetFloat::Evaluate(const FEvaluationContext& InContext)
{
    *Target = Source->Evaluate(InContext);
}


