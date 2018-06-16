#include "SDL2_Draw.h"
#include <SDL2/SDL.h>
#include <SDL2_Renderer.h>

using namespace WaterBox;

void WaterBox::SDL2_Draw::drawRectangle(Math::vec2 position, Math::vec2 size, Math::vec4 color)
{
	SDL_Rect rect = { position.x, position.y, size.x, size.y };
	SDL_SetRenderDrawColor(SDL2_Renderer::get()->getRenderer(), color.x, color.y, color.z, color.w);
	SDL_RenderFillRect(SDL2_Renderer::get()->getRenderer(), &rect);
}
