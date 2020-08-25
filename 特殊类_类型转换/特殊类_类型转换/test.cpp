#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	static Test* GetInstance()
	{
		return new Test;
	}
public:
	void fun()
	{
		cout << "Test::fun()" << endl;
	}
private:
	Test()
	{}
private:
	int m_data = 0;
};
void main()
{
	Test *pt = Test::GetInstance();
	pt->fun();
}

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
//FILE *fp = OpenFile("C:\\Bit\\bit_kejian\\点名.txt");
//shared_ptr<FILE> sp(fp, CloseFile); //通用
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
//shared_ptr<File> sp(new File("C:\\Bit\\bit_kejian\\点名.txt"));
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
//	node1->_Next = node2;				//循环引用导致节点不能释放
//	node2->_Prev = node1;				//避免循环引用 采样weak_ptr
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