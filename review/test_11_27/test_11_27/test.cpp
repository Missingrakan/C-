#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//如果一个类没有显示定义任何构造函数
//编译器也不一定会生成

//编译器什么情况下会生成构造函数
//答案：编译器感觉自己需要的时候

class B
{
public:
	int _b;
};

// 虚拟继承
class D : virtual public B
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	B b;

	D d;
	d._b = 1;
	d._d = 2;

	return 0;
}

/*
class B
{
public:
	void TestFun()
	{}

	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;
	
	D d;
	//d._b = 1;			//不明确
	//d.TestFun();		//不明确

	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;
	d.C1::TestFun();



	return 0;
}



class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}

		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;

public:
	static int c;
};

int Base::c = 0;


class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			__super::operator=(d);
			_d = d._d;
		}

		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
	}

protected:
	int _d;
};

int main()
{
	cout << sizeof(Derived) << endl;
	Base::c = 1;
	Derived::c = 2;

	cout << &Base::c  << " " << &Derived::c << endl;
	return 0;
}


class Base
{
	friend void TestFriend();
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
	}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}

		return *this;
	}

	~Base()
	{
		cout << "~Base()" << endl;
	}

protected:
	int _b;
};


class Derived : public Base
{
public:
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			__super::operator=(d);
			_d = d._d;
		}

		return *this;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};

void TestFriend()
{
	Base b(1);
	b._b = 10;

	Derived d(1, 3);
	d._b = 100;
}

int main()
{
	TestFriend();
	return 0;
}
*/

/*
class Base
{
public:
	Base(int b) : _b(b)
	{
		cout << "Base::Base()" << endl;
	}

	Base(const Base& d) : _b(d._b)
	{}

	Base& operator=(const Base& d)
	{
		if (this != &d)
		{
			_b = d._b;
		}
		return *this;
	}

	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived(int b, int d) : Base(b), _d(d)
	{
		cout << "Derived::Derived()" << endl;
	}

	Derived(const Derived& d) : Base(d), _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		if (this != &d)
		{
			_d = d._d;
		}
		return *this;
	}

	~Derived()
	{
		cout << "Derived::~Derived()" << endl;
	}
protected:
	int _d;
};

int main()
{
	Derived d1(1, 2);
	Derived d2(3, 4);

	d1 = d2;

	return 0;
}
*/

/*
class Test
{
	Test()
	{

	}
private:
	int m_data;
};

int main()
{
	Test t;
	return 0;
}
*/

//#include <stdio.h>
//#pragma pack(8)
//
//struct one
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct two
//{
//	char c;
//	double d;
//	int i;
//};
//
//int main()
//{
//	int x = 1;
//	do
//	{
//		printf("%2d\n", x++);
//	} while (x--);
//	int a;
//	float b, c;
//	scanf("%2d%3f%4f", &a, &b, &c);
//	printf("\na=%d,b=%d,c=%f", a, b, c);
//
//	//cout << sizeof(struct one) << endl;
//	//cout << sizeof(struct two) << endl;
//
//	return 0;
//}