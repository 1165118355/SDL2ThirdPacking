///////////////////////////////
//	this class is a Console in SDL2.
//	���ǿ���̨�����������ڳ���֮ǰ��Ҳ����˵��������ǰҲ���Ե��øö����
//	������̨�ࡷ
//	2018��10��1�� 13:47:53
//	by	ˮ������

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

		/// \brief	���º���
		void update();

		/// \brief	���º���
		void updateEvent(SDL_Event *event);

		///	\brief	��ȡ���̰���״̬
		///
		///	\pram	key	����ֵ���ο�SDLԭ��ֵ::SDL_SCANCODE_
		int getKeyState(int key);

		int getKeyStateClear(int key);

		///	\brief	�����ֵ�״̬
		int getMouseWheelState();

		///	\brief	��ȡ����ƽ������
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