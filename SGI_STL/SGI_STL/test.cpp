#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Base
{
public:
	virtual void fun()const
	{
		cout << "This is Base::fub()" << endl;
	}
private:
	int m_a = 0;
};
class D : public Base
{
public:
	void fun()const
	{
		cout << "This is D::fun()" << endl;
	}
	void show()const
	{
		cout << "This is D::show()" << endl;
	}
private:
	int m_c = 0;
};
void Active(Base *pb)
{
	pb->fun();
	//(dynamic_cast<D*>(pb))->show();
	D *pd = dynamic_cast<D*>(pb);
	if (pd != NULL)
		pd->show();
	else
		cout << "非法的转换......" << endl;
}
void main()
{
	D d;
	Base b;
	Active(&b);
}

//class A
//{
//private:
//	int m_a = 0;
//};
//class B
//{
//private:
//	int m_c = 0;
//};
//class D : public A, public B
//{
//private:
//	int m_c = 0;
//};
//void main()
//{
//	//D d;
//	//printf("%p, %p, %p\n", &d, static_cast<B*>(&d), reinterpret_cast<B*>(&d));
//
//	double d = 12.34;
//	int a = 10;
//	int *p = reinterpret_cast<int*>(&d);
//
//	//double d = 12.34;
//	//int *p2 = reinterpret_cast<int*>(&d);
//	//cout << *p2 << endl;
//}

//void main()
//{
//	const int a = 10;
//	int *p = const_cast<int*>(&a);	//用于去掉const和volatile
//	volatile int b = 10;
//	int *p1 = const_cast<int*>(&b);
//	double d = 12.34;
//	int *p2 = const_cast<int*>(&d);	//err
//
//	//int a = 10;
//	//double d = 12.34;
//	//a = static_cast<int>(d);		//用于替换C中的隐式转换
//	//int *p = static_cast<int*>(&d);	//err
//}