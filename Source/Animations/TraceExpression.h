// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseExpression.h"
#include "VectorExpression.h"
#include "TraceExpression.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UTraceExpression : public UBaseExpression
{
	GENERATED_BODY()

public:

	virtual FTraceStruct Evaluate(const FEvaluationContext& InContext);

};

USTRUCT(BlueprintType)
struct ANIMATIONS_API FTraceStruct
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HitDistance = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HitLocation = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector HitImpactNormal = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ValidHit = 0;
};