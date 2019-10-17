// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplyVector.h"

void UMultiplyVector::SetInputs(UVectorExpression* InA, UVectorExpression* InB)
{
	A = InA;
	B = InB;
}

FVector UMultiplyVector::Evaluate(const FEvaluationContext& InContext)
{
	return A->Evaluate(InContext) * B->Evaluate(InContext);
}