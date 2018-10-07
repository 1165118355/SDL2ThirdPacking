///////////////////////////////
//	this class is a window in SDL2.
//	���ڵĴ����ȣ�Ԥ��֮���Ľ������
//	�������ࡷ
//	2018��6��24�� 00:19:12
//	by	ˮ������

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

		///	brief	��ȡ����
		SDL_Window *getWindow();

		///	brief	���ô���λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	biref	���ô��ڳߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	���º���ʾ
		virtual void update(SDL_Event *event) {}
		virtual void show() {}

		///	brief	����������������
		virtual void addComponent(SDL2_Component *component);

		///	biref	���ô�������
		void setWindowName(std::string name);

		///	brief	���ô���ģʽ
		void setMode(int mode);

	private:
		SDL_Window *m_Win;
		SDL2_Window();
	};
}
#endif	//`!_SDL2_WINDOW_H_BOX