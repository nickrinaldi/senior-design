// Fill out your copyright notice in the Description page of Project Settings.

#include "DicomVisual.h"
#include "DicomParserLibrary.h"

FString UDicomParserLibrary::HelloWorld()
{
	return "hello world!";
}

FImageStruct UDicomParserLibrary::loadImage(std::string filePath)
{
	std::unique_ptr<imebra::DataSet> loadedDataSet(imebra::CodecFactory::load(filePath));

	// Retrieve the first image (index = 0)
	int imgNumber = 0;
	std::unique_ptr<imebra::Image> image(loadedDataSet->getImageApplyModalityTransform(imgNumber));

	// Get the color space
	std::string colorSpace = image->getColorSpace();

	// Get the size in pixels
	std::uint32_t width = image->getWidth();
	std::uint32_t height = image->getHeight();

	// Scans all the pixels
	std::unique_ptr<imebra::ReadingDataHandlerNumeric> dataHandler(image->getReadingDataHandler());

	FImageStruct imageStruct;
	for (unsigned int scanY(0); scanY < height; ++scanY)
	{
		for (unsigned int scanX(0); scanX < width; ++scanX)
		{
			try {
				// For monochrome images
				std::int32_t luminance = dataHandler->getSignedLong(scanY * width + scanX);

				APixelActor* pixels = NewObject<APixelActor>();
				pixels->x = scanX;
				pixels->y = scanY;
				pixels->imageNumber = imgNumber;
				pixels->luminance = luminance;

				imageStruct.imagePixels.Add(pixels);
			}
			catch (imebra::MissingItemError e) {
				continue;
			}
		}
	}

	return imageStruct;
}

TArray<FImageStruct> UDicomParserLibrary::getPixels()
{
	TArray<FImageStruct> bitmaps;

	try {
		for (int i = 1; i < 40; ++i) {
			//std::cout << "Parsing image: " << "C:/Users/Jimmy/Desktop/Senior Design/dicom_images/scan1/" + std::to_string(i) << std::endl;
			bitmaps.Add(UDicomParserLibrary::loadImage("C:/Users/Jimmy/Desktop/Senior Design/dicom_images/scan1/" + std::to_string(i)));
		}
	}
	catch (imebra::StreamOpenError) {
		//File out of bounds
		//std::cout << "Image name out of bounds" << std::endl;
	}

	//This is the 2D vector of images. Index 0 will be a bitmap for image 0.
	return bitmaps;
}