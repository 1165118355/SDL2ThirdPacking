///////////////////////////////
//	this class is a Label in SDL2.
//	标签类主要是显示文字
//	《标签类》
//	2018年6月25日 22:05:19
//	by	水华宝箱

#pragma once
#include <string>
#include <SDL2_MaterialText.h>
#include <SDL2_Component.h>
namespace WaterBox 
{
	class SDL2_Label: public SDL2_Component
	{
	public:
		static SDL2_Label *create(std::string text="label");

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2  getPosition();

		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	显示
		virtual void show();

		///	brief	更新事件
		virtual void update(SDL_Event *event);
	private:
		SDL2_Label(std::string text);
	private:
		std::string m_Text;					//	要显示的文本
		SDL2_Material *m_MaterialText;		//	文本的Material

	};
}