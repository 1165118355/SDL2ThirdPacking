#include "SDL2_MaterialText.h"

using namespace WaterBox;

SDL2_MaterialText * WaterBox::SDL2_MaterialText::cast(SDL2_Material * material)
{
	SDL2_MaterialText *matText = dynamic_cast<SDL2_MaterialText *>(material);
	if (nullptr == matText)
	{
		return nullptr;
	}
	return matText;
}

SDL2_MaterialText * WaterBox::SDL2_MaterialText::create()
{
	SDL2_MaterialText *mat = new SDL2_MaterialText();
	return mat;
}

SDL2_MaterialText * WaterBox::SDL2_MaterialText::create(std::string text)
{
	SDL2_MaterialText *mat = new SDL2_MaterialText();
	mat->setText(text);
	return mat;
}
void WaterBox::SDL2_MaterialText::show()
{
	SDL_Rect rectAfter = { 0, 0, m_CutSize.x, m_CutSize.y };
	SDL_Rect rectBefore = { m_Position.x, m_Position.y, m_Size.x, m_Size.y };
	if (m_CutSize.x < m_Size.x && m_CutSize.x != 0 && 0 != m_CutSize.y)
	{
		rectBefore.w = rectAfter.w;
		rectBefore.h = rectAfter.h;
		SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Texture, &rectAfter, &rectBefore);
	}
	else
	{
		SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Texture, NULL, &rectBefore);
	}
}

void WaterBox::SDL2_MaterialText::setText(std::string text)
{
	if (nullptr != m_Texture)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}
	m_Text = text; 
	SDL_Color color = {0, 0, 0, 255};
	SDL_Surface *sur = TTF_RenderUTF8_Blended(SDL2_FontSystem::get()->findFont("SystemFont"), text.c_str(), color);
	if (nullptr != m_Texture)
	{
		SDL_DestroyTexture(m_Texture);
	}
	this->setSize(Math::vec2(sur->w, sur->h));
	m_Texture = SDL_CreateTextureFromSurface(SDL2_Renderer::get()->getRenderer(), sur);
	SDL_FreeSurface(sur);
}

std::string WaterBox::SDL2_MaterialText::getText()
{
	return m_Text;
}

int WaterBox::SDL2_MaterialText::load(SDL2_Xml * xml)
{
	return 0;
}

SDL2_Xml * WaterBox::SDL2_MaterialText::save()
{
	SDL2_Material::save();

	m_MaterialXml->setTag("text", m_Text.c_str());

	return m_MaterialXml;
}

void WaterBox::SDL2_MaterialText::reload()
{
	this->setText(m_Text);
}

SDL2_MaterialText::SDL2_MaterialText()
{
	m_Texture = nullptr;
	m_Text = "";
	m_CutSize = Math::vec2(0, 0);
	setPosition(Math::vec2(0, 0));
	m_Type = TYPE_TEXT;
}
