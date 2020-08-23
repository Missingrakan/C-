#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vld.h>
#include <string>
#include <memory>

using namespace std;

template<class _Ty>
class my_auto_ptr
{
public:
	my_auto_ptr(_Ty *_P = 0) : _Owns(_P != 0), _Ptr(_P)
	{}
	my_auto_ptr(const my_auto_ptr<_Ty> &_Y);
	my_auto_ptr<_Ty>& operator=(const my_auto_ptr<_Ty> &_Y);
	~my_auto_ptr()
	{
		if (_Owns)
			delete _Ptr;
	}
public:
	_Ty& operator*()
	{
		return *_Ptr;
	}
	_Ty* operator->()
	{
		return _Ptr;
	}
private:
	bool _Owns;
	_Ty *_Ptr;
};
class Test
{
public:
	void fun()
	{
		cout << "This is Test::fun()" << endl;
	}
};

void main()
{
	int *p = new int(1);    //new int[10]
	my_auto_ptr<int> ap(p); //管理单个对象
	cout << *ap << endl;
	my_auto_ptr<Test> ap1(new Test);
	ap1->fun();
}

//void  main()
//{
//	int *tmp = new int(100);
//	auto_ptr<int> ap(tmp);
//	cout << *ap << endl;
//	auto_ptr<string> ap1(new string("Hello world!"));
//	cout << ap1->size() << endl;
//}

//double Div(int a, int b)
//{
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void main()
//{
//	int *tmp = new int[10];
//	try
//	{
//		Div(10, 0);
//		delete[] tmp;		//内存泄漏
//	}
//	catch (...)
//	{}
//}

////栈满异常声明
//template<typename T>
//class pushOnFull
//{
//	T _value;
//public:
//	pushOnFull(T i)
//	{
//		_value = i;
//	}
//	T value()const
//	{
//		return _value;
//	}
//	void print()const
//	{
//		cerr << "栈满. " << value() << "未压入栈" << endl;
//	}
//};
////栈空异常声明
//template<typename T>
//class popOnEmpty
//{
//public:
//	void print()const
//	{
//		cerr << "栈已空，无法出栈" << endl;
//	}
//};
//template<typename T>
//class Stack
//{
//	int top;				//栈顶指针(下标)
//	T* elements;			//动态建立的数值
//	int maxsize;			//栈最大允纳的元素个数
//public:
//	Stack(int sz = 5)
//	{
//		maxsize = sz > 5 ? sz : 5;
//		elements = new T[maxsize];
//		top = 0;
//	}
//	~Stack()
//	{
//		delete[] elements;
//	}
//public:
//	void Push(const T& data)
//	{
//		if (IsFull())
//			throw pushOnFull<T>(data);
//		elements[top++] = data;
//	}
//	void Pop()
//	{
//		if (IsEmpty())
//			throw popOnEmpty<T>();
//		top--;
//	}
//public:
//	T GetElem(int i)
//	{
//		return elements[i];
//	}
//	void MakeEmpty()
//	{
//		top = 0;
//	}
//	bool IsEmpty()const
//	{
//		return top == 0;
//	}
//	bool IsFull()const
//	{
//		return top == maxsize;
//	}
//	void PrintStack()
//	{
//		for (int i = top - 1; i >= 0; --i)
//			cout << elements[i] << endl;
//	}
//};
//
//void main()
//{
//	Stack<int> st;
//	try
//	{
//		//st.Pop();
//		st.Push(1);
//		st.Push(2);
//		st.Push(3);
//		st.Push(4);
//		st.Push(5);
//		st.Push(6);
//	}
//	catch (const popOnEmpty<int> &e)
//	{
//		e.print();
//	}
//	catch (const pushOnFull<int> &e)
//	{
//		e.print();
//	}
//	catch (...)
//	{
//		cout << "Unknown Exception." << endl;
//	}
//}

//void fun(int ar[], int pos)
//{
//	if (pos >= 10)
//	{
//		throw out_of_range("array out of range ...");
//	}
//	cout << ar[pos] << endl;
//}
//void main()
//{
//	try
//	{
//		int ar[10] = { 0 };
//		fun(ar , 10);
//	}
//	catch (const out_of_range &e)
//	{
//		cout << e.what() << endl;
//	}
//}

//void main()
//{
//	try
//	{
//		int *ptr = new int[536870911];
//		cout << "new int[] ok." << endl;
//		delete[] ptr;
//	}
//	catch (const bad_alloc &e)
//	{
//		cout << "Bad_alloc : " << endl;
//		//e.what();
//	}
//}

//class Exception
//{
//public:
//	virtual void what() = 0;
//public:
//	string _errmsg = "Have a Exception.";
//};
//class SqlException : public Exception
//{
//public:
//	virtual void what()
//	{
//		cout << "SqlException Exception" << endl;
//	}
//};
//class CacheException : public Exception
//{
//public:
//	virtual void what()
//	{
//		cout << "CacheException Exception" << endl;
//	}
//};
//class HttpServerException : public Exception
//{
//public:
//	virtual void what()
//	{
//		cout << "HttpServerException Exception" << endl;
//	}
//};
//void Startup()
//{
//	throw HttpServerException();
//}
//int main()
//{
//	try
//	{
//		Startup();
//	}
//	catch (Exception &e)
//	{
//		e.what();		//多态的体现
//	}
//	catch (...)
//	{
//		cout << "UnKnown Exception" << endl;
//	}
//	return 0;
//}

//double Division(int a, int b)
//{
//	if (b == 0)
//	{
//		throw "Division by zero condition";
//	}
//	return (double)a / (double)b;
//}
//
//void Func()
//{
//	int *array = new int[10];
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;
//	}
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}

//class Test
//{};
//int Div(int a, int b)
//{
//	//char ch = 'A';
//	//double d = 3.14;
//	Test t;
//	if (b == 0)
//	{
//		throw t;
//	}
//	cout << "zzzzzzzzzzzzzzzzzz" << endl;
//	return a / b;
//}
//void main()
//{
//	try
//	{
//		int *p = new int[10];
//		cout << Div(10, 0) << endl;
//		cout << "tttttttttttttt" << endl;
//		delete[] p;
//	}
//	catch (int &e)
//	{
//		cout << "e1 = " << e << "Div Error, b == 0" << endl; 
//	}
//	catch (char &e)
//	{
//		cout << "e2 = " << e << " Div Error, b == 0." << endl;
//	}
//	catch (...)
//	{
//		cout << "e3  Div Error." << endl;
//	}
//}

//int Div(int a, int b)
//{
//	if (b == 0)
//	{
//		cout << "Div error, b ==0" << endl;
//		exit(1);
//	}
//	return a / b;
//}
//void main()
//{
//	cout << Div(10, 0) << endl;
//}