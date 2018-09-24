#include "SDL2_Box.h"

using namespace WaterBox;

int WaterBox::SDL2_Box::getNumComponents()
{
	return m_Components.size();
}

SDL2_Component * WaterBox::SDL2_Box::getComponent(int num)
{
	if (m_Components.size() <= num)
	{
		return nullptr;
	}
	return m_Components[num];
}

void WaterBox::SDL2_Box::materialModification()
{
}

void WaterBox::SDL2_Box::show()
{
}

void WaterBox::SDL2_Box::update(SDL_Event * event)
{
}

void WaterBox::SDL2_Box::clear()
{
	for (int i=0; i<m_Components.size(); ++i)
	{
		delete m_Components[i];
	}
	m_Components.clear();
}

SDL2_Box::SDL2_Box()
{
	m_ComponentType = COMPONENT_BOX;
}


SDL2_Box::~SDL2_Box()
{
}

SDL2_Box * WaterBox::SDL2_Box::cast(SDL2_Component * component)
{
	if (nullptr == component)
	{
		return nullptr;
	}
	SDL2_Box * box = dynamic_cast<SDL2_Box *>(component);
	return box;
}

void WaterBox::SDL2_Box::addComponent(SDL2_Component * component)
{
	m_Components.push_back(component);
}
