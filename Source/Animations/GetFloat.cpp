// Fill out your copyright notice in the Description page of Project Settings.

#include "GetFloat.h"

void UGetFloat::SetInputs(float* InSource)
{
    Source = InSource;
}

float UGetFloat::Evaluate(const FEvaluationContext& InContext)
{
    return *Source;
}

void UGetFloatImmediate::SetInputs(float InValue)
{
    Value = InValue;
}

float UGetFloatImmediate::Evaluate(const FEvaluationContext& InContext)
{
    return Value;
}

