///////////////////////////////
//	this class is a System in SDL2.
//	ϵͳ�࣬��������֮ǰ�����е�
//	��ϵͳ�ࡷ
//	2018��10��1�� 13:48:00
//	by	ˮ������

#ifndef _SDL2_SYSTEM_H_BOX
#define _SDL2_SYSTEM_H_BOX

#include <SDL2_SceneManager.h>

namespace WaterBox
{
	class SDL2_System
	{
	public:
		static SDL2_System *get();

		///	\brief	ϵͳ��ʼ��
		void init();

		///	\brief	��ϵͳȥ����
		void update();

		///	\brief	��ϵͳ������Ⱦ
		void render();

		///	\brief	ϵͳ�ر�ʱ����
		void shutdown();

		/*
		*	\brief ��ȡ����������ʵ��
		*
		*	\return	���س���������ʵ��
		*/
		SDL2_SceneManager *getSceneManager() { return m_SceneManager; }

	private:
		~SDL2_System();
		SDL2_System();
	private:
		static SDL2_System *m_Instance;
		SDL2_SceneManager *m_SceneManager;
		SDL2_Scene *m_NowScene;
		SDL_Event *m_Event;								//	�¼���������������ᴫ��ÿ�������ÿ������ڲ�ȥʵ���Լ����߼���
	};
}

#endif // !_SDL2_SYSTEM_H_BOX