// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "HttpRequestActor.generated.h"

UCLASS()
class AHttpRequestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHttpRequestActor();
	FHttpModule* Http;
	UFUNCTION(BlueprintCallable, Category = "Http")
	void Request();
	void OnResponseReceive(FHttpRequestPtr Request,FHttpResponsePtr Response,bool bWasSuccessful);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
