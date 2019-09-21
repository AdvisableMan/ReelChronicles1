// Fill out your copyright notice in the Description page of Project Settings.

#include "SmoothFloatConst.h"

void USmoothFloatConst::SetInputs(UFloatExpression* InTarget, float InSpeed)
{
	Speed = InSpeed;
	Target = InTarget;
}

float USmoothFloatConst::Evaluate(const FEvaluationContext& InContext)
{
	auto TargetValue = Target->Evaluate(InContext);

	if (!InContext.DoReset)
	{
		Current = FMath::FInterpConstantTo(Current, TargetValue, InContext.DeltaTime, Speed);
	}
	else
	{
		Current = TargetValue;
	}

	return Current;
}