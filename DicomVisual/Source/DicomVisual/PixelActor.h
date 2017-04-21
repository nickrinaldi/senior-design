// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PixelActor.generated.h"

UCLASS()
class DICOMVISUAL_API APixelActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dicom Pixel")
	uint8 x;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dicom Pixel")
	uint8 y;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dicom Pixel")
	uint8 imageNumber;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dicom Pixel")
	uint8 luminance;

	// Sets default values for this actor's properties
	APixelActor();
	APixelActor(uint8 x, uint8 y, uint8 imageNumber, uint8 luminance);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;



};