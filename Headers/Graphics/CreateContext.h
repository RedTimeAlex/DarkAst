#include <GLFW/glfw3.h>
///  @addtogroup Graphics_module  
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
	 * \warning Use if can't load context setings from files
	 */
	void CreateStandartContext(); 	

	///Create context and load setings for files
	/**
	 * \throw char* If glfw can't init.
	 * \throw char* If glfw can't create window.
	 * \throw char* If meta tag != [RTA_META_Game_Options]
	 */
	void LoadSetingsFromMeta();	

	///close window and Destroy context
	void DestroyContext();
}
/// @}
