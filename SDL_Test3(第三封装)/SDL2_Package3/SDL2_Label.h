#pragma once
#include <string>
#include <SDL2_MaterialText.h>
#include <SDL2_Component.h>
namespace WaterBox 
{
	class SDL2_Label: public SDL2_Component
	{
	public:
		static SDL2_Label *create(std::string text="label");
		virtual int show();
		virtual void update(SDL_Event *event);
		virtual void setSize(Math::vec2 size);
	private:
		SDL2_Label(std::string text);
	private:
		std::string m_Text;
		SDL2_Material *m_MaterialText;

	};
}