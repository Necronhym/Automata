--Sleep testing:
--[[
print("time");
Sleep(0.1);
print("time");
Sleep(0.5);
print("time");
Sleep(1);
print("time");
Sleep(0.5);
print("time");
Sleep(0.1);
print("time");
]]--
--Mouse Testing:
--[[
MoveMouse(500, 500);
RClick();
RRelease();
Sleep(1);
MoveMouse(510, 505);
LClick();
Lelease();
]]--
--Keyboard Testing:
--Keyboard Char Testing:
--[[
KeyboardCharPress("A");
KeyboardCharRelease("A");
KeyboardCharPress("s");
KeyboardCharRelease("s");
KeyboardCharPress("s");
KeyboardCharRelease("s");
]]--
--Keyboard Command Key Testing
--[[
KeyboardKeyPress(Shift);
KeyboardCharPress("A");
KeyboardCharRelease("A");
KeyboardKeyRelease(Shift);
]]--
--Screenshto Test:
--[[
Screenshot(1, 200, 300, 400, 500);
]]--
--OCR Test:
--[[
Screenshot(1, 200, 300, 400, 500);
Sleep(1);
print(GetTextFromImage(1));
]]--
--Load image from location test
--[[
LoadImage(1,"Automata.png");
]]--
--Image Filtering:
--[[
LoadImage(1,"Automata.png");
Sleep(1);
	Image to save to, images to filter
FilterImage(2, 1, 255, 0, 255, 0, 255, 0, 0);
]]--
--AlphaMasking:
--[[
LoadImage(1,"Automata.png");
Sleep(1);
FilterImage(1, 1, 255, 0, 255, 155, 255, 0, 0);
Sleep(1);
	Image to save to, Image turn in to a mask
CreateMask(1,1);
Sleep(1);
LoadImage(2,"Automata.png");
Sleep(1);
	Image to save to, image to apply mask to, mask
ApplyMask(3,2,1)
]]--
--Templet Matching:
--[[
LoadImage(2,"Automata.png");
Sleep(1);
print(FindTemplet(2,2));
]]--
--Obj Find:
--[[
LoadImage(1,"Automata.png");
Sleep(1);
FilterImage(1, 1, 255, 0, 255, 200, 255, 0, 0);
print(FindObject(1));
]]--
--Cropping
--[[
LoadImage(1,"Automata.png");
Sleep(1);
CropImage(1, 1, 20, 20, 50, 50);
]]--
--Image Show
--[[
LoadImage(1,"Automata.png");
Sleep(1);
ShowImage(1);
]]--
