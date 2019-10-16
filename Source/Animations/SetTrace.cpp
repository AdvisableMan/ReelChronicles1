// Fill out your copyright notice in the Description page of Project Settings.


#include "SetTrace.h"

void USetTrace::SetInputs(FTraceStruct* InTarget, UTraceExpression* InSource)
{
	Target = InTarget;
	Source = InSource;
}

void USetTrace::Evaluate(const FEvaluationContext& InContext)
{
	*Target = Source->Evaluate(InContext);
}


