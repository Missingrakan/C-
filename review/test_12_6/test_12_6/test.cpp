#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual Base* f2()
	{
		cout << "Base::f2()" << endl;
		return this;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}

	void f4()
	{
		cout << "Base::f4()" << endl;
	}

	void f5()
	{
		cout << "Base::f5()" << endl;
	}

	virtual int f6()
	{
		cout << "Base::f6()" << endl;
		return 0;
	}

	int f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}
};

class Derived : public Base
{
public:
	///////////////////////////////
	// ��д
	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual Derived* f2()
	{
		cout << "Derived::f2()" << endl;
		return this;
	}

	//////////////////////////////////////////////
	// ͬ������
	virtual void f3(int)
	{
		cout << "Derived::f3(int)" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	void f5()
	{
		cout << "Derived::f5()" << endl;
	}

	char f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}

	///////////////////////////////////////
	// ����ʧ�ܣ���Ϊû�й���Э��
	//virtual char f6()
	//{
	//	cout << "Derived::f6()" << endl;
	//	return 0;
	//}
};

int main()
{
	Derived d;
	Base *b = &d;
	b->f1();
	b->f2();
	b->f3();
	b->f4();
	b->f5();
	b->f6();
	b->f7();

	return 0;
}

/*
class A
{
public:
	static A* GetInstance(int a)
	{
		return new A(a);
	}

	static void Destroy(A* pa)
	{
		delete pa;
		pa = nullptr;
	}
private:
	A(int a)
		: _a(a)
	{}
protected:
	int _a;
};

int main()
{
	A* pa = A::GetInstance(1);
	A::Destroy(pa);
	return 0;
}
*/

/*
// A ���ü̳�
class A final
{
public:
	A(int a)
		: _a(a)
	{}

protected:
	int _a;
};


class B : public A
{};

*/

/*

// override : �ñ������ڱ���׶����û���������Ƿ񽫻����麯����д�ɹ�
// ��д�ɹ�������ͨ��
// ��дʧ�ܣ�����ʧ��

class Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
	virtual void f1()//final	//final�������麯�����಻�ܶ�����д
	{
		cout << "Base::f1()" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void TestFunc()override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}
};

void TestVirtual(Base& b)
{
	b.TestFunc();
}


int main()
{
	Base b;
	Derived d;
	TestVirtual(b);
	TestVirtual(d);
	return 0;
}
*/
 
/*
class A
{
public:
	A(int a)
		: _a(a)
	{
		cout << "A::A()" << endl;
	}

	virtual ~A()
	{
		cout << "A::~A()" << endl;
	}
protected:
	int _a;
};

class B : public A
{
public:
	B(int a, int b)
		: A(a)
		, _b(b)
	{
		_p = new int[10];
		cout << "B::B()" << endl;
	}
private:
	~B()
	{
		delete[] _p;
		cout << "B::~B()" << endl;
	}

protected:
	int _b;
	int *_p;
};

int main()
{
	A* pa = new B(1, 2);
	
	delete pa;
	pa = nullptr;
	return 0;
}
*/

/*
class Person
{
public:
	virtual void BuyTickets()
	{
		cout << "��ͨƱ" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTickets()
	{
		cout << "ѧ��Ʊ" << endl;
	}
};

// �ڱ���׶Σ��������޷�ȷ������Ҫ�����ĸ�����麯��
// ֻ���ڳ�������ʱ����֪��pbָ���ĸ���Ķ���Ȼ����ö�Ӧ����麯��
void TestVirtual(Person *pb)
{
	pb->BuyTickets();
}

int main()
{
	Person p;
	Student s;
	TestVirtual(&p);
	TestVirtual(&s);

	return 0;
}
*/