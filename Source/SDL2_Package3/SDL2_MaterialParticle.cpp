#include "SDL2_MaterialParticle.h"
#include <SDL2_Material.h>

using namespace WaterBox;

SDL2_MaterialParticle::SDL2_MaterialParticle()
{
}


SDL2_MaterialParticle * WaterBox::SDL2_MaterialParticle::create()
{
	SDL2_MaterialParticle *particleMaterial = new SDL2_MaterialParticle();
	return particleMaterial;
}

SDL2_MaterialParticle::~SDL2_MaterialParticle()
{
}
