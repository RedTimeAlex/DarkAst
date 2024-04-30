#include <iostream>
#include <stdio.h>
#include "Graphics/CreateContext.h"
int main()
{
	std::cout << "Hello world" << std::endl;

	Graphics::LoadSetingsFromMeta();

	getchar();

	Graphics::DestroyContext();

	return 0;
}
