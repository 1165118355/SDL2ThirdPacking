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
	case SDL_MOUSEBUTTONDOWN:		//	鼠标按下
		break;
	case SDL_MOUSEBUTTONUP:			//	鼠标释放
		break;
	case SDL_MOUSEWHEEL:			//	鼠标滚轮混动
		break;
	case SDL_MOUSEMOTION:			//	鼠标拖动
		break;
	case SDL_KEYDOWN:				//	按键按下
		break;
	case SDL_KEYUP:					//	按键抬起
		break;
	case SDL_TEXTEDITING:			//	键盘文本编辑
		break;
	case SDL_TEXTINPUT:				//	键盘文本输入
		break;
	case SDL_KEYMAPCHANGED:			//	由于系统事件(如输入语言或键盘布局改变。
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
