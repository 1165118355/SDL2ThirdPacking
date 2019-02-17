#include "SDL2_ObjectParticleEmitterPoint.h"
#include <SDL2_ObjectParticle.h>

using namespace WaterBox;

SDL2_ObjectParticleEmitterPoint::SDL2_ObjectParticleEmitterPoint()
{
	m_EmitterType = EMITTER_POINT;
}

SDL2_ObjectParticleEmitterPoint * WaterBox::SDL2_ObjectParticleEmitterPoint::create()
{
	SDL2_ObjectParticleEmitterPoint *point = new SDL2_ObjectParticleEmitterPoint();
	return point;
}

SDL2_ObjectParticleEmitterPoint::~SDL2_ObjectParticleEmitterPoint()
{
}

void WaterBox::SDL2_ObjectParticleEmitterPoint::generateParticle()
{
	SDL2_ObjectParticle *particle = SDL2_ObjectParticle::create();

	//	位置设置
	particle->m_Point = m_Position;

	//	速度设置
	particle->m_Speed = Math::randFloat(m_EmitSpeed - m_EmitSpeedSpread, m_EmitSpeed + m_EmitSpeedSpread);
	particle->m_SpeedDamping = m_EmitSpeedDamping;

	//	方向设置
	float dir = (m_EmitDirectionAngle + m_EmitDirectionAngleSpread * Math::randFloat(-1, 1)) * 0.0174532925f;
	particle->m_Direction = Math::vec2(sinf(dir), cosf(dir));

	//	生命设置
	particle->m_Life = Math::randFloat(m_Life - m_LifeSpread, m_Life + m_LifeSpread);
	particle->m_Size = m_Size;
	m_Particles.push_back(particle);
}
