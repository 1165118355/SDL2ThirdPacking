#include "SDL2_Image.h"

WaterBox::SDL2_Image::SDL2_Image()
{
	type = COMPONENT_IMAGE;
}

WaterBox::SDL2_Image::SDL2_Image(std::string path)
{
	type = COMPONENT_IMAGE;
	m_Material = new SDL2_Material(path);
}

int WaterBox::SDL2_Image::show()
{
	if (NULL != m_Material)
	{
		m_Material->show();
	}
	return 0;
}
