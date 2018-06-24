#include "SDL2_Component.h"

using namespace WaterBox;

void WaterBox::SDL2_Component::setPosition(Math::vec2 position)
{
	m_Position = position;
}

void WaterBox::SDL2_Component::setSize(Math::vec2 size)
{
	m_Size = size;
}

Math::vec2 WaterBox::SDL2_Component::getPosition()
{
	return Math::vec2();
}

Math::vec2 WaterBox::SDL2_Component::getSize()
{
	return Math::vec2();
}
