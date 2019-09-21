// Fill out your copyright notice in the Description page of Project Settings.

#include "RemapFloat.h"

void URemapFloat::SetInputs(UFloatExpression* Value, UFloatExpression* OldA, UFloatExpression* OldB, UFloatExpression*NewA, UFloatExpression* NewB)
{
	i = Value;
	A = OldA;
	B = OldB;
	X = NewA;
	Y = NewB;
}

float URemapFloat::Evaluate(const FEvaluationContext& InContext)
{
	return ((i->Evaluate(InContext) - A->Evaluate(InContext)) / (B->Evaluate(InContext) - A->Evaluate(InContext)))*(Y->Evaluate(InContext) - X->Evaluate(InContext)) + X->Evaluate(InContext);
}