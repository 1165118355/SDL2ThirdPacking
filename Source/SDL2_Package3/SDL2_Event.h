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
	public:
		static SDL2_Event *get();

		/// \brief	���º���
		void update(SDL_Event *event);

		int getKeyState(int key);

		int getKeyStateClear(int key);

		///	\brief	��ȡ����ƽ������
		Math::vec2 getMousePosition();
	private:
		SDL2_Event();
		~SDL2_Event();
	private:
		static SDL2_Event *m_Instance;
		SDL_Event *m_Event;
		Math::vec2 m_MousePosition;
		std::map<int, int> m_KeyState;
	};
}

#endif // !_SDL2_EVENT_H_BOX