///////////////////////////////
//	this class is a Label in SDL2.
//	��ǩ����Ҫ����ʾ����
//	����ǩ�ࡷ
//	2018��6��25�� 22:05:19
//	by	ˮ������
#ifndef _SDL2_LABEL_H_BOX
#define _SDL2_LABEL_H_BOX

#include <string>
#include <SDL2_MaterialText.h>
#include <SDL2_Component.h>
#include <SDL2_Xml.h>

namespace WaterBox 
{
	class SDL2_Label: public SDL2_Component
	{
	public:
		///	\brief	��ͨ�Ĵ���һ��label
		static SDL2_Label *create(std::string text="label");

		///	\brief	ͨ��xml��Ϣ����һ��Label
		static SDL2_Label *create(SDL2_Xml *xml);

		///	brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2  getPosition();

		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		/// \brief	�����ı�
		void setText(std::string text);
		std::string getText();
		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);


		///	brief	�����¼�
		virtual void update(SDL_Event *event);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	��ʾ
		virtual void show();

		///	\brief	��ȡ���е�material
		virtual std::vector<SDL2_Material *> getMaterials();

	private:
		SDL2_Label();
	private:
		std::string m_Text;					//	Ҫ��ʾ���ı�
		SDL2_MaterialText *m_MaterialText;		//	�ı���Material

	};
}
#endif // !_SDL2_LABEL_H_BOX


/*
xml˵��
	tag˵��
		text=""			//	��ʾ������		������ͼƬ�����Ƕ�����
	name˵��
	<label>				//	���־��������
*/