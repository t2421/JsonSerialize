// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpRequestActor.h"
#include "JsonItem.h"
#include "JsonObjectConverter.h"

// Sets default values
AHttpRequestActor::AHttpRequestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Http = &FHttpModule::Get();
}

// Called when the game starts or when spawned
void AHttpRequestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHttpRequestActor::Request()
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = Http->CreateRequest();
	request->OnProcessRequestComplete().BindUObject(this, &AHttpRequestActor::OnResponseReceive);
	request->SetURL("http://localhost:3010");
	request->SetVerb("GET");
	request->SetHeader("Contents-Type", "application/json");
	request->ProcessRequest();

}

void AHttpRequestActor::OnResponseReceive(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccesful)
{
	FString  url = Request->GetURL();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, url);

	if (bWasSuccesful && Response->GetResponseCode() >= 200)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, Response->GetContentAsString());	
		FJsonItem JsonData;
		FJsonObjectConverter::JsonObjectStringToUStruct<FJsonItem>(
			Response->GetContentAsString(),
			&JsonData,
			0, 0);
	
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, JsonData.id);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, JsonData.name.ja);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, JsonData.name.en);
		return;
	}
}
