// Fill out your copyright notice in the Description page of Project Settings.


#include "SmoothRotator.h"

void USmoothRotator::SetInputs(URotatorExpression* InTarget, float InSpeed)
{
	Speed = InSpeed;
	Target = InTarget;
}

FRotator USmoothRotator::Evaluate(const FEvaluationContext& InContext)
{
	auto TargetValue = Target->Evaluate(InContext);

	if (!InContext.DoReset)
	{
		Current = FMath::RInterpTo(Current, TargetValue, InContext.DeltaTime, Speed);
	}
	else
	{
		Current = TargetValue;
	}

	return Current;
}

void USmoothRotatorConst::SetInputs(URotatorExpression* InTarget, float InSpeed)
{
	Speed = InSpeed;
	Target = InTarget;
}

FRotator USmoothRotatorConst::Evaluate(const FEvaluationContext& InContext)
{
	auto TargetValue = Target->Evaluate(InContext);

	if (!InContext.DoReset)
	{
		Current = FMath::RInterpConstantTo(Current, TargetValue, InContext.DeltaTime, Speed);
	}
	else
	{
		Current = TargetValue;
	}

	return Current;
}