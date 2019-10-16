// Fill out your copyright notice in the Description page of Project Settings.


#include "TraceExpression.h"

FTraceStruct UTraceExpression::Evaluate(const FEvaluationContext& InContext)
{
	return FTraceStruct{0.0f, FVector::ZeroVector, FVector::ZeroVector, false};
}

