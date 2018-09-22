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
		///	\brief	用于添加组件在这里
		virtual void addComponent(SDL2_Component *component);

		///	\brief	显示
		virtual void show();

		///	\brief	更新逻辑
		virtual void update(SDL_Event *event);

	private:
		SDL2_Dialog();

		///	\brief	重新加载所有组件的材质
		void reloadMaterialOfComponent(SDL2_Component *component);
	private:
		SDL_Window *m_Win;
		SDL_Renderer *m_Rend;
	};
}

#endif // ！_SDL2_DIALOG_H_BOX
