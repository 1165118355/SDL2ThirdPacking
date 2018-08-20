#include "SDL2_Window.h"

using namespace WaterBox;

WaterBox::SDL2_Window::~SDL2_Window()
{
}

SDL2_Window * WaterBox::SDL2_Window::create(std::string name, Math::vec2 position, Math::vec2 size)
{
	SDL2_Window *win = new SDL2_Window();
	win->setName(name);
	win->setPosition(position);
	win->setSize(size);
	return win;
}

SDL_Window * WaterBox::SDL2_Window::getWindow()
{
	return m_Win;
}

void WaterBox::SDL2_Window::setPosition(Math::vec2 position)
{
	m_Position = position;
	SDL_SetWindowPosition(m_Win, m_Position.x, m_Position.y);
}

Math::vec2 WaterBox::SDL2_Window::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Window::setSize(Math::vec2 size)
{
	m_Size = size;
	SDL_SetWindowSize(m_Win, m_Size.x, m_Size.y);
}

Math::vec2 WaterBox::SDL2_Window::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_Window::addComponent(SDL2_Component * component)
{
	component->setParent(this);
}

void WaterBox::SDL2_Window::setName(std::string name)
{
	SDL_SetWindowTitle(m_Win, name.c_str());
}

void WaterBox::SDL2_Window::setMode(int mode)
{
}

WaterBox::SDL2_Window::SDL2_Window()
{
	m_Win = SDL_CreateWindow("w", 0, 0, 100, 100, 0);
}