#include "Graphics/CreateContext.h"
#include "Meta/LoadWindowOptions.h"

#include <string>

#include <iostream>

void (*GraphicsWindowCloseEvent)() {nullptr};

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Number Error: %d\nError: %s\n",description);
}

GLFWwindow* window;

int GraphicsStart()
{
	glfwSetErrorCallback(error_callback);

	if(!glfwInit())
		return 1;		


	int width,height,windowLoadStatus;
	bool isFloating;

	std::string title = "DarkAst";

	windowLoadStatus = LoadWindowOptions("Resources/Options.dat",width,height,isFloating);

	if(windowLoadStatus)
	{
		width = 100;
		height = 100;
		isFloating = true;
		title = "Error load";

		windowLoadStatus |= 0b100;
	}

	window = glfwCreateWindow(width,height,title.c_str(),NULL,NULL);
	if(!window)
		return 2;
	
	glfwMakeContextCurrent(window);

	return windowLoadStatus;
}

void GraphicsStop()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GraphicsUpdate()
{
	glfwSwapBuffers(window);
	glfwPollEvents();

	if(glfwWindowShouldClose(window) && GraphicsWindowCloseEvent) 
		GraphicsWindowCloseEvent();
}

/*
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
}*/
