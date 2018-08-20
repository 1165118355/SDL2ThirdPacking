///////////////////////////////
//	this class is a Combox in SDL2.
//	创建一个编辑框
//	《下拉列表类》
//	2018年6月26日 21:36:25
//	by	水华宝箱
#pragma once
#include <vector>
#include <SDL2_Component.h>
#include <SDL2_Math.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_Combox :public SDL2_Component
	{
	public:
		static SDL2_Combox *create();

		static SDL2_Combox *create(SDL2_Xml *xml);

		///	brief	返回现在所选择的项的编号
		int getValue();

		///	brief	添加一项
		void addItem(std::string itmeName);

		///	\brief	设置子项的名字
		int setItemName(int number, std::string name);
		std::string getItemName(int number);

		///	brief	设置材质，这个组件的（一般用Material_Picture）
		void setMaterialBox(SDL2_Material *matBox);
		SDL2_Material *getMaterialBox();

		///	\brief	设置子项的材质
		void setMaterialItem(SDL2_Material *matItem);
		SDL2_Material *getMaterialItem();

		///	brief	设置位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	设置尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	显示函数
		virtual void show();

		///	brief	更新事件函数
		virtual void update(SDL_Event *event);

	private:
		SDL2_Combox();

	private:
		int m_Value;										//	我觉得叫index可能会好些
		int m_PreValue;										//	预选，鼠标指着的Item
		int m_ChooseFlag;									//	展开标志（展开下拉列表）
		int m_Space;										//	文本材质与back之间四周的间距
		std::vector<std::string> m_ItemName;				//	Item的名字

		std::vector<SDL2_Material *> m_MaterialText;		//	用于存储文本的材质
		SDL2_Material *m_MaterialBox;						//	主体的材质
		SDL2_Material *m_MaterialItem;						//	子项的材质
		
	};
}