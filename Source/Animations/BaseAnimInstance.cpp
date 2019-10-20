// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAnimInstance.h"
#include "Components/CapsuleComponent.h"


void UBaseAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    // Load scripts...
    bNeedsReset = true;

	Character = Cast<ABaseCharacter>(GetOwningActor());
	if (Character)
	{
		Mesh = GetOwningComponent();
		MovementComponent = Character->GetCharacterMovement();
		CapsuleHalfHeight = Character->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	}

}

void UBaseAnimInstance::NativeUninitializeAnimation()
{
    Super::NativeUninitializeAnimation();

    // Remove scripts...
    Scripts.Reset();
}

void UBaseAnimInstance::LoadScript(UVoidExpression* InScript)
{
    if (InScript)
    {
        Scripts.Push(InScript);
    }
}
void UBaseAnimInstance::LoadScripts(TArray<UVoidExpression*> InScripts)
{
	for (auto&& Script : InScripts)
	{
		if (Script) { Scripts.Push(Script); }
	}
}

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

	/// S C R I P T S
    // Setup execution context
    FEvaluationContext Context;
    Context.DeltaTime = DeltaSeconds;
	Context.World = GetOwningComponent()->GetWorld();
    Context.DoReset = bNeedsReset;
    // Evaluate scripts...
    for (auto&& Script : Scripts)
    {
        Script->Evaluate(Context);
    }
    bNeedsReset = false;

	/// Populate variables
	if (Character)
	{
		IsInAir = (MovementComponent->MovementMode == EMovementMode::MOVE_Falling);
		IsSprinting = Character->IsSprinting;

		// If in air, trace ground distance
		if (IsInAir)
		{
			FCollisionQueryParams TraceParams(FName(TEXT("HitTraceParams")), true);
			//TraceParams.bTraceComplex = true;
			FHitResult OutHit;
			FVector Start = FVector(Character->GetActorLocation().X, Character->GetActorLocation().Y, Character->GetActorLocation().Z - CapsuleHalfHeight);
			GetWorld()->LineTraceSingleByChannel(
				OutHit,        //result
				FVector(Character->GetActorLocation().X, Character->GetActorLocation().Y, Character->GetActorLocation().Z - CapsuleHalfHeight),    //start
				FVector(Character->GetActorLocation().X, Character->GetActorLocation().Y, Character->GetActorLocation().Z - CapsuleHalfHeight - 10000.0f), //end
				ECC_Visibility, //collision channel
				TraceParams);
			GroundDistance = OutHit.Distance-2.15; //TODO horrible constant value cause I have yet to discover what's that offset
		}
		else { GroundDistance = 0.0f; }
		
		InputX_Anim = Character->InputX;
		InputZ_Anim = Character->InputZ;
		Direction = Character->Direction;
	}

}

