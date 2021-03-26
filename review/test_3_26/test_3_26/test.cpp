#include <iostream>
#include <mutex>

using namespace std;

//单例模式

//饿汉模式

class Singleton2
{
public:
	static Singleton2* getInstance()
	{
		if (m_pInstance == nullptr)
		{
			tex.lock();
			if (m_pInstance == nullptr)
				m_pInstance = new Singleton2();
			tex.unlock();
		}

		return m_pInstance;
	}

	//优化

	class cleaner
	{
	public:
		~cleaner()
		{
			if (m_pInstance)
				delete m_pInstance;
		}
	};

	static cleaner clean;

private:
	Singleton2(){};
	Singleton2(const Singleton2&);
	Singleton2& operator=(const Singleton2&);

	static Singleton2* m_pInstance;
	static mutex tex;
};

Singleton2* Singleton2::m_pInstance = nullptr;
Singleton2::cleaner clean;
mutex Singleton2::tex;

//懒汉模式
class Singleton1
{
public:
	static Singleton1* getInstance()
	{
		return &m_instance;
	}

private:
	Singleton1(){};
	Singleton1(const Singleton1&);
	Singleton1& operator=(const Singleton1&);

	static Singleton1 m_instance;
};

Singleton1 Singleton1::m_instance;

int main()
{
	Singleton1* sig = Singleton1::getInstance();
	Singleton1* sig2 = Singleton1::getInstance();

	Singleton2* sig3 = Singleton2::getInstance();
	Singleton2* sig4 = Singleton2::getInstance();
}

/*
class Base
{
public:
	virtual void fun()
	{
		fun2();
	}

	virtual void fun2(int a = 0)
	{
		cout << "Base::fun2(int)" << a << endl;
	}
private:
	void fun1()
	{
		cout << "Base::fun1()" << endl;
	}
	int m_a;
};

class Derived : public Base
{
public:
	virtual void fun2(int b = 2)
	{
		cout << "Derived::fun2(int)" << b << endl;
	}
private:
	int m_b;
};

int main()
{
	Derived* d = new Derived;
	d->fun();

	//erived d;
	//ase* b = &d;
	//->fun();
	//erived* d;
	//ase* b = new Base;
	// = (Derived*)b;
	//->fun2();
	return 0;
}
*/

/*
class Base final
{
private:
	int m_a;
};

class Derived : public Base
{
private:
	int m_b;
};

int main()
{
	return 0;
}
*/