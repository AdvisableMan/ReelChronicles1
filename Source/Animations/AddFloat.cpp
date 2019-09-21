// Fill out your copyright notice in the Description page of Project Settings.

#include "AddFloat.h"

void UAddFloat::SetInputs(UFloatExpression* InA, UFloatExpression* InB)
{
    A = InA;
    B = InB;
}

float UAddFloat::Evaluate(const FEvaluationContext& InContext)
{
    return A->Evaluate(InContext) + B->Evaluate(InContext);
}


