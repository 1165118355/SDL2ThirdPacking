#pragma once
#include <SDL2_Window.h>
#include <SDL2/SDL.h>

namespace WaterBox
{
	class SDL2_MainWindow
	{
	public:
		static SDL2_MainWindow *get();

		~SDL2_MainWindow();

		SDL2_Window *getSDL2Window();

		void setPosition(Math::vec2 position);
		Math::vec2 getPosition();

		void setSize(Math::vec2 size);
		Math::vec2 getSize();

	private:
		SDL2_MainWindow();
		static SDL2_MainWindow *m_MainWindow;
		SDL2_Window *m_Win;
	};
}