#include "SDL2_Utils.h"

using namespace WaterBox;

SDL2_Utils *SDL2_Utils::m_Utils = nullptr;

SDL2_Utils::SDL2_Utils()
{
}


SDL2_Utils * WaterBox::SDL2_Utils::get()
{
	return nullptr;
}

int WaterBox::SDL2_Utils::StrToInt(std::string string)
{
	return -1;
}

SDL2_Utils::~SDL2_Utils()
{
}
