#include <GLFW/glfw3.h>
///\addtogroup Graphics_module  
///\{

///Create gl context and open window
/**
 * \returns If return 1, can't glfw init;\n
 * If return 2, can't create window;\n
 * IF return 5, create window, but LoadWindowOptions() returned 1;
 * IF return 6, create window, but LoadWindowOptions() returned 2;
 * \see int LoadWindowOptions();
 */
int GraphicsStart();

///Events for close window
/**
 * This pointer is used when the user closes the window.
 */
extern void (*GraphicsWindowCloseEvent)();


///Close window
void GraphicsStop();

///Update graphics events
void GraphicsUpdate();
///\}
