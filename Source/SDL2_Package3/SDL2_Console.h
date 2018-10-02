///////////////////////////////
//	this class is a Console in SDL2.
//	���ǿ���̨�����������ڳ���֮ǰ��Ҳ����˵��������ǰҲ���Ե��øö����
//	������̨�ࡷ
//	2018��10��1�� 13:47:53
//	by	ˮ������

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

		///	\brief	��������¼�
		virtual void updateEventMouse(SDL_Event *event);

		///	\brief	���¼����¼�
		virtual void updateEventKeyboard(SDL_Event *event);

		///	\brief	���п���̨����
		bool run(std::string common);

		///	\breif	�����־��Ϣ
		void addLog(const char* format,...);

		///	\breif	��Ӿ�����Ϣ
		void addWarning(const char* format, ...);

		///	\breif	��Ӵ�����Ϣ
		void addError(const char* format, ...);

		///	\brief	�������е���Ϣ
		void clear();

		///	\brief	�����Ƿ���ʾ����̨
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
