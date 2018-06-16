#include "SDL2_Material.h"
#include <SDL2_Renderer.h>

using namespace WaterBox;


SDL2_Material::MaterialType WaterBox::SDL2_Material::getType()
{
	return m_Type;
}

SDL2_Material::SDL2_Material()
{
	m_Type = TYPE_PARENT;
}

SDL2_Material * WaterBox::SDL2_Material::create()
{
	
	return new SDL2_Material();
}

SDL2_Material::~SDL2_Material()
{
}

void SDL2_Material::setPosition(Math::vec2 position)
{
	m_Position = position;
}

Math::vec2 WaterBox::SDL2_Material::getPosition()
{
	return m_Position;
}

void SDL2_Material::setSize(Math::vec2 size)
{
	m_Size = size;
}

Math::vec2 WaterBox::SDL2_Material::getSize()
{
	return m_Size;
}

