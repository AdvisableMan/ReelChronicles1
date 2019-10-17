// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "FloatExpression.h"
#include "VoidExpression.h"
#include "TraceExpression.h"

#include "Camera/CameraComponent.h"

#include "AnimationFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UAnimationFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
    
public:
	// Get Float
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(CompactNodeTitle = "getFloat"), Category = "Script||Get\Set")
    static UFloatExpression* GetFloat(UPARAM(ref) float& Source);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "___ getF"), Category = "Script||Get\Set")
    static UFloatExpression* GetConstantFloat(float Value);
	// Get Boolean
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getBool"), Category = "Script||Get\Set")
	static UFloatExpression* GetBoolean(UPARAM(ref) bool& Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "___ getB"), Category = "Script||Get\Set")
	static UFloatExpression* GetConstantBoolean(bool Value);
	// Get Rotator
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getRot"), Category = "Script||Get\Set")
	static URotatorExpression* GetRotator(UPARAM(ref) FRotator& Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "___ getR"), Category = "Script||Get\Set")
	static URotatorExpression* GetConstantRotator(FRotator Value);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getPitch"), Category = "Script||Get\Set")
	static UFloatExpression* GetRotatorPitch(URotatorExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getYaw"), Category = "Script||Get\Set")
	static UFloatExpression* GetRotatorYaw(URotatorExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getRoll"), Category = "Script||Get\Set")
	static UFloatExpression* GetRotatorRoll(URotatorExpression* Source);
    // Get Vector
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getVec"), Category = "Script||Get\Set")
	static UVectorExpression* GetVector(UPARAM(ref) FVector& Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "___ getV"), Category = "Script||Get\Set")
	static UVectorExpression* GetConstantVector(FVector Value);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getX"), Category = "Script||Get\Set")
	static UFloatExpression* GetVectorX(UVectorExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getY"), Category = "Script||Get\Set")
	static UFloatExpression* GetVectorY(UVectorExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getZ"), Category = "Script||Get\Set")
	static UFloatExpression* GetVectorZ(UVectorExpression* Source);

	// Set
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "setFloat"), Category = "Script||Get\Set")
    static UVoidExpression* SetFloat(UPARAM(ref) float& Target, UFloatExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "setRot"), Category = "Script||Get\Set")
	static UVoidExpression* SetRotator(UPARAM(ref) FRotator& Target, URotatorExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "setVec"), Category = "Script||Get\Set")
	static UVoidExpression* SetVector(UPARAM(ref) FVector& Target, UVectorExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "setTrace"), Category = "Script||Get\Set")
	static UVoidExpression* SetTrace(UPARAM(ref) FTraceStruct& Target, UTraceExpression* Source);

	// Math Float
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "f+f"), Category = "Script||Math")
	static UFloatExpression* AddFloat(UFloatExpression* A, UFloatExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "f*f"), Category = "Script||Math")
	static UFloatExpression* MultiplyFloat(UFloatExpression* A, UFloatExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* Lerp(UFloatExpression* InA, UFloatExpression* InB, UFloatExpression* Alpha);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* WeightedAverage3(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* WeightedAverage4(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha, UFloatExpression* InD, UFloatExpression* InDAlpha);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* RemapFloat(UFloatExpression* i, UFloatExpression* A, UFloatExpression* B, UFloatExpression* X, UFloatExpression* Y);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* SmoothFloat(UFloatExpression* Value, float Speed);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* SmoothFloatConst(UFloatExpression* Value, float Speed);
	// Math Rotator
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static URotatorExpression* SmoothRotator(URotatorExpression* Value, float Speed);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static URotatorExpression* SmoothRotatorConst(URotatorExpression* Value, float Speed);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "r+r"), Category = "Script||Math")
	static URotatorExpression* AddRotator(URotatorExpression* A, URotatorExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "r*r"), Category = "Script||Math")
	static URotatorExpression* MultiplyRotator(URotatorExpression* A, URotatorExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static URotatorExpression* MakeRotatorExpression(UFloatExpression* Pitch, UFloatExpression* Yaw, UFloatExpression* Roll);
	// Math Vector
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UVectorExpression* SmoothVector(UVectorExpression* Value, float Speed);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UVectorExpression* SmoothVectorConst(UVectorExpression* Value, float Speed);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "v+v"), Category = "Script||Math")
	static UVectorExpression* AddVector(UVectorExpression* A, UVectorExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "v*v"), Category = "Script||Math")
	static UVectorExpression* MultiplyVector(UVectorExpression* A, UVectorExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UVectorExpression* MakeVectorExpression(UFloatExpression* X, UFloatExpression* Y, UFloatExpression* Z);
	// Trace
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Trace")
	static UTraceExpression* LineTrace(UFloatExpression* InCondition, UVectorExpression* InStart, UVectorExpression* InEnd, bool InDebug);
	// Get Socket Transform
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getLoc"), Category = "Script||Get\Set")
	static UVectorExpression* GetSocketLocation(USkeletalMeshComponent* InSkeletalMesh, FName InName);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getRot"), Category = "Script||Get\Set")
	static URotatorExpression* GetSocketRotation(USkeletalMeshComponent* InSkeletalMesh, FName InName);
	// Get point from Camera position
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Get\Set")
	static UVectorExpression* GetLocationFromCameraDirection(UCameraComponent* InCamera, float InDistance);
};
