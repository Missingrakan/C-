#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <Windows.h>

class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived::f5()" << endl;
	}
	int _d;
};

#include <string>

typedef void (*PVF)();

void PrintVFT(Base& b, const string& info)
{
	PVF* pVFT = (PVF*)(*(int*)(&b));
	//pVFT[0]();
	cout << info << endl;
	while (*pVFT)
	{
		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Base) << endl;

	Base b, b1, b2;
	b._b = 1;
	PrintVFT(b, "base virtual function table:");

	Derived d;
	d._b = 1;
	d._d = 2;
	PrintVFT(d, "derived virtual function table:");

	return 0;
}

/*
class WashRoom
{
public:
	void ManWC()
	{
		cout << this << "go to left" << endl;
	}

	void WomanWC()
	{
		cout << this << "go to right" << endl;
	}
};

//抽象类
class Person
{
public:
	//纯虚函数
	virtual void GoToWC(WashRoom& wc) = 0;
};

// 抽象类是一定要被继承的
// 

class Man : public Person
{
public:
	virtual void GoToWC(WashRoom& wc)
	{
		wc.ManWC();
	}
};

class Woman : public Person
{
public:
	virtual void GoToWC(WashRoom& wc)
	{
		wc.WomanWC();
	}
};

void TestWC()
{
	Person*p = nullptr;
	WashRoom wr;
	for (size_t i = 0; i < 10; ++i)
	{
		if (rand() % 2 == 0)
			p = new Man;
		else
			p = new Woman;

		p->GoToWC(wr);
		delete p;
		Sleep(3000);
	}
}

int main()
{
	//Person p;	//编译失败，抽象类不能实例化对象
	TestWC();
	return 0;
}
*/

/*
class A
{
public:
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};
class B : public A
{
public: virtual void print()
{
			cout << "B::print()" << "\n";
}
};
class C : public A
{
public: virtual void print()
{
			cout << "C::print()" << "\n";
}
};
void print(A a)
{
	a.print();
}
int main()
{
	A a, *aa, *ab, *ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print();
	b.print();
	c.print();
	aa->print();
	ab->print();
	ac->print();
	print(a);
	print(b);
	print(c);
}
*/