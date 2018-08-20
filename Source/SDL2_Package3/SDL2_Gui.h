///////////////////////////////
//	this class is a Gui in SDL2.manage the UI
//	��������UI��
//	��GUI�ࡷ
//	2018��6��23�� 23:58:53
//	by	ˮ������

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

		///	brief	����ģʽ��ȡGui
		static SDL2_Gui *get();

		///	brief	������
		int addComponent(SDL2_Component *component);

		///	brief	����Gui���е����
		void clear();

		///	brief	Guiˢ��һ��
		void refresh();

		///	brief	���º���
		static int update(void *ptr);
	private:
		SDL2_Gui();
	private:
		static SDL2_Gui *m_gui;
		std::map<int, SDL2_Component *> m_Components;	//	�������ṹʹ��map������
		SDL_Event *event;								//	�¼���������������ᴫ��ÿ�������ÿ������ڲ�ȥʵ���Լ����߼���

	};
}
#endif	//	!_SDL2_GUI_H