#include "SDL2_Image.h"

WaterBox::SDL2_Image::SDL2_Image()
{
	type = COMPONENT_IMAGE;
}

WaterBox::SDL2_Image::SDL2_Image(std::string path)
{
	type = COMPONENT_IMAGE;
	m_Material = new SDL2_Material(Math::vec2(100, 100), Math::vec4(100, 100, 100, 100));
}

int WaterBox::SDL2_Image::show()
{
	if (NULL != m_Material)
	{
		m_Material->show();
	}
	return 0;
}
