// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoGameInstance.h"

#include "LuaState.h"
#include "LuaImplementableInterface.h"

TSharedPtr<class FLuaState> UDemoGameInstance::GetLuaState()
{
	return LuaState;
}

void UDemoGameInstance::Init()
{
	LuaState = MakeShared<FLuaState>();
	if (LuaState.IsValid())
	{
		LuaState->SetOwnerGameInstane(this);
	}

	Super::Init();
}

void UDemoGameInstance::Shutdown()
{
	Super::Shutdown();

#if WITH_EDITOR
	ILuaImplementableInterface::CleanAllLuaImplementableObject();
#endif

	LuaState.Reset();
}

