// Fill out your copyright notice in the Description page of Project Settings.

#include "AddRotator.h"

void UAddRotator::SetInputs(URotatorExpression* InA, URotatorExpression* InB)
{
	A = InA;
	B = InB;
}

FRotator UAddRotator::Evaluate(const FEvaluationContext& InContext)
{
	return A->Evaluate(InContext) + B->Evaluate(InContext);
}


