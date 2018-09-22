///////////////////////////////
//	this class is a CheckBox in SDL2.
//	����һ���༭��
//	����ѡ���ࡷ
//	2018��6��25�� 22:07:18
//	by	ˮ������

#pragma once
#include <SDL2_Component.h>
#include <SDL2_Material.h>

namespace WaterBox
{
	class SDL2_CheckBox :public SDL2_Component
	{
	public:
		static SDL2_CheckBox *create();
		//static SDL2_CheckBox *create(SDL2_Material *matBack, SDL2_Material *matIn);

		///	\brief	����xml�ļ�����һ��CheckBox
		static SDL2_CheckBox *create(SDL2_Xml *xml);

		///	brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPositioin();

		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	�����¼�
		virtual void update(SDL_Event *event);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	������ʾ
		virtual void show();

		void setValue(int value);
		int getValue();

		///	\brief	���ø�ѡ�򱳾��Ĳ���
		void setMaterialBack(SDL2_Material *matBack);
		SDL2_Material *getMateralBack();

		///	\brief	���ø�ѡ�������Ǹ���Ĳ��ʣ����Ǳ�ѡ���Ǹ� 
		void setMaterialIn(SDL2_Material *In);
		SDL2_Material *getMaterialIn();

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	��ȡ���е�material
		virtual std::vector<SDL2_Material *> getMaterials();

	private:
		SDL2_CheckBox();

	private:
		int m_Value;
		SDL2_Material *m_MaterialBack;			//	��ѡ�򱳾��Ĳ���	
		SDL2_Material *m_MaterialIn;			//	��ѡ�������Ǹ�ȷ�ϵĲ���ʲô�ġ���������˵ʲô������

	};

}