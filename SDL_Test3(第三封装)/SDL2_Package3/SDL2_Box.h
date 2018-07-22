///////////////////////////////
//	this class is a VBox in SDL2.
//	主要用来装下其他组件，是个容器，
//	《组件容器类》
//	2018年7月7日 23:27:29
//	by	水华宝箱
#pragma once
#include <SDL2_Component.h>
#include <vector>

namespace WaterBox
{
	class SDL2_Box :public SDL2_Component
	{
	public:
		virtual ~SDL2_Box();

		///	brief	用于添加组件在这里
		virtual void addComponent(SDL2_Component *component) = 0;

		virtual void show();

		/// brief	更新事件
		virtual void update(SDL_Event *event);
	protected:
		SDL2_Box();
	protected:
		std::vector<SDL2_Component *> m_Components;
	private:
	};
}