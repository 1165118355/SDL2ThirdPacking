#include "SDL2_FontSystem.h"

using namespace WaterBox;

SDL2_FontSystem *SDL2_FontSystem::m_FontSys = nullptr;

SDL2_FontSystem * WaterBox::SDL2_FontSystem::get()
{
	if (nullptr == m_FontSys)
	{
		m_FontSys = new SDL2_FontSystem();
	}
	return m_FontSys;
}
TTF_Font *WaterBox::SDL2_FontSystem::createFont(std::string path, std::string name, int size/*=20*/)
{
	TTF_Font *font = TTF_OpenFont(path.c_str(), size);
	m_Fonts.insert(std::pair<std::string, TTF_Font *>(name.c_str(), font));
	return font;
}

TTF_Font * WaterBox::SDL2_FontSystem::findFont(std::string name)
{
	std::map<std::string, TTF_Font *>::iterator font = m_Fonts.find(name.c_str());
	if (nullptr != (*font).second)
	{
		return (*font).second;
	}
	return nullptr;
}

WaterBox::SDL2_FontSystem::SDL2_FontSystem()
{
}
