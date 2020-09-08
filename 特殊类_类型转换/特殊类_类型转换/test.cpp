#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <assert.h>

using namespace std;

void main()
{
	const int a = 10;
	int *p = const_cast<int*>(&a);
	int &b = const_cast<int&>(a);

	volatile int x = 20;			
	int *px = const_cast<int*>(&x);	//ȥ��volatile
}

//void main()
//{
//	int a = 10;
//	double d = 12.34;
//	a = static_cast<int>(d);
//	int p = 0x0012ff7c;
//	int *ptr = static_cast<int*>(p);		//err
//
//	//int a = 10;
//	//double d = 12.34;
//	//a = d;		//��ʽת��
//	//a = (int)d;	//��ʽת��
//	//int *p = (int*)0x0012ff7c;
//}

//template<typename T>
//class LASingletonTemplateBase
//{
//private:
//	static T* sm_instance;
//protected:
//	LASingletonTemplateBase()
//	{
//		assert(sm_instance == 0);
//		sm_instance = static_cast<T*>(this);
//	}
//	virtual ~LASingletonTemplateBase()
//	{
//		assert(sm_instance != 0);
//		sm_instance = 0;
//	}
//public:
//	static T* get_instance_ptr()
//	{
//		if (sm_instance == 0)
//		{
//			sm_instance = new T();
//		}
//		return sm_instance;
//	}
//	static T& get_instance_ref()
//	{
//		if (sm_instance == 0)
//		{
//			sm_instance = new T();
//		}
//		return *sm_instance;
//	}
//	static void remove_instance()
//	{
//		assert(sm_instance);
//		if (sm_instance)
//		{
//			delete sm_instance;
//		}
//		assert(sm_instance == 0);
//	}
//};
//template<typename T>
//T* LASingletonTemplateBase<T>::sm_instance = 0;
//class Test
//{};
//void main()
//{
//	Test t1, t2, t3;
//	Test *pt1 = LASingletonTemplateBase<Test>::get_instance_ptr();
//	Test *pt2 = LASingletonTemplateBase<Test>::get_instance_ptr();
//	Test *pt3 = LASingletonTemplateBase<Test>::get_instance_ptr();
//}

//mutex mt;
//class Singleton
//{
//public:
//	static Singleton* Instance()
//	{
//		if (_instance == nullptr)
//		{
//			mt.lock();
//			if (_instance == nullptr)
//			{
//				_instance = new Singleton;
//			}
//			mt.unlock();
//		}
//		return _instance;
//	}
//protected:
//	Singleton()
//	{
//		cout << "Create SIngleton Obj." <<endl;
//	}
//private:
//	static Singleton* _instance;
//};
//Singleton* Singleton::_instance = nullptr;
//void thread_fun(int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		Singleton *ps = Singleton::Instance();
//		cout << "ps = " << ps << endl;
//	}
//}
//void main()
//{
//	thread t1(thread_fun, 10);
//	thread t2(thread_fun, 10);
//	t1.join();
//	t2.join();
//}

//void main()
//{
//	system("pause");
//	Singleton *pst = Singleton::Instance();
//	Singleton *pst1 = Singleton::Instance();
//	Singleton *pst2 = Singleton::Instance();
//	Singleton *pst3 = Singleton::Instance();
//}

//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	Singleton()
//	{
//		cout << "Create Singleton Obj." << endl;
//	}
//
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance;
//void main()
//{
//	Singleton *ps = Singleton::GetInstance();
//	Singleton *ps1 = Singleton::GetInstance();
//	Singleton *ps2 = Singleton::GetInstance();
//	system("pause");
//}
//class noninherit final
//{
//public:
//};
//class Test : noninherit	//���ܼ̳�
//{};
//void main()
//{
//	Test t;
//}
//class noninherit
//{
//public:
//	static noninherit GetInstace()
//	{
//		return noninherit();
//	}
//private:
//	noninherit()
//	{}
//};
//class Test : public noninherit
//{};
//void main()
//{
//	Test t;		//������
//}

//class noncopyable
//{
//protected:
//	noncopyable(){}
//	~noncopyable(){}
//private:
//	noncopyable(const noncopyable&);
//	const noncopyable& operator=(const noncopyable&);
//};
//class Test : public noncopyable
//{
//public:
//	Test(int data = 0) :m_data(data)
//	{}
//	Test(const Test& t)
//	{
//		m_data = t.m_data;
//	}
//private:
//	int m_data;
//};
//
//void main()
//{
//	Test t1;
//	Test t2 = t1;
//	Test t3;
//	t3 = t1;
//}

//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly() {};
//};
//void main()
//{
//	//StackOnly *psk = new StackOnly;		//������new����
//	StackOnly sk = StackOnly::CreateObject();
//}

//class Test
//{
//public:
//	static Test* GetInstance()
//	{
//		return new Test;
//	}
//public:
//	void fun()
//	{
//		cout << "Test::fun()" << endl;
//	}
//private:
//	Test()
//	{}
//private:
//	int m_data = 0;
//};
//void main()
//{
//	Test *pt = Test::GetInstance();
//	pt->fun();
//}

//FILE* OpenFile(const char *path)
//{
//FILE *p = new FILE;
//cout<<"Open File."<<endl;
//p = fopen(path, "r");
//return p;
//}
//void CloseFile(FILE *fp)
//{
//fclose(fp);
//cout<<"Close File."<<endl;
//}
//void main()
//{
//FILE *fp = OpenFile("C:\\Bit\\bit_kejian\\����.txt");
//shared_ptr<FILE> sp(fp, CloseFile); //ͨ��
//}
//
//class File
//{
//public:
//File(const char *path)
//{
//cout<<"Open File."<<endl;
//fp = fopen(path, "r");
//}
//~File()
//{
//cout<<"Close File."<<endl;
//fclose(fp);
//}
//private:
//FILE *fp;
//};
//void main()
//{
//shared_ptr<File> sp(new File("C:\\Bit\\bit_kejian\\����.txt"));
//}

//template<class T>
//struct FreeFunc
//{
//	void operator()(T* ptr)
//	{
//		cout << "free: " << ptr << endl;
//		free(ptr);
//	}
//};
//
//template<class T>
//struct DeleteArrayFunc
//{
//	void operator()(T* ptr)
//	{
//		cout << "delete[]" << ptr << endl;
//		delete[] ptr;
//	}
//};
//
//void main()
//{
//	FreeFunc<int> freeFunc;
//	int *p = (int*)malloc(4);
//	cout << "p = " << p << endl;
//	shared_ptr<int> sp1(p, freeFunc);
//	DeleteArrayFunc<int> deleteArray;
//	shared_ptr<int> sp2((int*)malloc(4), deleteArray);
//}

//struct ListNode
//{
//	int _data;
//	weak_ptr<ListNode> _Prev;
//	weak_ptr<ListNode> _Next;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//void main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_Next = node2;				//ѭ�����õ��½ڵ㲻���ͷ�
//	node2->_Prev = node1;				//����ѭ������ ����weak_ptr
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//}

//void main()
//{
//	shared_ptr<int> sp(new int(10));
//	shared_ptr<int> sp1 = sp;
//	shared_ptr<int> sp2;
//	sp2 = sp1;
//	cout << "use count = " << sp.use_count() << endl;
//
//	weak_ptr<int> wp = sp;
//	cout << "use count = " << wp.use_count() << endl;
//	if (!wp.expired())
//	{
//		shared_ptr<int> sp3 = wp.lock();
//		cout << "use count = " << sp.use_count() << endl;
//	}
//	cout << "use count = " << sp.use_count() << endl;
//}