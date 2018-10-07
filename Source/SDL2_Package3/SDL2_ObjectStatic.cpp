#include "SDL2_ObjectStatic.h"
#include <SDL2_Console.h>
#include <SDL2_System.h>

using namespace WaterBox;

SDL2_ObjectStatic * WaterBox::SDL2_ObjectStatic::create(SDL2_Material * material)
{
	SDL2_ObjectStatic *staticObject = new SDL2_ObjectStatic();
	staticObject->setMaterialImage(material);
	return staticObject;
}

SDL2_ObjectStatic * WaterBox::SDL2_ObjectStatic::create(SDL2_Xml * xml)
{
	SDL2_ObjectStatic *obj = new SDL2_ObjectStatic();
	obj->analysisXml(xml);
	return obj;
}

void WaterBox::SDL2_ObjectStatic::materialModification()
{
	if (nullptr != m_MaterialImage)
	{
		m_MaterialImage->setPosition(this->getPositionShow());
		m_MaterialImage->setSize(this->getSize() * m_Scale);
	}
}

void WaterBox::SDL2_ObjectStatic::show()
{
	if (nullptr != m_MaterialImage)
	{
		m_MaterialImage->show();
	}
}

void WaterBox::SDL2_ObjectStatic::update()
{
}

SDL2_Xml * WaterBox::SDL2_ObjectStatic::saveToXml()
{
	SDL2_Xml *xml = SDL2_Object::saveToXml();

	xml->setTag("type", "object_static");
	if (nullptr != m_MaterialImage)
	{
		xml->setTag("material_image", m_MaterialImage->getName());
	}
	return xml;
}

int WaterBox::SDL2_ObjectStatic::analysisXml(SDL2_Xml * xml)
{
	SDL2_Object::analysisXml(xml);
	SDL2_Scene *scene = SDL2_System::get()->getSceneManager()->getScene();
	if("" != xml->getTag("material_image"))
	{
		this->setMaterialImage(scene->findMaterial(xml->getTag("material_image")));
	}
	return 0;
}

bool WaterBox::SDL2_ObjectStatic::setMaterialImage(SDL2_Material * material)
{
	if (nullptr == material)
	{
		SDL2_Console::get()->addError("material == nullptr in ObjectStatic::setMaterialImage()");
		return false;
	}
	m_MaterialImage = material;
	this->setSize(m_MaterialImage->getSize());
	return true;
}

SDL2_Material * WaterBox::SDL2_ObjectStatic::getMaterialImage()
{
	return m_MaterialImage;
}

SDL2_ObjectStatic::SDL2_ObjectStatic()
{
	m_Materials.push_back(&m_MaterialImage);
}


SDL2_ObjectStatic::~SDL2_ObjectStatic()
{
}
