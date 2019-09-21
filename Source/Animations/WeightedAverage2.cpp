// Fill out your copyright notice in the Description page of Project Settings.

#include "WeightedAverage2.h"

void UWeightedAverage2::SetInputs(UFloatExpression* InA, UFloatExpression* InB, UFloatExpression* InBAlpha)
{
	A = InA;
	B = InB;
	Ba = InBAlpha;
}

float UWeightedAverage2::Evaluate(const FEvaluationContext& InContext)
{
	return (A->Evaluate(InContext) * (1 - Ba->Evaluate(InContext)) + (B->Evaluate(InContext) * Ba->Evaluate(InContext)));
}
