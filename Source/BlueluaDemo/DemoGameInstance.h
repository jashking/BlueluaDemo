// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DemoGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BLUELUADEMO_API UDemoGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	TSharedPtr<class FLuaState> GetLuaState();

protected:
	virtual void Init() override;
	virtual void Shutdown() override;

protected:
	TSharedPtr<class FLuaState> LuaState;
};
