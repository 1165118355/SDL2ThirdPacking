#include "SDL2_List.h"
#include <SDL2_Draw.h>
#include <SDL2_MaterialManage.h>

using namespace WaterBox;

void WaterBox::SDL2_List::setMaterialBack(SDL2_Material * material)
{
	m_MaterialBack = material;
}

void WaterBox::SDL2_List::addItem(std::string name)
{
	SDL2_ListItem *item = SDL2_ListItem::create(name);
	addItem(item);
}

void WaterBox::SDL2_List::addItem(SDL2_ListItem * item)
{
	m_ListItems.push_back(item);
	m_ListBox->addComponent(item);
	item->setList(this);
}

void WaterBox::SDL2_List::removeItem()
{
}

SDL2_List::SDL2_List()
{
	m_MaterialBack = nullptr;
	m_CurrentTopItem = 0;
	m_CurrentItem = 0;
	this->setSize(Math::vec2(100, 250));
	m_ComponentType = COMPONENT_LIST;
	m_ListBox = SDL2_VBox::create();
	this->addChild(m_ListBox);
}

void WaterBox::SDL2_List::selectItem(int num)
{
	for (int i=0; i<m_ListItems.size(); ++i)
	{
		if (num != i)
		{
			m_ListItems[i]->setSelected(SDL2_ListItem::LISTITEM_RELEASE);
		}
	}
	m_CurrentItem = num;
}

void WaterBox::SDL2_List::clear()
{
	m_CurrentTopItem = 0;
	m_CurrentItem = 0;
	m_ListBox->clear();
	m_ListItems.clear();

}


SDL2_List::~SDL2_List()
{
	delete m_ListBox;
}

SDL2_List * WaterBox::SDL2_List::create()
{
	SDL2_List *list = new SDL2_List();
	return list;
}

int WaterBox::SDL2_List::analysisXml(SDL2_Xml * xml)
{
	SDL2_MaterialManage *materialManage = SDL2_Engine::get()->getSceneManager()->getScene()->getMaterialManage();
	if (SDL2_Component::analysisXml(xml) == -1)
	{
		return -1;
	}
	if (xml->getTag("material_back") != "")
	{
		this->setMaterialBack(materialManage->findMaterial(xml->getTag("material_back")));
	}
	return 0;
}

void WaterBox::SDL2_List::update(SDL_Event * event)
{
	for (int i=0; i<m_ListItems.size(); ++i)
	{
		m_ListItems[i]->setIndex(i);
	}
	m_ListBox->update(event);
}

void WaterBox::SDL2_List::materialModification()
{
	if (nullptr != m_MaterialBack)
	{
		m_MaterialBack->setPosition(this->getPosition());
		m_MaterialBack->setSize(this->getSize());
	}
	m_ListBox->materialModification();
}

void WaterBox::SDL2_List::show()
{
	if (nullptr == m_MaterialBack)
	{
		SDL2_Draw::drawRectangle(this->getPosition(), this->getSize(), Math::vec4(200, 200, 200, 200));
	}
	else
	{
		m_MaterialBack->show();
	}

	//	显示子项(并且限制能看到子项的数量)
	int length = 0;
	for (int i=0; i<m_ListItems.size(); ++i)
	{
		if (i >= m_CurrentTopItem)
		{
			Math::vec2 itemSize = m_ListItems[i]->getSize();
			m_ListItems[i]->show();
			length += itemSize.y;
		}
		if (length >= this->getSize().y)
		{
			break;
		}
	}
}

std::vector<SDL2_Material*> WaterBox::SDL2_List::getMaterials()
{
	std::vector<SDL2_Material*> materials;
	materials.push_back(m_MaterialBack);
	return materials;
}
