///////////////////////////////
//	this class is a Console in SDL2.
//	就是控制台咯，他运行在场景之前，也就是说场景加载前也可以调用该对象的
//	《控制台类》
//	2018年10月1日 13:47:53
//	by	水华宝箱

#ifndef _SDL2_CONSOLE_H_BOX
#define _SDL2_CONSOLE_H_BOX

#include <SDL2/SDL.h>
#include <SDL2_Node.h>
#include <SDL2_Utils.h>
#include <SDL2_Label.h>
#include <SDL2_Slider.h>

namespace WaterBox
{
	class SDL2_Console :public SDL2_Node
	{
	public:
		static SDL2_Console *get();

		virtual void update(SDL_Event *event);

		virtual void show();

		///	\brief	更新鼠标事件
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	更新键盘事件
		virtual void updateEventKeyboard(SDL_Event *event);

		///	\brief	运行控制台命令
		bool run(std::string common);

		///	\breif	添加日志信息
		void addLog(const char* format,...);

		///	\breif	添加警告信息
		void addWarning(const char* format, ...);

		///	\breif	添加错误信息
		void addError(const char* format, ...);

		///	\brief	清理所有的信息
		void clear();

		///	\brief	设置是否显示控制台
		void setShow(bool show);
		bool getShow();

	private:
		SDL2_Console();
		~SDL2_Console();
	private:
		static SDL2_Console *m_Instance;
		bool m_Show;
		std::vector<SDL2_Label *> m_Texts;
		SDL2_Slider *m_Slider;

		int m_ShowBottomTextNumber;
		Math::vec2 m_FocusMouse;
	};
}

#endif //!_SDL2_CONSOLE_H_BOX
