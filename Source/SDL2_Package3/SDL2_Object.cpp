#include "SDL2_Object.h"
#include <SDL2_SceneManager.h>
#include <SDL2_System.h>
#include <SDL2_ObjectStatic.h>
#include <SDL2_Utils.h>

using namespace WaterBox;
SDL2_Object::SDL2_Object()
{
	m_Xml = SDL2_Xml::create();
	m_Scale = 1.0f;
	SDL2_System::get()->getSceneManager()->getScene()->addObject(this);
}
WaterBox::SDL2_Object::~SDL2_Object()
{
}

SDL2_Object * WaterBox::SDL2_Object::create(SDL2_Xml * xml)
{
	SDL2_Object *obj = nullptr;
	if ("object" != xml->getName())
	{
		return nullptr;
	}
	if ("object_static" == xml->getTag("type"))
	{
		obj = SDL2_ObjectStatic::create(xml);
	}
	else
	{
		return nullptr;
	}
	return obj;
}

void WaterBox::SDL2_Object::setPositionShow(Math::vec2 position)
{
	m_PositionShow = position;
}

Math::vec2 WaterBox::SDL2_Object::getPositionShow()
{
	return m_PositionShow;
}

void WaterBox::SDL2_Object::setScale(float scale)
{
	m_Scale = scale;
}

float WaterBox::SDL2_Object::getScale()
{
	return m_Scale;
}

void WaterBox::SDL2_Object::setOverlapMask(int mask)
{
	m_OverlapMask = mask;
}

int WaterBox::SDL2_Object::getOverlapMask()
{
	return m_OverlapMask;
}

void WaterBox::SDL2_Object::materialModification()
{
}

void WaterBox::SDL2_Object::show()
{
}

void WaterBox::SDL2_Object::update()
{
}

int WaterBox::SDL2_Object::analysisXml(SDL2_Xml * xml)
{
	if ("object" != xml->getName())
	{
		return -1;
	}
	if ("" != xml->getTag("name"))
	{
		this->setName(xml->getTag("name"));
	}

	Math::vec2 position = this->getPosition();
	Math::vec2 size = this->getSize();
	if ("" != xml->getTag("x"))
	{
		position.x = SDL2_Utils::get()->StrToInt(xml->getTag("x"));
		this->setPosition(position);
	}
	if ("" != xml->getTag("y"))
	{
		position.y = SDL2_Utils::get()->StrToInt(xml->getTag("y"));
		this->setPosition(position);
	}
	if ("" != xml->getTag("w"))
	{
		size.x = SDL2_Utils::get()->StrToInt(xml->getTag("w"));
		this->setSize(size);
	}
	if ("" != xml->getTag("h"))
	{
		size.y = SDL2_Utils::get()->StrToInt(xml->getTag("h"));
		this->setSize(size);
	}
	return 0;
}

SDL2_Xml * WaterBox::SDL2_Object::saveToXml()
{
	m_Xml->setName("object");
	m_Xml->setTag("type", "object");
	m_Xml->setTag("name", "object");
	m_Xml->setTag("x", m_Position.x);
	m_Xml->setTag("y", m_Position.y);
	m_Xml->setTag("w", m_Size.x);
	m_Xml->setTag("h", m_Size.y);
	return m_Xml;
}

std::vector<SDL2_Material*> WaterBox::SDL2_Object::getMaterials()
{
	return std::vector<SDL2_Material*>();
}
