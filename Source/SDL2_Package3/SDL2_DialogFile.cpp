#include "SDL2_DialogFile.h"
#include <SDL2_Gui.h>

using namespace WaterBox;

SDL2_DialogFile *SDL2_DialogFile::m_Instance = nullptr;

SDL2_DialogFile::SDL2_DialogFile()
{
	m_List = SDL2_List::create();
	m_ButtonConfirm = SDL2_Button::create();
	m_ButtonConfirm = SDL2_Button::create();
}


SDL2_DialogFile * WaterBox::SDL2_DialogFile::get()
{
	if (nullptr == m_Instance)
	{
		m_Instance = new SDL2_DialogFile();
		SDL2_Gui::get()->addComponent(m_Instance);
	}
	return m_Instance;
}

std::string WaterBox::SDL2_DialogFile::getOpenFile(std::string title, std::string path/*="./"*/, std::string filter/*="*"*/)
{
	m_Enable = true;
	while (true)
	{
	}
	m_Enable = false;
	return std::string();
}

std::string WaterBox::SDL2_DialogFile::getDir(std::string title, std::string path/*="./"*/)
{
	m_Enable = true;
	while (true)
	{

	}
	m_Enable = false;
	return std::string();
}

void WaterBox::SDL2_DialogFile::show()
{
	if (false == m_Enable)
	{
		return;
	}
}

void WaterBox::SDL2_DialogFile::update(SDL_Event * event)
{
	if (false == m_Enable)
	{
		return;
	}
}

SDL2_DialogFile::~SDL2_DialogFile()
{
}
