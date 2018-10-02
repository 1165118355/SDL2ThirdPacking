#include "SDL2_CheckBox.h"
#include <SDL2_Draw.h>
#include <SDL2_Utils.h>
#include <SDL2_MaterialPicture.h>
#include <iostream>

using namespace WaterBox;

SDL2_CheckBox * WaterBox::SDL2_CheckBox::create()
{
	SDL2_CheckBox *checkBox = new SDL2_CheckBox();
	return checkBox;
}

SDL2_CheckBox * WaterBox::SDL2_CheckBox::create(SDL2_Xml * xml)
{
	SDL2_CheckBox *checkbox = new SDL2_CheckBox();
	checkbox->analysisXml(xml);
	return checkbox;
}

void WaterBox::SDL2_CheckBox::setValue(int value)
{
	m_Value = value;
}

int WaterBox::SDL2_CheckBox::getValue()
{
	return m_Value;
}

void WaterBox::SDL2_CheckBox::setPosition(Math::vec2 position)
{
	m_Position = position;
}

Math::vec2 WaterBox::SDL2_CheckBox::getPositioin()
{
	return m_Position;
}

void WaterBox::SDL2_CheckBox::setSize(Math::vec2 size)
{
	m_Size = size;
}

Math::vec2 WaterBox::SDL2_CheckBox::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_CheckBox::show()
{
	if (nullptr == m_MaterialBack)
	{
		SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(255, 255, 255, 200));
		if (1 == m_Value)
		{
			SDL2_Draw::drawRectangle(m_Position+(m_Size/6), (m_Size/6)*4, Math::vec4(20, 180, 20, 200));
		}
	}
	else
	{
		m_MaterialBack->show();
		m_MaterialIn->show();
	}
}

void WaterBox::SDL2_CheckBox::update(SDL_Event * event)
{
}

void WaterBox::SDL2_CheckBox::materialModification()
{
	if (m_MaterialBack != nullptr)
	{
		m_MaterialBack->setPosition(getPositioin());
		m_MaterialBack->setSize(getSize());
	}

	if (m_MaterialIn != nullptr)
	{
		m_MaterialIn->setPosition(getPositioin());
		m_MaterialIn->setSize(getSize());
	}
	
}

void WaterBox::SDL2_CheckBox::setMaterialBack(SDL2_Material * matBack)
{
	m_MaterialBack = matBack;
}

SDL2_Material * WaterBox::SDL2_CheckBox::getMateralBack()
{
	return m_MaterialBack;
}

void WaterBox::SDL2_CheckBox::setMaterialIn(SDL2_Material * matIn)
{
	m_MaterialIn = matIn;
}

SDL2_Material * WaterBox::SDL2_CheckBox::getMaterialIn()
{
	return m_MaterialIn;
}

int WaterBox::SDL2_CheckBox::analysisXml(SDL2_Xml * xml)
{
	if (-1 == SDL2_Component::analysisXml(xml))
	{
		return -1;
	}
	if (xml->getTag("value") != "")
	{
		setValue(SDL2_Utils::get()->StrToInt(xml->getTag("value")));
	}
	if (xml->getTag("path_back") != "")
	{
		setMaterialBack(SDL2_MaterialPicture::create(xml->getTag("path_back")));
	}
	if (xml->getTag("path_in") != "")
	{
		setMaterialIn(SDL2_MaterialPicture::create(xml->getTag("path_in")));
	}
	return 0;
}

std::vector<SDL2_Material*> WaterBox::SDL2_CheckBox::getMaterials()
{
	std::vector<SDL2_Material*> materials;
	if (nullptr != m_MaterialBack)
	{
		materials.push_back(m_MaterialBack);
	}
	if (nullptr != m_MaterialIn)
	{
		materials.push_back(m_MaterialIn);
	}
	return materials;
}

void WaterBox::SDL2_CheckBox::updateEventMouse(SDL_Event * event)
{
	int x = event->motion.x;
	int y = event->motion.y;
	if (x > m_Position.x && x < m_Position.x + m_Size.x &&
		y > m_Position.y && y < m_Position.y + m_Size.y)
	{
		if (SDL_MOUSEBUTTONDOWN == event->type)
		{
			m_Value = !m_Value;
			std::cout << "Value=" << m_Value << std::endl;
		}
	}
}

void WaterBox::SDL2_CheckBox::updateEventKeyboard(SDL_Event * event)
{
}

WaterBox::SDL2_CheckBox::SDL2_CheckBox()
{
	m_Value = 0;
	m_MaterialBack = nullptr;
	m_MaterialIn = nullptr;
	setSize(Math::vec2(30, 30));
	setPosition(Math::vec2(0, 0));
	m_ComponentType = COMPONENT_CHECKBOX;
}
