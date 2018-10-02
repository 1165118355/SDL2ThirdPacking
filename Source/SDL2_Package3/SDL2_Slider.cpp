#include "SDL2_Slider.h"
#include <SDL2_MaterialPicture.h>
#include <SDL2_Draw.h>
#include <SDL2_Utils.h>
#include <SDL2_System.h>
#include <SDL2_Console.h>
#include <iostream>
using namespace WaterBox;

SDL2_Slider * WaterBox::SDL2_Slider::cast(SDL2_Component * componet)
{
	SDL2_Slider *slider = dynamic_cast<SDL2_Slider *>(componet);
	if (nullptr == slider)
	{
		return nullptr;
	}
	return slider;
}

SDL2_Slider * WaterBox::SDL2_Slider::create(int length)
{
	SDL2_Slider *slider = new SDL2_Slider();
	slider->setLength(length);
	return slider;
}
SDL2_Slider * WaterBox::SDL2_Slider::create(int length, std::string backPath, std::string cakePath)
{
	SDL2_MaterialManage *matManage = SDL2_System::get()->getSceneManager()->getScene()->getMaterialManage();
	SDL2_Slider *slider = new SDL2_Slider();
	slider->setMaterialBack(matManage->findMaterial(backPath.c_str()));
	slider->setMaterialCake(matManage->findMaterial(cakePath.c_str()));
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
	SDL2_MaterialManage *matManage = SDL2_System::get()->getSceneManager()->getScene()->getMaterialManage();
	SDL2_Component::analysisXml(xml);
	if (xml->getTag("slider_type") != "")
	{
		if (xml->getTag("slider_type") == "horizontal")
		{
			setSliderType(SLIDER_HORIZONTAL);
		}
		else if(xml->getTag("slider_type") == "vertical")
		{
			setSliderType(SLIDER_VERTICAL);
		}
		else
		{
			setSliderType(SLIDER_HORIZONTAL);
		}
	}
	if (xml->getTag("path_back") != "" && xml->getTag("path_back") != "null")
	{
		setMaterialBack(matManage->findMaterial(xml->getTag("path_back")));
	}
	if (xml->getTag("path_cake") != "" && xml->getTag("path_cake") != "null")
	{
		setMaterialBack(matManage->findMaterial(xml->getTag("path_cake")));
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
	if (nullptr == m_MaterialBack)
	{
		SDL2_Draw::drawRectangle(m_Position, m_Size, Math::vec4(30, 30, 30, 200));
		SDL2_Draw::drawRectangle(m_CakePos, m_CakeSize, Math::vec4(70, 70, 70, 240));
	}
	else
	{
		//	显示滑条
		m_MaterialBack->show();
		m_MaterialCake->show();
	}
	return ;
}

std::vector<SDL2_Material*> WaterBox::SDL2_Slider::getMaterials()
{
	std::vector<SDL2_Material*> materials;
	if (nullptr != m_MaterialBack)
	{
		materials.push_back(m_MaterialBack);
	}
	if (nullptr != m_MaterialCake)
	{
		materials.push_back(m_MaterialCake);
	}
	return materials;
}

void WaterBox::SDL2_Slider::updateEventMouse(SDL_Event * event)
{
	int x = event->motion.x;
	int y = event->motion.y;

	if (SDL_MOUSEBUTTONDOWN == event->type)
	{
		if (x > m_CakePos.x && x < m_CakePos.x + m_CakeSize.x &&
			y > m_CakePos.y && y < m_CakePos.y + m_CakeSize.y)
		{
			m_MouseState = MOUSEDOWN;
		}
	}
	else if (SDL_MOUSEBUTTONUP == event->type)
	{
		m_MouseClickPosX = 0;
		m_MouseClickPosY = 0;
		m_MouseState = MOUSEUP;
	}

	//	如果鼠标还没有抬起滑块就跟随鼠标滑动
	if (m_MouseState == MOUSEDOWN)
	{
		if (0 == m_MouseClickPosX && 0 == m_MouseClickPosY)
		{
			m_MouseClickPosX = x - m_CakePos.x;
			m_MouseClickPosY = y - m_CakePos.y;
		}
		else
		{
			m_CakePos.x = x - m_MouseClickPosX;
			m_CakePos.y = y - m_MouseClickPosY;
		}
	}
}

void WaterBox::SDL2_Slider::updateEventKeyboard(SDL_Event * event)
{
}

void WaterBox::SDL2_Slider::update(SDL_Event * event)
{
	//	限制滑块在滑条的范围内不出去
	if (m_CakePos.x < m_Position.x)
	{
		m_CakePos.x = m_Position.x;
	}
	if (m_CakePos.x > (m_Position.x + m_Size.x) - m_CakeSize.x)
	{
		m_CakePos.x = (m_Position.x + m_Size.x) - m_CakeSize.x;
	}
	
	if (m_CakePos.y < m_Position.y)
	{
		m_CakePos.y = m_Position.y;
	}
	if (m_CakePos.y >(m_Position.y + m_Size.y) - m_CakeSize.y)
	{
		m_CakePos.y = (m_Position.y + m_Size.y) - m_CakeSize.y;
	}

}

void WaterBox::SDL2_Slider::materialModification()
{
	if (m_MaterialBack != nullptr)
	{
		m_CakePos.y = m_Position.y;
		m_MaterialBack->setSize(getSize());
		m_MaterialBack->setPosition(getPosition());
	}
	if (m_MaterialCake != nullptr)
	{
		m_MaterialCake->setPosition(m_CakePos);
		m_MaterialCake->setSize(m_CakeSize);
	}
}

void WaterBox::SDL2_Slider::setPosition(Math::vec2 position)
{
	m_Position = position;
	setValue(m_CakeValueMax*m_CakeValue);
}

Math::vec2 WaterBox::SDL2_Slider::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Slider::setSliderType(SliderType type)
{
	m_SliderType = type;
	setLength(m_Length);
	if (m_SliderType == SLIDER_HORIZONTAL)
	{
		m_CakeSize = Math::vec2(m_Size.y * 2, m_Size.y);
	}
	else if (m_SliderType == SLIDER_VERTICAL)
	{
		m_CakeSize = Math::vec2(m_Size.x, m_Size.x * 2);
	}
	setValue(m_CakeValueMax/2);
}

SDL2_Slider::SliderType WaterBox::SDL2_Slider::getSliderType()
{
	return m_SliderType;
}

void WaterBox::SDL2_Slider::setLength(int length)
{
	m_Length = length;
	if (m_SliderType == SLIDER_HORIZONTAL)
	{
		setSize(Math::vec2(length, 10));
	}
	else if (m_SliderType == SLIDER_VERTICAL)
	{
		setSize(Math::vec2(10, length));
	}
}

int WaterBox::SDL2_Slider::getLength()
{
	return m_Length;
}

void WaterBox::SDL2_Slider::setSize(Math::vec2 size)
{
	m_Size = size;
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
	if (m_SliderType == SLIDER_HORIZONTAL)
	{
		m_CakePos = (Math::vec2((getPosition().x + (m_Size.x - m_CakeSize.x) / m_CakeValueMax)*value, getPosition().y));
	}
	else if (m_SliderType == SLIDER_VERTICAL)
	{
		m_CakePos = (Math::vec2(getPosition().x, getPosition().y + ((m_Size.y - m_CakeSize.y) / m_CakeValueMax) * value));
	}
}

int WaterBox::SDL2_Slider::getValue()
{
	if (m_SliderType == SLIDER_HORIZONTAL)
	{
		m_CakeValue = ((m_CakePos.x - m_Position.x) / (m_Size.x - m_CakeSize.x));
	}
	else if(m_SliderType == SLIDER_VERTICAL)
	{
		m_CakeValue = ((m_CakePos.y - m_Position.y) / (m_Size.y - m_CakeSize.y));
	}
	return m_CakeValue * m_CakeValueMax;
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
	m_MouseState = MOUSEUP;	//	存储鼠标状态
	m_MouseClickPosX = 0, m_MouseClickPosY = 0;				//	存储鼠标点击滑块时的位置
	m_ComponentType = COMPONENT_SLIDER;
	setSliderType(SLIDER_HORIZONTAL);
	m_MaterialBack = nullptr;
	m_MaterialCake = nullptr;
	setPosition(Math::vec2(0, 0));
	setLength(100);
	m_CakeValueMax = 1000;
	
}

