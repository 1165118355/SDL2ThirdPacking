
#ifndef _SDL2_SCENEMANAGER_H_BOX
#define _SDL2_SCENEMANAGER_H_BOX
#include <SDL2_Scene.h>
#include <string>
#include <map>

/*
�������������Scene��ʹ��״̬ģʽ������
*/
namespace WaterBox
{
	class SDL2_Scene;
	class SDL2_SceneManager
	{
	public :
		SDL2_SceneManager();
		~SDL2_SceneManager() {}
	/*	SDL2_Scene *findSceneById(int id);
		SDL2_Scene *findSceneByName(std::string name);
*/
		void switchScene(SDL2_Scene *scene);
		SDL2_Scene *getScene() { return mScene; }
	private:
		SDL2_Scene *mScene;
	};
}

#endif	//	!_SDL2_SCENEMANGER_H_BOX
