///////////////////////////////
//	this class is a VBox in SDL2.
//	主要用来装下其他组件，是个容器，并且排列组件
//	《纵向容器类》
//	2018年6月25日 22:08:59
//	by	水华宝箱

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
		static SDL2_VBox *create(SDL2_Xml *xml);

		///	brief	更新事件
		virtual void update(SDL_Event *event);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		/// brief	用于显示组件的函数
		virtual void show();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	用于添加组件在这里
		void addComponent(SDL2_Component *component);
	private:
		SDL2_VBox();
	private:
		int m_Spacing;
	};
}