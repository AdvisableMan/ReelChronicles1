// Fill out your copyright notice in the Description page of Project Settings.


#include "SetVector.h"

void USetVector::SetInputs(FVector* InTarget, UVectorExpression* InSource)
{
	Target = InTarget;
	Source = InSource;
}

void USetVector::Evaluate(const FEvaluationContext& InContext)
{
	*Target = Source->Evaluate(InContext);
}

