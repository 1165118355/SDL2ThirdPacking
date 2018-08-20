#include "SDL2_Utils.h"

using namespace WaterBox;

SDL2_Utils *SDL2_Utils::m_Utils = nullptr;

SDL2_Utils::SDL2_Utils()
{
}


SDL2_Utils * WaterBox::SDL2_Utils::get()
{
	if (m_Utils == nullptr)
	{
		m_Utils = new SDL2_Utils();
	}
	return m_Utils;
}

int WaterBox::SDL2_Utils::StrToInt(std::string string)
{
	int num = 0;
	int tnum = 1;
	int n=0;
	for (int i = string.size(); i >= 0; --i)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			num += pow(10, n)*(string[i] - '0');
			++n;
		}
	}
	return num;
}

SDL2_Utils::~SDL2_Utils()
{
}
