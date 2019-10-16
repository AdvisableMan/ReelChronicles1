// Fill out your copyright notice in the Description page of Project Settings.


#include "SmoothVector.h"

void USmoothVector::SetInputs(UVectorExpression* InTarget, float InSpeed)
{
	Speed = InSpeed;
	Target = InTarget;
}

FVector USmoothVector::Evaluate(const FEvaluationContext& InContext)
{
	auto TargetValue = Target->Evaluate(InContext);

	if (!InContext.DoReset)
	{
		Current = FMath::VInterpTo(Current, TargetValue, InContext.DeltaTime, Speed);
	}
	else
	{
		Current = TargetValue;
	}

	return Current;
}

void USmoothVectorConst::SetInputs(UVectorExpression* InTarget, float InSpeed)
{
	Speed = InSpeed;
	Target = InTarget;
}

FVector USmoothVectorConst::Evaluate(const FEvaluationContext& InContext)
{
	auto TargetValue = Target->Evaluate(InContext);

	if (!InContext.DoReset)
	{
		Current = FMath::VInterpConstantTo(Current, TargetValue, InContext.DeltaTime, Speed);
	}
	else
	{
		Current = TargetValue;
	}

	return Current;
}