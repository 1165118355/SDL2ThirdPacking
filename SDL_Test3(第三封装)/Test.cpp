#include "Test.h"
#include <iostream>
#include <SDL2_Gui.h>
#include <SDL2_Image.h>
#include <SDL2_Button.h>
#include <SDL2_Draw.h>
#include <SDL2_Label.h>
#include <SDL2_Slider.h>

Test::Test(SDL2_SceneManager *manager) :SDL2_Scene(manager)
{
}

SDL2_Slider *slider;
void Test::init()
{
	//SDL2_Draw::drawRectangle(Math::vec2(0, 0), Math::vec2(500, 500), Math::vec4(30, 30, 30, 30));
	SDL2_Button *button = SDL2_Button::create();
	button->setPosition(Math::vec2(100, 100));
	SDL2_Image *image = SDL2_Image::create("Data/test.jpg");
	image->setSize(Math::vec2(500, 500));
	SDL2_Label *label = SDL2_Label::create("hello_world");
	label->setSize(Math::vec2(150, 30));
	slider = SDL2_Slider::create(250);

	SDL2_Gui::get()->addComponent(image);
	SDL2_Gui::get()->addComponent(button);
	SDL2_Gui::get()->addComponent(label);
	SDL2_Gui::get()->addComponent(slider);
	std::cout << "this is Init test ..\n";
}

void Test::update()
{
	SDL2_Draw::drawRectangle(Math::vec2(0, 0), Math::vec2(500, 500), Math::vec4(30, 30, 30, 30));
}

void Test::shutdown()
{
}
