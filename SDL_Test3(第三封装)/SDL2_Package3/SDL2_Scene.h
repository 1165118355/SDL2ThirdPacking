///////////////////////////////
//	this class is a Scene in SDL2.
//	一个场景，以后也许需要很多场景
//	《场景类》
//	2018年6月24日 00:16:46
//	by	水华宝箱

#ifndef _SDL2_SCENE_H_BOX
#define _SDL2_SCENE_H_BOX
#include <SDL2_Component.h>
#include <SDL2_SceneManager.h>
#include <SDL2_Gui.h>
#include <map>

/*
这个类用来管理场景，将一系列组件放入这个类，
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
		*该场景与Gui进行绑定，在该场景被移除的时候卸载该Gui
		*/
		void bindGui(SDL2_Gui *gui);
	protected:
		SDL2_SceneManager *mSceneManager;
	private:
		SDL2_Gui *mGui;
	};
}

#endif