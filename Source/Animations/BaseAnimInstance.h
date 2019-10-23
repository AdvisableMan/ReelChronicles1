// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Containers/Array.h"

#include "VoidExpression.h"
#include "BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Code||References")
	ABaseCharacter* Character = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Code||References")
	USkeletalMeshComponent* Mesh = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Code||References")
	UCharacterMovementComponent* MovementComponent = nullptr;

private:

    // List of scripts that needs to be evaluated on each frame.
    UPROPERTY()
    TArray<UVoidExpression*> Scripts;

    bool bNeedsReset = true;

	float CapsuleHalfHeight = 0.0f;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code||CharacterStates")
	bool IsInAir = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code||CharacterStates")
	bool IsSprinting = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code||CharacterStates")
	float GroundDistance = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code||MovementInputs")
	float InputX_Anim = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code||MovementInputs")
	float InputZ_Anim = 0.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Code||MovementInputs")
	float Direction = 0.0f;

};
