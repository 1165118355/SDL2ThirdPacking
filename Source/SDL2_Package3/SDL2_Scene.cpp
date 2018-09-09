#include "SDL2_Scene.h"

using namespace WaterBox;

WaterBox::SDL2_Scene::SDL2_Scene(SDL2_SceneManager * manager)
{
	mGui = nullptr;
	m_Player = nullptr;
	m_SceneXml = SDL2_Xml::create();
	m_MaterialManage = SDL2_MaterialManage::create();
}

WaterBox::SDL2_Scene::~SDL2_Scene()
{
	delete m_MaterialManage;
}

void WaterBox::SDL2_Scene::init()
{
}

void WaterBox::SDL2_Scene::update()
{
}

void WaterBox::SDL2_Scene::render()
{
	if (m_Player == nullptr)
	{
		return;
	}
	Math::vec2 winSize = SDL2_MainWindow::get()->getSize();
	Math::vec2 playerPos = m_Player->getPosition();
	for (int i=0; i<m_Objects.size(); ++i)
	{
		m_Objects[i]->update();
		Math::vec2 objectPos = m_Objects[i]->getPosition();
		if (objectPos.x > playerPos.x && objectPos.x < playerPos.x + winSize.x &&
			objectPos.y > playerPos.y && objectPos.y < playerPos.y + winSize.y)
		{
			//	如果对象在相机的范围内，就显示他
			m_Objects[i]->show();
		}
	}
}

void WaterBox::SDL2_Scene::shutdown()
{
}

SDL2_MaterialManage * WaterBox::SDL2_Scene::getMaterialManage()
{
	return m_MaterialManage;
}

void WaterBox::SDL2_Scene::addObject(SDL2_Object * object)
{
	m_Objects.push_back(object);
}

int WaterBox::SDL2_Scene::removeObject(SDL2_Object * object)
{
	for (int i=0; i<m_Objects.size(); ++i)
	{
		if (m_Objects[i]->getId() == object->getId())
		{
			m_Objects.erase(m_Objects.begin() + i);
			return 0;
		}
	}
	return -1;
}

int WaterBox::SDL2_Scene::setPlayer(SDL2_Player * player)
{
	if (m_Player == nullptr)
	{
		return -1;
	}
	m_Player = player;
	return 0;
}

SDL2_Player * WaterBox::SDL2_Scene::getPlayer()
{
	return m_Player;
}
void WaterBox::SDL2_Scene::save(std::string path)
{
	m_SceneXml->save(path);
	m_MaterialManage->save();
}
void WaterBox::SDL2_Scene::bindGui(SDL2_Gui *gui)
{
}

