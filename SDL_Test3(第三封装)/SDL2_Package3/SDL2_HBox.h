#pragma once

#include <SDL2_Component.h>
namespace WaterBox
{
	class SDL2_HBox
	{
	public:
		static SDL2_HBox *create();
		static SDL2_HBox *create(Math::vec2 position, Math::vec2 size);

		///	brief	设置位置
		virtual void setPosition();

		///	brief	设置尺寸
		virtual void setSize();

		///	brief	更新事件
		virtual void update(SDL_Event *even);

		/// brief	用于显示组件的函数
		virtual int show();

		///	brief	用于添加组件在这里
	private:
		SDL2_HBox();
	};
}