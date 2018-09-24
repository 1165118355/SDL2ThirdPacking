///////////////////////////////
//	this class is a Dirctory in SDL2.
//	用来获取用户想要拿到的目录
//	《文件对话框类》
//	2018年9月24日 11:49:49
//	by	水华宝箱

#include <SDL2_Dialog.h>
#include <SDL2_List.h>
#include <SDL2_Button.h>

namespace WaterBox
{
	class SDL2_DialogFile : public SDL2_Dialog
	{
	public:
		static SDL2_DialogFile *get();

		///	\brief	获取选择的文件的路径
		///
		///	\parm	title	窗口的标题
		///	\parm	path	从这个路径开始显示
		///	\parm	filter	后缀筛选，如果只显示后缀为txt的文件就传入"txt"，多个筛选用逗号分隔，默认显示所有文件
		///
		///	\return	返回选中路径的文件全路径
		std::string getOpenFile(std::string title, std::string path = "./", std::string filter = "*");

		///	\brief	获取目录路径(说明同上)
		std::string getDir(std::string title, std::string path = "./");

		///	\brief	显示
		virtual void show();

		///	\brief	更新逻辑
		virtual void update(SDL_Event *event);

	private:
		~SDL2_DialogFile();
		SDL2_DialogFile();
	private:
		static SDL2_DialogFile *m_Instance;
		bool m_Enable;
		SDL2_List *m_List;
		SDL2_Button *m_ButtonConfirm;
		SDL2_Button *m_ButtonCancel;
	};
}