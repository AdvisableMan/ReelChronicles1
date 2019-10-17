// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplyRotator.h"

void UMultiplyRotator::SetInputs(URotatorExpression* InA, URotatorExpression* InB)
{
	A = InA;
	B = InB;
}

FRotator UMultiplyRotator::Evaluate(const FEvaluationContext& InContext)
{
	return FRotator(A->Evaluate(InContext).Pitch * B->Evaluate(InContext).Pitch, A->Evaluate(InContext).Yaw * B->Evaluate(InContext).Yaw, A->Evaluate(InContext).Roll * B->Evaluate(InContext).Roll);
}