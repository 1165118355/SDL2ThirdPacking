///////////////////////////////
//	this class is a List in SDL2.
//	UI组件，列表
//	《列表类》
//	2018年9月22日 23:57:59
//	by	水华宝箱

#ifndef _SDL2_LIST_H_BOX
#define _SDL2_LIST_H_BOX

#include <SDL2_Component.h>
#include <SDL2_ListItem.h>
#include <SDL2_VBox.h>

namespace WaterBox
{
	class SDL2_ListItem;
	class SDL2_List : public SDL2_Component
	{
	public:
		friend SDL2_ListItem;
		~SDL2_List();
		static SDL2_List *create();

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

		///	\brief	设置背景材质
		void setMaterialBack(SDL2_Material *material);

		///	\brief	添加子项
		void addItem(std::string name);

		///	\brief	添加子项
		void addItem(SDL2_ListItem *item);

		///	\brief	移除某个子项
		void removeItem();

		///	\brief	选中某个子项
		void selectItem(int num);

		///	\brief	清理函数（清理状态和所有的子项）
		void clear();

	private:
		SDL2_List();

	private:
		SDL2_VBox *m_ListBox;
		std::vector<SDL2_ListItem *> m_ListItems;
		SDL2_Material *m_MaterialBack;
		int m_CurrentTopItem;
		int m_CurrentItem;
	};
}

#endif	//!_SDL2_LIST_H_BOX