///////////////////////////////
//	this class is a EditLine in SDL2.
//	创建一个编辑框
//	《编辑框类》
//	2018年6月25日 22:05:51
//	by	水华宝箱

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <SDL2_Label.h>
#include <string>

namespace WaterBox
{
	class SDL2_EditLine :public SDL2_Component
	{
	public :
		///	brief	创建一个编辑框
		static SDL2_EditLine *create();
		
		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	更新事件函数
		virtual void update(SDL_Event *event);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	brief	显示函数
		virtual void show();

		///	\brief	更新鼠标事件
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	更新键盘事件
		virtual void updateEventKeyboard(SDL_Event *event);

		///	\brief	获取背景的材质
		void setMaterialBack(SDL2_Material *material);
		SDL2_Material *getMaterialBack();

		///	\brief	获取所有的material
		virtual std::vector<SDL2_Material *> getMaterials();

		///	\brief	设置Editline中的信息
		void setText(std::string text);
		std::string getText();

		///	\brief	设置背景颜色(仅限默认材质)
		void setColorBackGround(Math::vec4 color);
		Math::vec4 getColorBackGround();

		///	\brief	设置字体颜色
		void setColorFont(Math::vec4 color);
		Math::vec4 getColorFont();

		///	\brief	设置游标颜色
		void setColorCursor(Math::vec4 color);
		Math::vec4 getColorCursor();

		///	\brief	清理字符串
		void clear();
	private:
		SDL2_EditLine();

	private:
		SDL2_Material *m_MaterialBack;			//	背景材质
		Math::vec4 m_ColorBack;
		Math::vec4 m_ColorFont;
		Math::vec4 m_ColorCursor;

		std::string m_Text;						//	EditLine中存储的字符串
		std::vector<SDL2_Label*> m_ShowText;	//	显示的Label，每一个字符都是一个label
		int m_CurSorPos;						//	游标，游标在字符串中第多少个字符的位置
		int m_ShowStartPos, m_ShowEndPos;		//	显示文本的开始位置和结束为止
		bool m_ChooseFlag;						//	焦点是否在这里
		bool m_ChangeText;						//	当文本发生变化这个变量等于true
	};
}