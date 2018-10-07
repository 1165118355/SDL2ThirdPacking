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
#include <SDL2_Dialog.h>
#include <SDl2_Dir.h>
#include <SDL2_List.h>
#include <SDL2_Event.h>
#include <SDL2_Console.h>
#include <SDL2_EditLine.h>
#include <SDL2_ObjectStatic.h>

Test::Test(SDL2_SceneManager *manager) :SDL2_Scene(manager)
{
}

SDL2_Slider *slider;
SDL2_Combox *combox;
SDL2_MaterialAnimal *animal;
SDL2_UserInterface *ui;
SDL2_Dialog *dialog;
SDL2_List *list;
SDL2_EditLine *editLine;
SDL2_ObjectStatic *backGround;
SDL2_Player *player;

SDL2_MaterialPicture *matPicture;
void Test::init()
{
	//dialog = SDL2_Dialog::create();
	this->load("defualt.world");
	player = SDL2_Player::create();
	setPlayer(player);
	//matPicture = SDL2_MaterialPicture::create("../Data/test.jpg");
	//matPicture->setName("backGround");
	//getMaterialManage()->addMaterial(matPicture, "default2");
	//backGround = SDL2_ObjectStatic::create(matPicture);
	ui = SDL2_UserInterface::create("uiTest.xml");
	//dialog->addComponent(ui->findComponent("hbox1"));
	SDL2_Gui::get()->addComponent(ui->findComponent("hbox1"));
	//SDL2_Gui::get()->addComponent(dialog);
	this->save();
	//SDL2_Dialog::SDL2_DialogBox(SDL2_Dialog::DIALOG_BOX_ERROR, "title", "save");
	char ch[10] = "helloA";
	for (int i=0; i<32; ++i)
	{
		SDL2_Console::get()->addLog(ch);
		ch[5]++;
	}
}

void Test::update()
{
	//	场景显示的底色
	SDL2_Draw::drawRectangle(Math::vec2(0, 0), Math::vec2(800, 800), Math::vec4(0, 70, 0, 255));
	
	//	相机控制
	if(SDL2_Event::get()->getKeyState(SDL_SCANCODE_UP))
	{ 
		Math::vec2 palyerPos = this->getPlayer()->getPosition();
		this->getPlayer()->setPosition(Math::vec2(palyerPos.x, palyerPos.y - 1));
	}
	if (SDL2_Event::get()->getKeyState(SDL_SCANCODE_DOWN))
	{
		Math::vec2 palyerPos = this->getPlayer()->getPosition();
		this->getPlayer()->setPosition(Math::vec2(palyerPos.x, palyerPos.y + 1));
	}
	if (SDL2_Event::get()->getKeyState(SDL_SCANCODE_RIGHT))
	{
		Math::vec2 palyerPos = this->getPlayer()->getPosition();
		this->getPlayer()->setPosition(Math::vec2(palyerPos.x + 1, palyerPos.y));
	}
	if (SDL2_Event::get()->getKeyState(SDL_SCANCODE_LEFT))
	{
		Math::vec2 palyerPos = this->getPlayer()->getPosition();
		this->getPlayer()->setPosition(Math::vec2(palyerPos.x - 1, palyerPos.y));
	}
	if (SDL2_Event::get()->getMouseWheelState() == SDL2_Event::SDL2_MOUSEWHEEL_UP)
	{
		this->getPlayer()->setDistance(this->getPlayer()->getDistance() + 0.01);
	}
	if (SDL2_Event::get()->getMouseWheelState() == SDL2_Event::SDL2_MOUSEWHEEL_DOWN)
	{
		this->getPlayer()->setDistance(this->getPlayer()->getDistance() - 0.01);
	}

}

void Test::shutdown()
{
}
