#include "SDL2_ObjectParticleEmitterLine.h"

using namespace WaterBox;

void WaterBox::SDL2_ObjectParticleEmitterLine::generateParticle()
{
}

SDL2_ObjectParticleEmitterLine::SDL2_ObjectParticleEmitterLine()
{
}


SDL2_ObjectParticleEmitterLine * WaterBox::SDL2_ObjectParticleEmitterLine::create()
{
	SDL2_ObjectParticleEmitterLine *emit = new SDL2_ObjectParticleEmitterLine();
	return emit;
}

SDL2_ObjectParticleEmitterLine::~SDL2_ObjectParticleEmitterLine()
{
}
