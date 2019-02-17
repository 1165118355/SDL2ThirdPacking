#include "SDL2_ObjectParticleEmitterRect.h"

using namespace WaterBox;

void WaterBox::SDL2_ObjectParticleEmitterRect::generateParticle()
{
}

SDL2_ObjectParticleEmitterRect::SDL2_ObjectParticleEmitterRect()
{
}


SDL2_ObjectParticleEmitterRect * WaterBox::SDL2_ObjectParticleEmitterRect::create()
{
	SDL2_ObjectParticleEmitterRect *eimt = new SDL2_ObjectParticleEmitterRect();
	return eimt;
}

SDL2_ObjectParticleEmitterRect::~SDL2_ObjectParticleEmitterRect()
{
}
