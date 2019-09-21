// Fill out your copyright notice in the Description page of Project Settings.

#include "GetBoolean.h"

void UGetBoolean::SetInputs(bool* InSource)
{
	Source = InSource;
}

float UGetBoolean::Evaluate(const FEvaluationContext& InContext)
{
	return *Source;
}

void UGetBooleanImmediate::SetInputs(bool InValue)
{
	Value = InValue;
}

float UGetBooleanImmediate::Evaluate(const FEvaluationContext& InContext)
{
	return Value;
}