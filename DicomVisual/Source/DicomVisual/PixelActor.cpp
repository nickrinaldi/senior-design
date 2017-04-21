// Fill out your copyright notice in the Description page of Project Settings.

#include "DicomVisual.h"
#include "PixelActor.h"


// Sets default values
APixelActor::APixelActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

APixelActor::APixelActor(uint8 x, uint8 y, uint8 imageNumber, uint8 luminance)
{
	this->x = x;
	this->y = y;
	this->imageNumber = imageNumber;
	this->luminance = luminance;
}

// Called when the game starts or when spawned
void APixelActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APixelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}