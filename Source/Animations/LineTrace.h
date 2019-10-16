// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatExpression.h"
#include "TraceExpression.h"
#include "Components/SkeletalMeshComponent.h"
#include "LineTrace.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API ULineTrace : public UTraceExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UFloatExpression* InCondition, UVectorExpression* InStart, UVectorExpression* InEnd, bool InDebug);

	virtual FTraceStruct Evaluate(const FEvaluationContext& InContext) override;

private:
	UPROPERTY()
	UFloatExpression* Condition = nullptr;
	UPROPERTY()
	bool Debug = false;
	UPROPERTY()
	UVectorExpression* Start = nullptr;
	UPROPERTY()
	UVectorExpression* End = nullptr;
};