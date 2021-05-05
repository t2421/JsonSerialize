#pragma once

#include "JsonItem.generated.h"

USTRUCT()
struct FLanguage
{
	GENERATED_BODY()

	UPROPERTY()
	FString ja = "";

	UPROPERTY()
	FString en = "";
};




USTRUCT()
struct FJsonItem
{
	GENERATED_BODY()

	UPROPERTY()
	FString id = "";

	UPROPERTY()
	FLanguage name; 
};



