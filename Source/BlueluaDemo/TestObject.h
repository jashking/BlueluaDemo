// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "TestObject.generated.h"

/**
 * 
 */
UCLASS()
class BLUELUADEMO_API UTestObject : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	int32 TestInt(int32 Param1);
};
