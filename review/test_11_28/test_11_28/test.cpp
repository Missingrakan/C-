#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base::Base()" << endl;
	}

	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}

	int _b;
};

class Derived : public Base
{
public:
	Derived()
	{
		pb = new int[10];
		cout << "Derived::Derived()" << endl;
	}

	~Derived()
	{
		if (pb)
		{
			delete[] pb;
			pb = nullptr;
			cout << "Derived::Derived()" << endl;
 		}
	}

	int *pb;
};

int main()
{
	Base* pb = new Derived;
	delete pb;

	return 0;
}

/*
class Person
{
public:
	virtual void BuyTickets()
	{
		cout << "È«¼ÛÆ±" << endl;
	}
protected:
	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	virtual void BuyTickets()
	{
		cout << "¶ùÍ¯Æ±" << endl;
	}
protected:
	int _StuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTickets()
	{
		cout << "Ãâ·ÑÆ±" << endl;
	}
protected:
	int _stuID;
};


void TestBuyTickets(Person* p)
{
	p->BuyTickets();
}

int main()
{
	Person p;
	Student stu;
	Soldier so;

	TestBuyTickets(&p);
	TestBuyTickets(&stu);
	TestBuyTickets(&so);

	return 0;
}
*/

/*
class B
{
public:
	void f()
	{
		cout << "B::f()" << endl;
	}

	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

class E : virtual public D
{
public:
	int _e;
};

int main()
{
	cout << sizeof(E) << endl;
	E e;
	e._c1 = 1;
	e._c2 = 2;
	e._d = 3;
	e._b = 4;
	e._e = 5;

	return 0;
}
*/
/*
int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;

	d.f();

	C1& c1 = d;
	c1._c1 = 5;
	c1._b = 6;

	C2& c2 = d;
	c2._c2 = 7;
	c2._b = 8;


	char* str = "hello";
	str[0] = 'H';

	int* p = (int*)(*(int*)&d);
	++p;
	(*p) = 100;

	return 0;
}
*/

/*
class B
{
public:
	int _b;
};

class D : virtual public B
{
public:
	D()
	{
		cout << "D::D()" << endl;
	}

	int _d;
};

int main()
{
	D d;
	return 0;
}
*/