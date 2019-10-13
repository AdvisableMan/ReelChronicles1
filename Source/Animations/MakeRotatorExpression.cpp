// Fill out your copyright notice in the Description page of Project Settings.


#include "MakeRotatorExpression.h"

void UMakeRotatorExpression::SetInputs(UFloatExpression* InPitch, UFloatExpression* InYaw, UFloatExpression* InRoll)
{
	Roll = InRoll;
	Yaw = InYaw;
	Pitch = InPitch;
}

FRotator UMakeRotatorExpression::Evaluate(const FEvaluationContext& InContext)
{
	FRotator test = FRotator(0.0f, 0.0f, 0.0f);
	return FRotator(Pitch->Evaluate(InContext), Yaw->Evaluate(InContext), Roll->Evaluate(InContext));
}