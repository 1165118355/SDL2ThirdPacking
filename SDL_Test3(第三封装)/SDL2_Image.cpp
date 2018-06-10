#include "SDL2_Image.h"

using namespace WaterBox;

SDL2_Image * WaterBox::SDL2_Image::create()
{
	SDL2_Material *mat = SDL2_Material::create();
	SDL2_Image *image = new SDL2_Image(mat);
	return image;
}

SDL2_Image * WaterBox::SDL2_Image::create(std::string path)
{
	SDL2_Material *mat = SDL2_Material::create(path);
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
}

int WaterBox::SDL2_Image::show()
{
	if (NULL != m_Material)
	{
		m_Material->show();
	}
	return 0;
}

void WaterBox::SDL2_Image::setMaterial(SDL2_Material * mat)
{
}

SDL2_Material * WaterBox::SDL2_Image::getMaterial()
{
	return nullptr;
}
