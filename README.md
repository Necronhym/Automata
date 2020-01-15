# Automata

Automata is an X11 based automation platform for GNU/Linux. It utilizes Lua scripting for automation, OpenCV for image processing, object detection and filtering, and tesseract-orc for optical character recognition

## Getting Started:

Simply download the contents of the repository, extract it and then run Make.
This should result in a working copy of Automata on your machine.

## Prerequisites:

Automata requires Lua 5.3 to handle scripting, OpenCV to handle image processing, X11 to handle image input and keyboard and mouse output and tesseract to handle ocr:

```
apt-get install libopencv-dev
apt-get install libtesseract-dev 
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

Here are examples of Automata in use:

### Authors:

* **Necronhym (N3cr0)** - *Initial work* -

