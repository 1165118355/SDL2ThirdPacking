#include "SDL2_ObjectParticleEmitter.h"
#include <SDL2_ObjectParticle.h>
#include <SDL2_Game.h>
#include <SDL2_Material.h>

using namespace WaterBox;

SDL2_ObjectParticleEmitter::SDL2_ObjectParticleEmitter()
{
	m_Gravity = Math::vec2(0, 0);
	m_EmitDirection = Math::vec2(0, 1);
	m_EmitDirectionAngle = 180;
	m_EmitDirectionAngleSpread = 40;
	m_EmitSpeed = 0.5;
	m_EmitSpeedSpread = 0.5;
	m_EmitSpeedDamping = 0.0001;
	m_Life = 1.5;
	m_LifeSpread = 1;
	m_Production = 60;
	m_Indensity = 1.0f;
	m_Size = Math::vec2(8, 8);
	m_SizeDamping = 0.0001;
}

void WaterBox::SDL2_ObjectParticleEmitter::generateParticle()
{
}

void WaterBox::SDL2_ObjectParticleEmitter::update()
{
	for (int i = 0; i < m_Particles.size(); ++i)
	{
		//	移除生命值低于零的粒子
		if (m_Particles[i]->m_Life <= 0)
		{
			m_Particles.erase(m_Particles.begin() + i);
			continue;
		}

		//	粒子向他应该移动的方向移动
		m_Particles[i]->m_Point = m_Particles[i]->m_Point + ((m_Particles[i]->m_Direction * m_Particles[i]->m_Speed) + m_Gravity);

		//	粒子速度衰减
		//m_Particles[i]->m_Speed -= m_Particles[i]->m_SpeedDamping;

		//	寿命减少ohye
		m_Particles[i]->m_Life -= SDL2_Game::get()->getIFPS(); 
	}

	//	根据时间产生粒子
	static float timeCount = 0;
	float uuouio = SDL2_Game::get()->getIFPS();
	timeCount += SDL2_Game::get()->getIFPS();
	while (timeCount >= 1.0 / m_Production)
	{
		float jjj = 1.0 / m_Production;
		timeCount -= 1.0 / m_Production;
		generateParticle();
	}
}

void WaterBox::SDL2_ObjectParticleEmitter::show()
{
	for (int i = 0; i < m_Particles.size(); ++i)
	{
		m_Material->setPosition(m_Particles[i]->m_Point);
		m_Material->setSize(m_Particles[i]->m_Size);
		m_Material->show();
	}
}

SDL2_ObjectParticleEmitter::EmitterType WaterBox::SDL2_ObjectParticleEmitter::getType()
{
	return m_EmitterType;
}

void WaterBox::SDL2_ObjectParticleEmitter::setPosition(Math::vec2 pos)
{
	m_Position = pos;
}

void WaterBox::SDL2_ObjectParticleEmitter::setGravity(Math::vec2 gravity)
{
	m_Gravity = gravity;
}

Math::vec2 WaterBox::SDL2_ObjectParticleEmitter::getGravity()
{
	return m_Gravity;
}

void WaterBox::SDL2_ObjectParticleEmitter::setEmitAngle(float angle)
{
	m_EmitDirectionAngle = angle;
}

float WaterBox::SDL2_ObjectParticleEmitter::getEmitAngle()
{
	return m_EmitDirectionAngle;
}

void WaterBox::SDL2_ObjectParticleEmitter::setEmitAngleSpread(float spread)
{
	m_EmitDirectionAngleSpread = spread;
}

float WaterBox::SDL2_ObjectParticleEmitter::getEmitAngleSpread()
{
	return m_EmitDirectionAngleSpread;
}

void WaterBox::SDL2_ObjectParticleEmitter::setSpeed(float speed)
{
	m_EmitSpeed = speed;
}

float WaterBox::SDL2_ObjectParticleEmitter::getSpeed()
{
	return m_EmitSpeed;
}

void WaterBox::SDL2_ObjectParticleEmitter::setSpeedSpread(float spread)
{
	m_EmitSpeedSpread = spread;
}

float WaterBox::SDL2_ObjectParticleEmitter::getSpeedSpread()
{
	return m_EmitSpeedSpread;
}

void WaterBox::SDL2_ObjectParticleEmitter::setLife(float life)
{
	m_Life = life;
}

float WaterBox::SDL2_ObjectParticleEmitter::getLife()
{
	return m_Life;
}

void WaterBox::SDL2_ObjectParticleEmitter::setLifeSpread(float spread)
{
	m_LifeSpread = spread;
}

float WaterBox::SDL2_ObjectParticleEmitter::getLifeSpread()
{
	return m_LifeSpread;
}

void WaterBox::SDL2_ObjectParticleEmitter::setProduction(float production)
{
	m_Production = production;
}

float WaterBox::SDL2_ObjectParticleEmitter::getProduction()
{
	return m_Production;
}

void WaterBox::SDL2_ObjectParticleEmitter::setSize(Math::vec2 size)
{
	m_Size = size;
}

Math::vec2 WaterBox::SDL2_ObjectParticleEmitter::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_ObjectParticleEmitter::setSizeSpread(float spread)
{
	m_Size;
}

float WaterBox::SDL2_ObjectParticleEmitter::getSizeSpread()
{
	return 0.0f;
}

void WaterBox::SDL2_ObjectParticleEmitter::setSizeDamping(float damping)
{
	m_SizeDamping = damping;
}

float WaterBox::SDL2_ObjectParticleEmitter::getSizeDamping()
{
	return m_SizeDamping;
}

void WaterBox::SDL2_ObjectParticleEmitter::setIndensity(float indensity)
{
	m_Indensity = indensity;
}

float WaterBox::SDL2_ObjectParticleEmitter::getIndensity()
{
	return m_Indensity;
}

void WaterBox::SDL2_ObjectParticleEmitter::setMaterial(SDL2_Material * material)
{
	m_Material = material;
}


SDL2_ObjectParticleEmitter::~SDL2_ObjectParticleEmitter()
{
}
