#include <GLFW/glfw3.h>
///  @addtogroup graphics
///  @{
	
///DON'T USE IT!
/**
 * \warning DON'T USE IT!
 */
void CreateContext();

///namespace with Functions for currecti work 
namespace Graphics
{

	///Open window and create context from standart context
	/**
	 * \throw char* If glfw can't init;
	 * \throw char* If glfw can't 
	void CreateStandartContext(); 	

	void LoadSetingsFromMeta();	

	void DestroyContext();
}
/// @}
