INPUT=Automata.cxx AutomataCore/X11/X11.cxx AutomataCore/CV/CV.cxx AutomataCore/OCR/OCR.cxx AutomataCore/LUAScript/luaScript.cxx AutomataCore/AutomataCore.cxx
OUTPUT=Automata
FLAGS=-o 
LINKS= -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_imgcodecs -lopencv_videoio  -lX11 -lXtst -llept -ltesseract -llua5.3
CC=g++ -Wall
c: $(INPUT)
		$(CC) $(INPUT) $(FLAGS) $(OUTPUT) $(LINKS)
