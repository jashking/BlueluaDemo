// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaImplementableWidget.h"
#include "TestCaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLUELUADEMO_API UTestCaseWidget : public ULuaImplementableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetCycles();

	UFUNCTION(BlueprintPure)
	float GetSeconds(int32 InCycles);

	UFUNCTION(BlueprintCallable)
	void FunctionNoParam();

	UFUNCTION(BlueprintCallable)
	int32 EmptyFunctionOneIntParam(int32 Param1);

	UFUNCTION(BlueprintCallable)
	int32 EmptyFunctionTwoIntParam(int32 Param1, int32 Param2);

	UFUNCTION(BlueprintCallable)
	int32 EmptyFunctionThreeIntParam(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION(BlueprintCallable)
	int32 EmptyFunctionFourIntParam(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION(BlueprintCallable)
	int32 EmptyFunctionFiveIntParam(int32 Param1, int32 Param2, int32 Param3, int32 Param4, int32 Param5);

	UFUNCTION(BlueprintCallable)
	FString EmptyFunctionOneStringParam(const FString& Param1);

	UFUNCTION(BlueprintCallable)
	FString EmptyFunctionTwoStringParam(const FString& Param1, const FString& Param2);

	UFUNCTION(BlueprintCallable)
	FString EmptyFunctionThreeStringParam(const FString& Param1, const FString& Param2, const FString& Param3);

	UFUNCTION(BlueprintCallable)
	FString EmptyFunctionFourStringParam(const FString& Param1, const FString& Param2, const FString& Param3, const FString& Param4);

	UFUNCTION(BlueprintCallable)
	FString EmptyFunctionFiveStringParam(const FString& Param1, const FString& Param2, const FString& Param3, const FString& Param4, const FString& Param5);

	UFUNCTION(BlueprintCallable)
	FVector EmptyFunctionOneVectorParam(const FVector& Param1);

	UFUNCTION(BlueprintCallable)
	FVector EmptyFunctionTwoVectorParam(const FVector& Param1, const FVector& Param2);

	UFUNCTION(BlueprintCallable)
	FVector EmptyFunctionThreeVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3);

	UFUNCTION(BlueprintCallable)
	FVector EmptyFunctionFourVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3, const FVector& Param4);

	UFUNCTION(BlueprintCallable)
	FVector EmptyFunctionFiveVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3, const FVector& Param4, const FVector& Param5);

	UFUNCTION(BlueprintCallable)
	void EmptyFunctionMixParam(int32 Param1, float Param2, const FString& Param3, const FVector& Param4, const FRotator& Param5, const FTransform& Param6, UObject* Param7);

	////////////////////////////////////////////////////////////////

	UFUNCTION(BlueprintImplementableEvent)
		void BP_FunctionNoParam();

	UFUNCTION(BlueprintImplementableEvent)
		int32 BP_EmptyFunctionOneIntParam(int32 Param1);

	UFUNCTION(BlueprintImplementableEvent)
		int32 BP_EmptyFunctionTwoIntParam(int32 Param1, int32 Param2);

	UFUNCTION(BlueprintImplementableEvent)
		int32 BP_EmptyFunctionThreeIntParam(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION(BlueprintImplementableEvent)
		int32 BP_EmptyFunctionFourIntParam(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION(BlueprintImplementableEvent)
		int32 BP_EmptyFunctionFiveIntParam(int32 Param1, int32 Param2, int32 Param3, int32 Param4, int32 Param5);

	UFUNCTION(BlueprintImplementableEvent)
		FString BP_EmptyFunctionOneStringParam(const FString& Param1);

	UFUNCTION(BlueprintImplementableEvent)
		FString BP_EmptyFunctionTwoStringParam(const FString& Param1, const FString& Param2);

	UFUNCTION(BlueprintImplementableEvent)
		FString BP_EmptyFunctionThreeStringParam(const FString& Param1, const FString& Param2, const FString& Param3);

	UFUNCTION(BlueprintImplementableEvent)
		FString BP_EmptyFunctionFourStringParam(const FString& Param1, const FString& Param2, const FString& Param3, const FString& Param4);

	UFUNCTION(BlueprintImplementableEvent)
		FString BP_EmptyFunctionFiveStringParam(const FString& Param1, const FString& Param2, const FString& Param3, const FString& Param4, const FString& Param5);

	UFUNCTION(BlueprintImplementableEvent)
		FVector BP_EmptyFunctionOneVectorParam(const FVector& Param1);

	UFUNCTION(BlueprintImplementableEvent)
		FVector BP_EmptyFunctionTwoVectorParam(const FVector& Param1, const FVector& Param2);

	UFUNCTION(BlueprintImplementableEvent)
		FVector BP_EmptyFunctionThreeVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3);

	UFUNCTION(BlueprintImplementableEvent)
		FVector BP_EmptyFunctionFourVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3, const FVector& Param4);

	UFUNCTION(BlueprintImplementableEvent)
		FVector BP_EmptyFunctionFiveVectorParam(const FVector& Param1, const FVector& Param2, const FVector& Param3, const FVector& Param4, const FVector& Param5);

	UFUNCTION(BlueprintImplementableEvent)
		void BP_EmptyFunctionMixParam(int32 Param1, float Param2, const FString& Param3, const FVector& Param4, const FRotator& Param5, const FTransform& Param6, UObject* Param7);

	UFUNCTION(BlueprintCallable)
		FString TestNativeCallScript();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 CPPCallScriptCount;
};
