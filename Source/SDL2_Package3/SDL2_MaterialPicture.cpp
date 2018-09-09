#include "SDL2_MaterialPicture.h"

using namespace WaterBox;

SDL2_MaterialPicture * WaterBox::SDL2_MaterialPicture::cast(SDL2_Material * mat)
{
	SDL2_MaterialPicture * matPic = dynamic_cast<SDL2_MaterialPicture *>(mat);
	return matPic;
}

SDL2_MaterialPicture * WaterBox::SDL2_MaterialPicture::create()
{
	SDL2_MaterialPicture *mat = new SDL2_MaterialPicture();
	return mat;
}

SDL2_MaterialPicture * WaterBox::SDL2_MaterialPicture::create(std::string path)
{
	SDL2_MaterialPicture *mat = new SDL2_MaterialPicture();
	mat->setPath(path);
	return mat;
}

void WaterBox::SDL2_MaterialPicture::show()
{
	SDL_Rect cutRect = {m_CutPosition.x, m_CutPosition.y, m_CutSize.x, m_CutSize.y};
	SDL_Rect rect = {m_Position.x, m_Position.y, m_Size.x, m_Size.y};
	if (cutRect.x+ cutRect.y+ cutRect.w+ cutRect.h == 0)
	{

		SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Texture, NULL, &rect);
	}
	else
	{
		SDL_RenderCopy(SDL2_Renderer::get()->getRenderer(), m_Texture, &cutRect, &rect);
	}
}

void WaterBox::SDL2_MaterialPicture::setTransparent(int transparent)
{
	if (-1 == SDL_SetTextureAlphaMod(m_Texture, transparent))//					设置纹理透明度
	{
		printf("error setTransparent()\n");
	}
}

int WaterBox::SDL2_MaterialPicture::getTransparent()
{
	Uint8 transparent;
	SDL_GetTextureAlphaMod(m_Texture, &transparent);//				获取纹理透明度（第二个参数是透明度）
	return transparent;
}

int WaterBox::SDL2_MaterialPicture::setPath(std::string path)
{
	SDL_Surface *sur = IMG_Load(path.c_str());
	if (nullptr == sur)
	{
		return -1;
	}
	SDL_Texture *tex = SDL_CreateTextureFromSurface(SDL2_Renderer::get()->getRenderer(), sur);
	if (nullptr == tex)
	{
		return -1;
	}
	setSize(Math::vec2(sur->w, sur->h));
	m_Path = path;
	m_Texture = tex;
	SDL_FreeSurface(sur);
	return 0;
}

std::string WaterBox::SDL2_MaterialPicture::getPath()
{
	return m_Path;
}

int WaterBox::SDL2_MaterialPicture::load(SDL2_Xml * xml)
{
	SDL2_Material::load(xml);
	if (xml->getTag("picture_path") != "")
	{
		setPath(xml->getTag("picture_path"));
	}
	/*if ()
	{
	}*/
	return 0;
}

SDL2_Xml * WaterBox::SDL2_MaterialPicture::save()
{
	SDL2_Material::save();
	m_MaterialXml->setTag("type", "picture");
	m_MaterialXml->setTag("picture_path", m_Path.c_str());
	return m_MaterialXml;
}

WaterBox::SDL2_MaterialPicture::SDL2_MaterialPicture()
{
	m_Texture = nullptr;
	m_Type = TYPE_PICTURE;
}

