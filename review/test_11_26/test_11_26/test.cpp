#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
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
	/*
	Derived()
	: Base()
	{}
	*/
	Derived(int b, int d)
		: Base(b)
		, _d(d)
	{}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};

int main()
{
	int a;
	char c;
	short b;
	float f;
	double d;

	char array[100];
	cout << array << endl; 

	Derived dd(1,2);
	int* p = new int[10];
	delete[] p;
	return 0;
}

#if 0
class Base
{
public:
	Base(int b=10)
		: _b(b)
	{
		cout << "Base()" << endl;
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
	/*
	如果用户没有显式给出，则编译器会自动生成一份默认的构造函数
	Derived()
	: Base(10)
	, _d(0xCCCCCCCC)  // 栈上的对象
	{
	cout << "Derived()" << endl;
	}
	*/

	Derived()
		: _d(0xCCCCCCCC)  // 栈上的对象
	{
		cout << "Derived()" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};

int main()
{
	Derived d;
	return 0;
}

#endif

#if 0
class Base
{
public:
	Base(int b)
		: _b(b)
	{
		cout << "Base()" << endl;
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
		: Base(b)   // 初始化基类部分继承下来的成员
		, _d(d)
	{
		cout << "Derived()" << endl;
	}

	~Derived()
	{
		cout << "~Derived()" << endl;
		// call ~Base();
	}

protected:
	int _d;
};

void TestFunc()
{
	Derived d(1, 2);
}

int main()
{
	TestFunc();
	return 0;
}


class Base
{
public:
	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	void TestFunc(int b)
	{
		Base::_b = 100;
		cout << "Derived::TestFunc(in)" << endl;
	}
	char _b;
};

int main()
{
	Derived d;
	d.TestFunc(10);
	d.Base::TestFunc();

	d.Base::_b = 10;

	return 0;
}
#endif

//int main()
//{
//	long l = 1L;
//	cout << l << endl;
//	return 0;
//}

//int cnt = 0;
//int fib(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//void main()
//{
//	fib(8);
//	printf("%d\n", cnt);
//}

//int main()
//{
//	int a[5] = { 1, 3, 5, 7, 9 };
//	int *p = (int*)(&a + 1);
//	printf("%d, %d", *(a + 1), *(p - 1));
//	return 0;
//}