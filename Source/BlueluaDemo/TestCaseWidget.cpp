// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCaseWidget.h"

#include "GenericPlatform/GenericPlatformTime.h"

int32 UTestCaseWidget::GetCycles()
{
	return FPlatformTime::Cycles();
}

float UTestCaseWidget::GetSeconds(int32 InCycles)
{
	return FPlatformTime::ToSeconds(InCycles);
}

void UTestCaseWidget::FunctionNoParam()
{

}

int32 UTestCaseWidget::EmptyFunctionOneIntParam(int32 Param1)
{
	return 1;
}

int32 UTestCaseWidget::EmptyFunctionTwoIntParam(int32 Param1, int32 Param2)
{
	return 2;
}

int32 UTestCaseWidget::EmptyFunctionThreeIntParam(int32 Param1, int32 Param2, int32 Param3)
{
	return 3;
}

int32 UTestCaseWidget::EmptyFunctionFourIntParam(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	return 4;
}

int32 UTestCaseWidget::EmptyFunctionFiveIntParam(int32 Param1, int32 Param2, int32 Param3, int32 Param4, int32 Param5)
{
	return 5;
}

FString UTestCaseWidget::EmptyFunctionOneStringParam(const FString& Param1)
{
	return TEXT("1");
}

FString UTestCaseWidget::EmptyFunctionTwoStringParam(const FString& Param1, const FString& Param2)
{
	return TEXT("2");
}

FString UTestCaseWidget::EmptyFunctionThreeStringParam(const FString& Param1, const FString& Param2, const FString& Param3)
{
	return TEXT("3");
}

FString UTestCaseWidget::EmptyFunctionFourStringParam(const FString& Param1, const FString& Param2, const FString& Param3, const FString& Param4)
{
	return TEXT("4");
}

FString UTestCaseWidget::EmptyFunctionFiveStringParam(const FString& Param1, const FString& Param2, const FString& Param3, const FString& Param4, const FString& Param5)
{
	return TEXT("5");
}

FVector UTestCaseWidget::EmptyFunctionOneVectorParam(const FVector& Param1)
{
	return FVector(1.f, 1.f, 1.f);
}

FVector UTestCaseWidget::EmptyFunctionTwoVectorParam(const FVector& Param1, const FVector& Param2)
{
	return FVector(2.f, 2.f, 2.f);
}

FVector UTestCaseWidget::EmptyFunctionThreeVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3)
{
	return FVector(3.f, 3.f, 3.f);
}

FVector UTestCaseWidget::EmptyFunctionFourVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3, const FVector& Param4)
{
	return FVector(4.f, 4.f, 4.f);
}

FVector UTestCaseWidget::EmptyFunctionFiveVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3, const FVector& Param4, const FVector& Param5)
{
	return FVector(5.f, 5.f, 5.f);
}

void UTestCaseWidget::EmptyFunctionMixParam(int32 Param1, float Param2, const FString& Param3, const FVector& Param4, const FRotator& Param5, const FTransform& Param6, UObject* Param7)
{

}

FString UTestCaseWidget::TestNativeCallScript()
{
	FString CostInfo;
	const int32 LoopCountMax = CPPCallScriptCount;
	uint32 Start = 0;

#define TEST_FUNC(FUNC_NAME, FUNC) \
	Start = FPlatformTime::Cycles(); \
	for (int32 i = 0; i < LoopCountMax; ++i) \
	{ \
		FUNC; \
	} \
	CostInfo = FString::Printf(TEXT("%s\n%s %0.5fs %d"), *CostInfo, FUNC_NAME, FPlatformTime::ToSeconds(FPlatformTime::Cycles() - Start), LoopCountMax)

	TEST_FUNC(TEXT("BP_FunctionNoParam"), BP_FunctionNoParam());

	TEST_FUNC(TEXT("BP_EmptyFunctionOneIntParam"), BP_EmptyFunctionOneIntParam(1));
	TEST_FUNC(TEXT("BP_EmptyFunctionTwoIntParam"), BP_EmptyFunctionTwoIntParam(1, 2));
	TEST_FUNC(TEXT("BP_EmptyFunctionThreeIntParam"), BP_EmptyFunctionThreeIntParam(1, 2, 3));
	TEST_FUNC(TEXT("BP_EmptyFunctionFourIntParam"), BP_EmptyFunctionFourIntParam(1, 2, 3, 4));
	TEST_FUNC(TEXT("BP_EmptyFunctionFiveIntParam"), BP_EmptyFunctionFiveIntParam(1, 2, 3, 4, 5));

	TEST_FUNC(TEXT("BP_EmptyFunctionOneStringParam"), BP_EmptyFunctionOneStringParam(TEXT("1")));
	TEST_FUNC(TEXT("BP_EmptyFunctionTwoStringParam"), BP_EmptyFunctionTwoStringParam(TEXT("1"), TEXT("2")));
	TEST_FUNC(TEXT("BP_EmptyFunctionThreeStringParam"), BP_EmptyFunctionThreeStringParam(TEXT("1"), TEXT("2"), TEXT("3")));
	TEST_FUNC(TEXT("BP_EmptyFunctionFourStringParam"), BP_EmptyFunctionFourStringParam(TEXT("1"), TEXT("2"), TEXT("3"), TEXT("4")));
	TEST_FUNC(TEXT("BP_EmptyFunctionFiveStringParam"), BP_EmptyFunctionFiveStringParam(TEXT("1"), TEXT("2"), TEXT("3"), TEXT("4"), TEXT("5")));

	FVector Vector(1, 2, 3);

	TEST_FUNC(TEXT("BP_EmptyFunctionOneVectorParam"), BP_EmptyFunctionOneVectorParam(Vector));
	TEST_FUNC(TEXT("BP_EmptyFunctionTwoVectorParam"), BP_EmptyFunctionTwoVectorParam(Vector, Vector));
	TEST_FUNC(TEXT("BP_EmptyFunctionThreeVectorParam"), BP_EmptyFunctionThreeVectorParam(Vector, Vector, Vector));
	TEST_FUNC(TEXT("BP_EmptyFunctionFourVectorParam"), BP_EmptyFunctionFourVectorParam(Vector, Vector, Vector, Vector));
	TEST_FUNC(TEXT("BP_EmptyFunctionFiveVectorParam"), BP_EmptyFunctionFiveVectorParam(Vector, Vector, Vector, Vector, Vector));

	FRotator Rotator(1, 2, 3);

	TEST_FUNC(TEXT("BP_EmptyFunctionMixParam"), BP_EmptyFunctionMixParam(1, 2.f, TEXT("3"), Vector, Rotator, FTransform(), this));

	return CostInfo;
}
