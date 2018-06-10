#include "Test.h"
#include <iostream>
#include <SDL2_Gui.h>
#include <SDL2_Image.h>
#include <SDL2_Button.h>

Test::Test(SDL2_SceneManager *manager) :SDL2_Scene(manager)
{
}

void Test::init()
{
	SDL2_Image *image = SDL2_Image::create();
	SDL2_Button *button = SDL2_Button::create();
	button->setPosition(Math::vec2(100, 100));
	SDL2_Gui::get()->addComponent(image);
	std::cout << "this is Init test ..\n";
}

void Test::update()
{

	std::cout << "this is Update test ..\n";
}

void Test::shutdown()
{
}
