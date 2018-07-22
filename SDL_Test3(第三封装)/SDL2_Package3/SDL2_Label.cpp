#include "SDL2_Label.h"

using namespace WaterBox;

SDL2_Label * WaterBox::SDL2_Label::create(std::string text)
{
	SDL2_Label *label = new SDL2_Label(text);
	return label;
}

void WaterBox::SDL2_Label::show()
{
	m_MaterialText->show();
	return ;
}

void WaterBox::SDL2_Label::update(SDL_Event * event)
{
}

void WaterBox::SDL2_Label::setPosition(Math::vec2 position)
{
	m_Position = position;
	m_MaterialText->setPosition(position);
}

Math::vec2 WaterBox::SDL2_Label::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Label::setSize(Math::vec2 size)
{
	m_Size = size;
	m_MaterialText->setSize(size);
}

Math::vec2 WaterBox::SDL2_Label::getSize()
{
	return m_Size;
}

SDL2_Label::SDL2_Label(std::string text)
{
	m_Text = text;
	m_MaterialText = SDL2_MaterialText::create(text);
	m_ComponentType = COMPONENT_LABEL;
}
