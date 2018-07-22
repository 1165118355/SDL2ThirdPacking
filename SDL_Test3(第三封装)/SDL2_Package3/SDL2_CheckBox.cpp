#include "SDL2_CheckBox.h"
#include <SDL2_Draw.h>
#include <iostream>

using namespace WaterBox;

SDL2_CheckBox * WaterBox::SDL2_CheckBox::create()
{
	SDL2_Material *matBack = SDL2_Material::create();
	SDL2_Material *matIn = SDL2_Material::create();
	SDL2_CheckBox *checkBox = new SDL2_CheckBox(matBack, matIn);
	return checkBox;
}

int WaterBox::SDL2_CheckBox::getValue()
{
	return m_Value;
}

void WaterBox::SDL2_CheckBox::setPosition(Math::vec2 position)
{
	m_Position = position;
	m_MaterialBack->setPosition(position);
	m_MaterialIn->setPosition(position);
}

Math::vec2 WaterBox::SDL2_CheckBox::getPositioin()
{
	return m_Position;
}

void WaterBox::SDL2_CheckBox::setSize(Math::vec2 size)
{
	m_Size = size;
	m_MaterialBack->setSize(size);
	m_MaterialIn->setSize(size);
}

Math::vec2 WaterBox::SDL2_CheckBox::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_CheckBox::show()
{
	if (SDL2_Material::TYPE_PARENT == m_MaterialBack->getType())
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
	int x = event->motion.x;
	int y = event->motion.y;
	if (x > m_Position.x && x < m_Position.x + m_Size.x &&
		y > m_Position.y && y < m_Position.y + m_Size.y)
	{
		if (SDL_MOUSEBUTTONDOWN == event->type)
		{
			m_Value = !m_Value;
			std::cout <<"Value="<< m_Value<<std::endl;
		}
	}
}

WaterBox::SDL2_CheckBox::SDL2_CheckBox(SDL2_Material *matBack, SDL2_Material *matIn)
{
	m_Value = 0;
	m_MaterialBack = matBack;
	m_MaterialIn = matIn;
	setSize(Math::vec2(30, 30));
	setPosition(Math::vec2(0, 0));
	m_ComponentType = COMPONENT_CHECKBOX;
}
