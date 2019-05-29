// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LuaImplementableInterface.h"
#include "NetCharacter.generated.h"

UCLASS()
class BLUELUADEMO_API ANetCharacter : public ACharacter, public ILuaImplementableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANetCharacter();

	UFUNCTION(Unreliable, Server, WithValidation)
	void TestNativeServerFunction();

	UFUNCTION(Unreliable, NetMulticast)
	void TestNativeNetMulticastFunction();

	UFUNCTION(Unreliable, Client)
	void TestNativeClientFunction();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupPlayerInputComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void ProcessEvent(UFunction* Function, void* Parameters) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Begin override ILuaImplementableInterface
	virtual FString OnInitBindingLuaPath_Implementation() override;
	virtual bool ShouldEnableLuaBinding_Implementation() override;
	virtual TSharedPtr<FLuaState> OnInitLuaState();
	// End override ILuaImplementableInterface

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "LuaImplementable", meta = (AllowPrivateAccess = "true"))
	FString LuaFilePath;
};
