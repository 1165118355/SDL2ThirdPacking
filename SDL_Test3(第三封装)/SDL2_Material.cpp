#include "SDL2_Material.h"
#include <SDL2_Renderer.h>

using namespace WaterBox;

SDL2_Material * WaterBox::SDL2_Material::create(Math::vec2 size, Math::vec4 color)
{
	SDL_Surface *sur = nullptr;
	sur = SDL_CreateRGBSurface(0, size.x, size.y, 1, color.x, color.y, color.z, color.w);
	if (!sur)
	{
		return nullptr;
	}
	SDL2_Material *mat = new SDL2_Material(sur);
	return mat;
}

SDL2_Material * WaterBox::SDL2_Material::create(std::string path)
{
	SDL_Surface *sur = nullptr;
	sur = IMG_Load(path.c_str());
	if (!sur)
	{
		return nullptr;
	}
	SDL2_Material *mat = new SDL2_Material(sur);
	return mat;
}

SDL2_Material::SDL2_Material(SDL_Surface *sur)
{
	m_Tex = SDL_CreateTextureFromSurface(SDL2_Renderer::get()->getRenderer(), sur);
	m_Size.x = sur->w;
	m_Size.y = sur->h;
	SDL_FreeSurface(sur);
}

SDL2_Material::~SDL2_Material()
{
	SDL_DestroyTexture(m_Tex);
}

void SDL2_Material::show()
{
	SDL_Rect rect;
	rect.x = m_Position.x;
	rect.y = m_Position.y;
	rect.w = m_Size.x;
	rect.h = m_Size.y;

	SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Tex, NULL, &rect);
}

void SDL2_Material::setPosition(Math::vec2 position)
{
	m_Position = position;
}

void SDL2_Material::setSize(Math::vec2 size)
{
	m_Size = size;
}
