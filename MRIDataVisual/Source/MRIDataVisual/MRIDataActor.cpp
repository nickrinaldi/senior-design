// Fill out your copyright notice in the Description page of Project Settings.

#include "MRIDataVisual.h"
#include "MRIDataActor.h"


// Sets default values
AMRIDataActor::AMRIDataActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/MRIDataVisual/Content/VirtualReality/Materials/M_MRIDataActor.M_MRIDataActor'"));
	//UMaterial *material = NULL;
	//if (Material.Object != NULL)
	//{
	//	material = (UMaterial*)Material.Object;
	//}

	//UMaterialInstanceDynamic* dynamicMaterial = UMaterialInstanceDynamic::Create(material, this);

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	/**
	*	Create/replace a section for this procedural mesh component.
	*	@param	SectionIndex		Index of the section to create or replace.
	*	@param	Vertices			Vertex buffer of all vertex positions to use for this mesh section.
	*	@param	Triangles			Index buffer indicating which vertices make up each triangle. Length must be a multiple of 3.
	*	@param	Normals				Optional array of normal vectors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	UV0					Optional array of texture co-ordinates for each vertex. If supplied, must be same length as Vertices array.
	*	@param	VertexColors		Optional array of colors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	Tangents			Optional array of tangent vector for each vertex. If supplied, must be same length as Vertices array.
	*	@param	bCreateCollision	Indicates whether collision should be created for this section. This adds significant cost.
	*/
	//UFUNCTION(BlueprintCallable, Category = "Components|ProceduralMesh", meta = (AutoCreateRefTerm = "Normals,UV0,VertexColors,Tangents"))
	//	void CreateMeshSection(int32 SectionIndex, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, const TArray<FVector>& Normals,
	// const TArray<FVector2D>& UV0, const TArray<FColor>& VertexColors, const TArray<FProcMeshTangent>& Tangents, bool bCreateCollision);

	int allImages = 35;

	for (int i = 14; i <= 15; i++) {
		loadImage("C:/Users/Nick Rinaldi/Documents/MRI-images/scan/" + std::to_string(i) + ".txt", i);
	}

	TArray<FVector> normals;
	//TArray<FVector2D> UV0;
	TArray<FProcMeshTangent> tangents;

	mesh->CreateMeshSection(0, vertices, triangles, normals, UV0, vertexColors, tangents, false);
	//mesh->SetMaterial(0, dynamicMaterial);
}

// sets the vertices, triangles, vertexColors arrays
void AMRIDataActor::loadImage(std::string fileName, int imgNumber)
{
	/**************************
	* reading from text file *
	**************************/

	std::string line;
	std::ifstream pixelDataFile(fileName);

	int pixelCount = 0;
	int startHeight = 370;

	float lengthRadius = 0.8;
	float widthHeightRadius = 0.08;

	if (pixelDataFile.is_open())
	{
		while (getline(pixelDataFile, line))
		{
			std::vector<std::string> parsedTokens = split(line, ',');

			if (parsedTokens.size() != 3) {
				// incorrect amount of tokens in the line
				continue;
			}

			int scanX = atoi(parsedTokens[0].c_str());
			int scanY = startHeight - atoi(parsedTokens[1].c_str());
			int luminance = atoi(parsedTokens[2].c_str());

			if (luminance > LUMINANCE_FILTER)
			{
				pixelCount++;

				float rgb = ((luminance / 14) % 256);
				int blue = 255;
				int green = 255;
				int red = 255;

				// front view
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
					((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 - widthHeightRadius));
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
					((float)scanX) * widthHeightRadius * 2 + widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 - widthHeightRadius));
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
					((float)scanX) * widthHeightRadius * 2 + widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 + widthHeightRadius));
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
					((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 + widthHeightRadius));

				/*vertexColors.Add(FColor(red, green, blue, 1));
				vertexColors.Add(FColor(red, green, blue, 1));
				vertexColors.Add(FColor(red, green, blue, 1));
				vertexColors.Add(FColor(red, green, blue, 1));*/

				/*FDynamicMeshVertex v1;
				v1.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v1.Color = FColor(255, 255, 255, 1);
				FDynamicMeshVertex v2;
				v2.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v2.Color = FColor(255, 255, 255, 1);
				FDynamicMeshVertex v3;
				v3.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v3.Color = FColor(255, 255, 255, 1);
				FDynamicMeshVertex v4;
				v4.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v4.Color = FColor(255, 255, 255, 1);

				vertices.Add(v1);
				vertices.Add(v2);
				vertices.Add(v3);
				vertices.Add(v4);*/

				triangles.Add(vertices.Num() - 4);
				triangles.Add(vertices.Num() - 3);
				triangles.Add(vertices.Num() - 2);
				triangles.Add(vertices.Num() - 4);
				triangles.Add(vertices.Num() - 2);
				triangles.Add(vertices.Num() - 1);

				// back view
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 + lengthRadius,
					((float)scanX) * widthHeightRadius * 2 + widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 - widthHeightRadius));
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 + lengthRadius,
					((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 - widthHeightRadius));
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 + lengthRadius,
					((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 + widthHeightRadius));
				vertices.Add(FVector(((float)imgNumber) * lengthRadius * 2 + lengthRadius,
					((float)scanX) * widthHeightRadius * 2 + widthHeightRadius,
					((float)scanY) * widthHeightRadius * 2 + widthHeightRadius));

				vertexColors.Add(FColor(red, green, blue, 1));
				vertexColors.Add(FColor(red, green, blue, 1));
				vertexColors.Add(FColor(red, green, blue, 1));
				vertexColors.Add(FColor(red, green, blue, 1));

				/*FDynamicMeshVertex v5;
				v5.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v5.Color = FColor(255, 255, 255, 1);
				FDynamicMeshVertex v6;
				v6.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v6.Color = FColor(255, 255, 255, 1);
				FDynamicMeshVertex v7;
				v7.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v7.Color = FColor(255, 255, 255, 1);
				FDynamicMeshVertex v8;
				v8.Position = FVector(((float)imgNumber) * lengthRadius * 2 - lengthRadius,
				((float)scanX) * widthHeightRadius * 2 - widthHeightRadius,
				((float)scanY) * widthHeightRadius * 2 - widthHeightRadius);
				v8.Color = FColor(255, 255, 255, 1);

				vertices.Add(v5);
				vertices.Add(v6);
				vertices.Add(v7);
				vertices.Add(v8);*/

				triangles.Add(vertices.Num() - 4);
				triangles.Add(vertices.Num() - 3);
				triangles.Add(vertices.Num() - 2);
				triangles.Add(vertices.Num() - 4);
				triangles.Add(vertices.Num() - 2);
				triangles.Add(vertices.Num() - 1);

				// left side
				triangles.Add(vertices.Num() - 3);
				triangles.Add(vertices.Num() - 8);
				triangles.Add(vertices.Num() - 5);
				triangles.Add(vertices.Num() - 3);
				triangles.Add(vertices.Num() - 5);
				triangles.Add(vertices.Num() - 2);

				// right side
				triangles.Add(vertices.Num() - 6);
				triangles.Add(vertices.Num() - 7);
				triangles.Add(vertices.Num() - 4);
				triangles.Add(vertices.Num() - 6);
				triangles.Add(vertices.Num() - 4);
				triangles.Add(vertices.Num() - 1);

				/*if (pixelCount > 20) {
				break;
				}*/
			}
		}
		pixelDataFile.close();
	}
}

// Splits a string into a vector of tokens on the delimiter
std::vector<std::string> AMRIDataActor::split(std::string str, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;

	while (getline(ss, token, delimiter))
	{
		result.push_back(token);
	}

	return result;
}

// Called when the game starts or when spawned
void AMRIDataActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMRIDataActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

