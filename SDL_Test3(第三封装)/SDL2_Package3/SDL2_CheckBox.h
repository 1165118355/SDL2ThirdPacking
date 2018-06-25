///////////////////////////////
//	this class is a CheckBox in SDL2.
//	创建一个编辑框
//	《复选框类》
//	2018年6月25日 22:07:18
//	by	水华宝箱

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_CheckBox :public SDL2_Component
	{
	public:
		static SDL2_CheckBox *create();
		//static SDL2_CheckBox *create(SDL2_Material *matBack, SDL2_Material *matIn);

		///	brief	获取复选框是否被勾上！！
		int getValue();

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPositioin();

		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	更新显示
		virtual void show();

		///	brief	更新事件
		virtual void update(SDL_Event *event);

	private:
		SDL2_CheckBox(SDL2_Material *matBack, SDL2_Material *matIn);

	private:
		int m_Value;
		SDL2_Material *m_MaterialBack;
		SDL2_Material *m_MaterialIn;

	};

}