// Fill out your copyright notice in the Description page of Project Settings.

#include "GetRotator.h"

void UGetRotator::SetInputs(FRotator* InSource)
{
	Source = InSource;
}

FRotator UGetRotator::Evaluate(const FEvaluationContext& InContext)
{
	return *Source;
}

void UGetRotatorImmediate::SetInputs(FRotator InValue)
{
	Value = InValue;
}

FRotator UGetRotatorImmediate::Evaluate(const FEvaluationContext& InContext)
{
	return Value;
}

void UGetRotatorPitch::SetInputs(URotatorExpression* InValue)
{
	Source = InValue;
}
float UGetRotatorPitch::Evaluate(const FEvaluationContext& InContext)
{
	return Source->Evaluate(InContext).Pitch;
}
void UGetRotatorYaw::SetInputs(URotatorExpression* InValue)
{
	Source = InValue;
}
float UGetRotatorYaw::Evaluate(const FEvaluationContext& InContext)
{
	return Source->Evaluate(InContext).Yaw;
}
void UGetRotatorRoll::SetInputs(URotatorExpression* InValue)
{
	Source = InValue;
}
float UGetRotatorRoll::Evaluate(const FEvaluationContext& InContext)
{
	return Source->Evaluate(InContext).Roll;
}