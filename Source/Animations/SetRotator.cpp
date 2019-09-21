// Fill out your copyright notice in the Description page of Project Settings.

#include "SetRotator.h"

void USetRotator::SetInputs(FRotator* InTarget, URotatorExpression* InSource)
{
	Target = InTarget;
	Source = InSource;
}

void USetRotator::Evaluate(const FEvaluationContext& InContext)
{
	*Target = Source->Evaluate(InContext);
}


