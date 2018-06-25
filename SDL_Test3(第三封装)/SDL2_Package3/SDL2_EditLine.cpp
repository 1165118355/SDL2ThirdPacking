#include "SDL2_EditLine.h"
#include <SDL2_Draw.h>

using namespace WaterBox;

SDL2_EditLine * WaterBox::SDL2_EditLine::create()
{
	SDL2_Material *mat = SDL2_Material::create();
	SDL2_EditLine *editLine = new SDL2_EditLine(mat);
	return editLine;
}

void WaterBox::SDL2_EditLine::setPosition(Math::vec2 position)
{
	m_Position = position;
	m_Material->setPosition(position);
}

Math::vec2 WaterBox::SDL2_EditLine::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_EditLine::setSize(Math::vec2 size)
{
	m_Size = size;
	m_Material->setSize(size);
}

Math::vec2 WaterBox::SDL2_EditLine::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_EditLine::show()
{
	if (SDL2_Material::TYPE_PARENT == m_Material->getType())
	{
		SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(200, 200, 200, 200));
	}
	else
	{
		m_Material->show();
	}
	if (1 == m_ChooseFlag)
	{
		Math::vec2 cursorPos1 = m_Position;
		Math::vec2 cursorPos2 = m_Position;
		cursorPos2.y += m_Size.y;
		cursorPos2.x += m_CurSorPos + 1;
		cursorPos1.x += m_CurSorPos + 1;
		SDL2_Draw::drawLine(cursorPos1, cursorPos2, Math::vec4(30, 30, 30, 200));
	}
}

void WaterBox::SDL2_EditLine::update(SDL_Event *event)
{
	int x = event->motion.x;
	int y = event->motion.y;
	if (x > m_Position.x && x < m_Position.x + m_Size.x && 
		y > m_Position.y && y < m_Position.y + m_Size.y)
	{
		if (SDL_MOUSEBUTTONDOWN == event->type)
		{
			m_ChooseFlag = 1;
		}
	}
	else if (SDL_MOUSEBUTTONUP == event->type || SDL_MOUSEBUTTONDOWN == event->type)
	{
		m_ChooseFlag = 0;
	}
}

WaterBox::SDL2_EditLine::SDL2_EditLine(SDL2_Material *mat)
{
	m_Material = mat;
	m_ChooseFlag = 0;
	setSize(Math::vec2(100, 30));
	setPosition(Math::vec2(0, 0));
}
