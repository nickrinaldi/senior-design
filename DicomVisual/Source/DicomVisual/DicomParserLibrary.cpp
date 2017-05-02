// Fill out your copyright notice in the Description page of Project Settings.

#include "DicomVisual.h"
#include "DicomParserLibrary.h"

std::vector<std::string> UDicomParserLibrary::split(std::string str, char delimiter)
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

FString UDicomParserLibrary::HelloWorld()
{
	return "hello world!";
}

FImageStruct UDicomParserLibrary::loadImage(std::string fileName, uint8 imgNumber)
{
	FImageStruct imageStruct;
	
	//const char *file = fileName.c_str();
	//std::unique_ptr<imebra::DataSet> loadedDataSet(imebra::CodecFactory::load(std::string(file)));

	//// Retrieve the first image (index = 0)
	//int imgNumber = 0;
	//std::unique_ptr<imebra::Image> image(loadedDataSet->getImageApplyModalityTransform(imgNumber));

	//// Get the color space
	//std::string colorSpace = image->getColorSpace();

	//// Get the size in pixels
	//std::uint32_t width = image->getWidth();
	//std::uint32_t height = image->getHeight();

	//// Scans all the pixels
	//std::unique_ptr<imebra::ReadingDataHandlerNumeric> dataHandler(image->getReadingDataHandler());

	//for (unsigned int scanY(0); scanY < height; ++scanY)
	//{
	//	for (unsigned int scanX(0); scanX < width; ++scanX)
	//	{
	//		try {
	//			// For monochrome images
	//			std::int32_t luminance = dataHandler->getSignedLong(scanY * width + scanX);

	//			if (luminance > LUMINANCE_FILTER)
	//			{
	//				APixelActor* pixels = NewObject<APixelActor>();
	//				pixels->x = scanX;
	//				pixels->y = scanY;
	//				pixels->imageNumber = imgNumber;
	//				pixels->luminance = luminance;

	//				imageStruct.imagePixels.Add(pixels);
	//			}
	//		}
	//		catch (imebra::MissingItemError e) {
	//			continue;
	//		}
	//	}
	//}



	/**************************
	 * reading from text file *
	 **************************/

	std::string line;
	std::ifstream pixelDataFile(fileName);

	int pixelCount = 0;
	if (pixelDataFile.is_open())
	{
		while (getline(pixelDataFile, line))
		{
			std::vector<std::string> parsedTokens = UDicomParserLibrary::split(line, ',');

			if (parsedTokens.size() != 3) {
				// incorrect amount of tokens in the line
				continue;
			}

			uint8 scanX = atoi(parsedTokens[0].c_str());
			uint8 scanY = atoi(parsedTokens[1].c_str());
			uint8 luminance = atoi(parsedTokens[2].c_str());

			if (luminance > LUMINANCE_FILTER)
			{
				APixelActor* pixels = NewObject<APixelActor>();
				pixels->x = scanX;
				pixels->y = scanY;
				pixels->imageNumber = imgNumber;
				pixels->luminance = luminance;

				imageStruct.imagePixels.Add(pixels);


				/*pixelCount++;
				if (pixelCount > 10) {
					break;
				}*/
			}
		}
		pixelDataFile.close();
	}


	return imageStruct;
}

TArray<FImageStruct> UDicomParserLibrary::getPixels()
{
	TArray<FImageStruct> bitmaps;

	//try {
	//	for (uint8 i = 1; i < 40; ++i) {
	//		std::string filePath = "C:/Users/Nick Rinaldi/Documents/dicom_images/scan1/" + std::to_string(i) + ".dcm";
	//		UE_LOG(LogTemp, Warning, TEXT("Parsing image: %d.dcm"), i);
	//		//bitmaps.Add(UDicomParserLibrary::loadImage("C:/Users/Nick Rinaldi/Documents/dicom_images/scan1/" + std::to_string(i) + ".dcm"));
	//		bitmaps.Add(UDicomParserLibrary::loadImage(filePath));
	//	}
	//}
	//catch (imebra::StreamOpenError) {
	//	//File out of bounds
	//	//std::cout << "Image name out of bounds" << std::endl;
	//}



	for (uint8 i = 1; i < 2; ++i)
	{
		std::string filePath = "C:/Users/Nick Rinaldi/Documents/MRI-images/text/" + std::to_string(i) + ".txt";
		UE_LOG(LogTemp, Warning, TEXT("Parsing image: %d.dcm"), i);
		bitmaps.Add(UDicomParserLibrary::loadImage(filePath, i));
	}

	//This is the 2D vector of images. Index 0 will be a bitmap for image 0.
	return bitmaps;
}