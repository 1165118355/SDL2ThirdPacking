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
#include <SDL2_Xml.h>
#include <SDL2_MaterialManage.h>
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
		enum AlignMode
		{
			AMODE_NONE,
			AMODE_HORIZONTAL,
			AMODE_VERTICAL

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
		virtual void addChild(SDL2_Component *child);

		///	brief	设置对齐方式（与父组件对齐）
		virtual void setAlign(AlignType align);
		virtual AlignType getAlign();

		///	brief	设置组件名字
		virtual void setName(std::string name);
		virtual std::string getName();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	组件更新（包括事件检测，逻辑判断）
		virtual void update(SDL_Event *event)=0;

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	brief	显示函数
		virtual void show()=0;

	protected:
		//	父组件对子组件进行排版
		virtual void Align();
	protected:
		std::string								m_Name;					//	组件名称
		ComponentType							m_ComponentType;		//	组件的类型
		SDL2_Component*							m_Parent;				//	组件的父组件
		AlignType								m_Align;				//	组件的对齐方式（基于父组件）
		AlignMode								m_AMode;				//	组件对齐的模式
		std::vector<SDL2_Component *>			m_Childes;				//	子组件们
		SDL2_Component();
	private:
	};
}

#endif// !_SDL2_COMPONENT_BOX

/*
xml说明
	后缀说明
		10xsp					//	基于x轴的比例像素,10sp表示1%，100sp表示10%	（仅用于数字）
		10xsp					//	基于y轴比例像素,10sp表示1%，100sp表示10%	（仅用于数字）
		10px					//	像素，就是1:1的像素咯				（仅用于数字）
	tag说明
		x="0"					//	组件的x坐标
		y="0"					//	组件的y坐标
		w="0"					//	组件的宽度
		h="0"					//	组件的高度
		align="none"			//	
	name说明
		<button>				//	按钮组件
		<image>					//	图像组件
		<checkbox>				//	复选框
		<combox>				//	下拉列表
		<editline>				//	编辑条
		<label>					//	标签（文字）
		<slider>				//	滑条
		<hbox>
		<vbox>
		<window>
*/