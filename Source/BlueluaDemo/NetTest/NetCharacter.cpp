// Fill out your copyright notice in the Description page of Project Settings.

#include "NetCharacter.h"

#include "Engine/World.h"
#include "Misc/Paths.h"
#include "Net/UnrealNetwork.h"

#include "DemoGameInstance.h"
#include "LuaState.h"

// Sets default values
ANetCharacter::ANetCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FString GetPrefix(ANetCharacter* Character)
{
	FString Prefix;

	UWorld* World = Character->GetWorld();
	if (World)
	{
		//if (World->WorldType == EWorldType::PIE)
		{
			switch (World->GetNetMode())
			{
			case NM_Client:
				Prefix = FString::Printf(TEXT("Client %d: "), GPlayInEditorID - 1);
				break;
			case NM_DedicatedServer:
			case NM_ListenServer:
				Prefix = FString::Printf(TEXT("Server: "));
				break;
			case NM_Standalone:
				break;
			}
		}
	}

	return Prefix;
}

void ANetCharacter::TestNativeClientFunction_Implementation()
{
	UE_LOG(LogTemp, Display, TEXT("%sTestNativeClientFunction get called"), *GetPrefix(this));
}

void ANetCharacter::TestNativeNetMulticastFunction_Implementation()
{
	UE_LOG(LogTemp, Display, TEXT("%sTestNativeNetMulticastFunction get called"), *GetPrefix(this));
}

void ANetCharacter::TestNativeServerFunction_Implementation()
{
	UE_LOG(LogTemp, Display, TEXT("%sTestNativeServerFunction get called"), *GetPrefix(this));

	TestNativeNetMulticastFunction(); // will run on local and remote
	TestNativeClientFunction(); // will run on remote
}

bool ANetCharacter::TestNativeServerFunction_Validate()
{
	return true;
}

// Called when the game starts or when spawned
void ANetCharacter::BeginPlay()
{
	OnInitLuaBinding();

	Super::BeginPlay();
}

void ANetCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	OnReleaseLuaBinding();
}

void ANetCharacter::ProcessEvent(UFunction* Function, void* Parameters)
{
	LuaProcessEvent<Super>(Function, Parameters);
}

// Called every frame
void ANetCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANetCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	OnSetupPlayerInputComponent();
}

FString ANetCharacter::OnInitBindingLuaPath_Implementation()
{
	return FPaths::ProjectContentDir() / LuaFilePath;
}

bool ANetCharacter::ShouldEnableLuaBinding_Implementation()
{
	return true;
}

TSharedPtr<FLuaState> ANetCharacter::OnInitLuaState()
{
	UDemoGameInstance* GameInstance = Cast<UDemoGameInstance>(GetGameInstance());

	TSharedPtr<FLuaState> GameInstanceLuaState = GameInstance ? GameInstance->GetLuaState() : nullptr;
	if (!GameInstanceLuaState.IsValid())
	{
		return ILuaImplementableInterface::OnInitLuaState();
	}

	return GameInstanceLuaState;
}
