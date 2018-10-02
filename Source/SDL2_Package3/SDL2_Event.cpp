#include "SDL2_Event.h"
#include <SDL2_Console.h>

using namespace WaterBox;

SDL2_Event *SDL2_Event::m_Instance = nullptr;

SDL2_Event * WaterBox::SDL2_Event::get()
{
	if (nullptr == m_Instance)
	{
		m_Instance = new SDL2_Event();
	}
	return m_Instance;
}

void WaterBox::SDL2_Event::update(SDL_Event *event)
{
	m_Event = event;
	m_MousePosition.x = event->motion.x;
	m_MousePosition.y = event->motion.y;
	switch (m_Event->type)
	{
	case SDL_MOUSEBUTTONDOWN:		//	��갴��
		break;
	case SDL_MOUSEBUTTONUP:			//	����ͷ�
		break;
	case SDL_MOUSEWHEEL:			//	�����ֻ춯
		break;
	case SDL_MOUSEMOTION:			//	����϶�
		break;
	case SDL_KEYDOWN:				//	��������
		break;
	case SDL_KEYUP:					//	����̧��
		break;
	case SDL_TEXTEDITING:			//	�����ı��༭
		break;
	case SDL_TEXTINPUT:				//	�����ı�����
		break;
	case SDL_KEYMAPCHANGED:			//	����ϵͳ�¼�(���������Ի���̲��ָı䡣
		break;
	}
}

int WaterBox::SDL2_Event::getKeyState(int key)
{
	switch (key)
	{
	}
	const Uint8 *state = SDL_GetKeyboardState(nullptr);
	return state[key];
}

int WaterBox::SDL2_Event::getKeyStateClear(int key)
{
	return 0;
}

Math::vec2 WaterBox::SDL2_Event::getMousePosition()
{
	return m_MousePosition;
}

SDL2_Event::SDL2_Event()
{
	m_Event = new SDL_Event;
}


SDL2_Event::~SDL2_Event()
{
}
