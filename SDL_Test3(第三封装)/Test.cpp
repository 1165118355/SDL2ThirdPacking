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
#include <SDL2_MaterialAnimal.h>
#include <SDL2_UserInterface.h>

Test::Test(SDL2_SceneManager *manager) :SDL2_Scene(manager)
{
}

SDL2_Slider *slider;
SDL2_Combox *combox;
SDL2_MaterialAnimal *animal;
void Test::init()
{
	SDL2_UserInterface *ui = SDL2_UserInterface::create("uiTest.xml");
	SDL2_Gui::get()->addComponent(ui->findComponent("hbox1"));
}

void Test::update()
{
	SDL2_Draw::drawRectangle(Math::vec2(0, 0), Math::vec2(800, 800), Math::vec4(0, 70, 0, 255));

}

void Test::shutdown()
{
}
