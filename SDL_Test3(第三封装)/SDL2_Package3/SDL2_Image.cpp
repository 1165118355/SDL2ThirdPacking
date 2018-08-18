#include "SDL2_Image.h"
#include <SDL2_MaterialPicture.h>

using namespace WaterBox;

SDL2_Image * WaterBox::SDL2_Image::create(std::string path)
{
	SDL2_Material *mat = SDL2_MaterialPicture::create(path);
	SDL2_Image *image = new SDL2_Image();
	image->setMaterial(mat);
	return image;
}

SDL2_Image * WaterBox::SDL2_Image::create(SDL2_Material * mat)
{
	SDL2_Image *image = new SDL2_Image();
	image->setMaterial(mat);
	return image;
}

SDL2_Image * WaterBox::SDL2_Image::create(SDL2_Xml * xml)
{
	SDL2_Image *image = new SDL2_Image();
	image->analysisXml(xml);
	return image;
}

WaterBox::SDL2_Image::SDL2_Image()
{
	m_ComponentType = COMPONENT_IMAGE;
	m_Material = SDL2_Material::create();
	setPosition(Math::vec2(0, 0));
	setSize(Math::vec2(50, 50));

}

void WaterBox::SDL2_Image::show()
{
	if (NULL != m_Material)
	{
		m_Material->show();
	}
	return ;
}

void WaterBox::SDL2_Image::update(SDL_Event * event)
{
}

int WaterBox::SDL2_Image::analysisXml(SDL2_Xml * xml)
{
	SDL2_Component::analysisXml(xml);
	if (xml->getTag("path") != "" && xml->getTag("path") != "null")
	{
		setMaterial(SDL2_MaterialPicture::create(xml->getTag("path")));
	}
	return 0;
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
	return m_Material;
}

void WaterBox::SDL2_Image::setTransparent(int transparent)
{
	m_Material->setTransparent(transparent);
}

int WaterBox::SDL2_Image::getTransparent()
{
	return m_Material->getTransparent();
}
