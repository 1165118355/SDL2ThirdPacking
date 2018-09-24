///////////////////////////////
//	this class is a Dirctory in SDL2.
//	������ȡ�û���Ҫ�õ���Ŀ¼
//	���ļ��Ի����ࡷ
//	2018��9��24�� 11:49:49
//	by	ˮ������

#include <SDL2_Dialog.h>
#include <SDL2_List.h>
#include <SDL2_Button.h>

namespace WaterBox
{
	class SDL2_DialogFile : public SDL2_Dialog
	{
	public:
		static SDL2_DialogFile *get();

		///	\brief	��ȡѡ����ļ���·��
		///
		///	\parm	title	���ڵı���
		///	\parm	path	�����·����ʼ��ʾ
		///	\parm	filter	��׺ɸѡ�����ֻ��ʾ��׺Ϊtxt���ļ��ʹ���"txt"�����ɸѡ�ö��ŷָ���Ĭ����ʾ�����ļ�
		///
		///	\return	����ѡ��·�����ļ�ȫ·��
		std::string getOpenFile(std::string title, std::string path = "./", std::string filter = "*");

		///	\brief	��ȡĿ¼·��(˵��ͬ��)
		std::string getDir(std::string title, std::string path = "./");

		///	\brief	��ʾ
		virtual void show();

		///	\brief	�����߼�
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