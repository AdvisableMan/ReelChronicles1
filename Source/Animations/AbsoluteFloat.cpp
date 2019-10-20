// Fill out your copyright notice in the Description page of Project Settings.


#include "AbsoluteFloat.h"

void UAbsoluteFloat::SetInputs(UFloatExpression* InValue)
{
	Value = InValue;
}

float UAbsoluteFloat::Evaluate(const FEvaluationContext& InContext)
{
	return FMath::Abs(Value->Evaluate(InContext));
}
