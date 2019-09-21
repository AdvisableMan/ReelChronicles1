// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseExpression.h"
#include "FloatExpression.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UFloatExpression : public UBaseExpression
{
    GENERATED_BODY()
    
public:

    virtual float Evaluate(const FEvaluationContext& InContext);

};
