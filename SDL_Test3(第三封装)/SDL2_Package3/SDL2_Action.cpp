#include "SDL2_Action.h"
#include <SDL2/SDL_image.h>

using namespace WaterBox;
namespace WaterBox
{
	static int g_add=0;
}
SDL2_Action::SDL2_Action()
{
	m_Velocity = 1;
}


SDL2_Action::~SDL2_Action()
{
}

SDL2_Action * WaterBox::SDL2_Action::create(std::string path, Math::vec2 pos, Math::vec2 cutSize, Math::vec2 isize, int number)
{
	SDL2_Action *action = new SDL2_Action();
	action->setPath(path);
	action->setInitPosition(pos);
	action->setCutSize(cutSize);
	action->setIncreasingSize(isize);
	action->setMaxFrame(number);
	return action;
}

void WaterBox::SDL2_Action::paly()
{
	if (g_add >= m_Velocity)
	{
		g_add = 0;
		++m_Action;
	}
	else
	{
		///		ËÙÂÊ
		g_add++;
	}

	if (m_Mat == nullptr)
	{
		return;
	}
	if (m_Action >= m_MaxFrame)
	{
		m_Action = 0;
	}
	m_NowPos = m_InitPos + (m_IncreasingSize * m_Action);
	m_Mat->setCutPosition(m_NowPos);
	m_Mat->setCutSize(m_CutSize);
	m_Mat->show();

}

void WaterBox::SDL2_Action::setName(std::string name)
{
	m_Name = name;
}

std::string WaterBox::SDL2_Action::getName()
{
	return m_Name;
}

void WaterBox::SDL2_Action::setPath(std::string path)
{
	m_Mat = SDL2_MaterialPicture::create(path.c_str());
	
}

std::string WaterBox::SDL2_Action::getPath()
{
	return std::string();
}

void WaterBox::SDL2_Action::setInitPosition(Math::vec2 pos)
{
	m_InitPos = pos;
}

Math::vec2 WaterBox::SDL2_Action::getInitPosition()
{
	return m_InitPos;
}

void WaterBox::SDL2_Action::setCutSize(Math::vec2 size)
{
	m_CutSize = size;
}

Math::vec2 WaterBox::SDL2_Action::getCutSize()
{
	return m_CutSize;
}

void WaterBox::SDL2_Action::setIncreasingSize(Math::vec2 size)
{
	m_IncreasingSize = size;
}

Math::vec2 WaterBox::SDL2_Action::getIncreasingSize()
{
	return m_IncreasingSize;
}

void WaterBox::SDL2_Action::setMaxFrame(int number)
{
	m_MaxFrame = number;
}

int WaterBox::SDL2_Action::getMaxFrame()
{
	return m_MaxFrame;
}

void WaterBox::SDL2_Action::setVelocity(int velocity)
{
	m_Velocity = velocity;
}

int WaterBox::SDL2_Action::getVelocity()
{
	return m_Velocity;
}

void WaterBox::SDL2_Action::setPosition(Math::vec2 position)
{
	m_Mat->setPosition(position);
}

Math::vec2 WaterBox::SDL2_Action::getPosition()
{
	return m_Mat->getPosition();
}

void WaterBox::SDL2_Action::setSize(Math::vec2 size)
{
	m_Mat->setSize(size);
}

Math::vec2 WaterBox::SDL2_Action::getSize()
{
	return m_Mat->getSize();
}

SDL2_Material * WaterBox::SDL2_Action::getMaterial()
{
	return m_Mat;
}
