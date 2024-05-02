#include <iostream>
#include <stdio.h>
#include "Graphics/CreateContext.h"

int isRunnig = true;

int main()
{

	GraphicsWindowCloseEvent = [](){isRunnig = false;};

	fprintf(stderr, "Error: %s\n", "description");

	std::cout << GraphicsStart() << std::endl;

	while(isRunnig)
	{
		GraphicsUpdate();	
	}

	GraphicsStop();

	return 0;
}
