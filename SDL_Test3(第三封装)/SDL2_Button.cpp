#include "SDL2_Button.h"

using namespace WaterBox;

SDL2_Button * WaterBox::SDL2_Button::create()
{
	SDL2_Material *mat1 = SDL2_Material::create();
	SDL2_Material *mat2 = SDL2_Material::create();
	SDL2_Button *button = new SDL2_Button(mat1, mat2);
	return button;
}

SDL2_Button * WaterBox::SDL2_Button::create(std::string path1, std::string path2)
{
	SDL2_Material *mat1 = SDL2_Material::create(path1);
	SDL2_Material *mat2 = SDL2_Material::create(path2);
	SDL2_Button *button = new SDL2_Button(mat1, mat2);
	return button;
}

WaterBox::SDL2_Button::SDL2_Button(SDL2_Material *matBefor, SDL2_Material *matAfter)
{
	m_Flag = 0;
}

int WaterBox::SDL2_Button::show()
{
	return 0;
}

void WaterBox::SDL2_Button::setCallback(int *(*Callback)(void *ptr))
{
	m_Callback = Callback;
}
