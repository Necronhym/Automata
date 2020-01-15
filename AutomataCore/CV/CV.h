#ifndef CV_H
#define CV_H
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
class CV
	{
		public:
		CV();
		//Struct to store object data:
		class Object
			{
				int x, y, w, h;
				public:
				//Constructor:
				Object(int X=0, int Y=0, int W=0, int H=0);
				//Getters:
				int getX();
				int getY();
				int getW();
				int getH();
				int getCenterX();
				int getCenterY();
				//Setters:
				void setX(int i);
				void setY(int i);
				void setW(int i);
				void setH(int i);
				~Object();
			};
		cv::Mat loadMat(const char* IMGloc);
		cv::Mat cropMat(cv::Mat Img, int x, int y, int w, int h);	
		cv::Mat matFilter(cv::Mat Img, int HighHue=255, int LowHue=0, int HighSaturation=255, int LowSaturation=0, int HighValue=255, int LowValue=0, bool Metod=true);
		cv::Mat createAlphaMask(cv::Mat Img);
		cv::Mat applyMask(cv::Mat Mask, cv::Mat Img);
		Object objTempletMatch(cv::Mat Templet, cv::Mat Img);
	

		Object objDetect(cv::Mat Img);
		~CV();
	};
#endif
