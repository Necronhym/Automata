# Automata

Automata is an X11 based automation platform for GNU/Linux. It utilizes Lua scripting for automation, OpenCV for image processing, object detection and filtering, and tesseract-orc for optical character recognition.

## Getting Started:

Simply download the contents of the repository, extract it and then run Make.
This should result in a working copy of Automata on your machine.

## Prerequisites:

Automata requires Lua 5.3 to handle scripting, OpenCV to handle image processing, X11 to handle image input and keyboard and mouse output and tesseract to handle ocr:

```
apt-get install libopencv-dev
apt-get install libtesseract-dev 
apt-get install tesseract-ocr
apt-get install libx11-dev
apt-get install liblua5.3-dev
```

## Running:

Following an installation to run Automata you need to give it execution permissions.
To do this run the following:

```
chmod +x Automata
```

And then execute it by running:

```
Automata example.lua
```

This will run the example script. To run your own custom script replace the example.lua wita a file path to your own lua script.

## Scripting:

Automata hosts a diverse tool set of functions designed for responsive automation.
Currently supported functions, and examples on how to use them include:

### Mouse Actions: 

Move the mouse to a given location:
```
MoveMouse(int x, int y);
```
Perform a right mouse button press:
```
RClick();
```
Release right mouse button:
```
RRelease();
```
Perform a left button press:
```
LClick();
```
Release left mouse button:
```
LRelease();
```
Perform a middle button press:
```
LClick();
```
Release middle mouse button:
```
LRelease();
```

### Keyboard Acrions:

Presses a keyboard character:
```
KeyboardCharPress( char c);
```
Releases a keyboard character:
```
KeyboardCharRelease(char c);
```
Presses a keyboard command kaye:
```
KeyboardCharPress(CommandKey);
```
Releases a keyboard command key:
```
KeyboardCharRelease(CommandKey);
```
Command Keys are supplied to the function as their names.
Examples:
```
Esc, Enter, Backspace, Shift, Alt, Ctrl, Tab,
```
Locks:
```
CapsLock, NumLock,
```
Windows key:
```
Win
```
Arrow Keys:
```
Up, Down, Right, Left
```
F Keys:
```
F1-F12
```

#### Image IDs:

Due to lua limitations and lack of class support Automata currently has a limited number of images it can store.
This number is currently set to 10 images by default.(Might be expanded later)
These images can be referenced from memory using their image ID number.
These are indexed from 0 to 9;

### Image acquisition:

Automata hosts 2 mains ways of aquiring images.
Taking a screenshot from X11:
```
Screenshot(int ImageID, int x, int y, int w, int h);
```
And Loading an image from memory:
```
LoadImage(int ImageId, string ImageLocation);
```

### Image view:

For testing reasons Automata allows for image viewing from a script.
```
ShowImage(int ImageId);
```

### Sleep:
Lua doesn't wait for a C function to finish executing to run the next function.
This could lead to errors in scripts.
This is currently fixed by using a sleep function.
Sleep takes a flot as a variable and waits for a given amount of time.
0.5 waits for 500ms
1 waits form 1 second
```
Sleep(float Time);
```

### Image Processing:

#### Cropping:
```
CropImage(int IDtoSaveImageTo, int ImageToCrop, int x, int y, int w, int h);
```
#### Filtering:
Values for Hue, Saturation and Value go from 0-255
Masking method defines the filtering method. 
0 results in removing all pixels that are not inside filter parameters
1 results in removing all pixels that are inside the filter parameters
```
FilterImage(int IDtoSaveImageTo, int ImageToFilter, int HighHue, int LowHue, int HighSaturation, int LowSaturation, int HighValue, int LowValue, bool MatchingMethon);
```
#### AlphaMasking:
Alpha masking allows removeing parts of an image from antoher image using alpha transparency masks.
Transparent parts of an image will not be removed.
This process is split in to two parts
Creating an alpha mask:
```
CreateMask(int ImageIdToSaveTo, int ImageToTurnToMask);
```
Applying an alpha mask:
```
ApplyMask(ing ImageIdToSaveTo,int ImageToApplyMaskTo, int MaskToApply)
```

### Extractiong Data From Images:

#### Templet Mathing:
Templet matching locates an image inside another image and returns it's x,y and w,h.
```
FindTemplet(int ImageId,int TempletId);
```
#### Object Detection:
Object detection returns a rectangles x,y and w,h drawn around object bounderies found inside an image. It is recommended to use this function in combination with image filtering.
```
FindObject(int ImageId);
```
#### OCR:
Optical character recognition is used to scrape text from iamges and returns a string:
```
GetTextFromImage(int ImageID);
```

## Authors:

* **Necronhym (N3cr0)** - *Initial work* -

