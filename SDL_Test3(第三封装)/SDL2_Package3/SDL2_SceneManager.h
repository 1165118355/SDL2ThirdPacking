///////////////////////////////
//	this class is a SceneManager in SDL2.
//	�����������������л�ʲô��
//	�����������ࡷ
//	2018��6��24�� 00:17:39
//	by	ˮ������

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
		///	brief	�л�������
		void switchScene(SDL2_Scene *scene);

		///	brief	��ȡ��ǰ����
		SDL2_Scene *getScene() { return mScene; }
	private:
		SDL2_Scene *mScene;
	};
}

#endif	//	!_SDL2_SCENEMANGER_H_BOX
