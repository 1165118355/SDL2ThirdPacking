///////////////////////////////
//	this class is a VBox in SDL2.
//	��Ҫ����װ������������Ǹ������������������
//	�����������ࡷ
//	2018��6��25�� 22:07:47
//	by	ˮ������

#pragma once
#include <SDL2_Component.h>
#include <vector>
namespace WaterBox
{
	class SDL2_HBox :public SDL2_Component
	{
	public:
		static SDL2_HBox *create(Math::vec2 position = Math::vec2(0, 0));

		///	brief	�����¼�
		virtual void update(SDL_Event *event);

		/// brief	������ʾ����ĺ���
		virtual void show();

		///	brief	����������������
		void addComponent(SDL2_Component *component);
	private:
		SDL2_HBox();
	private:
		std::vector<SDL2_Component *> m_Components;
		int m_Spacing;
	};
}