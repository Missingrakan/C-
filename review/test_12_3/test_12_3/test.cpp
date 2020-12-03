#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <thread>
#include <Windows.h>
#include <mutex>
#include <atomic>

using namespace std;

int number = 0;
mutex g_lock;

int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		lock_guard<mutex> lock(g_lock);
		//unique_lock<mutex> lock(g_lock);
		++number;
		cout << "thread 1 :" << number << endl;

		//return;

		//g_lock.unlock();
	}
	return 0;
}

int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		lock_guard<mutex> lock(g_lock);
		--number;
		cout << "thread 2 :" << number << endl;
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

/*
//线程同步-->共享资源
mutex mt;
//unsigned long sum = 0L;
atomic_long sum = { 0 };
void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		sum++;
	}
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}
*/
/*
void ThreadFunc() { cout << "ThreadFunc()" << endl; }
void Test1() { throw 1; }
void main()
{
	int* p = new int[10];

	std::thread t(ThreadFunc);   //多线程 退化成 单线程

	try
	{
		Test1();
	}
	catch (...)
	{
		delete[] p;
		throw;
	}

	t.join(); //阻塞
}
*/
/*
void ThreadFunc()
{
	cout << "ThreadFunc()" << endl;
}

bool DoSomething()
{
	return false;
}

int main()
{
	thread t(ThreadFunc);

	if (!DoSomething())
		return -1;		//程序提前退出未等待子线程导致程序出错
	t.join();
	return 0;
}
*/

/*
void ThreadFunc1(int &x)
{
	x += 10;
}

void ThreadFunc2(int *x)
{
	*x += 10;
}

int main()
{
	int a = 10;
	thread t1(ThreadFunc1, ref(a));
	t1.join();
	cout << a << endl;

	int b = 10;
	thread t2(ThreadFunc2, &b);
	t2.join();
	cout << b << endl;

	return 0;

	return 0;
}
*/
/*
void thread_fun(int n)
{
	for (int i = 0; i<n; ++i)
	{
		cout << "This is Child Thread." << endl;
	}
	Sleep(2000);
	cout << "Child Thread End." << endl;
}
struct ThreadObj
{
	void operator()(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << "This is Child Thread." << endl;
		}
		Sleep(2000);
		cout << "Child Thread End." << endl;
	}
};
void main()
{
	thread th(thread_fun, 10);
	//th.detach();
	//thread th(ThreadObj(), 10);
	//thread th([]{cout<<"This is Child Thread Lamuda."<<endl;});
	thread &&th1 = move(th);
	for (int i = 0; i<10; ++i)
	{
		cout << "This is Main Thread." << endl;
	}
	th.join();
	cout << "Main Thread End." << endl;
}
*/
/*
void thread_fun()
{
	for (int i = 0; i<10; ++i)
	{
		cout << "This is Child Thread." << endl;
	}
	Sleep(2000);
	cout << "Child Thread End." << endl;
}
void main()
{
	thread th(thread_fun);
	th.detach();
	for (int i = 0; i<10; ++i)
	{
		cout << "This is Main Thread." << endl;
	}
	cout << "Main Thread End." << endl;
}


void thread_fun()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << "This is child thread." << endl;
	}
}

int main()
{
	thread th(thread_fun);
	cout << "thread_id = " << th.get_id() << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "This is main thread" << endl;
	}
	th.join();
	return 0;
}
*/