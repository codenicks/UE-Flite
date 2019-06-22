// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IFliteTTSPlugin.h"
#include "FliteTTSPlugin.h"

#include "lex_test.generated.h"




/**
 * 
 */
 UCLASS(MinimalAPI)
class Alex_test : public AActor
{
	//virtual void StartupModule() override; 
	//virtual void ShutdownModule() override; 
	
	GENERATED_BODY() 
	
	
public:
	Alex_test();
	~Alex_test();
	
	 UFUNCTION(BlueprintCallable, Category = "citeste")
	 void citeste(FString str);
	 FFliteTTSPlugin* flite;
	 
}; 



