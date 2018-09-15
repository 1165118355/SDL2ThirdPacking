///////////////////////////////
//	this class is a Scene in SDL2.
//	һ���������Ժ�Ҳ����Ҫ�ܶೡ��
//	�������ࡷ
//	2018��6��24�� 00:16:46
//	by	ˮ������

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
�������������������һϵ�������������࣬
*/

namespace WaterBox 
{
	class SDL2_SceneManager;
	class SDL2_Scene
	{
	public :
		SDL2_Scene(SDL2_SceneManager *manager);
		virtual ~SDL2_Scene();

		///	\brief	��ʼ��
		virtual void init()=0;

		///	\brief	����
		virtual void update()=0;

		///	\brief	��Ⱦ
		void render();

		///	\brief	����
		virtual void shutdown()=0;

		///	\brief	��ȡ��ȡ�ó����Ĳ��ʹ�����
		SDL2_MaterialManage *getMaterialManage();

		///	brief	�򳡾����һ������
		void addObject(SDL2_Object *object);

		///	brief	�Ƴ������е�һ������
		int removeObject(SDL2_Object *object);

		///	brief	���õ�ǰ�������
		virtual int setPlayer(SDL2_Player *player);
		virtual SDL2_Player *getPlayer();

		///	\brief	����ͼ��س���
		void save();
		int load(std::string path);

		///	\brief	��������
		void setName(std::string name);
		std::string getName();

		///	\brief	���ñ���·��
		void setPath(std::string path);
		std::string getPath();

		/*
		*�ó�����Gui���а󶨣��ڸó������Ƴ���ʱ��ж�ظ�Gui
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