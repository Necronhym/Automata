#include "X11/X11.h"
#include "OCR/OCR.h"
#include "CV/CV.h"
#include "LUAScript/luaScript.h"
#include <iostream>
#include <unistd.h>
class Automata
	{
		public:
		//Automata Initializer:
		Automata(const char* ScriptLocation);
		void loadScript(const char* ScriptLocation);
		void runScript();
		~Automata();
	};
