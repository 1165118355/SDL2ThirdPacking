#include "SDL2_Label.h"

using namespace WaterBox;

SDL2_Label * WaterBox::SDL2_Label::create(std::string text)
{
	SDL2_Label *label = new SDL2_Label(text);
	return label;
}

int WaterBox::SDL2_Label::show()
{
	m_MaterialText->show();
	return 0;
}

void WaterBox::SDL2_Label::update(SDL_Event * event)
{
}

void WaterBox::SDL2_Label::setSize(Math::vec2 size)
{
	m_Size = size;
	m_MaterialText->setSize(size);
}

SDL2_Label::SDL2_Label(std::string text)
{
	m_Text = text;
	m_MaterialText = SDL2_MaterialText::create(text);
}
