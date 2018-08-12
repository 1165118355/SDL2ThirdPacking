#include "SDL2_MaterialPicture.h"

using namespace WaterBox;

SDL2_MaterialPicture * WaterBox::SDL2_MaterialPicture::create(std::string path)
{
	SDL_Surface *sur = IMG_Load(path.c_str()); 
	if (nullptr == sur)
	{
		return nullptr;
	}
	SDL_Texture *tex = SDL_CreateTextureFromSurface(SDL2_Renderer::get()->getRenderer(), sur);
	if (nullptr == tex)
	{
		return nullptr;
	}
	SDL2_MaterialPicture *mat = new SDL2_MaterialPicture(tex);
	mat->setSize(Math::vec2(sur->w, sur->h));
	SDL_FreeSurface(sur);
	return mat;
}

void WaterBox::SDL2_MaterialPicture::show()
{
	SDL_Rect cutRect = {m_CutPosition.x, m_CutPosition.y, m_CutSize.x, m_CutSize.y};
	SDL_Rect rect = {m_Position.x, m_Position.y, m_Size.x, m_Size.y};
	if (cutRect.x+ cutRect.y+ cutRect.w+ cutRect.h == 0)
	{

		SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Texture, NULL, &rect);
	}
	else
	{
		SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Texture, &cutRect, &rect);
	}
}

void WaterBox::SDL2_MaterialPicture::setTransparent(int transparent)
{
	if (-1 == SDL_SetTextureAlphaMod(m_Texture, transparent))//					设置纹理透明度
	{
		printf("error setTransparent()\n");
	}
}

int WaterBox::SDL2_MaterialPicture::getTransparent()
{
	Uint8 transparent;
	SDL_GetTextureAlphaMod(m_Texture, &transparent);//				获取纹理透明度（第二个参数是透明度）
	return transparent;
}

WaterBox::SDL2_MaterialPicture::SDL2_MaterialPicture(SDL_Texture * tex)
{
	m_Texture = tex;
	m_Type = TYPE_PICTURE;
}

