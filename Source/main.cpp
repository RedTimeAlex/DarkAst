#include <iostream>
#include <stdio.h>
#include "Graphics/CreateContext.h"

int isRunnig = true;

int main()
{

	GraphicsWindowCloseEvent = [](){isRunnig = false;};

	printf("0b%b\n",GraphicsStart());

	while(isRunnig)
	{
		GraphicsUpdate();	
	}

	GraphicsStop();

	return 0;
}
