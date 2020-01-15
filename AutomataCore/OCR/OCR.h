#ifndef OCR_H
#define OCR_H
//Opencv for Mat format
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
//Tessaract ocr api:
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
class OCR
	{
		tesseract::TessBaseAPI* api;
		public:
		OCR();
		tesseract::TessBaseAPI* getTessAPI();
		void setTessAPI(tesseract::TessBaseAPI* a);
		const char* getTextFromMat(cv::Mat img);
		~OCR();
	};
#endif
