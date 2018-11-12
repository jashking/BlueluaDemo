// Fill out your copyright notice in the Description page of Project Settings.

#include "UseCaseWidget.h"

void UUseCaseWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TestScriptFunction();
	TestScriptFunctionWithParam(TEXT("100"), FVector(1, 2, 3));
}

int32 UUseCaseWidget::TestFunction()
{
	return 1;
}

int32 UUseCaseWidget::TestFunctionWithParam(const FString& Param1, const FVector& Param2)
{
	return 2;
}
