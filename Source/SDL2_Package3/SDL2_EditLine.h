///////////////////////////////
//	this class is a EditLine in SDL2.
//	����һ���༭��
//	���༭���ࡷ
//	2018��6��25�� 22:05:51
//	by	ˮ������

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <string>

namespace WaterBox
{
	class SDL2_EditLine :public SDL2_Component
	{
	public :
		///	brief	����һ���༭��
		static SDL2_EditLine *create();

		///	brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	brief	��ʾ����
		virtual void show();

		///	brief	�����¼�����
		virtual void update(SDL_Event *event);
	private:
		SDL2_EditLine(SDL2_Material *mat);

	private:
		SDL2_Material *m_Material;
		std::string m_Text;
		int m_CurSorPos;
		bool m_ChooseFlag;
	};
}