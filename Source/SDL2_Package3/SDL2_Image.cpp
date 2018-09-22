#include "SDL2_Image.h"
#include <SDL2_MaterialPicture.h>

using namespace WaterBox;

SDL2_Image * WaterBox::SDL2_Image::create(std::string materialName)
{
	SDL2_MaterialManage *matManage = SDL2_Engine::get()->getSceneManager()->getScene()->getMaterialManage();
	SDL2_Material *mat = matManage->findMaterial(materialName);
	if (mat == nullptr)
	{
		return nullptr;
	}
	SDL2_Image *image = new SDL2_Image();
	image->setMaterial(mat);
	image->setSize(mat->getSize());
	return image;
}

SDL2_Image * WaterBox::SDL2_Image::create(SDL2_Material * mat)
{
	if (mat == nullptr)
	{
		return nullptr;
	}
	SDL2_Image *image = new SDL2_Image();
	image->setMaterial(mat);
	image->setSize(mat->getSize());
	return image;
}

SDL2_Image * WaterBox::SDL2_Image::create(SDL2_Xml * xml)
{
	if (xml == nullptr)
	{
		return nullptr;
	}
	SDL2_Image *image = new SDL2_Image();
	image->analysisXml(xml);
	return image;
}

WaterBox::SDL2_Image::SDL2_Image()
{
	m_ComponentType = COMPONENT_IMAGE;
	m_Material = nullptr;
	setPosition(Math::vec2(0, 0));
	setSize(Math::vec2(0, 0));

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

void WaterBox::SDL2_Image::materialModification()
{
	if (m_Material != nullptr)
	{
		m_Material->setPosition(getPosition());
		m_Material->setSize(getSize());
	}
}

int WaterBox::SDL2_Image::analysisXml(SDL2_Xml * xml)
{
	SDL2_MaterialManage *matManage = SDL2_Engine::get()->getSceneManager()->getScene()->getMaterialManage();
	SDL2_Component::analysisXml(xml);
	if (xml->getTag("material_image") != "" && xml->getTag("material_image") != "null")
	{
		setMaterial(matManage->findMaterial(xml->getTag("material_image")));
	}
	if (m_Material != nullptr)
	{
		setSize(m_Material->getSize());
	}
	return 0;
}

void WaterBox::SDL2_Image::setPosition(Math::vec2 position)
{
	m_Position = position;
}

Math::vec2 WaterBox::SDL2_Image::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Image::setSize(Math::vec2 size)
{
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

std::vector<SDL2_Material*> WaterBox::SDL2_Image::getMaterials()
{
	std::vector<SDL2_Material*> materials;
	if (nullptr != m_Material)
	{
		materials.push_back(m_Material);
	}
	return materials;
}
