///////////////////////////////
//	this class is a EditLine in SDL2.
//	创建一个编辑框
//	《编辑框类》
//	2018年6月25日 22:05:51
//	by	水华宝箱

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <string>

namespace WaterBox
{
	class SDL2_EditLine :public SDL2_Component
	{
	public :
		///	brief	创建一个编辑框
		static SDL2_EditLine *create();

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
		SDL2_EditLine(SDL2_Material *mat);

	private:
		SDL2_Material *m_Material;
		std::string m_Text;
		int m_CurSorPos;
		bool m_ChooseFlag;
	};
}