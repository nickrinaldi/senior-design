// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "ProceduralMeshComponent.h"

#include "GameFramework/Actor.h"
#include "MRIDataActor.generated.h"

UCLASS()
class MRIDATAVISUAL_API AMRIDataActor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere, Category = Materials)
		UProceduralMeshComponent * mesh;

	static const int LUMINANCE_FILTER = 500;

	TArray<FVector> vertices;
	//TArray<FDynamicMeshVertex> vertices;
	TArray<FColor> vertexColors;
	TArray<int32> triangles;
	TArray<FVector2D> UV0;

	static std::vector<std::string> split(std::string str, char delimiter);
	void loadImage(std::string filePath, int imgNumber);

public:

	// Sets default values for this actor's properties
	AMRIDataActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

};