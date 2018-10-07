#include "SDL2_Label.h"

using namespace WaterBox;

WaterBox::SDL2_Label::~SDL2_Label()
{
	delete m_MaterialText;
}

SDL2_Label * WaterBox::SDL2_Label::create(std::string text, Math::vec4 color)
{
	SDL2_Label *label = new SDL2_Label();
	label->setText(text, color);
	return label;
}

SDL2_Label * WaterBox::SDL2_Label::create(SDL2_Xml * xml)
{
	SDL2_Label *label = new SDL2_Label();
	label->analysisXml(xml);
	return label;
}

void WaterBox::SDL2_Label::show()
{
	m_MaterialText->show();
	return ;
}

std::vector<SDL2_Material*> WaterBox::SDL2_Label::getMaterials()
{
	std::vector<SDL2_Material*> materials;
	if (nullptr != m_MaterialText)
	{
		materials.push_back(m_MaterialText);
	}
	return materials;
}

void WaterBox::SDL2_Label::updateEventMouse(SDL_Event * event)
{
}

void WaterBox::SDL2_Label::updateEventKeyboard(SDL_Event * event)
{
}

void WaterBox::SDL2_Label::update(SDL_Event * event)
{
}

void WaterBox::SDL2_Label::materialModification()
{
	if (m_MaterialText != nullptr)
	{
		m_MaterialText->setPosition(getPosition());
	}
}

void WaterBox::SDL2_Label::setPosition(Math::vec2 position)
{
	m_Position = position;
}

Math::vec2 WaterBox::SDL2_Label::getPosition()
{
	return m_Position;
}

void WaterBox::SDL2_Label::setSize(Math::vec2 size)
{
	m_Size = size;
}

Math::vec2 WaterBox::SDL2_Label::getSize()
{
	return m_Size;
}

void WaterBox::SDL2_Label::setScaleText(double scale)
{
	m_TextScale = scale;
	this->setSize(m_OriginalTextSize * m_TextScale);
}

double WaterBox::SDL2_Label::getScaleText()
{
	return m_TextScale;
}

void WaterBox::SDL2_Label::setText(std::string text, Math::vec4 color)
{
	m_MaterialText->setText(text, color);
	m_OriginalTextSize = m_MaterialText->getSize();
	m_Text = text;
	this->setSize(m_OriginalTextSize * m_TextScale);
}

std::string WaterBox::SDL2_Label::getText()
{
	return m_Text;
}

int WaterBox::SDL2_Label::analysisXml(SDL2_Xml * xml)
{
	if (SDL2_Component::analysisXml(xml) == -1)
	{
		return -1;
	}
	if (xml->getTag("text") != "")
	{
		setText(xml->getTag("text"));
	}
	return 0;
}

SDL2_Label::SDL2_Label()
{
	m_Text = "";
	m_TextScale = 1.0;
	m_MaterialText = SDL2_MaterialText::create();
	m_ComponentType = COMPONENT_LABEL;
}
