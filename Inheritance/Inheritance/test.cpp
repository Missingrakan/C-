#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Base
{
public:
	int m_n;
};
//����̳�
class A : virtual public Base   //A ���Լ��������
{
public:
	int m_a;
};
class B : virtual public Base  //B ���Լ��������
{
public:
	int m_b;
};
class D : public A, public B
{
public:
	int m_d;
};
int main()
{
	D d;
	d.m_d = 0;
	d.m_a = 1;
	d.m_b = 2;

	d.A::m_n = 3; //A  ?  B
	d.B::m_n = 4;
	return 0;
}


//class Base
//{
//public:
//	int m_n;
//};
////��̳� �����ڴ�ռ�
////������Է�����D�����н�A�ŵ����˶�����ɵ������棬
////���Aͬʱ����B��C����ôB��C���ȥ�ҵ�������A�أ�������ͨ����B��C������ָ�룬ָ���һ�ű�
////������ָ��������ָ�룬��������������������д��ƫ������ͨ��ƫ���������ҵ������A��
//class A : virtual public Base
//{
//public:
//	int m_a;
//};
//class B : virtual public Base
//{
//public:
//	int m_b;
//};
//class D : public A, public B
//{
//public:
//	int m_d;
//};
//int main()
//{
//	D d;
//	d.m_d = 0;
//	d.m_a = 1;
//	d.m_b = 2;
//	d.A::m_n = 3;
//	d.B::m_n = 10;
//
//	return 0;
//}

//#define DISPLAY
//class Base
//{
//public:
//	Base(int a) : m_a(a),m_b(a)
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
//	void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//	void fun(int, int)
//	{
//		cout << "Base::fun(int,int)" << endl;
//	}
//	void show()
//	{
//		cout << "Base::show()" << endl;
//	}
//public:
//	int m_a = 0;
//	int m_b = 0;
//};
//class Base1
//{
//public:
//	Base1(int a, int b) :m_a1(a), m_b1(b)
//	{
//#ifdef DISPLAY
//		cout << "Base1::Base1()" << endl;
//#endif
//	}
//	~Base1()
//	{
//#ifdef DISPLAY
//		cout << "Base1::~Base1()" << endl;
//#endif
//	}
//public:
//	void fun()
//	{
//		cout << "Base1::fun()" << endl;
//	}
//	void fun(int, int)
//	{
//		cout << "Base1::fun(int,int)" << endl;
//	}
//	void show()
//	{
//		cout << "Base1::show()" << endl;
//	}
//public:
//	int m_a1 = 0;
//	int m_b1 = 0;
//
//};
////��̳�
//class D : public Base1, public Base
//{
//public:
//	D() : bs(0), Base(1), bs1(1, 2), Base1(1,2)
//	{
//		cout << "D::D()" << endl;
//	}
//	~D()
//	{
//		cout << "D::~D()" << endl;
//	}
//private:
//	int m_x;
//	int m_y;
//	Base bs;
//	Base1 bs1;
//};
//
//int main()
//{
//	//1.�Ȱ��ռ̳е�˳���츸��
//	//2.���ն����˳��ʵ���������Ա
//	//3.��������
//	D d;
//	return 0;
//}

//class Base
//{
//public:
//	Base()
//	{
//		++m_count;
//	}
//	~Base()
//	{
//		--m_count;
//	}
//public:
//	int GetCount()const
//	{
//		return m_count;
//	}
//	void Increment()
//	{
//		m_count++;
//	}
//private:
//	static int m_count;		//����ͳ�ƶ���ĸ���
//};
//int Base::m_count = 0;
//class D : public Base
//{
//public:
//	D()
//	{}
//};

//int main()
//{
//	cout << "Base Size = " << sizeof(Base) << endl;		//1	Baseֻ��һ������û��ʵ�ʿ��ٿռ�c++��������Ĭ��ֵ1
//	cout << "D Size = " << sizeof(D) << endl;			//1   
//	D d;
//	Base b;
//	cout << "Base Size = " << sizeof(Base) << endl;		//1
//	cout << "D Size = " << sizeof(D) << endl;			//1
//
//	cout << "Base b Size = " << sizeof(b) << endl;		//1
//	cout << "D d Size = " << sizeof(d) << endl;			//1
//
//	return 0;
//}

//void main()
//{
//	D d;
//	cout << "object count = " << d.GetCount() << endl;
//	{
//		D d1;
//		cout << "object count = " << d.GetCount() << endl;
//	}
//	cout << "object count = " << d.GetCount() << endl;
//}

//#define DISPLAY
//class D;
//class C;
//class Base
//{
//	friend void PrintData(const Base &b, const D &d, const C &c);
//public:
//	Base(int a, int b) : m_a(a), m_b(b)
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
//	void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//	void fun(int, int)
//	{
//		cout << "Base::fun(int,int)" << endl;
//	}
//	void show()
//	{
//		cout << "Base::show()" << endl;
//	}
//public:
//	int m_a = 0;
//	int m_b = 0;
//};
//class D : public Base
//{
//	friend void PrintData(const Base &b, const D &d, const C &c);
//public:
//	D() :Base(1, 2)
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
//public:
//	int m_x = 0;
//	int m_y = 0;
//};
//class C
//{
//	friend void PrintData(const Base &b, const D &d, const C &c);
//public:
//	int m_n = 0;
//	int m_k = 0;
//};
//void PrintData(const Base &b, const D &d, const C &c)
//{
//	cout << b.m_a << " : " << b.m_b << endl;
//	cout << d.m_x << " : " << d.m_y << endl;
//	cout << c.m_n << " : " << c.m_k << endl;
//}
////�̳���ϵ�������Ԫ�������߱�������
//int main()
//{
//	D d;
//	d.fun();
//	//d.fun(0,0);		//�����������Base::fun(int,int)
//	d.show();
//	Base b(1, 2);
//	C c;
//	PrintData(b, d, c);
//	return 0;
//}

//int main()
//{
//	Base b(0, 0);
//	D d;
//	//��ֵ���ݹ���
//	b = d;
//	Base *pb = &d;
//	Base &rb = d;
//	return 0;
//}

//class Base
//{
//public:
//	Base(int a, int b) : m_a(a), m_b(b)
//	{}
//	Base(const Base &b)
//	{
//		cout << "This is Base(const Base &)" << endl;
//	}
//	Base& operator=(const Base &b)
//	{
//		cout << "This is Base operator=(const Base &)" << endl;
//		m_a = b.m_a;
//		m_b = b.m_b;
//		return *this;
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
//	D() : Base(1,2)
//	{
//		cout << "D::D()" << endl;
//		m_x = m_y = m_z = 0;
//	}
//	D(const D &d) : Base(d)
//	{}
//	D& operator=(const D &d)
//	{
//		Base::operator=(d);
//		m_x = d.m_x;
//		m_y = d.m_y;
//		m_z = d.m_z;
//		return *this;
//	}
//	~D()
//	{
//		cout << "D::~D()" << endl;
//	}
//public:
//	//ͬ������
//	void fun()
//	{
//		cout << "This is D::fun()" << endl;
//	}
//	void show()
//	{
//		cout << "This is D::show()" << endl;
//	}
//private:
//	int m_x = 0;
//	int m_y = 0;
//	int m_z = 0;
//};
//
//void main()
//{
//	D d;
//}

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