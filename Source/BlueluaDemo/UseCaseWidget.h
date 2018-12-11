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

	UFUNCTION(BlueprintImplementableEvent)
	FString TestBlueprintImplementableEvent(const FString& InString);

	UFUNCTION(BlueprintNativeEvent)
	FString TestBlueprintNativeEvent1(const FString& InString);
	FString TestBlueprintNativeEvent1_Implementation(const FString& InString);

	UFUNCTION(BlueprintNativeEvent)
	FString TestBlueprintNativeEvent2(const FString& InString);
	FString TestBlueprintNativeEvent2_Implementation(const FString& InString);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString StrValue;
};
