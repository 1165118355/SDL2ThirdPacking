#include "SDL2_TextBrowser.h"
#include <SDL2_Draw.h>

using namespace WaterBox;

SDL2_TextBrowser::SDL2_TextBrowser()
{
	m_MaterialBack = nullptr;
}


SDL2_TextBrowser::~SDL2_TextBrowser()
{
}

SDL2_TextBrowser * WaterBox::SDL2_TextBrowser::create()
{
	SDL2_TextBrowser *textBrowser = new SDL2_TextBrowser();
	return nullptr;
}

void WaterBox::SDL2_TextBrowser::update(SDL_Event * event)
{
}

void WaterBox::SDL2_TextBrowser::materialModification()
{
	if (m_MaterialBack)
	{
		m_MaterialBack->setPosition(this->getPosition());
		m_MaterialBack->setSize(this->getSize());
	}
}

void WaterBox::SDL2_TextBrowser::show()
{
	if (nullptr == m_MaterialBack)
	{
		SDL2_Draw::drawRectangle(this->getPosition(), this->getSize(), Math::vec4(90, 90, 90, 90));
	}
	else
	{
		m_MaterialBack->show();
	}
}

int WaterBox::SDL2_TextBrowser::analysisXml(SDL2_Xml * xml)
{
	return 0;
}

std::vector<SDL2_Material*> WaterBox::SDL2_TextBrowser::getMaterials()
{
	return std::vector<SDL2_Material*>();
}

void WaterBox::SDL2_TextBrowser::updateEventMouse(SDL_Event * event)
{
}

void WaterBox::SDL2_TextBrowser::updateEventKeyboard(SDL_Event * event)
{
}
