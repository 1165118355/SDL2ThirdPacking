#ifndef _SDL2_GUI_H_BOX
#define _SDL2_GUI_H_BOX
#include <map>
#include <SDL2/SDL.h>
#include <SDL2_Component.h>

/*
֡�����Ƶķ�������������Ҫ�޸ģ�������֡���������Ƶ�ʱ����ܻ���ɿ��٣�
ͼ����˸�������Ƕ��̵߳��õ����⣨renderClear�������һ���̣߳���ɶ��ݺ�����������rend���������̣߳�����
*/

namespace WaterBox
{
	class SDL2_Gui
	{
	public :

		//	����ģʽ��ȡGui
		static SDL2_Gui *get();

		//	������
		int addComponent(SDL2_Component *component);

		//	����Gui���е����
		void clear();

		//	Guiˢ��һ��
		void refresh();

		int getFps() { return m_Fps; }
		int setFps(int fps) { m_Fps = fps; }
		static int update(void *ptr);
	private:
		SDL2_Gui();
	private:
		static SDL2_Gui *m_gui;
		std::map<int, SDL2_Component *> m_Components;
		SDL_Event *event;
		int m_Fps;

	};
}
#endif	//	!_SDL2_GUI_H