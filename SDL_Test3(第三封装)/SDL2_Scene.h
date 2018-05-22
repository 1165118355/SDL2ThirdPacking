
#ifndef _SDL2_SCENE_H_BOX
#define _SDL2_SCENE_H_BOX
#include <SDL2_Component.h>
#include <SDL2_SceneManager.h>
#include <SDL2_Gui.h>
#include <map>

/*
�������������������һϵ�������������࣬
*/

namespace WaterBox 
{
	class SDL2_SceneManager;
	class SDL2_Scene
	{
	public :
		SDL2_Scene(SDL2_SceneManager *manager);
		virtual void init()=0;
		virtual void update()=0;
		virtual void shutdown()=0;

		/*
		*�ó�����Gui���а󶨣��ڸó������Ƴ���ʱ��ж�ظ�Gui
		*/
		void bindGui(SDL2_Gui *gui);
	protected:
		SDL2_SceneManager *mSceneManager;
	private:
		SDL2_Gui *mGui;
	};
}

#endif