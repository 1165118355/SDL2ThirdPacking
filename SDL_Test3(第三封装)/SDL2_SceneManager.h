#ifndef _SDL2_SCENEMANAGER_BOX
#define _SDL2_SCENEMANAGER_BOX
#include <SDL2_Engine.h>
/*
这个类用来管理Scene，使用状态模式来管理
*/
namespace WaterBox
{
	class SDL2_SceneManager
	{
	public :
		friend class SDL2_Engine;
	private:

		SDL2_SceneManager();
	};
}
#endif