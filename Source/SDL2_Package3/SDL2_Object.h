///////////////////////////////
//	this class is a Object in SDL2.
//	һ������һ����˵��һ�����ڵ����壬ӵ�в��ʵ�
//	�������ࡷ
//	2018��8��13�� 20:11:05
//	by	ˮ������

#ifndef _SDL2_OBJECT_H_BOX
#define _SDL2_OBJECT_H_BOX

#include <SDL2_Math.h>
#include <SDL2_Node.h>
#include <SDL2_Material.h>
#include <vector>
namespace WaterBox
{
	class SDL2_Object :public SDL2_Node
	{
	public:   
		///	brief	��ȡλ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	��ȡ�ߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	��ʾ�������
		virtual void show();

		///	brief	�������������߼�
		virtual void update();
		
		///	brief	��ȡ����
		std::vector<SDL2_Material *> getMaterials();
	protected:
		SDL2_Object();
		std::vector<SDL2_Material **> m_Materials;
	};
}
#endif	//	!_SDL2_OBJECT_H_BOX