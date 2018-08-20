#include "SDL2_Button.h"
#include <SDL2_MaterialPicture.h>
#include <SDL2_MaterialText.h>
#include <SDL2_Draw.h>
#include <SDL2_Utils.h>
#include <iostream>

using namespace WaterBox;

SDL2_Button * WaterBox::SDL2_Button::cast(SDL2_Component * component)
{

	SDL2_Button *button = dynamic_cast<SDL2_Button *>(component);
	if (nullptr == button)
	{
		return nullptr;
	}
	return button;
}

SDL2_Button * WaterBox::SDL2_Button::create(std::string text/*="button"*/)
{
	SDL2_Material *mat1 = SDL2_Material::create();
	SDL2_Material *mat2 = SDL2_Material::create();
	SDL2_Material *matTex = SDL2_MaterialText::create(text);
	SDL2_Button *button = new SDL2_Button(mat1, mat2, matTex);
	return button;
}

SDL2_Button * WaterBox::SDL2_Button::create(std::string path1, std::string path2, std::string text/*="button"*/)
{
	SDL2_Material *mat1 = SDL2_MaterialPicture::create(path1);
	SDL2_Material *mat2 = SDL2_MaterialPicture::create(path2);
	SDL2_Material *matTex = SDL2_MaterialText::create(text);
	SDL2_Button *button = new SDL2_Button(mat1, mat2, matTex);
	return button;
}

SDL2_Button * WaterBox::SDL2_Button::create(SDL2_Xml * xml)
{
	SDL2_Button *button = SDL2_Button::create();
	button->analysisXml(xml);
	
	return button;
}

void WaterBox::SDL2_Button::setFlag(int flag)
{
	m_Flag = flag;
}

int WaterBox::SDL2_Button::getFlag()
{
	return m_Flag;
}

void WaterBox::SDL2_Button::setMaterialBefore(SDL2_Material * matBefore)
{
	m_MaterialBefore = matBefore;
}

SDL2_Material * WaterBox::SDL2_Button::getMaterialBefore()
{
	return m_MaterialBefore;
}

void WaterBox::SDL2_Button::setMaterialAfter(SDL2_Material * matAfter)
{
	m_MaterialAfter = matAfter;
}

SDL2_Material * WaterBox::SDL2_Button::getMaterialAfter()
{
	return m_MaterialAfter;
}

void WaterBox::SDL2_Button::setText(std::string text)
{
	SDL2_MaterialText::cast(m_MaterialText)->setText(text);
}

std::string WaterBox::SDL2_Button::getText()
{
	return SDL2_MaterialText::cast(m_MaterialText)->getText();
}

WaterBox::SDL2_Button::SDL2_Button(SDL2_Material *matBefor, SDL2_Material *matAfter, SDL2_Material *matText)
{
	m_MaterialAfter = matAfter;
	m_MaterialBefore = matBefor;
	m_MaterialText = matText;
	setPosition(Math::vec2(0, 0));
	setSize(Math::vec2(150, 50));
	m_Flag = 0;
	m_Callback = nullptr;
	m_ComponentType = COMPONENT_BUTTON;
}

void WaterBox::SDL2_Button::show()
{
	if (SDL2_Material::TYPE_PARENT == m_MaterialAfter->getType())
	{
		if (m_Flag)
		{
			SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(100, 100, 100, 110));
			
		}
		else
		{
			SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(180, 180, 180, 110));
		}
	}
	else
	{
		if (m_Flag)
		{
			m_MaterialAfter->show();
		}
		else
		{
			m_MaterialBefore->show();
		}
	}
	m_MaterialText->show();
	return ;
}

void WaterBox::SDL2_Button::update(SDL_Event * event)
{
	int x = event->motion.x;
	int y = event->motion.y;
	if (x>m_Position.x && x<m_Position.x+m_Size.x &&
		y>m_Position.y && y<m_Position.y+m_Size.y)
	{
		std::cout << "into"<< event->type <<std::endl;
		if (event->type == SDL_MOUSEBUTTONDOWN)
		{
			m_Flag = 1;
		}
		else if (event->type == SDL_MOUSEBUTTONUP)
		{
			if (NULL != m_Callback)
			{
				m_Callback(NULL);
			}
			m_Flag = 0;
		}
	}
	else
	{
		m_Flag = 0;
	}
}

int WaterBox::SDL2_Button::analysisXml(SDL2_Xml * xml)
{
	if (SDL2_Component::analysisXml(xml) == -1)
	{
		return -1;
	}
	if (xml->getTag("text") != "")
	{
		setText(xml->getTag("text"));
	}
	if (xml->getTag("name") != "")
	{
		setName(xml->getTag("name"));
	}
	if (xml->getTag("path_befor") != "")
	{
		setMaterialBefore(SDL2_MaterialPicture::create(xml->getTag("path_befor")));
	}
	if (xml->getTag("path_after") != "")
	{
		setMaterialAfter(SDL2_MaterialPicture::create(xml->getTag("path_after")));
	}
	return 0;
}

void WaterBox::SDL2_Button::setCallback(int *(*Callback)(void *ptr))
{
	m_Callback = Callback;
}

void WaterBox::SDL2_Button::setPosition(Math::vec2 position)
{
	m_Position = position;
	m_MaterialAfter->setPosition(position);
	m_MaterialBefore->setPosition(position);
	m_MaterialText->setPosition(position);
}

Math::vec2 WaterBox::SDL2_Button::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Button::setSize(Math::vec2 size)
{
	m_Size = size;
	m_MaterialAfter->setSize(size);
	m_MaterialBefore->setSize(size);
	m_MaterialText->setSize(size);
}

Math::vec2 WaterBox::SDL2_Button::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_Button::setTransparent(int transparent)
{
	m_MaterialBefore->setTransparent(transparent);
	m_MaterialAfter->setTransparent(transparent);
}

int WaterBox::SDL2_Button::getTransparent()
{
	return m_MaterialBefore->getTransparent();
}
