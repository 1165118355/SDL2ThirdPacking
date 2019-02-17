#include "SDL2_Material.h"
#include <SDL2_Renderer.h>
#include <SDL2_MaterialManage.h>

using namespace WaterBox;


void WaterBox::SDL2_Material::show()
{
}

SDL2_Xml * WaterBox::SDL2_Material::save()
{
	if (m_MaterialXml == nullptr)
	{
		m_MaterialXml = SDL2_Xml::create();
	}
	m_MaterialXml->setName("material");
	m_MaterialXml->setTag("name", m_Name.c_str());
	m_MaterialXml->setTag("type", "parent");
	return m_MaterialXml;
}

int WaterBox::SDL2_Material::load(SDL2_Xml * materialXml)
{
	/*std::string m_Name;
	Math::vec2 m_CutSize;
	Math::vec2 m_CutPosition;
	Math::vec2 m_Position;
	Math::vec2 m_Size;
	Math::vec2 m_DefaultSize;*/

	std::string tabStrings[] = {"name", "type", "parent", "cut_size", "cut_position", "size", "position", "default_size"};
	for (int i=0; i<sizeof(tabStrings)/sizeof(tabStrings[0]); ++i)
	{
		if (materialXml->getTag(tabStrings[i]) == "")
		{
			continue;
		}
		if (tabStrings[i] == "name")
		{
			setName(materialXml->getTag(tabStrings[i]));
		}
		else if (tabStrings[i] == "type")
		{
			if (materialXml->getTag(tabStrings[i]) == "picture")
			{
				m_Type = TYPE_PICTURE;
			}
			else if (materialXml->getTag(tabStrings[i]) == "text")
			{
				m_Type = TYPE_TEXT;
			}
			else if (materialXml->getTag(tabStrings[i]) == "animal")
			{
				m_Type = TYPE_ANIMAL;
			}
		}
		/*else if (tabStrings[i] == "size")
		{
		}
		else if (tabStrings[i] == "default_size")
		{
		}
		else if (tabStrings[i] == "cut_position")
		{
		}
		else if (tabStrings[i] == "cut_size")
		{
		}
		else
		{
		}*/
	}
	return 0;
}

void WaterBox::SDL2_Material::reload()
{
}

SDL2_Material::MaterialType WaterBox::SDL2_Material::getType()
{
	return m_Type;
}

SDL2_Material::SDL2_Material()
{
	m_Type = TYPE_PARENT;
	m_MaterialXml = nullptr;
	m_Position = Math::vec2(0, 0);
	m_Size = Math::vec2(50, 50);
}

void WaterBox::SDL2_Material::setDefaultSize(Math::vec2 size)
{
	m_DefaultSize = size;
}

SDL2_Material::~SDL2_Material()
{
}

SDL2_Material * WaterBox::SDL2_Material::create()
{
	return new SDL2_Material();
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

void WaterBox::SDL2_Material::setCutPosition(Math::vec2 position)
{
	m_CutPosition = position;
}

Math::vec2 WaterBox::SDL2_Material::getCutPosition()
{
	return m_CutPosition;
}

void WaterBox::SDL2_Material::setCutSize(Math::vec2 size)
{
	m_CutSize = size;
}

Math::vec2 WaterBox::SDL2_Material::getCutSize()
{
	return m_CutSize;
}

void WaterBox::SDL2_Material::setName(std::string name)
{
	m_Name = name;
}

std::string WaterBox::SDL2_Material::getName()
{
	return m_Name;
}

void WaterBox::SDL2_Material::setTransparent(int transparent)
{
}

int WaterBox::SDL2_Material::getTransparent()
{
	return 0;
}

void WaterBox::SDL2_Material::reSize()
{
	m_Size = m_DefaultSize;
}

