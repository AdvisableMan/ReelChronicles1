// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/SkeletalMesh.h"
#include "VectorExpression.h"
#include "RotatorExpression.h"
#include "GetSocketTransform.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UGetSocketLocation : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(USkeletalMeshComponent* InSkeletalMesh, FName InName);

	virtual FVector Evaluate(const FEvaluationContext& InContext);

private:

	USkeletalMeshComponent* SkeletalMesh = nullptr;
	FName Name = "";

};
UCLASS()
class ANIMATIONS_API UGetSocketRotation : public URotatorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(USkeletalMeshComponent* InSkeletalMesh, FName InName);

	virtual FRotator Evaluate(const FEvaluationContext& InContext);

private:

	USkeletalMeshComponent* SkeletalMesh = nullptr;
	FName Name = "";

};