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
		///	\brief 将父类强制转换成Button
		static SDL2_Button *cast(SDL2_Component *componet);

		///	\brief 创建一个Button（单色彩的）
		static SDL2_Button *create(std::string text="button");

		///	\brief 创建一个Button 带图片的
		static SDL2_Button *create(std::string materialNameBefore, std::string materialNameAfter, std::string text = "button");

		///	\brief	通过一个xml创建一个button
		static SDL2_Button *create(SDL2_Xml *xml);

		///	\brief	更新
		virtual void update(SDL_Event *event);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	\brief 显示该Gui组件
		virtual void show();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	设置回调函数
		void setCallback(int *(*Callback)(void *ptr));

		///	\brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	\brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	\brief	设置透明度
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

		///	\brief 设置按钮是否被按下
		void setFlag(int flag);
		int getFlag();

		///	\breif	设置按钮按下之前的材质
		void setMaterialBefore(SDL2_Material *matBefore);
		SDL2_Material *getMaterialBefore();

		///	\breif	设置按钮按下之后的材质
		void setMaterialAfter(SDL2_Material *matAfter);
		SDL2_Material *getMaterialAfter();

		///	\brief	设置按钮里的文字
		void setText(std::string text);
		std::string getText();

		///	\brief	获取所有的material
		virtual std::vector<SDL2_Material *> getMaterials();

	private:
		SDL2_Button();
	private:
		int m_Flag;
		int *(*m_Callback)(void *ptr);
		SDL2_Material *m_MaterialBefore;
		SDL2_Material *m_MaterialAfter;
		SDL2_Material *m_MaterialText;
	};
}

/*
xml说明
	tag说明
		material_befor="null"		//	点击之前的图片路径	
		material_after="null"		//	点击之后的图片路径
	name说明
		<button>				//	名字就是这个咯
*/