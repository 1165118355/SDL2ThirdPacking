#include "Test.h"
#include <iostream>
#include <SDL2_Gui.h>
#include <SDL2_Image.h>

Test::Test(SDL2_SceneManager *manager) :SDL2_Scene(manager)
{
}

void Test::init()
{
	SDL2_Image *image = new SDL2_Image("E:/test.png");
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
