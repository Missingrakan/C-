#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	auto f1 = []{cout << "This is f1." << endl; };
	auto f2 = []{cout << "This is f2." << endl; };
	f1();
	f2();
	cout << typeid(f1).name() << endl;
	auto f3 = f1;
	f3();
	void(*pfun)() = f1;
	pfun();
	return 0;
}

/*
int z = 300;
int main()
{
	int x = 100;
	int y = 200;
	auto fun = [&](int a, int b)mutable->int
	{
		x = 1;
		y = 2;
		z = 3;
		return a + b + x + y + z;
	};

	cout << fun(10, 20) << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl; 
	return 0;
}


int main()
{
	//语法：[]()->{}
	int x = 100;
	int y = 200;
	auto fun = [x, y](int a, int b)mutable->int
	{
		x = 1;
		return a + b + x + y + z;
	};
	cout << fun(10, 20) << endl;
	cout << "x = " << x << endl;
	//fun = []{cout << "This is lamuda." << endl; };
	//fun();
	return 0;
}
*/

/*
struct Goods
{
	string _name;
	double _price;
};

struct Compare
{
	bool operator()(const Goods &gds1, const Goods &gds2)const
	{
		return gds1._price < gds2._price;
	}
};

void main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds + n, Compare());
}


struct Goods
{
	string _name;
	double _price;

	bool operator<(const Goods &gds)const
	{
		return _price < gds._price;
	}
};

int main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds + n, less<Goods>());

	int ar[] = { 43, 432, 32, 4, 3, 21, 9, 0, 7, 8, 6, 5 };
	n = sizeof(ar) / sizeof(ar[0]);
	//sort(ar, ar + n);
	sort(ar, ar + n, greater<int>());
	return 0;
}
*/

/*
void fun(int &x)
{
	cout << "lvalue ref" << endl;
}

void fun(int &&x)
{
	cout << "rvalue ref" << endl;
}

void fun(const int& x)
{
	cout << "const lvalue ref" << endl;
}

void fun(const int&& x)
{
	cout << "const rvalue ref" << endl;
}

template<typename T>
void PerfectForward(T &&t)
{
	cout << typeid(t).name() << endl;
	fun(forward<T>(t));
	//fun(t);				//全部为左值
}

int main()
{
	PerfectForward(10);				//rvalue ref
	int a = 10;
	PerfectForward(a);				//lvalue ref
	PerfectForward(std::move(a));	//rvalue ref
	const int b = 8;
	PerfectForward(b);				//const lvalue ref
	PerfectForward(std::move(b));	//const rvalue ref

	return 0;
}
*/

/*
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s) : _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String(String &&s) : _str(s._str)
	{
		s._str = nullptr;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	String operator+(const String& s)
	{
		char* ptemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(ptemp, _str);
		strcpy(ptemp + strlen(_str), s._str);
		String strRet(ptemp);
		delete[] ptemp;
		return strRet;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}
private:
	char* _str;
};

class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(Person &&p)
		:_name(move(p._name))
		, _sex(move(p._sex))
		, _age(move(p._age))
	{}
private:
	String _name;
	String _sex;
	int _age;
};

Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}

void fun(const int &a)
{
	cout << a << endl;
}
void fun(int &&a)
{
	cout << a << endl;
}
void main()
{
	Person p(GetTempPerson());
	fun(10);
	String s1("Hello");
	String s2(move(s1));
}
*/

/*
int fun(int a)
{
	//a ^= (1 << 5) - 1;
	a = a ^ ((1 << 5) - 1);
	return a;
}

int main()
{
	cout << fun(21) << endl;
	return 0;
}
*/