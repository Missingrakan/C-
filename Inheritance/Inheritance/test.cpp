#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Base
{
public:
	Base(int a, int b) : m_a(a), m_b(b)
	{}
	Base(const Base &b)
	{
		cout << "This is Base(const Base &)" << endl;
	}
	Base& operator=(const Base &b)
	{
		cout << "This is Base operator=(const Base &)" << endl;
		m_a = b.m_a;
		m_b = b.m_b;
		return *this;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
public:
	void fun()
	{
		cout << "This is Base::fun()" << endl;
	}
	void fun(int a)
	{
		cout << "This is Base::fun(int)" << endl;
	}
private:
	int m_a;
	int m_b;
};
class D : public Base
{
public:
	D() : Base(1,2)
	{
		cout << "D::D()" << endl;
		m_x = m_y = m_z = 0;
	}
	D(const D &d) : Base(d)
	{}
	D& operator=(const D &d)
	{
		Base::operator=(d);
		m_x = d.m_x;
		m_y = d.m_y;
		m_z = d.m_z;
		return *this;
	}
	~D()
	{
		cout << "D::~D()" << endl;
	}
public:
	//ͬ������
	void fun()
	{
		cout << "This is D::fun()" << endl;
	}
	void show()
	{
		cout << "This is D::show()" << endl;
	}
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;
};

void main()
{
	D d;
}

//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base::Base()" << endl;
//		m_a = m_b = 0;
//	}
//	~Base()
//	{
//		cout << "Base::~Base()" << endl;
//	}
//public:
//	void fun()
//	{
//		cout << "This is Base::fun()" << endl;
//	}
//	void fun(int a)
//	{
//		cout << "This is Base::fun(int)" << endl;
//	}
//private:
//	int m_a;
//	int m_b;
//};
//class D : public Base
//{
//public:
//	D()
//	{
//		cout << "D::D()" << endl;
//		m_x = m_y = m_z = 0;
//	}
//	~D()
//	{
//		cout << "D::~D()" << endl;
//	}
//public:
//	void fun()
//	{
//		cout << "This is D::fun()" << endl;
//	}
//	void show()
//	{
//		cout << "This is D::show()" << endl;
//	}
//private:
//	int m_x;
//	int m_y;
//	int m_z;
//};
//int main()
//{
//	D d;
//	Base *pb = &d;
//	pb->fun();
//}

//int main()
//{
//	Base b, *pb = nullptr;
//	D    d;
//	//1
//	b = d;		//������������ำֵ
//	//2
//	pb = &d;	//����������ĵ�ַ�������ָ�븳ֵ
//	//3
//	Base &rb = d;	//�����������������ø�ֵ
//	
//	return 0;
//}

//class Base
//{
//public:
//	void fun1()
//	{}
//protected:
//	void show1()
//	{}
//private:
//	void list1()
//	{}
//private:
//	int m_a;
//};
//class D : private Base
//{
//public:
//	void fun()
//	{
//		fun1();
//		show1();
//		//list1();		//error ���ܷ���˽�г�Ա
//	}
//protected:
//	void show()
//	{
//		fun1();
//	}
//private:
//	int m_x;
//};
//class C : public D
//{
//public:
//	void fun2()
//	{
//		//fun1();		//error˽�м̳�
//	}
//};
//
////�����ܷ���ʵ�����    //1.վ�ڶ���ĽǶ�	//2.վ������ĽǶ�
//int main()
//{
//	D d;
//	d.fun();
//	//d.fun1();			//error private�̳�
//	return 0;
//}