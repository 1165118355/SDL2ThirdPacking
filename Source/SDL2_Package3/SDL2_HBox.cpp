#include "SDL2_HBox.h"

using namespace WaterBox;

SDL2_HBox * WaterBox::SDL2_HBox::create(Math::vec2 position/*=vec2(0, 0)*/)
{
	SDL2_HBox *hBox =  new SDL2_HBox();
	hBox->setPosition(Math::vec2(0, 0));
	return hBox;
}

SDL2_HBox * WaterBox::SDL2_HBox::create(SDL2_Xml * xml)
{
	SDL2_HBox *hBox = new SDL2_HBox();
	hBox->analysisXml(xml);
	return hBox;
}

void WaterBox::SDL2_HBox::update(SDL_Event * event)
{
	Math::vec2 nowPos = m_Position;
	for (auto &i : m_Components)
	{
		nowPos.y = i->getPosition().y;
		if (i->getAlign() == ALIGN_NONE)
		{
			nowPos.y = m_Position.y;
		}
		i->update(event);
		i->setPosition(nowPos);
		nowPos.x += i->getSize().x + m_Spacing;
	}
}

void WaterBox::SDL2_HBox::materialModification()
{
	for (auto &i : m_Components)
	{
		i->materialModification();
	}
}

void WaterBox::SDL2_HBox::show()
{
	for (auto &i:m_Components)
	{
		i->show();
	}
	return ;
}

int WaterBox::SDL2_HBox::analysisXml(SDL2_Xml * xml)
{
	if (-1 == SDL2_Component::analysisXml(xml))
	{
		return -1;
	}
	return 0;
}

void WaterBox::SDL2_HBox::addComponent(SDL2_Component * component)
{
	m_Components.push_back(component);
}

void WaterBox::SDL2_HBox::addChild(SDL2_Component * child)
{
	SDL2_Component::addChild(child);
	addComponent(child);
}

WaterBox::SDL2_HBox::SDL2_HBox()
{
	m_Spacing = 5;
	m_ComponentType = COMPONENT_HBOX;
}
