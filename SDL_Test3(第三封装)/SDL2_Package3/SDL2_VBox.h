#pragma once

#include <SDL2_Component.h>
#include <vector>
namespace WaterBox
{
	class SDL2_VBox :public SDL2_Component
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
		std::vector<SDL2_Component *> m_Components;
		int m_Spacing;
	};
}