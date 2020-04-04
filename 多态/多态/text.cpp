#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Base
{
public:
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
	virtual void show()
	{
		cout << "Base::show()" << endl;
	}
	void print()
	{
		cout << "Base::print()" << endl;
	}
};
class D : public Base
{
public:
	virtual void fun()
	{
		cout << "D::fun()" << endl;
	}
	virtual void list()
	{
		cout << "D::list()" << endl;
	}
	virtual void self()
	{
		cout << "D::self()" << endl;
	}
private:
	int m_x = 0;
	int m_y = 0;
};
typedef void(*vfptr_t)();

void PrintVirtualTable(vfptr_t *vfptr)
{
	for (int i = 0; vfptr[i] != nullptr; ++i)
	{
		vfptr[i]();
	}
}

int main()
{
	D d;
	vfptr_t * vfptr_ar = (vfptr_t*)(*(int*)&d);
	PrintVirtualTable(vfptr_ar);

	//Base b;
	////cout << b._vfptr << endl;	//error		 //virtual table 隐藏在对象构造内部
	//cout << &b << endl;
	//cout << *(int *)&b << endl;
	//vfptr_t *vfptr_ar = (vfptr_t*)(*(int*)&b);
	//cout << vfptr_ar << endl;
	//PrintVirtualTable(vfptr_ar);
	return 0;
}

////#define DISPLAY
//class Base
//{
//public:
//	Base()
//	{
//#ifdef DISPLAY
//		cout << "Base::Base()" << endl;
//#endif
//	}
//	~Base()
//	{
//#ifdef DISPLAY
//		cout << "Base::~Base()" << endl;
//#endif
//	}
//public:
//	virtual void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//	virtual void show()
//	{
//		cout << "Base::show()" << endl;
//	}
//	void print()
//	{
//		cout << "Base::print()" << endl;
//	}
//private:
//	int m_a = 0;
//	int m_b = 0;
//};
//class D : public Base
//{
//public:
//	D()
//	{
//#ifdef DISPLAY
//		cout << "D::D()" << endl;
//#endif
//	}
//	~D()
//	{
//#ifdef DISPLAY
//		cout << "D::~D()" << endl;
//#endif
//	}
//public:
//	virtual void fun()
//	{
//		cout << "D::fun()" << endl;
//	}
//	virtual void list()
//	{
//		cout << "D::list()" << endl;
//	}
//	void self()
//	{
//		cout << "D::self()" << endl;
//	}
//private:
//	int m_x = 0;
//	int m_y = 0;
//};
//
////virtual function pointer vfptr
////_vfptr		32 ->> 4 Bytes
////m_a+m_b		4 + 4
//int main()
//{
//	D d;
//	Base *pb = &d;
//	pb->fun();			//D::fun()
//	pb->show();			//Base::show()
//
//	Base *pb1 = new Base;
//	pb1->fun();			//Base::fun()
//	pb1->print();		//Base::print()
//	//cout << sizeof(Base) << endl;		//12Bytes
//	return 0;
//}

//class A
//{
//public:
//	virtual void Eat(int a, double b)
//	{
//		cout << "A::Eat()" << endl;
//	}
//	virtual void Foot()
//	{
//		cout << "A::Foot()" << endl;
//	}
//	virtual void Sleep()
//	{
//		cout << "A::Sleep()" << endl;
//	}
//};
//class Dog : public A
//{
//public:
//	void Eat(int x, double y)
//	{
//		cout << "Dog::Eat()" << endl;
//	}
//	void Foot()
//	{
//		cout << "Dog::Foot()" << endl;
//	}
//	void Sleep()
//	{
//		cout << "Dog::Sleep()" << endl;
//	}
//};
//class Pig : public A
//{
//public:
//	void Eat()
//	{
//		cout << "Pig::Eat()" << endl;
//	}
//	void Foot()
//	{
//		cout << "Pig::Foot()" << endl;
//	}
//	void Sleep()
//	{
//		cout << "Pig::Sleep()" << endl;
//	}
//};
//class Person : public A
//{
//public:
//	void Eat()
//	{
//		cout << "Person::Eat()" << endl;
//	}
//	void Foot()
//	{
//		cout << "Person::Foot()" << endl;
//	}
//	void Sleep()
//	{
//		cout << "Person::Sleep()" << endl;
//	}
//};
//class Bird : public A
//{
//public:
//	virtual void Eat()
//	{
//		cout << "Bird::Eat()" << endl;
//	}
//	virtual void Foot()
//	{
//		cout << "Bird::Foot()" << endl;
//	}
//	virtual void Sleep()
//	{
//		cout << "Bird::Sleep()" << endl;
//	}
//};
//
////通用方法 -->
//void Active(A *pa)
//{
//	pa->Eat(1,2);
//	pa->Foot();
//	pa->Sleep();
//}
//
//int main()
//{
//	Dog dog;
//	Pig pig;
//	Person per;
//	Bird bird;
//	Active(&dog);
//	Active(&pig);
//	Active(&per);
//	Active(&bird);
//	return 0;
//}

////覆盖（重写） 隐藏 重载
//class Base
//{
//public:
//	virtual void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//};
//class D : public Base
//{
//public:
//	void fun()  // 覆盖
//	{
//		cout << "D::fun()" << endl;
//	}
//};
//
//int main()
//{
//	D d;
//	Base *pb = &d;
//	Base *pb1 = new D;
//	pb->fun();			//D::fub()
//	pb1->fun();			//D::fun()
//	return 0;
//}

//#define DISPLAY
//class Base
//{
//public:
//	Base()
//	{
//#ifdef DISPLAY
//		cout << "Base::Base()" << endl;
//#endif
//	}
//	~Base()
//	{
//#ifdef DISPLAY
//		cout << "Base::~Base()" << endl;
//#endif
//	}
//public:
//	virtual void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//	void fun(int a)
//	{
//		cout << "Base::fun(int)" << endl;
//	}
//	void show()
//	{
//		cout << "Base::show()" << endl;
//	}
//private:
//	int m_a = 0;
//	int m_b = 0;
//};
//class D : public Base
//{
//public:
//	D()
//	{
//#ifdef DISPLAY
//		cout << "D::D()" << endl;
//#endif
//	}
//	~D()
//	{
//#ifdef DISPLAY
//		cout << "D::~D()" << endl;
//#endif
//	}
//public:
//	void fun()
//	{
//		cout << "D::fun()" << endl;
//	}
//	void show()
//	{
//		cout << "D::show()" << endl;
//	}
//	void list()
//	{
//		cout << "D::list()" << endl;
//	}
//private:
//	int m_x = 0;
//	int m_y = 0;
//};
//
//int main()
//{
//	D d;
//	Base *pb = &d;
//	pb->fun();			//D::fun();
//	Base b = d;
//	b.fun();			//Base::fun();
//	Base &rb = d;
//	rb.fun();			//D::fun();
//
//	//D d;
//	//d.fun();
//	////d.fun(0);			//error
//	//d.Base::fun(0);
//
//	//D d;
//	//Base b = d;
//	//b.fun();			//Base::fun()
//	//Base *pb = &d;
//	//pb->fun();			//D::fun()
//	////pb->list();		//error
//
//	//Base b;
//	//D d;
//	////赋值兼容规则
//	//b = d;
//	//Base *pb = &d;
//	//Base &rb = d;
//
//	return 0;
//}