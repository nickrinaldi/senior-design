// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
//#include "../../ThirdParty/Imebra/Includes/imebra.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<AActor*> imagePixels;
};

/**
*
*/
UCLASS()
class DICOMVISUAL_API UDicomParserLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	static const int LUMINANCE_FILTER = 500;

	static std::vector<std::string> split(std::string str, char delimiter);

public:

	UFUNCTION(BlueprintCallable, Category = "DicomParsing")
	static FString HelloWorld();

	static FImageStruct loadImage(std::string filePath, uint8 imgNumber);

	UFUNCTION(BlueprintCallable, Category = "DicomParsing")
	static TArray<FImageStruct> getPixels();


};