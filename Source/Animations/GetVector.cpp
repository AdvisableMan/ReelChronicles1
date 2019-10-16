// Fill out your copyright notice in the Description page of Project Settings.


#include "GetVector.h"

void UGetVector::SetInputs(FVector* InSource)
{
	Source = InSource;
}

FVector UGetVector::Evaluate(const FEvaluationContext& InContext)
{
	return *Source;
}

void UGetVectorImmediate::SetInputs(FVector InValue)
{
	Value = InValue;
}

FVector UGetVectorImmediate::Evaluate(const FEvaluationContext& InContext)
{
	return Value;
}

void UGetVectorX::SetInputs(UVectorExpression* InValue)
{
	Source = InValue;
}
float UGetVectorX::Evaluate(const FEvaluationContext& InContext)
{
	return Source->Evaluate(InContext).X;
}
void UGetVectorY::SetInputs(UVectorExpression* InValue)
{
	Source = InValue;
}
float UGetVectorY::Evaluate(const FEvaluationContext& InContext)
{
	return Source->Evaluate(InContext).Y;
}
void UGetVectorZ::SetInputs(UVectorExpression* InValue)
{
	Source = InValue;
}
float UGetVectorZ::Evaluate(const FEvaluationContext& InContext)
{
	return Source->Evaluate(InContext).Z;
}