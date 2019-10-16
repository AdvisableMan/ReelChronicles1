// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAnimInstance.h"



void UBaseAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    // Load scripts...

    bNeedsReset = true;
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
	//if (InScripts[0] != nullptr)
	//{
	//	for (int i = 0; i < InScripts.Num(); i++)
	//	{
	//		if (InScripts[i] != nullptr) { Scripts.Push(InScripts[i]); }
	//	}
	//}
}

void UBaseAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

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
}

