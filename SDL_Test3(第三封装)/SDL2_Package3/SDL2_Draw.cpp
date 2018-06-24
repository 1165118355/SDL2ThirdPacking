#include "SDL2_Draw.h"
#include <SDL2/SDL.h>
#include <SDL2_Renderer.h>

using namespace WaterBox;

void WaterBox::SDL2_Draw::drawPoint(Math::vec2 position, Math::vec4 color)
{
	SDL_SetRenderDrawColor(SDL2_Renderer::get()->getRenderer(), color.x, color.y, color.z, color.w);
	SDL_RenderDrawPoint(SDL2_Renderer::get()->getRenderer(), position.x, position.y);
}

void WaterBox::SDL2_Draw::drawLine(Math::vec2 position1, Math::vec2 position2, Math::vec4 color)
{
	SDL_SetRenderDrawColor(SDL2_Renderer::get()->getRenderer(), color.x, color.y, color.z, color.w);
	SDL_RenderDrawLine(SDL2_Renderer::get()->getRenderer(), position1.x, position1.y, position2.x, position2.y);
}

void WaterBox::SDL2_Draw::drawRectangle(Math::vec2 position, Math::vec2 size, Math::vec4 color)
{
	SDL_Rect rect = { position.x, position.y, size.x, size.y };
	SDL_SetRenderDrawColor(SDL2_Renderer::get()->getRenderer(), color.x, color.y, color.z, color.w);
	SDL_RenderFillRect(SDL2_Renderer::get()->getRenderer(), &rect);
}
