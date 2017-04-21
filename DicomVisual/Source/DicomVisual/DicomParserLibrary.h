// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>
#include "../../ThirdParty/Imebra/Includes/imebra.h"
#include "PixelActor.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "DicomParserLibrary.generated.h"

/**
*
*/
USTRUCT()
struct FImageStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<AActor*> imagePixels;
};

/**
*
*/
UCLASS()
class DICOMVISUAL_API UDicomParserLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "DicomParsing")
	static FString HelloWorld();

	static FImageStruct loadImage(std::string filePath);

	UFUNCTION(BlueprintCallable, Category = "DicomParsing")
	static TArray<FImageStruct> getPixels();


};