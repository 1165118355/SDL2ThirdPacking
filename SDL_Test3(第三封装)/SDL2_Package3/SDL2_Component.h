///////////////////////////////
//	this class is a Component in SDL2.
//	组件创建，组件的基类
//	《组件类》
//	2018年6月25日 22:04:32
//	by	水华宝箱

#ifndef _SDL2_COMPONENT_H_BOX
#define _SDL2_COMPONENT_H_BOX

/*
组件的基类
*/
#include <SDL2_Node.h>
#include <SDL2_Math.h>
#include <vector>
#include <SDL2/SDL.h>
namespace WaterBox
{
	class SDL2_Component :public SDL2_Node
	{
	public :
		enum ComponentType
		{
			COMPONENT_NONE = 0,
			COMPONENT_BUTTON,
			COMPONENT_IMAGE,
			COMPONENT_WINDOW,
			COMPONENT_CHECKBOX,
			COMPONENT_LABEL,
			COMPONENT_HBOX,
			COMPONENT_VBOX,
			COMPONENT_EDITLINE,
			COMPONENT_COMBOX,
			COMPONENT_SLIDER
		};
		enum AlignType
		{
			ALIGN_NONE = 0,
			ALIGN_CENTER = 1,
			ALIGN_LEFT = 2,
			ALIGN_RIGHT = 4,
			ALIGN_TOP = 8,
			ALIGN_BOTTOM = 16
		};
	public :

		///	brief	设置组件的位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	设置组件的尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	获取组件类型
		virtual ComponentType getComponentType() { return m_ComponentType; }

		///	brief	设置组件的父组件
		virtual void setParent(SDL2_Component *parent);
		
		///	breif	添加一个子组件
		virtual void addChild(SDL2_Component *parent);

		///	brief	设置对齐方式（与父组件对齐）
		virtual void setAlign(AlignType align);
		virtual AlignType getAlign();

		///	brief	显示函数
		virtual void show()=0;

		///	brief	组件更新（包括事件检测，逻辑判断）
		virtual void update(SDL_Event *event)=0;
	protected:
		//	父组件对子组件进行排版
		virtual void Align();
	protected:
		ComponentType							m_ComponentType;		//	组件的类型
		SDL2_Component*							m_Parent;				//	组件的父组件
		AlignType								m_Align;				//	组件的对齐方式（基于父组件）
		std::vector<SDL2_Component *>			m_Childes;				//	子组件们
		SDL2_Component();
	private:
	};
}

#endif// !_SDL2_COMPONENT_BOX