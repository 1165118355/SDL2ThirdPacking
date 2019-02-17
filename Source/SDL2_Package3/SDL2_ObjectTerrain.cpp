#include "SDL2_ObjectTerrain.h"

using namespace WaterBox;

SDL2_ObjectTerrain::SDL2_ObjectTerrain()
{
}


SDL2_ObjectTerrain::~SDL2_ObjectTerrain()
{
}

SDL2_ObjectTerrain * WaterBox::SDL2_ObjectTerrain::create()
{
	SDL2_ObjectTerrain *terrain = new SDL2_ObjectTerrain();
	return terrain;
}

void WaterBox::SDL2_ObjectTerrain::materialModification()
{
}

void WaterBox::SDL2_ObjectTerrain::show()
{
	for (auto &i:m_Layer)
	{
	}
}

void WaterBox::SDL2_ObjectTerrain::update()
{
}

SDL2_Xml * WaterBox::SDL2_ObjectTerrain::saveToXml()
{
	return nullptr;
}

int WaterBox::SDL2_ObjectTerrain::analysisXml(SDL2_Xml * xml)
{
	return 0;
}

void WaterBox::SDL2_ObjectTerrain::addLayer(SDL2_ObjectTerrainLayer * layer)
{
	m_Layer.push_back(layer);
}
