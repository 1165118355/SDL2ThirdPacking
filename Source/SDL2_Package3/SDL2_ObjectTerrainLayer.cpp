#include "SDL2_ObjectTerrainLayer.h"

using namespace WaterBox;

SDL2_ObjectTerrainLayer * WaterBox::SDL2_ObjectTerrainLayer::create(Math::vec2 number)
{
	SDL2_ObjectTerrainLayer *layer = new SDL2_ObjectTerrainLayer();
	layer->setNumRowColumn(number);
	return layer;
}

void WaterBox::SDL2_ObjectTerrainLayer::setNumRowColumn(Math::vec2 number)
{
	m_Map.resize(number.x);
	for (auto &i : m_Map)
	{
		i.resize(number.y);
	}
}

void WaterBox::SDL2_ObjectTerrainLayer::show()
{

}

SDL2_ObjectTerrainLayer::~SDL2_ObjectTerrainLayer()
{
}

SDL2_ObjectTerrainLayer::SDL2_ObjectTerrainLayer()
{
}
