///////////////////////////////
//	this class is a MaterialAnimal in SDL2. Dynamic Object used The material ,normal
//	���������࣬һ��Ķ�̬�����ʹ���������
//	�������ࡷ
//	2018��7��29�� 09:06:12
//	by	ˮ������
#pragma once
#include <SDL2_Action.h>
#include <SDL2_Material.h>
#include <vector>

namespace WaterBox
{
	
	class SDL2_MaterialAnimal :public SDL2_Material
	{
	public:
	public:
		///	\brief	����һ���������ʣ���
		static SDL2_MaterialAnimal *create(); 

		///	\brief	ֱ���ò�������ʼ���������
		static SDL2_MaterialAnimal *create(SDL2_MaterialAnimal *mat);

		void addAction(SDL2_Action *action);

		/// \brief	��ʾ����
		virtual void show();

		///	\brief	���ţ�loop==1�Ļ���ѭ�����ţ�
		///
		///	\pragma	ѡ�񲥷ŵĶ�����Ĭ��0���������У�
		virtual void play(int action = 0);

		///	\brief	��ͣ����
		///	
		///	\pragma	ѡ����ͣ���ŵĶ�����Ĭ��0����ͣ���У�
		virtual void pause(int action = 0);

		///	\brief	���ò���
		///	
		///	\pragma ѡ����ͣ���ŵĶ�����Ĭ��0����ͣ���У�
		virtual void stop(int action = 0);

		///	\brief	����ѭ������
		virtual void setLoop(int loop);

		///	\brief	����λ��
		virtual void setPosition(Math::vec2 position);

		///	\brief	���óߴ�
		virtual void setSize(Math::vec2 size);

		///	\brief	���ز���
		virtual int load(SDL2_Xml *xml);
		virtual SDL2_Xml *save();
	protected:
		SDL2_MaterialAnimal();
		~SDL2_MaterialAnimal();
	private:
		std::vector<SDL2_Action *> m_Actions;
		int m_Action;
		int m_Loop;
	};
}