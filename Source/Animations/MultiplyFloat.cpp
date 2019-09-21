// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiplyFloat.h"

void UMultiplyFloat::SetInputs(UFloatExpression* InA, UFloatExpression* InB)
{
	A = InA;
	B = InB;
}

float UMultiplyFloat::Evaluate(const FEvaluationContext& InContext)
{
	return A->Evaluate(InContext) * B->Evaluate(InContext);
}