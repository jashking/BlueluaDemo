// Fill out your copyright notice in the Description page of Project Settings.

#include "UseCaseWidget.h"

void UUseCaseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TestBlueprintNativeEvent1(TEXT("Test"));
	TestBlueprintNativeEvent2(TEXT("Test"));
	TestBlueprintImplementableEvent(TEXT("Test"));
}

FString UUseCaseWidget::TestBlueprintNativeEvent1_Implementation(const FString& InString)
{
	UE_LOG(LogTemp, Display, TEXT("TestBlueprintNativeEvent1 in C++"));

	return InString;
}

FString UUseCaseWidget::TestBlueprintNativeEvent2_Implementation(const FString& InString)
{
	UE_LOG(LogTemp, Display, TEXT("TestBlueprintNativeEvent2 in C++"));

	return InString;
}
