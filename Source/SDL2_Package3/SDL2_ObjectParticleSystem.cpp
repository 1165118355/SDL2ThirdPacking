#include "SDL2_ObjectParticleSystem.h"
#include <SDL2_System.h>
#include <SDL2_ObjectParticleEmitter.h>
#include <SDL2_ObjectParticleEmitterLine.h>
#include <SDL2_ObjectParticleEmitterPoint.h>
#include <SDL2_ObjectParticleEmitterRect.h>

using namespace WaterBox;

SDL2_ObjectParticleEmitter * WaterBox::SDL2_ObjectParticleSystem::getEmitter()
{
	return m_Emitter;
}

SDL2_ObjectParticleSystem::SDL2_ObjectParticleSystem()
{
	m_Emitter = SDL2_ObjectParticleEmitterPoint::create();
}


SDL2_ObjectParticleSystem * SDL2_ObjectParticleSystem::create()
{
	SDL2_ObjectParticleSystem *particle = new SDL2_ObjectParticleSystem();
	return particle;
}

SDL2_ObjectParticleSystem::~SDL2_ObjectParticleSystem()
{
}

void WaterBox::SDL2_ObjectParticleSystem::materialModification()
{
	///	粒子系统用不上这个函数
}

void WaterBox::SDL2_ObjectParticleSystem::show()
{
	if (m_Emitter)
	{
		m_Emitter->show();
	}
}

void WaterBox::SDL2_ObjectParticleSystem::update()
{
	m_Emitter->setPosition(m_Position);
	if (m_Emitter)
	{
		m_Emitter->update();
	}
}

SDL2_Xml * WaterBox::SDL2_ObjectParticleSystem::saveToXml()
{
	SDL2_Xml *xml = SDL2_Object::saveToXml();
	xml->setTag("type", "object_particle_system");
	if (nullptr != m_Material)
	{
		xml->setTag("material_image", m_Material->getName());
	}
	return xml;
}

int WaterBox::SDL2_ObjectParticleSystem::analysisXml(SDL2_Xml * xml)
{
	return 0;
}

void WaterBox::SDL2_ObjectParticleSystem::setMaterialParticle(const char * materialName)
{
	SDL2_Material *material = SDL2_System::get()->getSceneManager()->getScene()->getMaterialManage()->findMaterial(std::string(materialName));
	setMaterialParticle(material);
}

void WaterBox::SDL2_ObjectParticleSystem::setMaterialParticle(SDL2_Material * material)
{
	m_Material = material;
	m_Emitter->setMaterial(material);
}

void WaterBox::SDL2_ObjectParticleSystem::setEmitterType(SDL2_ObjectParticleEmitter::EmitterType type)
{
	if (m_Emitter)
	{
		delete m_Emitter;
	}
	switch (type)
	{
	case SDL2_ObjectParticleEmitter::EMITTER_POINT:
		m_Emitter = SDL2_ObjectParticleEmitterPoint::create();
		break;
	case SDL2_ObjectParticleEmitter::EMITTER_LINE:
		m_Emitter = SDL2_ObjectParticleEmitterLine::create();
		break;
	case SDL2_ObjectParticleEmitter::EMITTER_RECT:
		m_Emitter = SDL2_ObjectParticleEmitterRect::create();
		break;
	default:
		m_Emitter = SDL2_ObjectParticleEmitterPoint::create();
		break;
	}
}

SDL2_ObjectParticleEmitter::EmitterType WaterBox::SDL2_ObjectParticleSystem::getEmitterType()
{
	return m_Emitter->getType();
}
