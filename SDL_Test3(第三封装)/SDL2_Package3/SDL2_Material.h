///////////////////////////////
//	this class is a Material in SDL2. Save the Material use the class please.
//	���ʵ����࣬һ��������������в��ʵĴ洢
//	�������ࡷ
//	2018��6��23�� 23:58:53
//	by	ˮ������

#ifndef _SDL2_MATERIAL_H_BOX
#define _SDL2_MATERIAL_H_BOX

#include <string>
#include <SDl2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2_Math.h>

namespace WaterBox
{
	class SDL2_Material
	{
	public :
		///	�������͵�ö��
		enum MaterialType
		{
			TYPE_PARENT = 0,	//	���Ǹ���
			TYPE_PICTURE,		//	ͼƬ������
			TYPE_ANIMAL,		//	����������
			TYPE_TEXT			//	���ֲ�����
		};
	public:
		static SDL2_Material *create();
		~SDL2_Material();

		///	brief	����λ��
		virtual void setPosition(Math::vec2 position);
		virtual Math::vec2 getPosition();

		///	brief	���óߴ�
		virtual void setSize(Math::vec2 size);
		virtual Math::vec2 getSize();

		///	brief	���ü���wλ��
		virtual void setCutPosition(Math::vec2 position);
		virtual Math::vec2 getCutPosition();

		///	brief	���ü��гߴ�
		virtual void setCutSize(Math::vec2 size);
		virtual Math::vec2 getCutSize();

		///	brief	���ò��ʵ�����
		virtual void setName(std::string name);
		virtual std::string getName();

		///	brief	�ָ�Ĭ�ϳߴ�
		virtual void reSize();

		///	brief	��ʾ
		virtual void show() {}

		virtual MaterialType getType();

	protected:
		SDL2_Material();
		void setDefaultSize(Math::vec2 size);
	protected:
		MaterialType m_Type;
		std::string m_Name;
		Math::vec2 m_CutSize;
		Math::vec2 m_CutPosition;
		Math::vec2 m_Position;
		Math::vec2 m_Size;
		Math::vec2 m_DefaultSize;
	private:

	};
}
#endif	//	!_SDL2_MATERIAL_H_BOX