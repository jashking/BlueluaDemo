// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LuaImplementableWidget.h"
#include "UseCaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLUELUADEMO_API UUseCaseWidget : public ULuaImplementableWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintPure)
	int32 TestFunction();

	UFUNCTION(BlueprintPure)
	int32 TestFunctionWithParam(const FString& Param1, const FVector& Param2);

	UFUNCTION(BlueprintImplementableEvent)
	int32 TestScriptFunction();

	UFUNCTION(BlueprintImplementableEvent)
	int32 TestScriptFunctionWithParam(const FString& Param1, const FVector& Param2);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString StrValue;
};
