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

		///	\brief	根据xml文件创建一个CheckBox
		static SDL2_CheckBox *create(SDL2_Xml *xml);

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPositioin();

		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	更新事件
		virtual void update(SDL_Event *event);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	brief	更新显示
		virtual void show();

		void setValue(int value);
		int getValue();

		///	\brief	设置复选框背景的材质
		void setMaterialBack(SDL2_Material *matBack);
		SDL2_Material *getMateralBack();

		///	\brief	设置复选框里面那个块的材质，就是被选上那个 
		void setMaterialIn(SDL2_Material *In);
		SDL2_Material *getMaterialIn();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	获取所有的material
		virtual std::vector<SDL2_Material *> getMaterials();

		///	\brief	更新鼠标事件
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	更新键盘事件
		virtual void updateEventKeyboard(SDL_Event *event);

	private:
		SDL2_CheckBox();

	private:
		int m_Value;
		SDL2_Material *m_MaterialBack;			//	复选框背景的材质	
		SDL2_Material *m_MaterialIn;			//	复选框里面那个确认的材质什么的。。。我在说什么。。。

	};

}