#include <fstream>
#include <iostream> 

///Load Game options from path.
/**
 * \ingroup Meta_module
 * Open file and check Tag
 * \see bool CheckTag()
 * \param[in] path Path to file
 * \param[out] wight,height Window size parametrs for file
 * \param[out] isWindowFloating Flag window floating for file
 *
 * \returns If return 0, load done;\n
 * If return 1, failed open file;\n
 * If return 2, failed check tag;
 */
int LoadWindowOptions(const char* path, int& wight,int& height,bool& isFloating);
