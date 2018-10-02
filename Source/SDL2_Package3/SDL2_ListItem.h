///////////////////////////////
//	this class is a ListItem in SDL2.
//	UI组件，列表的子项
//	《列表子项类》
//	2018年9月23日 00:20:44
//	by	水华宝箱

#ifndef _SDL2_LISTITEM_H_BOX
#define _SDL2_LISTITEM_H_BOX

#include <SDL2_Component.h>
#include <SDL2_Label.h>
#include <SDL2_List.h>

namespace WaterBox
{
	class SDL2_List;
	class SDL2_ListItem :
		public SDL2_Component
	{
		friend SDL2_List;
	public:
		enum ListItemState
		{
			LISTITEM_RELEASE,
			LISTITEM_SELECTED,
			LISTITEM_HOVER
		};
	public:
		~SDL2_ListItem();
		static SDL2_ListItem *create(std::string name="");

		static SDL2_ListItem *create(SDL2_Xml *xml);

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	组件更新（包括事件检测，逻辑判断）
		virtual void update(SDL_Event *event);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	brief	显示函数
		virtual void show();

		///	\brief	获取material的数量
		virtual std::vector<SDL2_Material *> getMaterials();

		///	\brief	更新鼠标事件
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	更新键盘事件
		virtual void updateEventKeyboard(SDL_Event *event);

		///	\brief	给该项设置一个lable
		void setText(std::string text);
		std::string getText();

		///	\brief	设置背景材质
		void setMaterialBack(SDL2_Material *mat);
		SDL2_Material *getMaterialBack();

		///	\brief	设置子项的状态
		void setSelected(ListItemState selct);
		ListItemState getSelected();

		///	\brief	返回父列表
		SDL2_List *getList();

		///	\brief	返回索引编号
		int getIndex();
	private:
		SDL2_ListItem();

		///	\brief	设置父列表（）
		void setList(SDL2_List *list);

		///	\brief	设置索引编号
		void setIndex(int index);
	private:
		int m_Index;								//	在列表中的编号
		SDL2_List *m_List;							//	存储父列表
		std::vector<SDL2_Component *> m_Components;	//	子项的组件
		SDL2_Label *m_Lable;						//	默认一项是一个lable
		SDL2_Material *m_MaterialBack;				//	项背景材质
		Math::vec4 m_ColorBackDefault;				//	默认的背景颜色
		ListItemState m_Select;						//	保存子项的状态
	};
}
#endif	//!_SDL2_LISTITEM_H_BOX

/*
xml说明
	tag说明
		material_back="null"		//	背景的材质						（仅限图片不能是动画）
	name说明
		<list_item>				//	名字就是这个咯
*/