#include "SDL2_Scene.h"

using namespace WaterBox;

WaterBox::SDL2_Scene::SDL2_Scene(SDL2_SceneManager * manager)
{
	mGui = nullptr;
	m_Player = nullptr;
	m_Name = "defualt";
	m_Path = "";
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
			//	�������������ķ�Χ�ڣ�����ʾ��
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
void WaterBox::SDL2_Scene::save()
{
	m_SceneXml->clear(1);
	SDL2_Xml *materialLibs = SDL2_Xml::create();
	m_SceneXml->setName("scene");

	materialLibs->setName("material_libs");
	for (int i=0; i<m_MaterialManage->getNumMaterialLibs(); ++i)
	{
		SDL2_Xml *childXml = SDL2_Xml::create();
		childXml->setName("materials");
		childXml->setTag("name", m_MaterialManage->getMaterialLibName(i));
		childXml->setTag("path", m_MaterialManage->getMaterialLibPath(i));
		materialLibs->addChild(childXml);
	}
	m_SceneXml->addChild(materialLibs);

	m_SceneXml->save(m_Path + m_Name + ".world");
	m_MaterialManage->save();
}
int WaterBox::SDL2_Scene::load(std::string path)
{
	m_SceneXml->clear(1);
	if (-1 == m_SceneXml->load(path))
	{
		return -1;
	}
	for (int i=0; i<m_SceneXml->getNumChild(); ++i)
	{
		SDL2_Xml *sceneChild = m_SceneXml->getChild(i);
		if (std::string("material_libs") == sceneChild->getName())
		{
			for (int m=0; m<sceneChild->getNumChild(); ++m)
			{
				SDL2_Xml *matChild = sceneChild->getChild(m);
				if (std::string("materials") == matChild->getName())
				{
					m_MaterialManage->load(std::string(matChild->getTag("path")) + std::string(matChild->getTag("name")) + ".mat");
				}
			}
		}
	}
	return 0;
}

void WaterBox::SDL2_Scene::setName(std::string name)
{
	m_Name = name;
}

std::string WaterBox::SDL2_Scene::getName()
{
	return m_Name;
}

void WaterBox::SDL2_Scene::setPath(std::string path)
{
	m_Path = path;
}

std::string WaterBox::SDL2_Scene::getPath()
{
	return m_Path;
}

void WaterBox::SDL2_Scene::bindGui(SDL2_Gui *gui)
{
}

