///////////////////////////////
//	this class is a Callback in SDL2.
//	��������Ŀ¼
//	���ص��ࡷ
//	2018��10��14�� 21:06:58
//	by	ˮ������


/*
������
	�ܹ���Ϊ������
		SDL2_CallbackBase
		SDL2_CallbackBasex
		SDL2_CallbackObjectx
	Ϊ�����û�����дģ��SDL2_CallbackBasex<xx, xx>�����鷳�������д��ô�������ģ�
	����д���ǲο�Unigine��Callbackͷ�ļ���д�ģ�������㳭�ģ�ģ��ѧ�˲���
	SDL2_CallbackBase ��Ϊ���û��������࣬����run������
	SDL2_CallbackBasex��Ϊ�м��࣬���������²��SDL2_CallbackObjectx
	SDL2_CallbackObjectx��Ҫ�ģ����洢����ͺ����ĵ�ַ�ȣ��͵��õĺ���
*/
#ifndef _SDL2_CALLBACK_H_BOX_
#define _SDL2_CALLBACK_H_BOX_

#include <SDL2_Variable.h>
#include <SDL2_Console.h>

namespace WaterBox
{
	class SDL2_CallbackBase
	{
	public:
		///	\brief	��ȡ��������
		virtual int getParmNumber();

		virtual void run();
		template <class A1> void run(A1 a1);
		template <class A1, class A2> void run(A1 a1, A2 a2);
		template <class A1, class A2, class A3> void run(A1 a1, A2 a2, A3 a3);
	protected:
		///	\brief	���ò�������
		virtual void setParmNumber(int parm);
	private:
		int m_ParmNumber;		//	�����ĸ����������жϵ��׵��ö��ٸ�������run��
	};

	//	�����������Ļص�****************************************************************************************************
	template <class Class, class Func>
	class SDL2_CallbackBase0 :public SDL2_CallbackBase
	{
	public:

		///	\brief	��ȡ��������
		virtual int getParmNumber()
		{
			return 0;
		}
		static SDL2_CallbackBase0<Class, Func> *create(Class *clas, Func(Class::*func)())
		{
			SDL2_CallbackBase0 *callback = new SDL2_CallbackBase0();
			callback->setCallback(clas, func);
			return callback;
		}
		virtual void run()
		{
			(m_Class->*m_Func)();
		}
	private:
		SDL2_CallbackBase0<Class, Func>()
		{
		}

		void setCallback(Class *clas, Func(Class::*func)())
		{
			m_Class = clas;
			m_Func = func;
		}
	private:
		Class *m_Class;
		Func(Class::*m_Func)();
	};

	//	����1�������Ļص�****************************************************************************************************//	�����������²��SDl2_Objectx��run����������Ϊ�м��
	template <class A1>
	class SDL2_CallbackBase1 :public SDL2_CallbackBase
	{
	public:
		virtual void run() 
		{
			SDL2_Console::get()->addError("CallbackBase1::run(): called");
		}
		virtual void run(A1 a1) = 0;
	protected:
		SDL2_CallbackBase1()
		{
			setParmNumber(1);
		}
	private:
		A1 m_A1;
	};

	//	����2�������Ļص�****************************************************************************************************//	�����������²��SDl2_Objectx��run����������Ϊ�м��
	template <class A1, class A2>
	class SDL2_CallbackBase2 :public SDL2_CallbackBase
	{
	public:
		virtual void run()
		{
			SDL2_Console::get()->addError("CallbackBase1::run(): called");
		}
		virtual void run(A1 a1, A2 a2) = 0;
	protected:
		SDL2_CallbackBase2()
		{
			setParmNumber(2);
		}
	private:
		A1 m_A1;
		A2 m_A2;
	};

	//	����3�������Ļص�****************************************************************************************************//	�����������²��SDl2_Objectx��run����������Ϊ�м��
	template <class A1, class A2, class A3>
	class SDL2_CallbackBase3 :public SDL2_CallbackBase
	{
	public:
		virtual void run()
		{
			SDL2_Console::get()->addError("CallbackBase1::run(): called");
		}
		virtual void run(A1 a1, A2 a2, A3 a3) = 0;
	protected:
		SDL2_CallbackBase3()
		{
			setParmNumber(3);
		}
	private:
		A1 m_A1;
		A2 m_A2;
		A3 m_A3;
	};

	//	����1�������Ļص�--------------------------------------------------------------------------------------------------------
	template <class Class, class Func, class A1>
	class SDL2_CallbackObject1 :public SDL2_CallbackBase1<A1>
	{
	public:
		static SDL2_CallbackObject1<Class, Func, A1> *create(Class *clas, Func func)
		{
			SDL2_CallbackObject1 *callback = new SDL2_CallbackObject1();
			callback->setCallback(clas, func);
			return callback;
		}
		virtual void run(A1 a1)
		{
			(m_Class->*m_Func)(a1);
		}
	private:
		SDL2_CallbackObject1<Class, Func, A1>()
		{
		}

		void setCallback(Class *clas, Func func)
		{
			m_Class = clas;
			m_Func = func;
		}
	private:
		Class *m_Class;
		Func m_Func;
		A1 m_A1;
	};

	//	����2�������Ļص�--------------------------------------------------------------------------------------------------------
	template <class Class, class Func, class A1, class A2>
	class SDL2_CallbackObject2 :public SDL2_CallbackBase2<A1, A2>
	{
	public:
		static SDL2_CallbackObject2<Class, Func, A1, A2> *create(Class *clas, Func func)
		{
			SDL2_CallbackObject2 *callback = new SDL2_CallbackObject2();
			callback->setCallback(clas, func);
			return callback;
		}

		virtual void run(A1 a1, A2 a2)
		{
			(m_Class->*m_Func)(a1, a2);
		}
	private:
		SDL2_CallbackObject2<Class, Func, A1, A2>()
		{
		}

		void setCallback(Class *clas, Func func)
		{
			m_Class = clas;
			m_Func = func;
		}
	private:
		Class *m_Class;
		Func m_Func;
		A1 m_A1;
		A2 m_A2;
	};

	//	����3�������Ļص�--------------------------------------------------------------------------------------------------------
	template <class Class, class Func, class A1, class A2, class A3>
	class SDL2_CallbackObject3 :public SDL2_CallbackBase3<A1, A2, A3>
	{
	public:
		static SDL2_CallbackObject3<Class, Func, A1, A2, A3> *create(Class *clas, Func func)
		{
			SDL2_CallbackObject3 *callback = new SDL2_CallbackObject3();
			callback->setCallback(clas, func);
			return callback;
		}

		virtual void run(A1 a1, A2 a2, A3 a3)
		{
			(m_Class->*m_Func)(a1, a2, a3);
		}
	private:
		SDL2_CallbackObject3<Class, Func, A1, A2, A3>()
		{
		}

		void setCallback(Class *clas, Func func)
		{
			m_Class = clas;
			m_Func = func;
		}
	private:
		Class *m_Class;
		Func m_Func;
		A1 m_A1;
		A2 m_A2;
		A3 m_A3;
	};

	//�����ص��õĺ���+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	template <class Class, class Func>
	SDL2_CallbackBase0<Class, Func> *makeCallback(Class *clas, Func(Class::*func)())
	{
		SDL2_CallbackBase0<Class, Func>* callback = SDL2_CallbackBase0<Class, Func>::create(clas, func);
		return callback;
	}

	template <class Class, class Func, class A1>
	SDL2_CallbackBase *makeCallback(Class *clas, Func(Class::*func)(A1))
	{
		SDL2_CallbackBase* callback = SDL2_CallbackObject1<Class, Func(Class::*)(A1), A1>::create(clas, func);
		return callback;
	}

	template <class Class, class Func, class A1, class A2>
	SDL2_CallbackBase *makeCallback(Class *clas, Func(Class::*func)(A1, A2))
	{
		SDL2_CallbackBase *callback = SDL2_CallbackObject2<Class, Func(Class::*)(A1, A2), A1, A2>::create(clas, func);
		return callback;
	}

	template <class Class, class Func, class A1, class A2, class A3>
	SDL2_CallbackBase *makeCallback(Class *clas, Func(Class::*func)(A1, A2, A3))
	{
		SDL2_CallbackBase *callback = SDL2_CallbackObject3<Class, Func(Class::*)(A1, A2, A3), A1, A2, A3>::create(clas, func);
		return callback;
	}

	template<class A1>
	inline void SDL2_CallbackBase::run(A1 a1)
	{
		switch (m_ParmNumber)
		{
		case 1:
			static_cast<SDL2_CallbackBase1<A1> *>(this)->run(a1);
			break;
		default:
			run();
			break;
		}
	}

	template<class A1, class A2>
	inline void SDL2_CallbackBase::run(A1 a1, A2 a2)
	{
		switch (m_ParmNumber)
		{
		case 2:
			static_cast<SDL2_CallbackBase2<A1, A2> *>(this)->run(a1, a2);
			break;
		default:
			run();
			break;
		}
	}

	template<class A1, class A2, class A3>
	inline void SDL2_CallbackBase::run(A1 a1, A2 a2, A3 a3)
	{
		switch (m_ParmNumber)
		{
		case 3:
			static_cast<SDL2_CallbackBase3<A1, A2, A3> *>(this)->run(a1, a2, a3);
			break;
		default:
			run();
			break;
		}
	}
}

#endif//! _SDL2_CALLBACK_H_BOX_
