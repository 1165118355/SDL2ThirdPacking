#ifndef _SDL2_SCENEMANAGER_BOX
#define _SDL2_SCENEMANAGER_BOX
#include <SDL2_Engine.h>
#include <SDL2_Scene.h>
#include <string>
#include <map>
/*
这个类用来管理Scene，使用状态模式来管理
*/
namespace WaterBox
{
	class SDL2_SceneManager
	{
	public :
		SDL2_Scene *createScene(std::string name);
		SDL2_Scene *findSceneById(int id);
		SDL2_Scene *findSceneByName(std::string name);


		~SDL2_SceneManager() {}
	private:
		SDL2_SceneManager();
		map<int, std::string> scene;
	};
}
#endif