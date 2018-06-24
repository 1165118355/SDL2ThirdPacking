#include "SDL2_MaterialText.h"

using namespace WaterBox;

SDL2_MaterialText * WaterBox::SDL2_MaterialText::create(std::string text)
{
	SDL_Color color = {0, 0, 0, 255};
	SDL_Surface *sur = TTF_RenderUTF8_Blended(SDL2_FontSystem::get()->findFont("SystemFont"), text.c_str(), color);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(SDL2_Renderer::get()->getRenderer(), sur);
	SDL2_MaterialText *mat = new SDL2_MaterialText(tex, text);
	return mat;
}
void WaterBox::SDL2_MaterialText::show()
{
	SDL_Rect rect = {m_Position.x, m_Position.y, m_Size.x, m_Size.y};
	SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Texture, NULL, &rect);
}
SDL2_MaterialText::SDL2_MaterialText(SDL_Texture * tex, std::string text)
{
	m_Texture = tex;
	m_Text = text;
	setPosition(Math::vec2(0, 0));
	setSize(Math::vec2(20, 20));
	m_Type = TYPE_TEXT;
}
