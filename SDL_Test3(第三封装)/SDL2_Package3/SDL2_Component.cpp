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
	return m_Position;
}

Math::vec2 WaterBox::SDL2_Component::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_Component::setParent(SDL2_Component * parent)
{
	m_Parent = parent;
}

void WaterBox::SDL2_Component::addChild(SDL2_Component * parent)
{
	m_Childes.push_back(parent);
}

void WaterBox::SDL2_Component::setAlign(AlignType align)
{
	m_Align = align;
}

SDL2_Component::AlignType WaterBox::SDL2_Component::getAlign()
{
	return m_Align;
}

void WaterBox::SDL2_Component::Align()
{
	/*ALIGN_CENTER = 1,
		ALIGN_LEFT = 2,
		ALIGN_RIGHT = 4,
		ALIGN_TOP = 8,
		ALIGN_BOTTOM = 16*/
	if (nullptr == m_Parent)
	{
		return;
	}
	int temp = 1;
	Math::vec2 parentPosition = m_Parent->getPosition();
	Math::vec2 parentSize = m_Parent->getSize();
	Math::vec2 nowPos = m_Parent->getPosition();;
	for (int i = 0; i<sizeof(AlignType) / sizeof(ALIGN_CENTER); ++i)
	{
		switch (m_Align & temp)
		{
		case ALIGN_CENTER:
			setPosition(parentPosition+((parentSize-getSize())/2));
			break;
		case ALIGN_LEFT:
			//setPosition();
			break;
		case ALIGN_RIGHT:

			break;
		case ALIGN_TOP:

			break;
		case ALIGN_BOTTOM:

			break;
		}
		temp = temp << 1;
	}
}

WaterBox::SDL2_Component::SDL2_Component()
{
	m_Parent = NULL;
	m_Align = ALIGN_NONE;
	m_ComponentType = COMPONENT_NONE;
}
