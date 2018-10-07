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
#include <SDL2_Player.h>
#include <SDL2_Object.h>
#include <SDL2_MainWindow.h>
#include <SDL2_MaterialManage.h>
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
		virtual ~SDL2_Scene();

		///	\brief	初始化
		virtual void init()=0;

		///	\brief	更新
		virtual void update()=0;

		///	\brief	渲染
		void render();

		///	\brief	结束
		virtual void shutdown()=0;

		///	\brief	获取获取该场景的材质管理器
		SDL2_MaterialManage *getMaterialManage();

		///	brief	向场景添加一个对象
		void addObject(SDL2_Object *object);

		///	brief	移除场景中的一个对象
		int removeObject(SDL2_Object *object);

		///	brief	设置当前场景相机
		virtual int setPlayer(SDL2_Player *player);
		virtual SDL2_Player *getPlayer();

		///	\brief	保存和加载场景
		void save();
		int load(std::string path);

		///	\brief	设置名字
		void setName(std::string name);
		std::string getName();

		///	\brief	设置保存路径
		void setPath(std::string path);
		std::string getPath();

		///	\brief	寻找材质
		SDL2_Material *findMaterial(std::string name);

		/*
		*该场景与Gui进行绑定，在该场景被移除的时候卸载该Gui
		*/
		void bindGui(SDL2_Gui *gui);
	protected:
		SDL2_SceneManager *mSceneManager;
	private:
		SDL2_Gui *mGui;
		SDL2_Player *m_Player;
		SDL2_MaterialManage *m_MaterialManage;
		std::string m_Name;
		std::string m_Path;
		SDL2_Xml *m_SceneXml;
		std::vector<SDL2_Object *> m_Objects;
	};
}

#endif