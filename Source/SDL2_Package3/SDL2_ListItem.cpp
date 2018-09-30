#include "SDL2_ListItem.h"
#include <SDL2_Draw.h>

using namespace WaterBox;

int WaterBox::SDL2_ListItem::getIndex()
{
	return m_Index;
}

SDL2_ListItem::SDL2_ListItem()
{
	m_List = nullptr;
	m_Lable == nullptr;
	m_ComponentType;
	this->setSize(Math::vec2(100, 30));
}

SDL2_ListItem::~SDL2_ListItem()
{
	if (nullptr != m_Lable)
	{
		delete m_Lable;
	}
}

void WaterBox::SDL2_ListItem::materialModification()
{
	if (nullptr != m_MaterialBack)
	{
		m_MaterialBack->setPosition(this->getPosition());
		m_MaterialBack->setSize(this->getSize());
	}
	if (nullptr != m_Lable)
	{
		m_Lable->setPosition(this->getPosition());
		//m_Lable->setAlign(ALIGN_CENTER | ALIGN_LEFT);
		m_Lable->materialModification();
	}
}

void WaterBox::SDL2_ListItem::show()
{
	if (nullptr == m_MaterialBack)
	{
		switch (m_Select)
		{
		case LISTITEM_RELEASE:
			m_ColorBackDefault = Math::vec4(180, 180, 180, 255);
			break;
		case LISTITEM_SELECTED:
			m_ColorBackDefault = Math::vec4(130, 160, 240, 255);
			break;
		case LISTITEM_HOVER:
			m_ColorBackDefault = Math::vec4(140, 140, 140, 180);
			break;
		}
		SDL2_Draw::drawRectangle(this->getPosition(), this->getSize(), m_ColorBackDefault);
	}
	else
	{
		m_MaterialBack->show();
	}
	if (nullptr != m_Lable)
	{
		m_Lable->show();
	}
}

std::vector<SDL2_Material*> WaterBox::SDL2_ListItem::getMaterials()
{
	std::vector<SDL2_Material*>materials;
	if (m_MaterialBack)
	{
		materials.push_back(m_MaterialBack);
	}
	if (m_Lable)
	{
		for (int i=0; i<m_Lable->getMaterials().size(); ++i)
		{
			materials.push_back(m_Lable->getMaterials()[i]);
		}
	}
	return materials;
}

void WaterBox::SDL2_ListItem::setText(std::string text)
{
	if (nullptr == m_Lable)
	{
		m_Lable = SDL2_Label::create(text);
		m_Lable->setParent(this);
		return;
	}
	m_Lable->setText(text);
}

std::string WaterBox::SDL2_ListItem::getText()
{
	if (nullptr == m_Lable)
	{
		return std::string();
	}
	return m_Lable->getText();
}

void WaterBox::SDL2_ListItem::setMaterialBack(SDL2_Material * mat)
{
	m_MaterialBack = mat;
}

SDL2_Material * WaterBox::SDL2_ListItem::getMaterialBack()
{
	return m_MaterialBack;
}

void WaterBox::SDL2_ListItem::setSelected(ListItemState selct)
{
	m_Select = selct;
}

SDL2_ListItem::ListItemState WaterBox::SDL2_ListItem::getSelected()
{
	return m_Select;
}

SDL2_ListItem * WaterBox::SDL2_ListItem::create(std::string name)
{
	SDL2_ListItem *item = new SDL2_ListItem();
	if (!name.empty())
	{
		item->setText(name);
	}
	return item;
}

SDL2_ListItem * WaterBox::SDL2_ListItem::create(SDL2_Xml * xml)
{
	SDL2_ListItem *item = new SDL2_ListItem();
	item->analysisXml(xml);
	return item;
}

int WaterBox::SDL2_ListItem::analysisXml(SDL2_Xml * xml)
{
	SDL2_MaterialManage *materialManage = SDL2_Engine::get()->getSceneManager()->getScene()->getMaterialManage();
	if (SDL2_Component::analysisXml(xml) == -1)
	{
		return -1;
	}
	if (xml->getTag("text") != "")
	{
		this->setText(xml->getTag("text"));
	}
	if (xml->getTag("material_back") != "")
	{
		this->setMaterialBack(materialManage->findMaterial(xml->getTag("material_back")));
	}
	return 0;
}

void WaterBox::SDL2_ListItem::update(SDL_Event * event)
{
	if (LISTITEM_SELECTED == m_Select)
	{
		return;
	}
	int x = event->motion.x;
	int y = event->motion.y;
	if (x > m_Position.x && x < m_Position.x + m_Size.x &&
		y > m_Position.y && y < m_Position.y + m_Size.y)
	{
		m_Select = LISTITEM_HOVER;
		if (event->type == SDL_MOUSEBUTTONDOWN)
		{
			if (nullptr != m_List)
			{
				m_List->selectItem(m_Index);
			}
			m_Select = LISTITEM_SELECTED;
		}
	}
	else
	{
		if (m_Select == LISTITEM_HOVER)
		{
			m_Select = LISTITEM_RELEASE;
		}
	}
}

SDL2_List *WaterBox::SDL2_ListItem::getList()
{
	return m_List;
}

void WaterBox::SDL2_ListItem::setList(SDL2_List * list)
{
	m_List = list;
}

void WaterBox::SDL2_ListItem::setIndex(int index)
{
	m_Index = index;
}
