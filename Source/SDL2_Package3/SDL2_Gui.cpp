#include "SDL2_Gui.h"
#include <SDL2/SDl.h>
#include <SDL2_Renderer.h>

using namespace WaterBox;

SDL2_Gui *SDL2_Gui::m_gui = nullptr;

SDL2_Gui * WaterBox::SDL2_Gui::get()
{
	if (m_gui == nullptr)
	{
		m_gui = new SDL2_Gui();
	}
	return m_gui;
}

int WaterBox::SDL2_Gui::addComponent(SDL2_Component *component)
{
	static int count=0;
	m_Components.insert(std::pair<int, SDL2_Component *>(count++, component));
	return 0;
}

void WaterBox::SDL2_Gui::clear()
{
	for (std::map<int, SDL2_Component *>::iterator it = m_gui->m_Components.begin(); it != m_gui->m_Components.end(); ++it)
	{
		if ((*it).second)
		{
			delete (*it).second;
		}
	}
	m_gui->m_Components.clear();
}

void WaterBox::SDL2_Gui::refresh()
{//	����һ��Ҫ��clear�������ϻ���������Ȼ����̱߳���
	/*for (auto it:m_gui->m_Components)
	{
		while (SDL_PollEvent(event))
		{
			it.second->update(event);
		}
		it.second->show();
	}*/
	while (SDL_PollEvent(event))
	{
		for (int i=0; i<m_Components.size(); ++i)
		{
			m_Components[i]->update(event);
		}
	}
	for (int i = 0; i<m_Components.size(); ++i)
	{
		m_Components[i]->show();
	}
}

WaterBox::SDL2_Gui::SDL2_Gui()
{
	event = new SDL_Event;
	SDL_Thread *thread = NULL;
	//thread = SDL_CreateThread(update, "Gui_update", NULL);
}

int WaterBox::SDL2_Gui::update(void *ptr)
{
	SDL2_Gui *gui = SDL2_Gui::get();

	gui->refresh();									//	ˢ��Gui

	return 0;
}
