//	this class is a Action in SDL2. a longggggggggggggg. no write
//	���������һ������MaterialAnimal����������֡����ͼƬ���л����ﵽ������Ч��
//	�������ࡷ
//	2018��7��29�� 09:50:14
//	by	ˮ������

#pragma once
#include <SDL2_Math.h>
#include <SDL2/SDL.h>
#include <SDL2_MaterialPicture.h>
#include <string>


namespace WaterBox
{
	class SDL2_Action
	{
	public:
		///	\brief	����һ���µĶ���
		///	
		///	\pragma	pos		������ͼƬ�еĳ�ʼλ��
		///	\pragma	size	������ͼƬ�вü��ĳߴ�
		///	\pragma	isize	������ͼƬ�е�ƫ�Ƴߴ�
		///	\pragma	number	������֡����һ�������Ż���
		static SDL2_Action *create(std::string path, Math::vec2 pos, Math::vec2 size, Math::vec2 isize, int number);

		///	\brief	��ʾ������ĳһ֡
		void paly();

		///	\brief	���ö�������
		void setName(std::string name);
		std::string getName();

		///	\brief	����·��
		void setPath(std::string path);
		std::string getPath();

		///	\brief	���ö�����ͼƬ�����ʼ��λ��
		void setInitPosition(Math::vec2 pos);
		Math::vec2 getInitPosition();

		///	\brief	���ö�����ͼƬ�����ʼ�ü��Ĵ�С
		void setCutSize(Math::vec2 size);
		Math::vec2 getCutSize();

		///	\brief	���ö���ÿ֡��ͼƬ�е�ƫ�ƴ�С
		void setIncreasingSize(Math::vec2 size);
		Math::vec2 getIncreasingSize();

		///	\brief	���ö��������֡����һ���ж�����ͼƬ�����л���
		void setMaxFrame(int number);
		int getMaxFrame();

		///	\brief	���ö�������
		void setVelocity(int velocity);
		int getVelocity();

		void setPosition(Math::vec2 position);
		Math::vec2 getPosition();

		void setSize(Math::vec2 size);
		Math::vec2 getSize();

		SDL2_Material *getMaterial();
	private:
		std::string m_Name;			//	�������֣���
		SDL2_MaterialPicture *m_Mat;//	�洢ͼƬ
		std::string m_Path;			//	�洢ͼƬ��·��
		Math::vec2 m_NowSize;		//	����Ŀǰ��ͼƬ�вü��ĳߴ�
		Math::vec2 m_NowPos;		//	����Ŀǰ��ͼƬ�е�λ��

		Math::vec2 m_InitPos;		//	������ʼ��λ��
		Math::vec2 m_CutSize;		//	�����ü�ͼƬ�ĳߴ�
		Math::vec2 m_IncreasingSize;//	������ͼ���л�ͼƬʱƫ��λ�õĳߴ�

		int m_Action;				//	����Ŀǰ��ͼƬ�е�֡������Ŀǰ�ǵڼ�֡��
		int m_MaxFrame;				//	���������֡����һ���ж�����ͼƬ�����л���
		int m_Velocity;				//	���������л����ٶ�

	private:
		SDL2_Action();
		~SDL2_Action();

	};
}

