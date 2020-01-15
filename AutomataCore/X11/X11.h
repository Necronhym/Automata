#ifndef X11_H
#define X11_H
//OpenCV
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
//Debugging /error checking:
#include <iostream>
//X11 inports:
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <X11/keysymdef.h>
//Mouse Buttons:
enum MouseButton 
	{
		left=1,
       		middle=2,
	       	right=3
	};
class X11
	{
		Display* display;
		XEvent* event;
		public:
		X11();
		//Display getters and setters
		//That i hopefully won't need ever;
		Display* getDisplay();
		void setDisplay(Display* d);
		//Xevent getter:
		XEvent* getEvent();
		//Take screenshot:
		cv::Mat takeScreenshot(int x, int y, int w, int h);

		//X11 Output:
		//Mouse:
		//Movement:	
		void mouseMove(int x, int y);
		//Clicks:
		void mousePressButton(MouseButton M);
		void mouseReleaseButton(MouseButton M);
		//Keyboard chars:
		void keyboardPressChar(char c);
		void keyboardReleaseChar(char c);
		//Keyboard Command keys:
		void keyboardPressKey(int I);
		void keyboardReleaseKey(int I);

		//Deconstructor:
		~X11();
	};
#endif
