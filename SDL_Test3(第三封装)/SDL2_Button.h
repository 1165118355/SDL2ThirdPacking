///////////////////////////////
//	this class is a Button in SDL2 
//	按钮类
//	2018年6月9日 08:18:50
//	by	水华宝箱
#pragma once
#include <string>
#include <SDL2_Component.h>
#include <SDL2_Material.h>


namespace WaterBox
{
	class SDL2_Button :public SDL2_Component
	{
	public:
		///	
		static SDL2_Button *cast(SDL2_Component *componet);

		///	创建一个Button（单色彩的）
		static SDL2_Button *create();

		///	创建一个Button 带图片的
		static SDL2_Button *create(std::string path1, std::string path2);

		///	显示该Gui组件
		virtual int show();

		virtual void update(SDL_Event *event);

		void setCallback(int *(*Callback)(void *ptr));

		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	设置按钮是否被按下
		void setFlag(int flag);
		int getFlag();
	private:
		SDL2_Button(SDL2_Material *matBefor, SDL2_Material *matAfter);
	private:
		int m_Flag;
		int *(*m_Callback)(void *ptr);
		SDL2_Material *m_MaterialBefore;
		SDL2_Material *m_MaterialAfter;
	};
}