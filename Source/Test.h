#pragma once
#include <SDL2_Scene.h>

using namespace WaterBox;

class Test:public SDL2_Scene
{
public :
	Test(SDL2_SceneManager *manager);
	virtual void init();
	virtual void update();
	virtual void shutdown();

	void showLog(std::string log, std::string log2, std::string log3);
private:

};