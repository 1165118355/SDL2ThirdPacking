#include "SDL2_MaterialLibrary.h"
#include <SDL2_MaterialPicture.h>
#include <SDL2_MaterialAnimal.h>

using namespace WaterBox;

SDL2_MaterialLibrary::SDL2_MaterialLibrary()
{
	m_MatLibXml = SDL2_Xml::create();
	m_MatLibXml->setName("materials");
	m_LibPath = "";
	m_LibName = "";
}


SDL2_MaterialLibrary * WaterBox::SDL2_MaterialLibrary::create()
{
	SDL2_MaterialLibrary *matLib = new SDL2_MaterialLibrary();
	return matLib;
}

SDL2_MaterialLibrary * WaterBox::SDL2_MaterialLibrary::create(std::string name)
{
	SDL2_MaterialLibrary *matLib = new SDL2_MaterialLibrary();
	matLib->setName(name);
	return matLib;
}

void WaterBox::SDL2_MaterialLibrary::setName(std::string name)
{
	m_LibName = name;
}

std::string WaterBox::SDL2_MaterialLibrary::getName()
{
	return m_LibName;
}

void WaterBox::SDL2_MaterialLibrary::setPath(std::string path)
{
	m_LibPath = path;
}

std::string WaterBox::SDL2_MaterialLibrary::getPath()
{
	return m_LibPath;
}

int WaterBox::SDL2_MaterialLibrary::addMaterial(SDL2_Material * mat)
{
	for (int i=0; i<m_Materials.size(); ++i)
	{
		if (std::string(m_Materials[i]->getName()) == mat->getName())
		{
			return -1;
		}
	}
	m_Materials.push_back(mat);
	return 0;
}

int WaterBox::SDL2_MaterialLibrary::removeMaterial(SDL2_Material * mat)
{
	for (int i=0; i<m_Materials.size(); ++i)
	{
		if (m_Materials[i] == mat)
		{
			m_Materials.erase(m_Materials.begin() + i);
			return 0;
		}
	}
	return -1;
}

int WaterBox::SDL2_MaterialLibrary::getNumMaterials()
{
	return m_Materials.size();
}

SDL2_Material * WaterBox::SDL2_MaterialLibrary::findMaterial(std::string name)
{
	for (int i=0; i<m_Materials.size(); ++i)
	{
		if (name == m_Materials[i]->getName())
		{
			return m_Materials[i];
		}
	}
	return nullptr;
}

int WaterBox::SDL2_MaterialLibrary::load(std::string path)
{
	if (-1 == m_MatLibXml->load(path))
	{
		return -1;
	}

	//	另一个加载函数
	load(m_MatLibXml);
}

int WaterBox::SDL2_MaterialLibrary::load(SDL2_Xml * matLibXml)
{
	for (int i = 0; i < matLibXml->getNumChild(); ++i)
	{
		SDL2_Material *material;
		SDL2_Xml *matLibChildXml = matLibXml->getChild(i);
		if (matLibChildXml->getTag("type") == "picture")
		{
			material = SDL2_MaterialPicture::create();
		}
		else if (matLibChildXml->getTag("type") == "animal")
		{
			material = SDL2_MaterialAnimal::create();
		}
		else
		{
			continue;
		}
		material->load(matLibChildXml);
		m_Materials.push_back(material);
	}
	this->setName(matLibXml->getTag("name"));
	this->setPath(matLibXml->getTag("path"));
	return 0;
}

void WaterBox::SDL2_MaterialLibrary::save()
{
	SDL2_Material *material;
	m_MatLibXml->clear(1);
	m_MatLibXml->setName("materials");
	m_MatLibXml->setTag("name", this->getName());
	m_MatLibXml->setTag("path", this->getPath());
	for (int i=0; i<m_Materials.size(); ++i)
	{
		material = m_Materials[i];
		m_MatLibXml->addChild(material->save());
	}
	m_MatLibXml->save(m_LibPath + m_LibName + ".mat");
}

SDL2_MaterialLibrary::~SDL2_MaterialLibrary()
{
	delete m_MatLibXml;
}
