// Fill out your copyright notice in the Description page of Project Settings.

#include "WeightedAverage3.h"

void UWeightedAverage3::SetInputs(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha)
{
	A = InA;
	Aa = InAAlpha;
	B = InB;
	Ba = InBAlpha;
	C = InC;
	Ca = InCAlpha;
}

float UWeightedAverage3::Evaluate(const FEvaluationContext& InContext)
{
	return ((A->Evaluate(InContext) *Aa->Evaluate(InContext)) + (B->Evaluate(InContext)*Ba->Evaluate(InContext)) + (C->Evaluate(InContext)*Ca->Evaluate(InContext))) / (Aa->Evaluate(InContext) + Ba->Evaluate(InContext) + Ca->Evaluate(InContext));
}
