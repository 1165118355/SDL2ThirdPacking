#include "SDL2_ObjectParticle.h"
#include <SDL2_Game.h>
#include <SDL2_System.h>
#include <SDL2_Console.h>
#include <SDL2_ObjectParticleEmitter.h>
#include <stdlib.h>
#include <time.h>

using namespace WaterBox;

SDL2_ObjectParticle::SDL2_ObjectParticle()
{
}
SDL2_ObjectParticle * WaterBox::SDL2_ObjectParticle::create()
{
	SDL2_ObjectParticle *particle = new SDL2_ObjectParticle();
	return particle;
}

SDL2_ObjectParticle::~SDL2_ObjectParticle()
{
}
