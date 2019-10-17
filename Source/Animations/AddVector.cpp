// Fill out your copyright notice in the Description page of Project Settings.


#include "AddVector.h"

void UAddVector::SetInputs(UVectorExpression* InA, UVectorExpression* InB)
{
	A = InA;
	B = InB;
}

FVector UAddVector::Evaluate(const FEvaluationContext& InContext)
{
	return A->Evaluate(InContext) + B->Evaluate(InContext);
}


