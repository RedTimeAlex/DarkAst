#include "Graphics/CreateContext.h"
#include "Meta/LoadGameOptions.h"

/**
 * \addtogroup graphics_module
 * \{
 */

///Object for window
GLFWwindow* window;

///\fn void CreateContext
///DON'T USE IT.
void CreateContext()
{
	throw "Don't use CreateContext";	
}

///\fn void Graphics::CreateStandartContext
///Create context for standart setings
/**
 * \throw char* If glfw can't init;
 * \throw char* If glfw can't create window
 * \warning Use if can't load context from Options.dat
 */
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

///\fn void Graphics::LoadSetingsFromMeta
///Create context for standart setings
/**
 * \fn LoadSetingsFromMeta()
 * \throw char* If glfw can't init;
 * \throw char* If glfw can't create window
 * \throw char* If meta tag != [RTA_META_Game_Options]
 */
void Graphics::LoadSetingsFromMeta()
{
	int width,height;
	bool isFloating;

	LoadGameOptions(width,height,isFloating);

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

///\fn Graphics::DestroyContext
///Close window and Destroy window
void Graphics::DestroyContext()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

/** \} */
