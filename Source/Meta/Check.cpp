#include "Meta/Check.h"
#include <string>
bool CheckTag(std::ifstream& in,const std::string&  tag)
{
	std::string buff;
	getline(in,buff);
	return buff == tag;
}
