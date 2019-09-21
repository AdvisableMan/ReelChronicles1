// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseExpression.h"

#include "RotatorExpression.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API URotatorExpression : public UBaseExpression
{
	GENERATED_BODY()
	
public:

	virtual FRotator Evaluate(const FEvaluationContext& InContext);

};
