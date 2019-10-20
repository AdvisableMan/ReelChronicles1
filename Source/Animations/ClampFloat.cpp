// Fill out your copyright notice in the Description page of Project Settings.


#include "ClampFloat.h"

void UClampFloat::SetInputs(UFloatExpression* InValue, float InRangeA, float InRangeB)
{
	Value = InValue;
	RangeA = InRangeA;
	RangeB = InRangeB;
}

float UClampFloat::Evaluate(const FEvaluationContext& InContext)
{
	return FMath::Clamp(Value->Evaluate(InContext), RangeA, RangeB);
}

void UClampFloatVariable::SetInputs(UFloatExpression* InValue, UFloatExpression* InRangeA, UFloatExpression* InRangeB)
{
	Value = InValue;
	RangeA = InRangeA;
	RangeB = InRangeB;
}

float UClampFloatVariable::Evaluate(const FEvaluationContext& InContext)
{
	return FMath::Clamp(Value->Evaluate(InContext), RangeA->Evaluate(InContext), RangeB->Evaluate(InContext));
}


