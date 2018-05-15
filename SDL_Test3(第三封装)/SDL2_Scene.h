#ifndef _SDL2_SCENE_H_BOX
#define _SDL2_SCENE_H_BOX

#include <SDL2_Component.h>
#include <map>
/*
这个类用来管理场景，将一系列组件放入这个类，
*/

namespace WaterBox 
{
	class SDL2_Scene
	{
	public :
		void init();
		void update();
		void shutdown();
		void switchScene(SDL2_Scene *scene);
	private:
		
	};
}

#endif