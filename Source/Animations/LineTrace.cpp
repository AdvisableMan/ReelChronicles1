// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTrace.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

void ULineTrace::SetInputs(UFloatExpression* InCondition, UVectorExpression* InStart, UVectorExpression* InEnd, bool InDebug)
{
	Condition = InCondition;
	Start = InStart;
	End = InEnd;
	Debug = InDebug;
}

FTraceStruct ULineTrace::Evaluate(const FEvaluationContext& InContext)
{
	if (Condition && Condition->Evaluate(InContext) == 1.0f)
	{
		FCollisionQueryParams TraceParams(FName(TEXT("HitTraceParams")), true);
		TraceParams.bTraceComplex = true;

		if (Debug)
		{
			DrawDebugLine(
				InContext.World,
				Start->Evaluate(InContext),
				End->Evaluate(InContext),
				FColor(255, 0, 0),
				false, 0, 0,
				3.0
			);
			UE_LOG(LogTemp, Warning, TEXT("Line drawn on %s"), GetWorld());
		}

		//Re-initialize hit info
		FHitResult OutHit;

		//call GetWorld() from within an actor extending class
		InContext.World->LineTraceSingleByChannel(
			OutHit,        //result
			Start->Evaluate(InContext),    //start
			End->Evaluate(InContext), //end
			ECC_Visibility, //collision channel
			TraceParams);

		return { OutHit.Distance, OutHit.ImpactPoint, OutHit.ImpactNormal, true };
	}
	else { return { 0.0f, FVector::ZeroVector, FVector::ZeroVector, true }; }
}