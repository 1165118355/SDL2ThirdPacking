#include "SDL2_Combox.h"
#include <SDL2_Draw.h>
#include <SDL2_MaterialText.h>

using namespace WaterBox;

SDL2_Combox::SDL2_Combox()
{
	m_Value = 0;
	m_PreValue = 0;
	m_ChooseFlag = 0;
}

SDL2_Combox * WaterBox::SDL2_Combox::create()
{
	SDL2_Combox *combox = new SDL2_Combox();
	combox->setMaterialBox(SDL2_Material::create());
	combox->setMaterialItem(SDL2_Material::create());
	combox->setSize(Math::vec2(90, 30));
	combox->setPosition(Math::vec2(0, 0));
	return combox;
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

void WaterBox::SDL2_Combox::setMaterialBox(SDL2_Material * matBox)
{
	m_MaterialBox = matBox;
}

void WaterBox::SDL2_Combox::setMaterialItem(SDL2_Material * matItem)
{
	m_MaterialItem = matItem;
}

void WaterBox::SDL2_Combox::setPosition(Math::vec2 position)
{
	m_Position = position;
	m_MaterialBox->setPosition(position);
	Math::vec2 itemPos = position;
	itemPos.y += m_Size.y;
	m_MaterialItem->setPosition(itemPos);
}

Math::vec2 WaterBox::SDL2_Combox::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Combox::setSize(Math::vec2 size)
{
	m_Size = size;
	m_MaterialBox->setSize(size);
	m_MaterialItem->setSize(size);
	
}

Math::vec2 WaterBox::SDL2_Combox::getSize()
{
	return m_Size;
}

void SDL2_Combox::show()
{
	if (SDL2_Material::TYPE_PARENT == m_MaterialBox->getType())
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
				//m_MaterialText[i]->setSize(m_Size);
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

void SDL2_Combox::update(SDL_Event * event)
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
		y > m_Position.y && y < m_Position.y + m_Size.y*(m_ItemName.size()+1) + m_ItemName.size() && m_ChooseFlag)
	{
		Math::vec2 itemPos = m_Position;
		itemPos.y += m_Size.y;
		for (int i=0; i<m_ItemName.size(); ++i)
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
			itemPos.y += m_Size.y+1;
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
