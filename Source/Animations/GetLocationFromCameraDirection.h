// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "VectorExpression.h"
#include "GetLocationFromCameraDirection.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UGetLocationFromCameraDirection : public UVectorExpression
{
	GENERATED_BODY()

public:

	void SetInputs(UCameraComponent* InCamera, float InDistance);

	virtual FVector Evaluate(const FEvaluationContext& InContext);

private:

	UCameraComponent* Camera = nullptr;
	float Distance = 0.0f;

};
