///////////////////////////////
//	this class is a Button in SDL2 
//	��ť��
//	2018��6��9�� 08:18:50
//	by	ˮ������

#pragma once
#include <string>
#include <SDL2_Component.h>
#include <SDL2_Material.h>
#include <SDL2_Xml.h>


namespace WaterBox
{
	class SDL2_Button :public SDL2_Component
	{
	public:
		///	\brief ������ǿ��ת����Button
		static SDL2_Button *cast(SDL2_Component *componet);

		///	\brief ����һ��Button����ɫ�ʵģ�
		static SDL2_Button *create(std::string text="button");

		///	\brief ����һ��Button ��ͼƬ��
		static SDL2_Button *create(std::string path1, std::string path2, std::string text = "button");

		///	\brief	ͨ��һ��xml����һ��button
		static SDL2_Button *create(SDL2_Xml *xml);

		///	\brief ��ʾ��Gui���
		virtual void show();

		///	\brief	����
		virtual void update(SDL_Event *event);

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	���ûص�����
		void setCallback(int *(*Callback)(void *ptr));

		///	\brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	\brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	\brief	����͸����
		virtual void setTransparent(int transparent);
		virtual int getTransparent();

		///	\brief ���ð�ť�Ƿ񱻰���
		void setFlag(int flag);
		int getFlag();

		///	\breif	���ð�ť����֮ǰ�Ĳ���
		void setMaterialBefore(SDL2_Material *matBefore);
		SDL2_Material *getMaterialBefore();

		///	\breif	���ð�ť����֮��Ĳ���
		void setMaterialAfter(SDL2_Material *matAfter);
		SDL2_Material *getMaterialAfter();

		///	\brief	���ð�ť�������
		void setText(std::string text);
		std::string getText();
	private:
		SDL2_Button(SDL2_Material *matBefor, SDL2_Material *matAfter, SDL2_Material *matText);
	private:
		int m_Flag;
		int *(*m_Callback)(void *ptr);
		SDL2_Material *m_MaterialBefore;
		SDL2_Material *m_MaterialAfter;
		SDL2_Material *m_MaterialText;
	};
}

/*
xml˵��
	tag˵��
		path_befor="null"		//	���֮ǰ��ͼƬ·��	
		path_after="null"		//	���֮���ͼƬ·��
	name˵��
		<button>				//	���־��������
*/