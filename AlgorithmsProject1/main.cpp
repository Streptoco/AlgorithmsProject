#include "DriverProgram.h"
#define  CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	// TODO: handle errors with input, check for validity of undirected graph.
	DriverProgram program;
	program.printMenu();
	//_CrtDumpMemoryLeaks();
}
