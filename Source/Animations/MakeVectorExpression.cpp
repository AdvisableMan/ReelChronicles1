// Fill out your copyright notice in the Description page of Project Settings.


#include "MakeVectorExpression.h"

void UMakeVectorExpression::SetInputs(UFloatExpression* InX, UFloatExpression* InY, UFloatExpression* InZ)
{
	X = InX;
	Y = InY;
	Z = InZ;
}

FVector UMakeVectorExpression::Evaluate(const FEvaluationContext& InContext)
{
	return FVector(X->Evaluate(InContext), Y->Evaluate(InContext), Z->Evaluate(InContext));
}