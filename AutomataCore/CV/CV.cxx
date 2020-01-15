#include "CV.h"
//Object struct:
CV::CV()
{
}
CV::~CV()
{
}
CV::Object::Object(int X, int Y, int W, int H)
	{
		x=X;
		y=Y;
		w=W;
		h=H;
	}
CV::Object::~Object()
	{
	}
//getters:
int CV::Object::getX()
	{
		if(x<0)
			{
				return 0;
			}
		else
			{
				return x;
			}
	}
int CV::Object::getY()
	{
		if(y<0)
			{
				return 0;
			}
		else
			{
				return y;
			}
	}
int CV::Object::getW()
	{
		return w;
	}
int CV::Object::getH()
	{
		return h;
	}
//Getters for center:
int CV::Object::getCenterX()
	{
		return (getX()+getW())/2;
	}
int CV::Object::getCenterY()
	{
		return (getY()+getH())/2;
	}
//Setter:
void CV::Object::setX(int i)
	{
		x = i;
	}
void CV::Object::setY(int i)
	{
		y = i;
	}
void CV::Object::setW(int i)
	{
		w = i;
	}
void CV::Object::setH(int i)
	{
		h = i;
	}
int CV::Object::getCenterY();
//Loads image from phone memory:
cv::Mat CV::loadMat(const char* IMGloc)
	{
		return cv::imread(IMGloc);
	}
cv::Mat CV::cropMat(cv::Mat Img, int x, int y, int w, int h)
	{	
		cv::Mat ret;
		ret.release();
		cv::Rect R(x,y,w,h);
		Img(R).copyTo(ret);
		Img.release();
		return ret;
	}
//Filtering:
cv::Mat CV::matFilter(cv::Mat Img, int HighHue, int LowHue, int HighSaturation, int LowSaturation, int HighValue, int LowValue, bool Method)
	{
		cv::Mat filteredMat;
		cv::Mat filter;
		cv::Mat tempMat;
		//Cleans old material
		filteredMat.release();
		//converts to colors cv can work with:
		cvtColor(Img, tempMat, CV_BGR2HSV);
		cv::inRange(tempMat, cv::Scalar(LowHue, LowSaturation, LowValue), cv::Scalar(HighHue, HighSaturation, HighValue), filter);
		//Method selects filtering method:
		if(Method)
			{
				//1 is addtiom method:
				Img.copyTo(filteredMat, ~filter);
			}
		else
			{
				//0 is subtaction method:
				Img.copyTo(filteredMat, filter);
			}
		//Frees memory:
		Img.release();
		filter.release();
		tempMat.release();
		return filteredMat;
	}
cv::Mat CV::createAlphaMask(cv::Mat Img)
	{	
		cv::Mat ret;
	       	cv::threshold(Img, ret, 0, 255, cv::THRESH_BINARY);
		Img.release();
		return ret;
	}
cv::Mat CV::applyMask(cv::Mat Mask, cv::Mat Img)
	{
		cv::Mat ret;
		Img.copyTo(ret, ~Mask);
		Img.release();
		Mask.release();
		return ret;
	}
CV::Object CV::objTempletMatch(cv::Mat Templet, cv::Mat Img)
	{
		CV::Object O;
		cv::Point minLoc, maxLoc;
		double minVal=0, maxVal=0;
		//Adjust templet colors to match:
		cv::Mat TempletDer, ImgDer, Result;
		cvtColor(Img, ImgDer, CV_RGBA2RGB);
		cvtColor(Templet, TempletDer, CV_RGBA2RGB);
		//Matching:
		cv::matchTemplate(ImgDer, TempletDer, Result, CV_TM_SQDIFF);
		//Extract location info:
		normalize(Result, Result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
		minMaxLoc(Result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());
		//Move variables in to object:
		O.setW(Templet.cols);
		O.setH(Templet.rows);
		O.setX(minLoc.x);
		//Y adjusted for Y location	
		O.setY(minLoc.y-(O.getH()/2));	
		//Clear memory
		Templet.release();
		Img.release();
		TempletDer.release();
		ImgDer.release();
		Result.release();
		return O;
	}
CV::Object CV::objDetect(cv::Mat Img)
	{
		cv::Rect r;
		CV::Object O;
		cv::Mat temp = createAlphaMask(Img);
		cv::cvtColor(temp, temp, CV_BGR2GRAY);
		r = cv::boundingRect(temp);
		temp.release();
		Img.release();
		O.setX(r.x);	
		O.setY(r.y);	
		O.setW(r.width);	
		O.setH(r.height);	
		return O;
	}
