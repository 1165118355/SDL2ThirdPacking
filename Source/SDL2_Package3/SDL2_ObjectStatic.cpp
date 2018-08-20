#include "SDL2_ObjectStatic.h"

using namespace WaterBox;

SDL2_ObjectStatic * WaterBox::SDL2_ObjectStatic::create()
{
	SDL2_ObjectStatic *staticObject = new SDL2_ObjectStatic();
	return staticObject;
}

SDL2_ObjectStatic::SDL2_ObjectStatic()
{
	m_Materials.push_back(&m_MaterialImage);
}


SDL2_ObjectStatic::~SDL2_ObjectStatic()
{
}
