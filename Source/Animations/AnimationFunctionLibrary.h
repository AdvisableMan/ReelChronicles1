// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "FloatExpression.h"
#include "VoidExpression.h"

#include "AnimationFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UAnimationFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
    
public:

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(CompactNodeTitle = "getFloat"), Category = "Script||Get\Set")
    static UFloatExpression* GetFloat(UPARAM(ref) float& Source);
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "___ getF"), Category = "Script||Get\Set")
    static UFloatExpression* GetConstantFloat(float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "getBool"), Category = "Script||Get\Set")
	static UFloatExpression* GetBoolean(UPARAM(ref) bool& Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "___ getB"), Category = "Script||Get\Set")
	static UFloatExpression* GetConstantBoolean(bool Value);

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
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "setFloat"), Category = "Script||Get\Set")
    static UVoidExpression* SetFloat(UPARAM(ref) float& Target, UFloatExpression* Source);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "setRot"), Category = "Script||Get\Set")
	static UVoidExpression* SetRotator(UPARAM(ref) FRotator& Target, URotatorExpression* Source);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "f+f"), Category = "Script||Math")
	static UFloatExpression* AddFloat(UFloatExpression* A, UFloatExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "f*f"), Category = "Script||Math")
	static UFloatExpression* MultiplyFloat(UFloatExpression* A, UFloatExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* SmoothFloatConst(UFloatExpression* Value, float Speed);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* Lerp(UFloatExpression* InA, UFloatExpression* InB, UFloatExpression* Alpha);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* WeightedAverage3(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* WeightedAverage4(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha, UFloatExpression* InD, UFloatExpression* InDAlpha);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static UFloatExpression* RemapFloat(UFloatExpression* i, UFloatExpression* A, UFloatExpression* B, UFloatExpression* X, UFloatExpression* Y);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (CompactNodeTitle = "r+r"), Category = "Script||Math")
	static URotatorExpression* AddRotator(URotatorExpression* A, URotatorExpression* B);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Script||Math")
	static URotatorExpression* MakeRotatorExpression(UFloatExpression* Pitch, UFloatExpression* Yaw, UFloatExpression* Roll);
    UFUNCTION(BlueprintCallable, BlueprintPure,  Category = "Script||Math")
    static UFloatExpression* SmoothFloat(UFloatExpression* Value, float Speed);

};
