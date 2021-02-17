#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <mutex>
#include <thread>
#include <assert.h>

using namespace std;

template<typename T>
class LASingletonTemplate
{
private:
	static T* sm_instance;
protected:
	LASingletonTemplate()
	{
		assert(sm_instance != 0);
		sm_instance = static_cast<T*>(this);
	}

	virtual ~LASingletonTemplate()
	{
		assert(sm_instance != 0);
		sm_instance = 0:
	}
public:
	static T* get_instance_ptr()
	{
		if (sm_instance == 0)
		{
			sm_instance = new T();
		}
		return sm_instance;
	}

	static T& get_instance_ref()
	{
		if (sm_instance == 0)
		{
			sm_instance = new T();
		}
		return *sm_instance;
	}

	static void remove_instance()
	{
		assert(sm_instance);
		if (sm_instance)
		{
			delegate sm_instance;
		}
		assert(sm_instance == 0);
	}
};

template<typename T>
T* LASingletonTemplate<T>::sm_instance = 0;

class Test
{};
void main()
{
	Test t1, t2, t3;
	Test *pt1 = LASingletonTemplate<Test>::get_instance_ptr();
	Test *pt2 = LASingletonTemplate<Test>::get_instance_ptr();
	Test *pt3 = LASingletonTemplate<Test>::get_instance_ptr();
}

/*
mutex mt;

class Singleton
{
public:
	static Singleton* Instance()
	{
		if (_instance == nullptr)
		{
			mt.lock();
			if (_instance == nullptr)
			{
				_instance = new Singleton;
			}
			mt.unlock();
		}

		return _instance;
	}
protected:
	Singleton()
	{
		cout << "create Singleton Obj." << endl;
	}
private:
	static Singleton* _instance;
};

Singleton* Singleton::_instance = nullptr;

void thread_fun(int n)
{
	for (int i = 0; i<n; ++i)
	{
		Singleton *ps = Singleton::Instance();
		cout << "ps = " << ps << endl;   //一样
	}
}
void main()
{
	thread t1(thread_fun, 10);
	thread t2(thread_fun, 10);
	t1.join();
	t2.join();
}


void main()
{
	system("pause");
	Singleton *pst = Singleton::Instance();
	Singleton *pst1 = Singleton::Instance();
	Singleton *pst2 = Singleton::Instance();
	Singleton *pst3 = Singleton::Instance();
}
*/

/*
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	Singleton()
	{
		cout << "Create Singleton Obj." << endl;
	}
	
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);
	static Singleton m_instance;
};
Singleton Singleton::m_instance;

void main()
{
	Singleton *ps = Singleton::GetInstance();
	Singleton *ps1 = Singleton::GetInstance();
	Singleton *ps2 = Singleton::GetInstance();
	system("pause");
}
*/

/*
//不能被继承
class NonInherit final
{};
class Test : public NonInherit
{};
void main()
{
	Test t;
}

class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};
class Test : public NonInherit
{};
void main()
{
	Test t;
}
*/

/*
//无法被拷贝
class noncopyable
{
protected:
	noncopyable()
	{}
	~noncopyable()
	{}
private:
	noncopyable(const noncopyable&);
	const noncopyable& operator=(const noncopyable&);
};

class Test : public noncopyable
{
public:
	Test(int data = 0) : m_data(data)
	{}

	Test(const Test& t)
	{
		m_data = t.m_data;
	}
private:
	int m_data = 0;
};

class Test1 : public noncopyable
{
};
void main()
{
	Test t1;
	Test t2 = t1;   //
	Test t3;
	t3 = t1;
}
*/

/*
//只能在栈上创建对象
class Test
{
private:
	void* operator new(size_t sz);
	void* operator new[](size_t sz);
};

void mian()
{
	Test t;
	Test *pt = new Test();
}
*/

/*
//只能在堆上创建对象
class Test
{
public:
	static Test* GetInstance()
	{
		return new Test;
	}
public:
	void fun()
	{
		cout << "Test::fun()" << endl;
	}
private:
	Test()
	{}
private:
	int m_data=0;
};

int main()
{
	Test *pt = Test::GetInstance();
	//Test t;

	pt->fun();
	return 0;
}
*/