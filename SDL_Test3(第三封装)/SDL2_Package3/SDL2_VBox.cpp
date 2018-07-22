#include "SDL2_VBox.h"

using namespace WaterBox;

SDL2_VBox * WaterBox::SDL2_VBox::create(Math::vec2 position)
{
	SDL2_VBox *vBox = new SDL2_VBox();
	vBox->setPosition(Math::vec2(0, 0));
	return vBox;
}

void WaterBox::SDL2_VBox::update(SDL_Event * event)
{
	Math::vec2 nowPos = m_Position;
	for (auto i : m_Components)
	{
		i->setPosition(nowPos);
		i->update(event);
		nowPos.y += i->getSize().y + m_Spacing;
	}
}

void WaterBox::SDL2_VBox::show()
{
	for (auto &i : m_Components)
	{
		i->show();
	}
	return ;
}

void WaterBox::SDL2_VBox::addComponent(SDL2_Component * component)
{
	m_Components.push_back(component);
	component->setParent(this);
}

WaterBox::SDL2_VBox::SDL2_VBox()
{
	m_ComponentType = COMPONENT_VBOX;
	m_Spacing = 5;
}
