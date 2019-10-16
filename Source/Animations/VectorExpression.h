// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseExpression.h"
#include "VectorExpression.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UVectorExpression : public UBaseExpression
{
	GENERATED_BODY()

public:

	virtual FVector Evaluate(const FEvaluationContext& InContext);

};
