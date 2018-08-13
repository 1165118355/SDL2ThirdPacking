#include "SDL2_Object.h"
#include <SDL2_SceneManager.h>
#include <SDL2_Engine.h>

using namespace WaterBox;
SDL2_Object::SDL2_Object()
{
	SDL2_Engine::get()->getSceneManager()->getScene()->addObject(this);
}
void WaterBox::SDL2_Object::setPosition(Math::vec2 position)
{
}

Math::vec2 WaterBox::SDL2_Object::getPosition()
{
	return Math::vec2();
}

void WaterBox::SDL2_Object::setSize(Math::vec2 size)
{
}

Math::vec2 WaterBox::SDL2_Object::getSize()
{
	return Math::vec2();
}

void WaterBox::SDL2_Object::show()
{
}

void WaterBox::SDL2_Object::update()
{
}

std::vector<SDL2_Material*> WaterBox::SDL2_Object::getMaterials()
{
	return std::vector<SDL2_Material*>();
}
