// Fill out your copyright notice in the Description page of Project Settings.

#include "GetRotator.h"

void UGetRotator::SetInputs(FRotator* InSource)
{
	Source = InSource;
}

FRotator UGetRotator::Evaluate(const FEvaluationContext& InContext)
{
	return *Source;
}

void UGetRotatorImmediate::SetInputs(FRotator InValue)
{
	Value = InValue;
}

FRotator UGetRotatorImmediate::Evaluate(const FEvaluationContext& InContext)
{
	return Value;
}

