// Fill out your copyright notice in the Description page of Project Settings.


#include "GetLocationFromCameraDirection.h"

void UGetLocationFromCameraDirection::SetInputs(UCameraComponent* InCamera, float InDistance)
{
	Camera = InCamera;
	Distance = InDistance;
}

FVector UGetLocationFromCameraDirection::Evaluate(const FEvaluationContext& InContext)
{
	//return Camera->GetComponentRotation()->GetForwardVector * Distance;
	//return FRotationMatrix(Camera->GetComponentRotation()).GetScaledAxis(EAxis::X) * Distance;
	if (Camera) { return Camera->GetForwardVector() * Distance; }
	else { return FVector::ZeroVector; }
}