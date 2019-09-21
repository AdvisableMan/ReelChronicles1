// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseExpression.h"
#include "EvaluationContext.h"
#include "VoidExpression.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UVoidExpression : public UBaseExpression
{
    GENERATED_BODY()
    
public:

    virtual void Evaluate(const FEvaluationContext& InContext);

};
