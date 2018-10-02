#include "SDL2_Combox.h"
#include <SDL2_Draw.h>
#include <SDL2_MaterialText.h>
#include <SDL2_System.h>

using namespace WaterBox;

SDL2_Combox::SDL2_Combox()
{
	m_Value = 0;
	m_PreValue = 0;
	m_ChooseFlag = 0; 
	m_MaterialBox = nullptr;
	m_MaterialItem = nullptr;
	m_ComponentType = COMPONENT_COMBOX;
}

SDL2_Combox * WaterBox::SDL2_Combox::create()
{
	SDL2_Combox *combox = new SDL2_Combox();
	combox->setSize(Math::vec2(90, 30));
	combox->setPosition(Math::vec2(0, 0));
	return combox;
}

SDL2_Combox * WaterBox::SDL2_Combox::create(SDL2_Xml * xml)
{
	SDL2_Combox *combox = new SDL2_Combox();
	combox->analysisXml(xml);
	return nullptr;
}

int WaterBox::SDL2_Combox::getValue()
{
	return m_Value;
}

void WaterBox::SDL2_Combox::addItem(std::string itmeName)
{
	m_ItemName.push_back(itmeName);
	m_MaterialText.push_back(SDL2_MaterialText::create(itmeName));
	for (int i = 0; i<m_MaterialText.size(); ++i)
	{
		m_MaterialText[i]->setCutSize(m_Size);
	}
}

int WaterBox::SDL2_Combox::setItemName(int number, std::string name)
{
	if (m_ItemName.size() < number)
	{
		return -1;
	}
	m_ItemName[number] = name;
	SDL2_MaterialText::cast(m_MaterialText[number])->setText(name);
	return 0;
}

std::string WaterBox::SDL2_Combox::getItemName(int number)
{
	if (m_ItemName.size() < number)
	{
		return "";
	}
	return m_ItemName[number];
}

void WaterBox::SDL2_Combox::setMaterialBox(SDL2_Material * matBox)
{
	m_MaterialBox = matBox;
}

SDL2_Material * WaterBox::SDL2_Combox::getMaterialBox()
{
	return m_MaterialBox;
}

void WaterBox::SDL2_Combox::setMaterialItem(SDL2_Material * matItem)
{
	m_MaterialItem = matItem;
}

SDL2_Material * WaterBox::SDL2_Combox::getMaterialItem()
{
	return m_MaterialItem;
}

void WaterBox::SDL2_Combox::setPosition(Math::vec2 position)
{
	m_Position = position;
}

Math::vec2 WaterBox::SDL2_Combox::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Combox::setSize(Math::vec2 size)
{
	m_Size = size;
	
}

Math::vec2 WaterBox::SDL2_Combox::getSize()
{
	return m_Size;
}

int WaterBox::SDL2_Combox::analysisXml(SDL2_Xml * xml)
{
	SDL2_MaterialManage *matManage = SDL2_System::get()->getSceneManager()->getScene()->getMaterialManage();
	if (-1 == SDL2_Component::analysisXml(xml))
	{
		return -1;
	}

	return 0;
}

void SDL2_Combox::show()
{
	if (nullptr == m_MaterialBox)
	{
		SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(60, 60, 60, 200));
		SDL2_Draw::drawRectangle(m_Position+2, m_Size-4, Math::vec4(150, 150, 150, 200));
		//SDL2_Draw::drawRectangle(m_Position + 2, m_Size - 4, Math::vec4(120, 120, 120, 200));
	}
	else
	{
		m_MaterialBox->show();
	}

	if (1 == m_ChooseFlag)
	{
		Math::vec2 itemPos = m_Position;
		itemPos.y += m_Size.y;
		for (int i=0; i<m_ItemName.size(); ++i)
		{
			if (SDL2_Material::TYPE_PARENT == m_MaterialBox->getType())
			{
				if (m_PreValue-1 == i)//		被鼠标指住的项会更黑点
				{
					SDL2_Draw::drawRectangle(itemPos, m_Size, Math::vec4(80, 80, 80, 200));
				}
				else
				{
					SDL2_Draw::drawRectangle(itemPos, m_Size, Math::vec4(100, 100, 100, 200));
				}
				m_MaterialText[i]->setPosition(itemPos);
				m_MaterialText[i]->show();
			}
			else
			{

			}
			itemPos.y += m_Size.y + 1;
		}
	}
	if (0 != m_Value)
	{
		m_MaterialText[m_Value-1]->setPosition(m_Position);
		m_MaterialText[m_Value-1]->show();
	}
}

std::vector<SDL2_Material*> WaterBox::SDL2_Combox::getMaterials()
{

	std::vector<SDL2_Material*> materials;
	if (nullptr != m_MaterialBox)
	{
		materials.push_back(m_MaterialBox);
	}
	if (nullptr != m_MaterialItem)
	{
		materials.push_back(m_MaterialItem);
	}
	for (int i=0; i<m_MaterialText.size(); ++i)
	{
		materials.push_back(m_MaterialText[i]);
	}
	return materials;
}

void WaterBox::SDL2_Combox::updateEventMouse(SDL_Event * event)
{
	int x = event->motion.x;
	int y = event->motion.y;

	if (x > m_Position.x && x < m_Position.x + m_Size.x &&
		y > m_Position.y && y < m_Position.y + m_Size.y)
	{
		if (SDL_MOUSEBUTTONDOWN == event->type)
		{
			m_ChooseFlag = !m_ChooseFlag;
		}
	}
	else if (x > m_Position.x && x<m_Position.x + m_Size.x &&
		y > m_Position.y && y < m_Position.y + m_Size.y*(m_ItemName.size() + 1) + m_ItemName.size() && m_ChooseFlag)
	{
		Math::vec2 itemPos = m_Position;
		itemPos.y += m_Size.y;
		for (int i = 0; i<m_ItemName.size(); ++i)
		{
			if (x > itemPos.x && x < itemPos.x + m_Size.x &&
				y > itemPos.y && y < itemPos.y + m_Size.y)
			{
				if (SDL_MOUSEBUTTONDOWN == event->type)
				{
					m_Value = i + 1;
					m_ChooseFlag = 0;
					return;
				}
				else
				{
					m_PreValue = i + 1;
				}
			}
			itemPos.y += m_Size.y + 1;
		}
	}
	else
	{
		if (SDL_MOUSEBUTTONDOWN == event->type || SDL_MOUSEBUTTONUP == event->type)
		{
			m_ChooseFlag = 0;
		}
	}
}

void WaterBox::SDL2_Combox::updateEventKeyboard(SDL_Event * event)
{
}

void SDL2_Combox::update(SDL_Event * event)
{
}

void WaterBox::SDL2_Combox::materialModification()
{

	if (m_MaterialBox != nullptr)
	{
		m_MaterialBox->setPosition(getPosition());
		m_MaterialBox->setSize(getSize());
	}

	if (m_MaterialItem != nullptr)
	{
		Math::vec2 itemPos = getPosition();
		itemPos.y += m_Size.y;
		m_MaterialItem->setPosition(itemPos);
		m_MaterialItem->setSize(getSize());
	}


}
