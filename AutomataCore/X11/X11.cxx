#include "X11.h"
X11::X11()
	{
		display = XOpenDisplay(NULL);
	}
//Display getters and setters:
Display* X11::getDisplay()
	{
		return display;
	}
void X11::setDisplay( Display* d)
	{
		display = d;
	}
//Xevent getter:
XEvent* X11::getEvent()
	{
		return event;
	}
//Take screenshot
cv::Mat X11::takeScreenshot(int x, int y, int w, int h)
	{
		XImage* img = XGetImage(display, DefaultRootWindow(display), x,y,w,h, AllPlanes, ZPixmap);
		//Some pointer magic makes this unviable as a return
		//x11 destorys the image and the Mat returns as garbage
		cv::Mat temp = cv::Mat( h, w, CV_8UC4, img->data);	
		cv::Mat ret;
		ret.release();
		//So we make a copy to return.
		//The line above frees it so we dont get artifacts
		temp.copyTo(ret);
		temp.release();
		//Frees memory from x11
		//And the relese ones free the memory of CV mat so they dont overlap or leak
		XDestroyImage(img);	
		return ret;
	}
//Mouse:
//Mouse movement:
void X11::mouseMove(int x, int y)
	{
		XWarpPointer( display, None, DefaultRootWindow( display ), 0,0,0,0, x, y);
		XFlush(display);
	}
//Mouse Clicks:
void X11::mousePressButton(MouseButton M)
	{
		XTestFakeButtonEvent(display, M, true, 0);
		XFlush(display);
	}
void X11::mouseReleaseButton(MouseButton M)
	{
		XTestFakeButtonEvent(display, M, false, 0);
		XFlush(display);
	}
//Keyboard:
//Chars:
void X11::keyboardPressChar(char c)
	{
		XTestFakeKeyEvent(display, XKeysymToKeycode(display, c), true, 0);
		XFlush(display);
	}
void X11::keyboardReleaseChar(char c)
	{
		XTestFakeKeyEvent(display, XKeysymToKeycode(display, c), false, 0);
		XFlush(display);
	}
//Command keys:
void X11::keyboardPressKey(int I)
	{
		XTestFakeKeyEvent(display, I, true, 0);
		XFlush(display);
	}
void X11::keyboardReleaseKey(int I)
	{
		XTestFakeKeyEvent(display, I, false, 0);
		XFlush(display);
	}
//Command keys:
X11::~X11()
	{
		XCloseDisplay(display);
	}
