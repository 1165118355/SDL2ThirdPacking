///////////////////////////////
//	this class is a Button in SDL2 
//	按钮类
//	2018年6月9日 08:18:50
//	by	水华宝箱

#pragma once
#include <string>
#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <SDL2_Xml.h>


namespace WaterBox
{
	class SDL2_Button :public SDL2_Component
	{
	public:
		///	brief 将父类强制转换成Button
		static SDL2_Button *cast(SDL2_Component *componet);

		///	创建一个Button（单色彩的）
		static SDL2_Button *create(std::string text="button");

		///	创建一个Button 带图片的
		static SDL2_Button *create(std::string path1, std::string path2, std::string text = "button");

		static SDL2_Button *create(SDL2_Xml *xml);

		///	显示该Gui组件
		virtual void show();

		///	brief	更新
		virtual void update(SDL_Event *event);

		///	biref	设置回调函数
		void setCallback(int *(*Callback)(void *ptr));

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	设置透明度
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

		///	设置按钮是否被按下
		void setFlag(int flag);
		int getFlag();

		///	brief	设置按钮里的文字
		void setText(std::string text);
		std::string getText();
	private:
		SDL2_Button(SDL2_Material *matBefor, SDL2_Material *matAfter, SDL2_Material *matText);
	private:
		int m_Flag;
		int *(*m_Callback)(void *ptr);
		SDL2_Material *m_MaterialBefore;
		SDL2_Material *m_MaterialAfter;
		SDL2_Material *m_MaterialText;
	};
}