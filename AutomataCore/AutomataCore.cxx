#include "AutomataCore.h"
/*
Lua C Function format:
int CH(lua_State* L)
	{
		//Passing a varable to function from lua: (-1 last, -2 second to last ets...)
		lua_Number a = lua_tonumber(L, -1);
		std::cout<<"Lua pass function Test Result"<<" Varable 1: " << a <<std::endl;

		//Return value to lua:
		lua_pushnumber(L, a*2);
		//Lua can return multiple variables: return tells us how many... Can be usefull for dem Objects:
		return 1;
	}	
*/

//Objects:
//Initiates X11 Machine:
X11 X;
//Initiates OCR Machine:
OCR O;
//Initiates OpenCV
CV C;
//CV Object container:
CV::Object S;
//Initiates Lua Script interpreter
luaScript L;
//CV mat container:
cv::Mat Image[9];
//Intermediate function to set image container:
void setImage(int i, cv::Mat img)
	{
		Image[i].release();
		Image[i] = img;
	}
cv::Mat getImage(int i)
	{
		return Image[i];
	}
cv::Mat loadImage(const char* c)
	{
		return C.loadMat(c);
	}
//Lua functions:
//Mouse Functions:
int LuaMoveMouse(lua_State* L)
	{		
		lua_Number y = lua_tonumber(L, -1);
		lua_Number x = lua_tonumber(L, -2);
		X.mouseMove( x, y );
		return 0;
	}
int LuaLClick(lua_State* L)
	{
		X.mousePressButton(left);
		return 0;
	}
int LuaLRelease(lua_State* L)
	{
		X.mouseReleaseButton(left);
		return 0;
	}
int LuaRClick(lua_State* L)
	{
		X.mousePressButton(right);
		return 0;
	}
int LuaRRelease(lua_State* L)
	{
		X.mouseReleaseButton(right);
		return 0;
	}
//Keyboard Functions:
int LuaKeyboardCharPress(lua_State* L)
	{
		const char* C = lua_tostring(L, -1);
		X.keyboardPressChar(C[0]);
		return 0;
	}
int LuaKeyboardCharRelease(lua_State* L)
	{
		const char* C = lua_tostring(L, -1);
		X.keyboardReleaseChar(C[0]);
		return 0;
	}
int LuaKeyboardKeyPress(lua_State* L)
	{
		lua_Number n = lua_tonumber(L, -1);
		X.keyboardPressKey(n);
		return 0;
	}
int LuaKeyboardKeyRelease(lua_State* L)
	{
		lua_Number n = lua_tonumber(L, -1);
		X.keyboardReleaseKey(n);
		return 0;
	}
//Image Functions:
int LuaTakeScreenshot(lua_State* L)
	{
		lua_Number h = lua_tonumber(L, -1);
		lua_Number w = lua_tonumber(L, -2);
		lua_Number y = lua_tonumber(L, -3);
		lua_Number x = lua_tonumber(L, -4);
		lua_Number i = lua_tonumber(L, -5);
		setImage((int)i, X.takeScreenshot((int)x,(int)y,(int)w,(int)h));
		return 0;
	}
int LuaLoadImage(lua_State* L)
	{
		const char* c = lua_tostring(L, -1);
		lua_Number i = lua_tonumber(L, -2);
		setImage(i, loadImage(c));
		return 0;
	}
int LuaCropImage(lua_State *L)
	{
		lua_Number h = lua_tonumber(L, -1);
		lua_Number w = lua_tonumber(L, -2);
		lua_Number y = lua_tonumber(L, -3);
		lua_Number x = lua_tonumber(L, -4);
		lua_Number i2 = lua_tonumber(L, -5);
		lua_Number i = lua_tonumber(L, -6);
		setImage( (int)i, C.cropMat( getImage((int)i2), (int)x, (int)y, (int)w, (int)h));
		return 0;
	}
int LuaShowImage(lua_State *L)
	{
		lua_Number i = lua_tonumber(L, -1);
		cv::imshow("Test", getImage((int)i));
		cv::waitKey(0);
		return 0;
	}
//OCR
int LuaGetTextFromImage(lua_State* L)
	{
		lua_Number i = lua_tonumber(L, -1);
		lua_pushstring(L,O.getTextFromMat(getImage(i)));
		return 1;	
	}
//Filtering:
int LuaFilterImage(lua_State* L)
	{
		lua_Number Method = lua_tonumber(L, -1);
		lua_Number LowValue = lua_tonumber(L, -2);
		lua_Number HighValue = lua_tonumber(L, -3);
		lua_Number LowSaturation = lua_tonumber(L, -4);
		lua_Number HighSaturation = lua_tonumber(L, -5);
		lua_Number LowHue = lua_tonumber(L, -6);
		lua_Number HighHue = lua_tonumber(L, -7);
		//Image to filter:
		lua_Number i2 = lua_tonumber(L, -8);
		//Location of image to save after filtering:
		lua_Number i = lua_tonumber(L, -9);
		setImage((int)i, C.matFilter(getImage((int)i2), (int)HighHue, (int)LowHue, (int)HighSaturation, (int)LowSaturation, (int)HighValue, (int)LowValue, (bool)Method));
		return 0;
	}
//Masking:
int LuaCreateMask(lua_State* L)
	{
		//Image to filter:
		lua_Number i2 = lua_tonumber(L, -1);
		//Location of image to save after filtering:
		lua_Number i = lua_tonumber(L, -2);
		setImage((int)i, C.createAlphaMask(getImage((int)i2)));
		return 0;
	}
int LuaApplyMask(lua_State* L)
	{
		//Image to filter:
		lua_Number i3 = lua_tonumber(L, -1);
		lua_Number i2 = lua_tonumber(L, -2);
		//Location of image to save after filtering:
		lua_Number i = lua_tonumber(L, -3);
		setImage((int)i, C.applyMask(getImage((int)i3),getImage((int)i2)));
		return 0;
	}
//Templet Matching:
int LuaFindTemplet(lua_State* L)
	{
		//Templet
		lua_Number i2 = lua_tonumber(L, -1);
		//Image:
		lua_Number i = lua_tonumber(L, -2);
		//Obj container:
		CV::Object Obj = C.objTempletMatch( getImage(i), getImage(i2));
		//Lua Returns:
		lua_pushnumber(L, Obj.getX());
		lua_pushnumber(L, Obj.getY());
		lua_pushnumber(L, Obj.getW());
		lua_pushnumber(L, Obj.getH());
		return 4;
	}
//Object detection:
int LuaFindObject(lua_State* L)
	{
		//Templet
		lua_Number i = lua_tonumber(L, -1);
		//Object Container:
		CV::Object Obj = C.objDetect(getImage(i));
		//Lua Returns:
		lua_pushnumber(L, Obj.getX());
		lua_pushnumber(L, Obj.getY());
		lua_pushnumber(L, Obj.getW());
		lua_pushnumber(L, Obj.getH());
		return 4;
	}
Automata::Automata()
	{
		//Pass Functions to lua Stack:

		//Functions Lua Doenst Have so i'm making them myself in lua:
		L.passStringToLua("function Sleep(n) \n os.execute(\"sleep \" .. tonumber(n))\n end");

		//X11:
		//Mouse:
		//Move Mouse to XY:
		L.passFuncToLua(LuaMoveMouse, "MoveMouse");
		//Mouse Clicks:
		L.passFuncToLua(LuaLClick, "LClick");
		L.passFuncToLua(LuaLRelease, "LRelease");
		L.passFuncToLua(LuaRClick, "RClick");
		L.passFuncToLua(LuaRRelease, "RRelease");

		//Keyboard:
		//Command Keys definitions:
		L.passStringToLua("Esc=0; Enter=36; Alt=64; Backspace=22; Shift=50; Alt=64; Ctrl=37; Tab=23; CapsLock=66; NumLock=77; Win=134;");
		L.passStringToLua("F1=67; F2=68; F3=69; F4=70; F5=71; F6=72; F7=73; F8=74; F9=75; F10=76;");
		L.passStringToLua("F11=95; F12=96;Up=111; Down=116; Right=114; Left=113;");
		//Comman Key Functions:
		L.passFuncToLua(LuaKeyboardKeyPress, "KeyboardKeyPress");
		L.passFuncToLua(LuaKeyboardKeyRelease, "KeyboardKeyRelease");	
		//Char Keys"
		L.passFuncToLua(LuaKeyboardCharPress, "KeyboardCharPress");
		L.passFuncToLua(LuaKeyboardCharRelease, "KeyboardCharRelease");

		//Screenshot:
		L.passFuncToLua(LuaTakeScreenshot, "Screenshot");
		L.passFuncToLua(LuaLoadImage, "LoadImage");
		
		//Tesseract:
		//OCR:
		L.passFuncToLua(LuaGetTextFromImage, "GetTextFromImage");
		
		//OpenCV:
		//Filtering:
		L.passFuncToLua(LuaFilterImage, "FilterImage");
		//Masking:
		L.passFuncToLua(LuaCreateMask, "CreateMask");
		L.passFuncToLua(LuaApplyMask, "ApplyMask");
		//Templet Matching
		L.passFuncToLua(LuaFindTemplet, "FindTemplet");
		//Object Bordering:
		L.passFuncToLua(LuaFindObject, "FindObject");
		//Cropping:
		L.passFuncToLua(LuaCropImage, "CropImage");
		//Show Image:
		L.passFuncToLua(LuaShowImage, "ShowImage");
	}
void Automata::loadScript(const char* ScriptLocation)
	{
		L.loadScript(ScriptLocation);
	}
void Automata::runScript()
	{
		L.doScript();
	}
Automata::~Automata()
	{

	}
