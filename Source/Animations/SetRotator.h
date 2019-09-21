// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoidExpression.h"
#include "RotatorExpression.h"
#include "SetRotator.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API USetRotator : public UVoidExpression
{
	GENERATED_BODY()

public:

	void SetInputs(FRotator* InTarget, URotatorExpression* InSource);

	virtual void Evaluate(const FEvaluationContext& InContext);

private:

	// Float to write.
	FRotator* Target = nullptr;

	// Float to read.
	UPROPERTY()
	URotatorExpression* Source = nullptr;
};
