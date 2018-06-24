#include "SDL2_Image.h"
#include <SDL2_MaterialPicture.h>

using namespace WaterBox;

SDL2_Image * WaterBox::SDL2_Image::create(std::string path)
{
	SDL2_Material *mat = SDL2_MaterialPicture::create(path);
	SDL2_Image *image = new SDL2_Image(mat);
	return image;
}

SDL2_Image * WaterBox::SDL2_Image::create(SDL2_Material * mat)
{
	SDL2_Image *image = new SDL2_Image(mat);
	return image;
}

WaterBox::SDL2_Image::SDL2_Image(SDL2_Material *mat)
{
	type = COMPONENT_IMAGE;
	m_Material = mat;
	setPosition(Math::vec2(0, 0));
	setSize(Math::vec2(50, 50));
}

int WaterBox::SDL2_Image::show()
{
	if (NULL != m_Material)
	{
		m_Material->show();
	}
	return 0;
}

void WaterBox::SDL2_Image::update(SDL_Event * event)
{
}

void WaterBox::SDL2_Image::setPosition(Math::vec2 position)
{
	m_Material->setPosition(position);
	m_Position = position;
}

Math::vec2 WaterBox::SDL2_Image::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Image::setSize(Math::vec2 size)
{
	m_Material->setSize(size);
	m_Size = size;
}

Math::vec2 WaterBox::SDL2_Image::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_Image::setMaterial(SDL2_Material * mat)
{
	if (nullptr != m_Material)
	{
		delete m_Material;
	}
	if (mat != nullptr)
	{
		m_Material = mat;
	}
}

SDL2_Material * WaterBox::SDL2_Image::getMaterial()
{
	return nullptr;
}
