#include "OCR.h"
OCR::OCR()
	{
		api = new tesseract::TessBaseAPI();
		api->Init(NULL, "eng");
	}
tesseract::TessBaseAPI* OCR::getTessAPI()
	{
		return api;
	}
void OCR::setTessAPI(tesseract::TessBaseAPI* a)
	{
		api = a;
	}
const char* OCR::getTextFromMat( cv::Mat img)
	{
		api->SetImage((uchar*)img.data, img.size().width, img.size().height, img.channels(), (int)img.step1());
		img.release();
		return api->GetUTF8Text();
	}
OCR::~OCR()
	{
		api->End();
	}
