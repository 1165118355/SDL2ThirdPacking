///////////////////////////////
//	this class is a window in SDL2.
//	窗口的创建等，预计之后会改进这个类
//	《窗口类》
//	2018年6月24日 00:19:12
//	by	水华宝箱

#ifndef _SDL2_WINDOW_H_BOX
#define _SDL2_WINDOW_H_BOX
#include <SDl2/SDL.h>
#include <vector>
#include <string>
#include <SDL2_Box.h>

namespace WaterBox
{
	class SDL2_Window:public SDL2_Box
	{
	public:
		virtual ~SDL2_Window();
		static SDL2_Window *create(std::string name = std::string("window"), Math::vec2 position = Math::vec2(), Math::vec2 size = Math::vec2(100, 100));

		///	brief	获取窗口
		SDL_Window *getWindow();

		///	brief	设置窗口位置
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	biref	设置窗口尺寸
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	更新和显示
		virtual void update(SDL_Event *event) {}
		virtual void show() {}

		///	brief	用于添加组件在这里
		virtual void addComponent(SDL2_Component *component);

		///	biref	设置窗口名字
		void setName(std::string name);

		///	brief	设置窗口模式
		void setMode(int mode);

	private:
		SDL_Window *m_Win;
		std::string m_Name;
		SDL2_Window();
	};
}
#endif	//`!_SDL2_WINDOW_H_BOX