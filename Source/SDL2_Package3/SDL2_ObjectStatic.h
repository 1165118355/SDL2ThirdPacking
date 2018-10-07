#ifndef _SDL2_OBJECTSTATIC_H_BOX
#define _SDL2_OBJECTSTATIC_H_BOX

#include <SDL2_Object.h>

namespace WaterBox
{

	class SDL2_ObjectStatic :public SDL2_Object
	{
	public:
		static SDL2_ObjectStatic *create(SDL2_Material *material);
		static SDL2_ObjectStatic *create(SDL2_Xml *xml);

		///	\brief	���ʵ�λ��У������֤������ʾ�������ϵ���ȷλ���ϣ�����3d�����UVһ��
		virtual void materialModification();

		///	brief	��ʾ�������
		virtual void show();

		///	brief	�������������߼�
		virtual void update();

		///	\brief	����Object�����һ��Xml��ʽ
		virtual SDL2_Xml *saveToXml();

		///	\brief	����xml�ļ������ֵ,����ֵ��ֵ���Լ�
		virtual int analysisXml(SDL2_Xml *xml);

		///	\brief	���þ�̬ͼ�����
		bool setMaterialImage(SDL2_Material *material);
		SDL2_Material *getMaterialImage();
	protected:
		SDL2_ObjectStatic();
		~SDL2_ObjectStatic();
	protected:
		SDL2_Material *m_MaterialImage;
	};
}

#endif // !_SDL2_OBJECTSTATIC_H_BOX
