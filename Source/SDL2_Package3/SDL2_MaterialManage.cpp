#include "SDL2_MaterialManage.h"
#include <SDL2_MaterialPicture.h>
#include <SDL2_MaterialText.h>
#include <SDL2_MaterialAnimal.h>

using namespace WaterBox;

SDL2_MaterialManage::SDL2_MaterialManage()
{
	SDL2_MaterialLibrary *defaultMatLib = SDL2_MaterialLibrary::create();
	defaultMatLib->setName("default");
	m_MaterialLibs.push_back(defaultMatLib);
}

SDL2_MaterialManage * SDL2_MaterialManage::create()
{
	return new SDL2_MaterialManage();
}

SDL2_MaterialManage::~SDL2_MaterialManage()
{
}

int SDL2_MaterialManage::loadMaterialLib(std::string matLibPath)
{
	SDL2_Xml *matLibXml = SDL2_Xml::create();
	if (-1 == matLibXml->load(matLibPath))
	{
		return -1;
	}
	loadMaterialLib(matLibXml);
	return 0;
}

int SDL2_MaterialManage::loadMaterialLib(SDL2_Xml * matLibXml)
{
	if (nullptr == matLibXml)
	{
		return -1;
	}

	SDL2_MaterialLibrary *matLib = SDL2_MaterialLibrary::create();
	matLib->load(matLibXml);
	m_MaterialLibs.push_back(matLib);
	return 0;
}

int WaterBox::SDL2_MaterialManage::addMaterial(SDL2_MaterialLibrary * matLib)
{
	if (nullptr == matLib)
	{
		return -1;
	}
	m_MaterialLibs.push_back(matLib);
	return 0;
}

int WaterBox::SDL2_MaterialManage::addMaterial(SDL2_Material * mat, std::string libName/*=default*/)
{
	for(int i=0; i<m_MaterialLibs.size(); ++i)
	{
		if (libName == m_MaterialLibs[i]->getName())
		{
			m_MaterialLibs[i]->addMaterial(mat);
			return 0;
		}
	}
	return -1;
}

int WaterBox::SDL2_MaterialManage::removeMaterial(SDL2_Material * mat, std::string libName/*=default*/)
{
	for (int i = 0; i<m_MaterialLibs.size(); ++i)
	{
		if (libName == m_MaterialLibs[i]->getName())
		{
			m_MaterialLibs[i]->removeMaterial(mat);
			return 0;
		}
	}
	return -1;
}

SDL2_Material * SDL2_MaterialManage::findMaterial(std::string name)
{
	for (auto &i : m_MaterialLibs)
	{
		std::string libName = i->getName();
		SDL2_Material *mat = findMaterial(name, libName);
		if (nullptr != mat)
		{
			return mat;
		}
	}
	return nullptr;
}

SDL2_Material * SDL2_MaterialManage::findMaterial(std::string materialName, std::string libName)
{
	for (int i=0; i<m_MaterialLibs.size(); ++i)
	{
		if (libName == m_MaterialLibs[i]->getName())
		{
			return m_MaterialLibs[i]->findMaterial(materialName);
		}
	}
	return nullptr;
}

SDL2_Material * SDL2_MaterialManage::findMaterial(int id)
{
	
	return nullptr;
}

std::string WaterBox::SDL2_MaterialManage::getMaterialLibName(int num)
{
	if (num >= m_MaterialLibs.size())
	{
		return std::string("");
	}
	return m_MaterialLibs[num]->getName();
}

std::string WaterBox::SDL2_MaterialManage::getMaterialLibPath(int num)
{
	if (num >= m_MaterialLibs.size())
	{
		return std::string("");
	}
	return m_MaterialLibs[num]->getPath();
}

int WaterBox::SDL2_MaterialManage::getNumMaterialLibs()
{
	return m_MaterialLibs.size();
}

int WaterBox::SDL2_MaterialManage::getNumMaterialByLib(std::string libName)
{
	for (int i=0; i<m_MaterialLibs.size(); ++i)
	{
		if (libName == m_MaterialLibs[i]->getName())
		{
			return m_MaterialLibs[i]->getNumMaterials();
		}
	}
	return -1;
}

void WaterBox::SDL2_MaterialManage::save()
{
	for (auto &i:m_MaterialLibs)
	{
		i->save();
	}
}

int WaterBox::SDL2_MaterialManage::load(std::string libPath)
{
	SDL2_MaterialLibrary *matLib = SDL2_MaterialLibrary::create();
	matLib->load(libPath);
	for (int i=0; i<m_MaterialLibs.size(); ++i)
	{
		if (matLib->getName() == m_MaterialLibs[i]->getName())
		{
			delete matLib;
			return -1;
		}
	}
	if (matLib == nullptr)
	{
		return -1;
	}
	m_MaterialLibs.push_back(matLib);
	return 0;
}

int WaterBox::SDL2_MaterialManage::load(SDL2_Xml * lib)
{
	SDL2_MaterialLibrary *matLib = SDL2_MaterialLibrary::create();
	matLib->load(lib);
	if (matLib == nullptr)
	{
		return -1;
	}
	m_MaterialLibs.push_back(matLib);
	return 0;
}

int SDL2_MaterialManage::saveMaterialLib(std::string libName)
{
	
	return 0;
}
