#pragma once
#include <string>
#include <SDL2_Math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2_Renderer.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_MaterialPicture :public SDL2_Material
	{
	public:
		static SDL2_MaterialPicture *create(std::string path);

		virtual void show();
	private:
		SDL2_MaterialPicture(SDL_Texture *tex);
		SDL_Texture *m_Texture;
	};
}