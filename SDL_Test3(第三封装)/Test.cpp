#include "Test.h"
#include <iostream>

Test::Test(SDL2_SceneManager *manager) :SDL2_Scene(manager)
{
}

void Test::init()
{
	std::cout << "this is Init test ..\n";
}

void Test::update()
{

	std::cout << "this is Update test ..\n";
}

void Test::shutdown()
{
}
