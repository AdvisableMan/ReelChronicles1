// Fill out your copyright notice in the Description page of Project Settings.

#include "WeightedAverage4.h"

void UWeightedAverage4::SetInputs(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha, UFloatExpression* InD, UFloatExpression* InDAlpha)
{
	A = InA;
	Aa = InAAlpha;
	B = InB;
	Ba = InBAlpha;
	C = InC;
	Ca = InCAlpha;
	D = InD;
	Da = InDAlpha;
}

float UWeightedAverage4::Evaluate(const FEvaluationContext& InContext)
{
	return ((A->Evaluate(InContext) *(Aa->Evaluate(InContext)) + (B->Evaluate(InContext)*Ba->Evaluate(InContext)) + (C->Evaluate(InContext)*Ca->Evaluate(InContext)) + (D->Evaluate(InContext)*Da->Evaluate(InContext))) / (Aa->Evaluate(InContext) + Ba->Evaluate(InContext) + Ca->Evaluate(InContext) + Da->Evaluate(InContext)));
}
