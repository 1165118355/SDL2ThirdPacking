#include "SDL2_MaterialManage.h"
#include <SDL2_MaterialPicture.h>
#include <SDL2_MaterialText.h>
#include <SDL2_MaterialAnimal.h>

using namespace WaterBox;

SDL2_MaterialManage::SDL2_MaterialManage()
{
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

int SDL2_MaterialManage::loadMaterialLib(SDL2_Xml * matLib)
{
	if (nullptr == matLib)
	{
		return -1;
	}
	for (int i=0; i<matLib->getNumChild(); ++i)
	{
	}
	return 0;
}

void WaterBox::SDL2_MaterialManage::addMaterial(SDL2_Material * mat, std::string libName)
{
	std::map<std::string, std::vector<SDL2_Material *>>::iterator matLibI = m_MaterialLibs.find(libName);
	if (m_MaterialLibs.end() == matLibI)
	{
		std::pair<std::string, std::vector<SDL2_Material *>> matLib;
		matLib.second.push_back(mat);
		m_MaterialLibs.insert(matLib);
	}
	else
	{
		matLibI->second.push_back(mat);
	}
}

int WaterBox::SDL2_MaterialManage::removeMaterial(SDL2_Material * mat, std::string libName)
{
	std::map<std::string, std::vector<SDL2_Material *>>::iterator matLibI = m_MaterialLibs.find(libName);
	if (m_MaterialLibs.end() == matLibI)
	{
		return -1;
	}
	else
	{
		matLibI->second;
		for (int i=0; i<matLibI->second.size(); ++i)
		{
			if (matLibI->second[i] == mat)
			{
				matLibI->second.erase(matLibI->second.begin() + i);
			}
		}
		
	}
}

SDL2_Material * SDL2_MaterialManage::findMaterial(std::string name)
{
	for (auto &i : m_MaterialLibs)
	{
		std::string libName = i.first;
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
	if (m_MaterialLibs.end() == m_MaterialLibs.find(libName))
	{
		return nullptr;
	}
	std::map<std::string, std::vector<SDL2_Material *>>::iterator matLib = m_MaterialLibs.find(libName);
	for (int i = 0; i < matLib->second.size(); ++i)
	{
		if (matLib->second[i]->getName() == materialName)
		{
			return matLib->second[i];
		}
	}
	return nullptr;
}

SDL2_Material * SDL2_MaterialManage::findMaterial(int id)
{
	
	return nullptr;
}

int WaterBox::SDL2_MaterialManage::getNumMaterialLibs()
{
	return m_MaterialLibs.size();
}

int WaterBox::SDL2_MaterialManage::getNumMaterialByLib(std::string libName)
{
	if (m_MaterialLibs.end() == m_MaterialLibs.find(libName))
	{
		return -1;
	}

	return m_MaterialLibs.find(libName)->second.size();
}

void WaterBox::SDL2_MaterialManage::save()
{
	for (auto &i:m_MaterialLibs)
	{
		saveMaterialLib(i.first);
	}
}

int WaterBox::SDL2_MaterialManage::load(std::string libPath)
{
	SDL2_Xml *matLibXml = SDL2_Xml::create();
	if (-1 == matLibXml->load(libPath))
	{
		return -1;
	}
	if (matLibXml->getName() != "materials")
	{
		return -1;
	}
	std::pair<std::string, std::vector<SDL2_Material *>> matLib;
	matLib.first = libPath;
	for (int i=0; i<matLibXml->getNumChild(); ++i)
	{
		SDL2_Xml *matLibChildXml = matLibXml->getChild(i);
		SDL2_Material *material = nullptr;
		if (matLibChildXml->getTag("type") == "material_picture")
		{
			material = SDL2_MaterialPicture::create();
		}
		else if (matLibChildXml->getTag("type") == "material_text")
		{
			material = SDL2_MaterialText::create();
		}
		else if (matLibChildXml->getTag("type") == "material_animal")
		{
			material = SDL2_MaterialAnimal::create();
		}
		else
		{
			continue;
		}
		material->load(matLibChildXml);
	}
	m_MaterialLibs.insert(matLib);
}

int SDL2_MaterialManage::saveMaterialLib(std::string libName)
{
	if (m_MaterialLibs.end() == m_MaterialLibs.find(libName))
	{
		return -1;
	}
	std::map<std::string, std::vector<SDL2_Material *>>::iterator matLib = m_MaterialLibs.find(libName);
	SDL2_Xml *matLibXml = SDL2_Xml::create("materials");
	for (int i=0; i<matLib->second.size(); ++i)
	{
		SDL2_Xml *matLibChildXml = matLib->second[i]->save();
		matLibXml->addChild(matLib->second[i]->save());
	}
	matLibXml->save(matLib->first);
	return 0;
}
