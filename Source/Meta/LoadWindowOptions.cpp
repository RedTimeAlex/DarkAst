#include "Meta/LoadWindowOptions.h"
#include "Meta/Check.h"

int LoadWindowOptions(const char* path, int& wight, int& height, bool& isWindowFloating)
{
	std::ifstream fileIn{path};

	if(!fileIn.is_open())
		return 1;

 	if(!CheckTag(fileIn,"[RTA_META_GameOptions]")) 
		return 2;

	fileIn >> wight >> height >> isWindowFloating;

	fileIn.close();

	return 0;
}
