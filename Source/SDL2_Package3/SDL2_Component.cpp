#include "SDL2_Component.h"
#include <SDL2_Utils.h>
#include <SDL2_MainWindow.h>

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

void WaterBox::SDL2_Component::addChild(SDL2_Component * child)
{
	if (nullptr != child)
	{
		child->setParent(this);
	}
	m_Childes.push_back(child);
}

void WaterBox::SDL2_Component::setAlign(int align)
{
	m_Align = align;
	Align();
}

int WaterBox::SDL2_Component::getAlign()
{
	return m_Align;
}

void WaterBox::SDL2_Component::setName(std::string name)
{
	m_Name = name;
}

std::string WaterBox::SDL2_Component::getName()
{
	return m_Name;
}

int WaterBox::SDL2_Component::getNumChildes()
{
	return m_Childes.size();
}

SDL2_Component * WaterBox::SDL2_Component::getChild(int num)
{
	if (num >= m_Childes.size())
	{
		return nullptr;
	}
	return m_Childes[num];
}

std::vector<SDL2_Material*> WaterBox::SDL2_Component::getMaterials()
{
	return std::vector<SDL2_Material*>();
}

int WaterBox::SDL2_Component::analysisXml(SDL2_Xml * xml)
{
	if (xml == nullptr)
	{
		return -1;
	}
	if (xml->getTag("x") != "")
	{
		m_Position.x = SDL2_Utils::get()->StrToInt(xml->getTag("x"));
	}
	if (xml->getTag("y") != "")
	{
		m_Position.y = SDL2_Utils::get()->StrToInt(xml->getTag("y"));
	}
	if (xml->getTag("w") != "")
	{
		m_Size.x = SDL2_Utils::get()->StrToInt(xml->getTag("w"));
	}
	if (xml->getTag("h") != "")
	{
		m_Size.y = SDL2_Utils::get()->StrToInt(xml->getTag("h"));
	}
	if (xml->getTag("align") != "")
	{
		//button->setMatAfterPath(xml->getTag("align"));
	}
	if (xml->getTag("name") != "")
	{
		setName(xml->getTag("name"));
	}
	setPosition(m_Position);
	setSize(m_Size);
	return 0;
}

void WaterBox::SDL2_Component::materialModification()
{
}

void WaterBox::SDL2_Component::Align()
{
	Math::vec2 parentPos;
	Math::vec2 parentSize;
	Math::vec2 nowPos;
	Math::vec2 nowSize;
	if (nullptr == m_Parent)
	{
		parentPos = Math::vec2(0, 0);
		parentSize = SDL2_MainWindow::get()->getSize();
		return;
	}
	else
	{
		parentPos = m_Parent->getPosition();
		parentSize = m_Parent->getSize();
	}

	int temp = 1;	//	
	nowPos = parentPos;
	nowSize = parentSize;
	for (int i = 0; i < sizeof(AlignType) / sizeof(ALIGN_CENTER); ++i)
	{
		switch (m_Align & temp)
		{
		case ALIGN_CENTER:
			setPosition(parentPos + (parentSize - m_Size)/2);
			break;
		case ALIGN_LEFT:
			nowPos = getPosition();
			nowPos.x = parentPos.x;
			setPosition(nowPos);
			//setPosition();
			break;
		case ALIGN_RIGHT:
			nowPos = getPosition();
			nowPos.x = parentPos.x+parentSize.x- nowSize.x;
			setPosition(nowPos);
			break;
		case ALIGN_TOP:
			nowPos = getPosition();
			nowSize = getSize();
			nowPos.y = parentPos.y;
			setPosition(nowPos);
			break;
		case ALIGN_BOTTOM:
			nowPos = getPosition();
			nowSize = getSize();
			nowPos.y = parentPos.y+parentSize.y- nowSize.y;
			setPosition(nowPos);
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
