// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Containers/Array.h"

#include "VoidExpression.h"

#include "BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ANIMATIONS_API UBaseAnimInstance : public UAnimInstance
{
    GENERATED_BODY()
    
public:

    virtual void NativeInitializeAnimation() override;

    virtual void NativeUninitializeAnimation() override;

    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Script")
	void LoadScript(UVoidExpression* InScript);

	UFUNCTION(BlueprintCallable, Category = "Script")
	void LoadScripts(TArray<UVoidExpression*> InScripts);

private:

    // List of scripts that needs to be evaluated on each frame.
    UPROPERTY()
    TArray<UVoidExpression*> Scripts;

    bool bNeedsReset = true;
};
