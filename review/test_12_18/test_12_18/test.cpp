#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vld.h>

using namespace std;

//栈满异常声明
template<class T>
class pushOnFull
{
	T _value;
public:
	pushOnFull(int i)
	{
		_value = i;
	}

	T value()const
	{
		return _value;
	}

	void print()const
	{
		cout << "栈满， " << value() << "为压入栈" << endl;
	}
};

//栈空异常声明
template<typename T>
class popOnEmpty
{
public:
	void print()const
	{
		cerr << "栈已空，无法出栈" << endl;
	}
};

template<class T>
class Stack
{
private:
	int top;			//栈顶指针
	T* elements;		//数据空间
	int maxsize;		//栈最大允许的元素个数

public:
	Stack(int sz = 5)
	{
		maxsize = sz > 5 ? sz : 5;
		elements = new T[maxsize];
		top = 0;
	}
	~Stack()
	{
		delete[] elements;
	}
public:
	void Push(const T& data)
	{
		if (IsFull())
			throw pushOnFull<T>(data);
		elements[top++] = data;
	}

	T Pop()
	{
		if (IsEmpty())
			throw popOnEmpty<T>();
		top--;
	}
public:
	T GetElement(int i)
	{
		return elements[i];
	}

	void MakeEmpty()
	{
		top= 0；
	}

	bool IsEmpty()const
	{
		return top == 0;
	}

	bool IsFull()const
	{
		return top == maxsize;
	}

	void PrintStack()
	{
		for (int i = top - 1; i >= 0; --i)
			cout << elements[i] << endl;
	}
};

void main()
{
	Stack<int> st;
	try
	{
		//st.Pop();
		st.Push(1);
		st.Push(2);
		st.Push(3);
		st.Push(4);
		st.Push(5);
		st.Push(6);
	}
	catch (const popOnEmpty<int> &e)
	{
		e.print();
	}
	catch (const pushOnFull<int> &e)
	{
		e.print();
	}
	catch (...)
	{
		cout << "Unkown Exception." << endl;
	}

}

/*
void func(int ar[], int pos)
{
	if (pos >= 10)
	{
		throw out_of_range("array out of range");
	}
	cout << ar[pos] << endl;
}

void main()
{
	try
	{
		int ar[10] = { 0 };
		func(ar, 10);
	}
	catch (const out_of_range &e)
	{
		cout << e.what() << endl;
	}
}

void main()
{
	try
	{
		int* ptr = new int[536870911];		//new申请空间失败会抛出bad_alloc异常
		cout << "new is ok!" << endl;
		delete[] ptr;
	}
	catch (const bad_alloc& e)
	{
		cout << "bad_alloc" << endl;
	}
}
*/

/*
class Exception
{
public:
	virtual void what() = 0;
public:
	string _errmsg = "have a exception";
};

class SqlException : public Exception
{
public:
	virtual void what()
	{
		cout << "SqlException Exception" << endl;
	}
};

class CacheException : public Exception
{
public:
	virtual void what()
	{
		cout << "CacheException Exception" << endl;
	}
};

class HttpServerException : public Exception
{
public:
	virtual void what()
	{
		cout << "HttpServerException Exception" << endl;
	}
};

void StartUp()
{
	throw SqlException();
}

int main()
{
	try
	{
		StartUp();
	}
	catch (Exception &e)
	{
		e.what();
	}
	catch (...)
	{
		cout << "UnKnown Exception" << endl;
	}
	return 0;
}
*/

/*
double Division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero";
	}
	return (double)a / (double)b;
}

void Func()
{
	int* array = new int[10];
	try
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}

	cout << "delete []" << array << endl;
	delete[] array;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errMsg)
	{
		cout << errMsg << endl;
	}
	return 0;
}
*/

/*
class Test
{};

int Div(int a, int b)
{
	char ch = 'a';
	double d = 12.34;
	Test t;
	if (b == 0)
	{
		throw ch;
	}
	cout << "This is Div message" << endl;
	return a / b;
}

int main()
{
	try
	{
		int *p = new int[10];
		cout << Div(10, 0) << endl;
		cout << "This is main message" << endl;		//可能会发生异常语句，后面的代码可能不会执行
		delete[] p;
	}

	catch (int &e)
	{
		cout << "e1 = " << e << "Div error, b == 0" << endl;
	}
	catch (char e)
	{
		cout << "e2 = " << e << "Div error, b == 0" << endl;
	}
	catch (...)
	{
		cout << "e3 Div error" << endl;
	}
	return 0;
}
*/

/*
int Div(int left, int right)
{
	if (right == 0)
	{
		cout << "Div error, right operator = 0" << endl;
		exit(1);
	}
	return left / right;
}

int main()
{
	cout << Div(10, 0) << endl;
	return 0;
}
*/