// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoidExpression.h"
#include "TraceExpression.h"
#include "SetTrace.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API USetTrace : public UVoidExpression
{
	GENERATED_BODY()

public:

	void SetInputs(FTraceStruct* InTarget, UTraceExpression* InSource);

	virtual void Evaluate(const FEvaluationContext& InContext);

private:

	// Float to write.
	FTraceStruct* Target = nullptr;

	// Float to read.
	UPROPERTY()
	UTraceExpression* Source = nullptr;
};
