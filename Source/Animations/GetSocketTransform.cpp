// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseExpression.h"
#include "GetSocketTransform.h"
#include "Engine.h"

void UGetSocketLocation::SetInputs(USkeletalMeshComponent* InSkeletalMesh, FName InName)
{
	SkeletalMesh = InSkeletalMesh;
	Name = InName;
}

FVector UGetSocketLocation::Evaluate(const FEvaluationContext& InContext)
{
	return SkeletalMesh->GetSocketLocation(Name);
}

void UGetSocketRotation::SetInputs(USkeletalMeshComponent* InSkeletalMesh, FName InName)
{
	SkeletalMesh = InSkeletalMesh;
	Name = InName;
}

FRotator UGetSocketRotation::Evaluate(const FEvaluationContext& InContext)
{
	return SkeletalMesh->GetSocketRotation(Name);
}
