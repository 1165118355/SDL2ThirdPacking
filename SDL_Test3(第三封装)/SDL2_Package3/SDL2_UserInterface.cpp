#include "SDL2_UserInterface.h"

using namespace WaterBox;

SDL2_UserInterface::SDL2_UserInterface()
{
}

int WaterBox::SDL2_UserInterface::componentTypeSwitch(std::string sType)
{
	if (sType == "button")
	{
		return SDL2_Component::COMPONENT_BUTTON;
	}
	else if (sType == "image")
	{
		return SDL2_Component::COMPONENT_IMAGE;
	}
	else if (sType == "checkbox")
	{
		return SDL2_Component::COMPONENT_CHECKBOX;
	}
	else if (sType == "label")
	{
		return SDL2_Component::COMPONENT_LABEL;
	}
	else if (sType == "slider")
	{
		return SDL2_Component::COMPONENT_SLIDER;
	}
	return 0;
}

void WaterBox::SDL2_UserInterface::createComponent(SDL2_Xml * xmlNode, SDL2_Component *parent)
{
	for (int i=0; i<xmlNode->getNumChild(); ++i)
	{
		SDL2_Xml *childXml = xmlNode->getChild(i);
		SDL2_Component *childComponent=nullptr;
		switch (componentTypeSwitch(childXml->getName()))
		{
		case SDL2_Component::COMPONENT_BUTTON:
			childComponent=SDL2_Button::create(childXml);
			break;
		case SDL2_Component::COMPONENT_LABEL:
			break;
		case SDL2_Component::COMPONENT_IMAGE:
			break;
		}
		if (parent != nullptr)
		{
			parent->addChild(childComponent);
		}
		m_Components.push_back(childComponent);
		createComponent(childXml, childComponent);
	}
}

SDL2_UserInterface * SDL2_UserInterface::create(std::string path)
{
	SDL2_UserInterface *ui = new SDL2_UserInterface();
	ui->load(path);
	return ui;
}

int SDL2_UserInterface::load(std::string path)
{
	SDL2_Xml *xml = SDL2_Xml::create();
	if (-1 == xml->load(path))
	{
		delete xml;
		return -1;
	}
	createComponent(xml, nullptr);

	//	m_Components

	return 0;
}

SDL2_Component * WaterBox::SDL2_UserInterface::findComponent(std::string name)
{
	for (int i=0; i<m_Components.size(); ++i)
	{
		if (m_Components[i]->getName() == name)
		{
			return m_Components[i];
		}
	}
	return nullptr;
}

SDL2_UserInterface::~SDL2_UserInterface()
{
}
