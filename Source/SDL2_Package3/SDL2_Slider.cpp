#include "SDL2_Slider.h"
#include <SDL2_MaterialPicture.h>
#include <SDL2_Draw.h>
#include <SDL2_Utils.h>
#include <iostream>
using namespace WaterBox;

SDL2_Slider * WaterBox::SDL2_Slider::create(int length)
{
	SDL2_Slider *slider = new SDL2_Slider();
	slider->setMaterialBack(SDL2_Material::create());
	slider->setMaterialCake(SDL2_Material::create());
	return slider;
}
SDL2_Slider * WaterBox::SDL2_Slider::create(int length, std::string backPath, std::string cakePath)
{
	SDL2_Slider *slider = new SDL2_Slider();
	slider->setMaterialBack(SDL2_MaterialPicture::create(backPath.c_str()));
	slider->setMaterialCake(SDL2_MaterialPicture::create(cakePath.c_str()));
	return slider;
}

SDL2_Slider * WaterBox::SDL2_Slider::create(SDL2_Xml * xml)
{
	SDL2_Slider *slider = new SDL2_Slider();
	slider->analysisXml(xml);
	return slider;
}

int WaterBox::SDL2_Slider::analysisXml(SDL2_Xml * xml)
{
	SDL2_Component::analysisXml(xml);
	if (xml->getTag("path_back") != "" && xml->getTag("path_back") != "null")
	{
		setMaterialBack(SDL2_MaterialPicture::create(xml->getTag("path_back")));
	}
	if (xml->getTag("path_cake") != "" && xml->getTag("path_cake") != "null")
	{
		setMaterialBack(SDL2_MaterialPicture::create(xml->getTag("path_cake")));
	}
	if (xml->getTag("value_max") != "")
	{
		setValueMax(SDL2_Utils::get()->StrToInt(xml->getTag("value_max")));
	}
	if (xml->getTag("length") != "")
	{
		setLength(SDL2_Utils::get()->StrToInt(xml->getTag("length")));
	}
	if (xml->getTag("value") != "")
	{
		setValue(SDL2_Utils::get()->StrToInt(xml->getTag("value")));
	}
	return 0;
}

void WaterBox::SDL2_Slider::show()
{
	if (SDL2_Material::TYPE_PARENT == m_MaterialBack->getType())
	{
		SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(30, 130, 100, 140));
		SDL2_Draw::drawRectangle(m_CakePos, m_CakeSize, Math::vec4(130, 30, 150, 140));
	}
	else
	{
		//	显示滑条
		m_MaterialBack->show();

		//	显示滑块，并定义位置
		m_MaterialCake->setPosition(m_CakePos);
		m_MaterialCake->setSize(m_CakeSize);
		m_MaterialCake->show();
	}
	return ;
}

enum MOUSE_STATE
{
	MOUSEDOWN=0,
	MOUSEUP
};

void WaterBox::SDL2_Slider::update(SDL_Event * event)
{
	int x = event->motion.x;						
	int y = event->motion.y;
	static MOUSE_STATE mouseState = MOUSEUP;	//	存储鼠标状态
	static int mouseClickPosX=0;				//	存储鼠标点击滑块时的位置
	
	if (SDL_MOUSEBUTTONDOWN == event->type)
	{
		if (x > m_CakePos.x && x < m_CakePos.x+m_CakeSize.x &&
			y > m_CakePos.y && y < m_CakePos.y+m_CakeSize.y)
		{
			mouseState = MOUSEDOWN;
		}
	}
	else if (SDL_MOUSEBUTTONUP == event->type)
	{
		mouseClickPosX = 0;
		mouseState = MOUSEUP;
	}

	//	如果鼠标还没有抬起滑块就跟随鼠标滑动
	if (mouseState == MOUSEDOWN)
	{
		if (0 == mouseClickPosX)
		{
			mouseClickPosX = x - m_CakePos.x;
		}
		else
		{
			m_CakePos.x = x - mouseClickPosX;
		}
	}

	//	限制滑块在滑条的范围内不出去
	if (m_CakePos.x < m_Position.x)
	{
		m_CakePos.x = m_Position.x;
	}
	if (m_CakePos.x > (m_Position.x + m_Size.x) - m_CakeSize.x)
	{
		m_CakePos.x = (m_Position.x + m_Size.x) - m_CakeSize.x;
	}

}

void WaterBox::SDL2_Slider::setPosition(Math::vec2 position)
{
	m_Position = position;
	m_CakePos.y = m_Position.y;
	m_MaterialBack->setPosition(position);
}

Math::vec2 WaterBox::SDL2_Slider::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Slider::setLength(int length)
{
	m_Length = length;
	setSize(Math::vec2(length, 10));
}

int WaterBox::SDL2_Slider::getLength()
{
	return m_Length;
}

void WaterBox::SDL2_Slider::setSize(Math::vec2 size)
{
	m_Size = size;
	m_MaterialBack->setSize(size);
}

Math::vec2 WaterBox::SDL2_Slider::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_Slider::setMaterialBack(SDL2_Material * matBack)
{
	m_MaterialBack = matBack;
}

SDL2_Material * WaterBox::SDL2_Slider::getMaterialBack()
{
	return m_MaterialBack;
}

void WaterBox::SDL2_Slider::setMaterialCake(SDL2_Material * matCake)
{
	m_MaterialCake = matCake;
}

SDL2_Material * WaterBox::SDL2_Slider::getMaterialCake()
{
	return m_MaterialCake;
}

void WaterBox::SDL2_Slider::setValue(int value)
{
	Math::clmp(value, 0, m_CakeValueMax);
	m_CakeValue = value;
	setPosition(Math::vec2(((m_Size.x - m_CakeSize.x)/ m_CakeValueMax)*value, getPosition().y));
}

int WaterBox::SDL2_Slider::getValue()
{
	m_CakeValue = (m_CakePos.x / (m_Size.x - m_CakeSize.x))*100;
	return m_CakeValue*(m_CakeValueMax/100);
}

void WaterBox::SDL2_Slider::setValueMax(int valueMax)
{
	m_CakeValueMax = valueMax;
}

int WaterBox::SDL2_Slider::getValueMax()
{
	return m_CakeValueMax;
}

WaterBox::SDL2_Slider::SDL2_Slider()
{
	m_ComponentType = COMPONENT_SLIDER;
	m_MaterialBack = SDL2_Material::create();
	m_MaterialCake = SDL2_Material::create();
	setPosition(Math::vec2(0, 0));
	setSize(Math::vec2(100, 10));
	m_CakeValueMax = 250;
	m_CakePos = Math::vec2(m_Size.x/2, m_Position.y);
	m_CakeSize = Math::vec2(m_Size.y * 2, m_Size.y);
}

