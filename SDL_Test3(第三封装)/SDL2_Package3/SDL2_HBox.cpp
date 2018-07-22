#include "SDL2_HBox.h"

using namespace WaterBox;

SDL2_HBox * WaterBox::SDL2_HBox::create(Math::vec2 position/*=vec2(0, 0)*/)
{
	SDL2_HBox *hBox =  new SDL2_HBox();
	hBox->setPosition(Math::vec2(0, 0));
	return hBox;
}

void WaterBox::SDL2_HBox::update(SDL_Event * event)
{
	Math::vec2 nowPos = m_Position;
	for (auto i : m_Components)
	{
		i->setPosition(nowPos);
		i->update(event);
		nowPos.x += i->getSize().x + m_Spacing;
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

void WaterBox::SDL2_HBox::addComponent(SDL2_Component * component)
{
	m_Components.push_back(component);
}

WaterBox::SDL2_HBox::SDL2_HBox()
{
	m_Spacing = 5;
	m_ComponentType = COMPONENT_HBOX;
}
