// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimationFunctionLibrary.h"

#include "GetFloat.h"
#include "GetBoolean.h"
#include "GetRotator.h"
#include "SetFloat.h"
#include "SetRotator.h"
#include "AddFloat.h"
#include "MultiplyFloat.h"
#include "AddRotator.h"
#include "SmoothFloat.h"
#include "SmoothFloatConst.h"
#include "WeightedAverage2.h"
#include "WeightedAverage3.h"
#include "WeightedAverage4.h"
#include "RemapFloat.h"

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

URotatorExpression* UAnimationFunctionLibrary::AddRotator(URotatorExpression* A, URotatorExpression* B)
{
	auto Node = NewObject<UAddRotator>(GetTransientPackage());

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