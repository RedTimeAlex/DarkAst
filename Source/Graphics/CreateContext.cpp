#include "Graphics/CreateContext.h"
#include "Meta/LoadWindowOptions.h"

#include <iostream>

GLFWwindow* window;

void CreateContext()
{
	throw "Don't use CreateContext";	
}

void Graphics::CreateStandartContext()
{
	if(!glfwInit())
		throw "Error glfw init!";
	window = glfwCreateWindow(640,480,"Error! Can't load meta file!",NULL,NULL);
	if(!window)
	{
		glfwTerminate();
		throw "Error can't create window";
	}

	glfwMakeContextCurrent(window);
}

void Graphics::LoadSetingsFromMeta()
{
	int width,height;
	bool isFloating;

	std::cout << LoadWindowOptions("Resources/Options.dat",width,height,isFloating);

	std::cout << width << ' '  << height << ' ' << isFloating << std::endl;

	if(!glfwInit())
		throw "Error glfw init!";

	glfwWindowHint(GLFW_FLOATING,GLFW_TRUE);

	window = glfwCreateWindow(width,height,"DarkAct",NULL,NULL);

	if(!window)
	{
		glfwTerminate();
		throw "Error can't create window";
	}
	glfwMakeContextCurrent(window);
}

void Graphics::DestroyContext()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
