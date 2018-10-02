/*
@ˮ������
*/
#include <SDL2/SDL.h>
#include <SDL2_Renderer.h>
#include <SDL2_Package.h>
#include <SDL2_Engine.h>
#include <SDL2_System.h>
#include "Test.h"

using namespace WaterBox;

int main(int argc, char *argv[])
{
	/*WaterBox::SDL2_Package *package = new WaterBox::SDL2_Package();
	package->init();*/
	Test *test = new Test(SDL2_System::get()->getSceneManager());
	SDL2_System::get()->getSceneManager()->switchScene(test);
	SDL2_Engine::get()->StartEngine();
	while (true)
	{
	}
	return 0;
}