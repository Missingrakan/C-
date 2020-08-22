#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <functional>
#include <thread>
#include <Windows.h>
#include <mutex>
#include <atomic>
using namespace std;

int number = 0;
mutex g_lock;

int ThreadProc1()
{
	for (int i = 0; i < 100; ++i)
	{
		//g_lock.lock();
		//unique_lock<mutex> lock(g_lock);
		lock_guard<mutex> lock(g_lock);
		++number;
		cout << "Thread 1 : " << number << endl;
		//g_lock.unlock();
	}
	return 0;
}

int ThreadProc2()
{
	for (int i = 0; i < 100; ++i)
	{
		//g_lock.lock();
		lock_guard<mutex> lock(g_lock);
		--number;
		cout << "Thread 2 : " << number << endl;
		//g_lock.unlock();
	}
	return 0;
}

int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);
	t1.join();
	t2.join();

	cout << "number:" << number << endl;
	system("pause");
	return 0;
}

//unsigned long sum = 0L;
////atomic_long sum = { 0 };
//void fun(size_t num)
//{
//	for (size_t i = 0; i < num; ++i)
//	{
//		sum++;
//	}
//}
//int main()
//{
//	cout << "Before joining,sum = " << sum << std::endl;
//	thread t1(fun, 10000000);
//	thread t2(fun, 10000000);
//	t1.join();
//	t2.join();
//	cout << "After joining, sum = " << sum << std::endl;
//	return 0;
//}

//void ThreadFunc(){ cout << "ThreadFunc()" << endl; }
//void Test1() { throw 1; }
//void main()
//{
//	int *p = new int[10];
//	std::thread t(ThreadFunc);
//
//	try
//	{
//		Test1();
//	}
//	catch (...)
//	{
//		delete[] p;
//		throw;
//	}
//	t.join(); //error
//}

//void ThreadFunc()
//{
//	cout << "ThreadFunc()" << endl;
//}
//bool Dosomething()
//{
//	return false;
//}
//int main()
//{
//	thread t(ThreadFunc);
//	
//	if (!Dosomething())
//		return -1;
//	t.join();		//error
//	return 0;
//}

//void ThreadFunc1(int &x)
//{
//	x += 10;
//}
//void ThreadFunc2(int *x)
//{
//	*x += 10;
//}
//class Test
//{
//public:
//	void show()
//	{
//		cout << "This is Test::show()" << endl;
//	}
//};
//void main()
//{
//	Test t;
//	thread th(&Test::show, &t);		//相当于传送this指针
//	th.join();
//
//	//int a = 10;
//	//thread t1(ThreadFunc2, &a);
//	//t1.join();
//	//cout << a << endl;
//
//	//int a = 10;
//	//thread t1(ThreadFunc1,ref(a));
//	//t1.join();
//	//cout << a << endl;
//}

//void thread_fun(int n)
//{
//	for (int i = 0; i<n; ++i)
//	{
//		cout << "This is Child Thread." << endl;
//	}
//	Sleep(2000);
//	cout << "Child Thread End." << endl;
//}
//struct Threadobj
//{
//	void operator()(int n)
//	{
//		for (int i = 0; i < n; ++i)
//		{
//			cout << "This is Child Thread." << endl;
//		}
//		Sleep(2000);
//		cout << "Child thread end." << endl;
//	}
//};
//
//void main()
//{
//	//thread th(thread_fun, 10);
//	//th.detach();
//	//thread th(Threadobj(), 10);
//	thread th([]{cout << "This is child thread Lamuda." << endl; });
//	thread &&th1 = move(th);
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "This is main thread" << endl;
//	}
//	th.join();
//	cout << "main thread end." << endl;
//}

//void thread_fun()
//{
//	for (int i = 0; i<10; ++i)
//	{
//		cout << "This is Child Thread." << endl;
//	}
//	Sleep(2000);
//	cout << "Child Thread End." << endl;
//}
//void main()
//{
//	thread th(thread_fun);
//	th.detach();
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "This is main Thread." << endl;
//	}
//	cout << "main Thread end." << endl;
//}

//void thread_fun()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "This is Child Thread." << endl;
//	}
//}
//void main()
//{
//	thread th(thread_fun);
//	cout << "thread id : " << th.get_id() << endl;
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "This is main Thread." << endl;
//	}
//	th.join();
//}

//void main()
//{
//	auto f1 = []{cout << "This is f1." << endl; };	//匿名函数
//	auto f2 = []{cout << "This is f2." << endl; };
//	f1();
//	f2();
//	cout << typeid(f1).name() << endl;
//	auto f3 = f1;
//	f3();
//	void(*pfun)() = f1;
//	pfun();
//}

//int z = 300;
//void main()
//{
//
//	int x = 100;
//	int y = 200;
//	auto fun = [&](int a, int b)mutable->int		//引用传递
//	{
//		x = 1;
//		y = 2;
//		z = 3;
//		return a + b + x + y + z;
//	};   //value
//
//	cout << fun(10, 20) << endl;
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//	cout << "z = " << z << endl;
//}

////[]()->{}
//int z = 300;
//void main()
//{
//	int x = 100;
//	int y = 200;
//	auto fun = [x, y](int a, int b)mutable->int
//	{
//		x = 1;
//		return a + b + x + y + z;
//	};
//	cout << fun(10, 20) << endl;
//	cout << "x = " << x << endl;
//
//	//auto fun = []{cout << "This is Lamuda" << endl; };
//	//fun();
//}

//struct Goods
//{
//	string _name;
//	double _price;
//};
//void main()
//{
//	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
//	int n = sizeof(gds) / sizeof(gds[0]);
//	sort(gds, gds + n, [](const Goods &gds1, const Goods &gds2)->bool{return gds1._price < gds2._price;});
//}

//struct Goods
//{
//	string _name;
//	double _price;
//};
//struct Compare
//{
//	bool operator()(const Goods &gds1, const Goods &gds2)
//	{
//		return gds1._price < gds2._price;
//	}
//};
//
//void main()
//{
//	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
//	int n = sizeof(gds) / sizeof(gds[0]);
//	sort(gds, gds + n, Compare());
//}

//struct Goods
//{
//	string _name;
//	double _price;
//	bool operator<(const Goods &gds)const
//	{
//		return _price < gds._price;
//	}
//};
//
//void main()
//{
//	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, { "菠萝", 1.5 } };
//	int n = sizeof(gds) / sizeof(gds[0]);
//	sort(gds, gds + n, less<Goods>());
//}

//void main()
//{
//	int ar[] = { 58, 43, 9, 48, 6, 7, 7, 2, 156, 7, 81, 7 };
//	int n = sizeof(ar) / sizeof(ar[0]);
//	sort(ar, ar + n, greater<int>());
//	//sort(ar, ar + n);
//}

//void Fun(int &x)
//{
//	cout << "lvalue ref" << endl;
//}
//void Fun(int &&x)
//{
//	cout << "rvalue ref" << endl;
//}
//void Fun(const int &x)
//{
//	cout << "const lvalue ref" << endl;
//}
//void Fun(const int &&x)
//{
//	cout << "const rvalue ref" << endl;
//}
//
//template<typename T>
//void PerfectForward(T &&t)
//{
//	cout << typeid(t).name() << endl;
//	Fun(forward<T>(t));
//}
//
//int main()
//{
//	PerfectForward(10);				//rvalue ref
//	int a = 10;
//	PerfectForward(a);				//lvalue ref
//	PerfectForward(std::move(a));	//rvalue ref
//	const int b = 0;
//	PerfectForward(b);				//const lvalue ref
//	PerfectForward(std::move(b));	//const rvalue ref
//	return 0;
//}