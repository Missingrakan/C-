#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;//命名空间

void main()
{
	int a = 10;
	int &b = a;
	int &c = a;
	int &d = b;
}

/*
void main()
{
	int c = 100;
	int a = 10;
	int &b = a;
	int *p = &a;
	int* &q = p;
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	int (&br)[10] = ar;
	int *pi = NULL; //nullptr
	pi = &a;
	pi = &c;
}
*/
//void Swap(int &a, int &b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//void main()
//{
//	int a = 10;
//	int &b = a;  //引用
//	//b = 30;      
//	Swap(a, b);
//}


//函数重载
/*char Max(char a,char b)
{
	return a > b ? a : b;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

double Max(double a, double b)
{
	return a > b ? a : b;
}

void main()
{
	cout << Max(10, 20) << endl;
	cout << Max('A', 'B') << endl;
	cout << Max(12.34, 12.45) << endl;
}
*/
//缺省参数
/*int fun(int a, int b, int c = 0);
void main()
{
	cout << fun(10, 20) << endl;
}
int fun(int a, int b, int c)
{
	return a + b + c;
}*/
//namespace myspace
//{
//	int a = 10;
//	int b = 20;
//	void fun()
//	{
//		cout << "This is fun 1" << endl;
//	}
//	void show()
//	{
//		cout << "This is a Show" << endl;
//	}
//};
//using myspace::show;
////using namespace myspace;
//void main()
//{
//	//fun();
//	//cout << a << endl;
//	show();
//}
//void main()
//{
//	// :: 作用域访问符
//	myspace::fun();
//	cout << myspace::a << endl;
//}

//namespace myspace
//{
//	void fun()
//	{
//		cout << "This is fun 1" << endl;
//	}
//	void show()
//	{
//		cout << "This is a Show" << endl;
//	}
//};
//
//namespace youspace
//{
//	void fun()
//	{
//		cout << "This is fun 2" << endl;
//	}
//};
//
//void fun()
//{
//	cout << "This is fun global" << endl;
//}
////using namespace myspace;
//void main()
//{
//	//myspace::fun();
//	//youspace::fun();
//	fun();
//}
/*
#define A

#ifdef A
void fun()
{
	cout << "This is fun 1" << endl;
}
#else
void fun()
{
	cout << "This is fun 2" << endl;
}
#endif
void main()
{
	fun();
}*/

//void fun(char str)
//{
//	cout << "Tjis is fun(char)" << endl;
//}
//void fun(int a)
//{
//	cout << "This is fun(int)" << endl;
//}
//void main()
//{
//	fun('A');
//	fun(0);
//}
//void main()
//{
//	cout<< "Hello Bit" << endl;
//	int a = 0;
//	char ch = 'A';
//	double d = 12.34;
//	cout << a << endl;//
//	cout << ch << endl;
//	cout << d << endl;
//	int b = 20;
//}
