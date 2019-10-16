// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimationFunctionLibrary.h"

#include "GetFloat.h"
#include "GetBoolean.h"
#include "GetRotator.h"
#include "GetVector.h"
#include "SetFloat.h"
#include "SetRotator.h"
#include "SetVector.h"
#include "SetTrace.h"
#include "AddFloat.h"
#include "MultiplyFloat.h"
#include "SmoothFloat.h"
#include "SmoothFloatConst.h"
#include "AddRotator.h"
#include "SmoothRotator.h"
#include "MakeRotatorExpression.h"
#include "SmoothVector.h"
#include "MakeVectorExpression.h"
#include "WeightedAverage2.h"
#include "WeightedAverage3.h"
#include "WeightedAverage4.h"
#include "RemapFloat.h"
#include "LineTrace.h"
#include "GetSocketTransform.h"


// Get Float
UFloatExpression* UAnimationFunctionLibrary::GetFloat(float& Source)
{
    auto Node = NewObject<UGetFloat>(GetTransientPackage());

    Node->SetInputs(&Source);

    return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetConstantFloat(float Value)
{
    auto Node = NewObject<UGetFloatImmediate>(GetTransientPackage());

    Node->SetInputs(Value);

    return Node;
}
// Get Boolean
UFloatExpression* UAnimationFunctionLibrary::GetBoolean(bool& Source)
{
	auto Node = NewObject<UGetBoolean>(GetTransientPackage());

	Node->SetInputs(&Source);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetConstantBoolean(bool Value)
{
	auto Node = NewObject<UGetBooleanImmediate>(GetTransientPackage());

	Node->SetInputs(Value);

	return Node;
}
// Get Rotator
URotatorExpression* UAnimationFunctionLibrary::GetRotator(FRotator& Source)
{
	auto Node = NewObject<UGetRotator>(GetTransientPackage());

	Node->SetInputs(&Source);

	return Node;
}
URotatorExpression* UAnimationFunctionLibrary::GetConstantRotator(FRotator Value)
{
	auto Node = NewObject<UGetRotatorImmediate>(GetTransientPackage());

	Node->SetInputs(Value);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetRotatorPitch(URotatorExpression* Source)
{
	auto Node = NewObject<UGetRotatorPitch>(GetTransientPackage());

	Node->SetInputs(Source);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetRotatorYaw(URotatorExpression* Source)
{
	auto Node = NewObject<UGetRotatorYaw>(GetTransientPackage());

	Node->SetInputs(Source);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetRotatorRoll(URotatorExpression* Source)
{
	auto Node = NewObject<UGetRotatorRoll>(GetTransientPackage());

	Node->SetInputs(Source);

	return Node;
}
// Get Vector
UVectorExpression* UAnimationFunctionLibrary::GetVector(FVector& Source)
{
	auto Node = NewObject<UGetVector>(GetTransientPackage());

	Node->SetInputs(&Source);

	return Node;
}
UVectorExpression* UAnimationFunctionLibrary::GetConstantVector(FVector Value)
{
	auto Node = NewObject<UGetVectorImmediate>(GetTransientPackage());

	Node->SetInputs(Value);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetVectorX(UVectorExpression* Source)
{
	auto Node = NewObject<UGetVectorX>(GetTransientPackage());

	Node->SetInputs(Source);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetVectorY(UVectorExpression* Source)
{
	auto Node = NewObject<UGetVectorY>(GetTransientPackage());

	Node->SetInputs(Source);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::GetVectorZ(UVectorExpression* Source)
{
	auto Node = NewObject<UGetVectorZ>(GetTransientPackage());

	Node->SetInputs(Source);

	return Node;
}
// Set
UVoidExpression* UAnimationFunctionLibrary::SetFloat(float& Target, UFloatExpression* Source)
{
	auto Node = NewObject<USetFloat>(GetTransientPackage());

	Node->SetInputs(&Target, Source);

	return Node;
}
UVoidExpression* UAnimationFunctionLibrary::SetRotator(FRotator& Target, URotatorExpression* Source)
{
	auto Node = NewObject<USetRotator>(GetTransientPackage());

	Node->SetInputs(&Target, Source);

	return Node;
}
UVoidExpression* UAnimationFunctionLibrary::SetVector(FVector& Target, UVectorExpression* Source)
{
	auto Node = NewObject<USetVector>(GetTransientPackage());

	Node->SetInputs(&Target, Source);

	return Node;
}
UVoidExpression* UAnimationFunctionLibrary::SetTrace(FTraceStruct& Target, UTraceExpression* Source)
{
	auto Node = NewObject<USetTrace>(GetTransientPackage());

	Node->SetInputs(&Target, Source);

	return Node;
}

UFloatExpression* UAnimationFunctionLibrary::AddFloat(UFloatExpression* A, UFloatExpression* B)
{
    auto Node = NewObject<UAddFloat>(GetTransientPackage());

    Node->SetInputs(A, B);

    return Node;
}
UFloatExpression* UAnimationFunctionLibrary::MultiplyFloat(UFloatExpression* A, UFloatExpression* B)
{
	auto Node = NewObject<UMultiplyFloat>(GetTransientPackage());

	Node->SetInputs(A, B);

	return Node;
}

UFloatExpression* UAnimationFunctionLibrary::SmoothFloat(UFloatExpression* Value, float Speed)
{
    auto Node = NewObject<USmoothFloat>(GetTransientPackage());

    Node->SetInputs(Value, Speed);

    return Node;
}
UFloatExpression* UAnimationFunctionLibrary::SmoothFloatConst(UFloatExpression* Value, float Speed)
{
	auto Node = NewObject<USmoothFloatConst>(GetTransientPackage());

	Node->SetInputs(Value, Speed);

	return Node;
}

UFloatExpression* UAnimationFunctionLibrary::Lerp(UFloatExpression* InA, UFloatExpression* InB, UFloatExpression* Alpha)
{
	auto Node = NewObject<UWeightedAverage2>(GetTransientPackage());

	Node->SetInputs(InA, InB, Alpha);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::WeightedAverage3(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha)
{
	auto Node = NewObject<UWeightedAverage3>(GetTransientPackage());

	Node->SetInputs(InA, InAAlpha, InB, InBAlpha, InC, InCAlpha);

	return Node;
}
UFloatExpression* UAnimationFunctionLibrary::WeightedAverage4(UFloatExpression* InA, UFloatExpression* InAAlpha, UFloatExpression* InB, UFloatExpression* InBAlpha, UFloatExpression* InC, UFloatExpression* InCAlpha, UFloatExpression* InD, UFloatExpression* InDAlpha)
{
	auto Node = NewObject<UWeightedAverage4>(GetTransientPackage());

	Node->SetInputs(InA, InAAlpha, InB, InBAlpha, InC, InCAlpha, InD, InDAlpha);

	return Node;
}

UFloatExpression* UAnimationFunctionLibrary::RemapFloat(UFloatExpression* i, UFloatExpression* A, UFloatExpression* B, UFloatExpression* X, UFloatExpression* Y)
{
	auto Node = NewObject<URemapFloat>(GetTransientPackage());

	Node->SetInputs(i, A, B, X, Y);

	return Node;
}

// ROTATOR
URotatorExpression* UAnimationFunctionLibrary::SmoothRotator(URotatorExpression* Value, float Speed)
{
	auto Node = NewObject<USmoothRotator>(GetTransientPackage());

	Node->SetInputs(Value, Speed);

	return Node;
}
URotatorExpression* UAnimationFunctionLibrary::SmoothRotatorConst(URotatorExpression* Value, float Speed)
{
	auto Node = NewObject<USmoothRotatorConst>(GetTransientPackage());

	Node->SetInputs(Value, Speed);

	return Node;
}

URotatorExpression* UAnimationFunctionLibrary::AddRotator(URotatorExpression* A, URotatorExpression* B)
{
	auto Node = NewObject<UAddRotator>(GetTransientPackage());

	Node->SetInputs(A, B);

	return Node;
}

URotatorExpression* UAnimationFunctionLibrary::MakeRotatorExpression(UFloatExpression* Pitch, UFloatExpression* Yaw, UFloatExpression* Roll)
{
	auto Node = NewObject<UMakeRotatorExpression>(GetTransientPackage());

	Node->SetInputs(Pitch, Yaw, Roll);

	return Node;
}

// VECTOR
UVectorExpression* UAnimationFunctionLibrary::SmoothVector(UVectorExpression* Value, float Speed)
{
	auto Node = NewObject<USmoothVector>(GetTransientPackage());

	Node->SetInputs(Value, Speed);

	return Node;
}
UVectorExpression* UAnimationFunctionLibrary::SmoothVectorConst(UVectorExpression* Value, float Speed)
{
	auto Node = NewObject<USmoothVectorConst>(GetTransientPackage());

	Node->SetInputs(Value, Speed);

	return Node;
}

UVectorExpression* UAnimationFunctionLibrary::MakeVectorExpression(UFloatExpression* X, UFloatExpression* Y, UFloatExpression* Z)
{
	auto Node = NewObject<UMakeVectorExpression>(GetTransientPackage());

	Node->SetInputs(X, Y, Z);

	return Node;
}

// Trace
UTraceExpression * UAnimationFunctionLibrary::LineTrace(UFloatExpression* InCondition, UVectorExpression* InStart, UVectorExpression* InEnd, bool InDebug)
{
	auto Node = NewObject<ULineTrace>(GetTransientPackage());

	Node->SetInputs(InCondition, InStart, InEnd, InDebug);

	return Node;
}


// Get Socket Transform
UVectorExpression* UAnimationFunctionLibrary::GetSocketLocation(USkeletalMeshComponent* InSkeletalMesh, FName InName)
{
	auto Node = NewObject<UGetSocketLocation>(GetTransientPackage());

	Node->SetInputs(InSkeletalMesh, InName);

	return Node;
}
URotatorExpression* UAnimationFunctionLibrary::GetSocketRotation(USkeletalMeshComponent* InSkeletalMesh, FName InName)
{
	auto Node = NewObject<UGetSocketRotation>(GetTransientPackage());

	Node->SetInputs(InSkeletalMesh, InName);

	return Node;
}