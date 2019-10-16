// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VoidExpression.h"
#include "VectorExpression.h"
#include "SetVector.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API USetVector : public UVoidExpression
{
	GENERATED_BODY()

public:

	void SetInputs(FVector* InTarget, UVectorExpression* InSource);

	virtual void Evaluate(const FEvaluationContext& InContext);

private:

	// Float to write.
	FVector* Target = nullptr;

	// Float to read.
	UPROPERTY()
	UVectorExpression* Source = nullptr;
};
