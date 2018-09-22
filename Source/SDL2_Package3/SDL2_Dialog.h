#ifndef _SDL2_DIALOG_H_BOX
#define _SDL2_DIALOG_H_BOX

#include <SDL2/SDL.h>
#include <SDL2_Renderer.h>
#include <SDL2_Component.h>
#include <SDL2_Box.h>

namespace WaterBox
{
	class SDL2_Dialog :public SDL2_Box
	{
	public:
		enum DialogBoxType
		{
			DIALOG_BOX_MESSAGE = SDL_MESSAGEBOX_INFORMATION,
			DIALOG_BOX_WARINIG = SDL_MESSAGEBOX_WARNING,
			DIALOG_BOX_ERROR = SDL_MESSAGEBOX_ERROR
		};
		///	\brief	
		static void SDL2_DialogBox(DialogBoxType type, std::string title, std::string text);
	public:
		static SDL2_Dialog *create();
		~SDL2_Dialog();
		///	\brief	����������������
		virtual void addComponent(SDL2_Component *component);

		///	\brief	��ʾ
		virtual void show();

		///	\brief	�����߼�
		virtual void update(SDL_Event *event);

	private:
		SDL2_Dialog();

		///	\brief	���¼�����������Ĳ���
		void reloadMaterialOfComponent(SDL2_Component *component);
	private:
		SDL_Window *m_Win;
		SDL_Renderer *m_Rend;
	};
}

#endif // ��_SDL2_DIALOG_H_BOX
