#include "Test.h"
#include <iostream>
#include <SDL2_Gui.h>
#include <SDL2_Image.h>
#include <SDL2_Button.h>
#include <SDL2_Draw.h>
#include <SDL2_Label.h>
#include <SDL2_Slider.h>
#include <SDL2_HBox.h>
#include <SDL2_VBox.h>
#include <SDL2_CheckBox.h>
#include <SDL2_EditLine.h>
#include <SDL2_Combox.h>

Test::Test(SDL2_SceneManager *manager) :SDL2_Scene(manager)
{
}

SDL2_Slider *slider;
SDL2_Combox *combox;
void Test::init()
{
	//SDL2_Draw::drawRectangle(Math::vec2(0, 0), Math::vec2(500, 500), Math::vec4(30, 30, 30, 30));
	SDL2_Button *button = SDL2_Button::create();
	button->setPosition(Math::vec2(100, 100));
	SDL2_Image *image = SDL2_Image::create("Data/test.jpg");
	image->setSize(Math::vec2(50, 50));
	SDL2_Label *label = SDL2_Label::create("hello_world");
	label->setSize(Math::vec2(150, 30));
	slider = SDL2_Slider::create(250);
	SDL2_CheckBox *checkBox = SDL2_CheckBox::create();
	SDL2_VBox *hbox = SDL2_VBox::create();
	SDL2_EditLine *editLine = SDL2_EditLine::create();
	combox = SDL2_Combox::create();
	combox->addItem("hellllllllllo");
	combox->addItem("niao");
	combox->addItem("wawa");

	hbox->addComponent(image);
	hbox->addComponent(button);
	hbox->addComponent(label);
	hbox->addComponent(slider);
	hbox->addComponent(checkBox);
	hbox->addComponent(editLine);
	hbox->addComponent(combox);
	

	SDL2_Gui::get()->addComponent(hbox);
	std::cout << "this is Init test ..\n";
}

void Test::update()
{
	SDL2_Draw::drawRectangle(Math::vec2(0, 0), Math::vec2(800, 800), Math::vec4(0, 70, 0, 255));
	std::cout << "comBoxV="<< combox->getValue() <<std::endl;
}

void Test::shutdown()
{
}
