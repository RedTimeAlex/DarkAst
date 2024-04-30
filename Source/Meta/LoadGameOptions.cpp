#include "Meta/LoadGameOptions.h"
#include "Meta/Check.h"

void LoadGameOptions(int& windowWight, int& windowHeight, bool& isWindowFloating)
{
	std::ifstream fileIn{"Resources/Options.dat"};

 	if(!CheckTag(fileIn,"[RTA_META_GameOptions]")) throw "bed tag!";

	fileIn >> windowWight >> windowHeight >> isWindowFloating;

	fileIn.close();
}

