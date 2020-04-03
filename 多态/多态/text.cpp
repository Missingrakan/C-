#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;



////∏≤∏«£®÷ÿ–¥£© “˛≤ÿ ÷ÿ‘ÿ
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
//	void fun()  // ∏≤∏«
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

#define DISPLAY
class Base
{
public:
	Base()
	{
#ifdef DISPLAY
		cout << "Base::Base()" << endl;
#endif
	}
	~Base()
	{
#ifdef DISPLAY
		cout << "Base::~Base()" << endl;
#endif
	}
public:
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
	void fun(int a)
	{
		cout << "Base::fun(int)" << endl;
	}
	void show()
	{
		cout << "Base::show()" << endl;
	}
private:
	int m_a = 0;
	int m_b = 0;
};
class D : public Base
{
public:
	D()
	{
#ifdef DISPLAY
		cout << "D::D()" << endl;
#endif
	}
	~D()
	{
#ifdef DISPLAY
		cout << "D::~D()" << endl;
#endif
	}
public:
	void fun()
	{
		cout << "D::fun()" << endl;
	}
	void show()
	{
		cout << "D::show()" << endl;
	}
	void list()
	{
		cout << "D::list()" << endl;
	}
private:
	int m_x = 0;
	int m_y = 0;
};

int main()
{
	D d;
	Base *pb = &d;
	pb->fun();			//D::fun();
	Base b = d;
	b.fun();			//Base::fun();
	Base &rb = d;
	rb.fun();			//D::fun();

	//D d;
	//d.fun();
	////d.fun(0);			//error
	//d.Base::fun(0);

	//D d;
	//Base b = d;
	//b.fun();			//Base::fun()
	//Base *pb = &d;
	//pb->fun();			//D::fun()
	////pb->list();		//error

	//Base b;
	//D d;
	////∏≥÷µºÊ»›πÊ‘Ú
	//b = d;
	//Base *pb = &d;
	//Base &rb = d;

	return 0;
}