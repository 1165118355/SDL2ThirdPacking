///////////////////////////////
//	this class is a Console in SDL2.
//	就是控制台咯，他运行在场景之前，也就是说场景加载前也可以调用该对象的
//	《控制台类》
//	2018年10月1日 13:47:53
//	by	水华宝箱

#ifndef _SDL2_EVENT_H_BOX
#define _SDL2_EVENT_H_BOX

#include <map>
#include <SDL2/SDL.h>
#include <SDL2_Math.h>

namespace WaterBox
{
	class SDL2_Event
	{
	public:
		enum
		{
			SDL2_KEY_DOWN,
			SDL2_KEY_UP
		};
		enum
		{
			SDL2_MOUSEWHEEL_NONE,
			SDL2_MOUSEWHEEL_DOWN,
			SDL2_MOUSEWHEEL_UP
		};
	public:
		static SDL2_Event *get();

		/// \brief	更新函数
		void update();

		/// \brief	更新函数
		void updateEvent(SDL_Event *event);

		///	\brief	获取键盘按键状态
		///
		///	\pram	key	按键值：参考SDL原键值::SDL_SCANCODE_
		int getKeyState(int key);

		int getKeyStateClear(int key);

		///	\brief	鼠标滚轮的状态
		int getMouseWheelState();

		///	\brief	获取鼠标的平面坐标
		Math::vec2 getMousePosition();
	private:
		SDL2_Event();
		~SDL2_Event();
	private:
		static SDL2_Event *m_Instance;
		SDL_Event *m_Event;

		int m_MouseWheelState;
		Math::vec2 m_MousePosition;
		std::map<int, int> m_KeyState;
	};
}

#endif // !_SDL2_EVENT_H_BOX