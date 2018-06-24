#pragma once

#include <SDL2_Component.h>
#include <vector>
namespace WaterBox
{
	class SDL2_VBox :public SDL2_Component
	{
	public:
		static SDL2_VBox *create(Math::vec2 position = Math::vec2(0, 0));

		///	brief	更新事件
		virtual void update(SDL_Event *event);

		/// brief	用于显示组件的函数
		virtual void show();

		///	brief	用于添加组件在这里
		void addComponent(SDL2_Component *component);
	private:
		SDL2_VBox();
	private:
		std::vector<SDL2_Component *> m_Components;
		int m_Spacing;
	};
}