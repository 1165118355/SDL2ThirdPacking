///////////////////////////////
//	this class is a VBox in SDL2.
//	��Ҫ����װ������������Ǹ������������������
//	�����������ࡷ
//	2018��6��25�� 22:08:59
//	by	ˮ������

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Box.h>
#include <vector>

namespace WaterBox
{
	class SDL2_VBox :public SDL2_Box
	{
	public:
		static SDL2_VBox *create(Math::vec2 position = Math::vec2(0, 0));

		///	brief	�����¼�
		virtual void update(SDL_Event *event);

		/// brief	������ʾ����ĺ���
		virtual void show();

		///	brief	����������������
		void addComponent(SDL2_Component *component);
	private:
		SDL2_VBox();
	private:
		int m_Spacing;
	};
}