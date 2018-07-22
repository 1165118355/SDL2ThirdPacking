#include "SDL2_Materials.h"

using namespace WaterBox;

SDL2_Materials::SDL2_Materials()
{
}


SDL2_Materials::~SDL2_Materials()
{
}

void WaterBox::SDL2_Materials::show()
{
}

void WaterBox::SDL2_Materials::addMaterial(SDL2_Material * mat)
{
	m_Materials.push_back(mat);
}
