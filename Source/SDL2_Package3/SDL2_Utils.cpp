#include "SDL2_Utils.h"

using namespace WaterBox;

SDL2_Utils *SDL2_Utils::m_Utils = nullptr;

SDL2_Utils::SDL2_Utils()
{
	m_WinSize = Math::vec2(1000, 1000);
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
	if (string.substr(string.size()-3, 3) == "px")
	{
	}
	else if (string.substr(string.size() - 3, 3) == "xsp")
	{
		return m_WinSize.x / 1000 * num;
	}
	else if (string.substr(string.size() - 3, 3) == "ysp")
	{
		return m_WinSize.y / 1000 * num;
	}
	return num;
}

void WaterBox::SDL2_Utils::setWinSize(Math::vec2 size)
{
	m_WinSize = size;
}

Math::vec2 WaterBox::SDL2_Utils::getWinSize()
{
	return m_WinSize;
}

SDL2_Utils::~SDL2_Utils()
{
}
