#include "AutomataCore/AutomataCore.h"
int main(int argc, char* argv[])
	{
		Automata A;
		A.loadScript(argv[1]);
		A.runScript();
		return 0;
	}
