///////////////////////////////
//	this class is a VBox in SDL2.
//	主要用来装下其他组件，是个容器，
//	《组件容器类》
//	2018年7月7日 23:27:29
//	by	水华宝箱

#ifndef _SDL2_TEXTBROWSER_H_BOX
#define _SDL2_TEXTBROWSER_H_BOX

#include <SDL2_Component.h>

namespace WaterBox
{
	class SDL2_TextBrowser : public SDL2_Component
	{
	public:
		~SDL2_TextBrowser();
		static SDL2_TextBrowser *create();

		///	\brief	更新
		virtual void update(SDL_Event *event);

		///	\brief	材质的位置校正，保证材质显示在物体上的正确位置上，类似3d里面的UV一样
		virtual void materialModification();

		///	\brief 显示该Gui组件
		virtual void show();

		///	\brief	解析xml文件里面的值,并将值赋值给自己
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	获取所有的material
		virtual std::vector<SDL2_Material *> getMaterials();

		///	\brief	更新鼠标事件
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	更新键盘事件
		virtual void updateEventKeyboard(SDL_Event *event);

	private:
		SDL2_TextBrowser();
	private:
		SDL2_Material *m_MaterialBack;

	};
}

#endif // !_SDL2_TEXTBROWSER_H_BOX
