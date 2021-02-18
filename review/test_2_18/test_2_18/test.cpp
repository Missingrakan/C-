#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>

using namespace std;

void OutOfMemory()
{
	//�ͷſռ�
	//����������
	cout << "Out Of Memory." << endl;
	exit(1);
}
void main()
{
	//set_new_handler(OutOfMemory);  //����û�δ����˺���������ռ�ʧ��ʱ�����׳��쳣�����򽫻�����û�����ĺ���
	try
	{
		int *p = new int[536870911];  //malloc
		cout << "new OK" << endl;
		delete[]p;
	}
	catch (bad_alloc &e)
	{
		cout << e.what() << endl;
	}
}

//namespace bit
//{
//	template<class T>
//	T* _allocate(size_t size, T*)
//	{
//		cout << typeid(T).name() << endl;
//		T* tmp = (T*)(::operator new(size*sizeof(T)));
//		if (tmp == 0)
//		{
//			cout << "Out of memory" << endl;
//			exit(1);
//		}
//		return tmp;
//	}
//
//	template<class T>
//	void _deallocate(T* buffer)
//	{
//		::operator delete(buffer);
//	}
//
//	template<class T1, class T2>
//	void _construct(T1* p, const T2 &value)
//	{
//		new(p) T1(value);
//	}
//
//	template<class T>
//	void _destroy(T *ptr)
//	{
//		ptr->~T();
//	}
//
//	template<class T>
//	class allocator
//	{
//	public:
//		//������ȡ
//		typedef T        value_type;
//		typedef T*       pointer;
//		typedef T&       reference_type;
//		typedef const T* const_pointer;
//		typedef const T& const_reference;
//		typedef size_t   size_type;
//		typedef size_t   difference_type;
//	public:
//		pointer allocate(size_type n, const void *hint = 0)
//		{
//			return _allocate(n, (pointer)nullptr);
//		}
//		void deallocate(pointer p, size_type n)
//		{
//			_deallocate(p);
//		}
//		void construct(pointer p, const T& value)
//		{
//			_construct(p, value);
//		}
//		void destroy(pointer p)
//		{
//			_destroy(p);
//		}
//	};
//}
//
//void main()
//{
//	list<int, bit::allocator<int> > lt;
//	vector<int, bit::allocator<int> > iv(1);
//}

//class Base
//{
//public:
//	virtual void fun()const
//	{
//		cout << "This is Base::fun()" << endl;
//	}
//private:
//	int m_a = 0;
//};
//
//class D : public Base
//{
//public:
//	void fun()const
//	{
//		cout << "This is D::fun()" << endl;
//	}
//
//	void show()const
//	{
//		cout << "This is D::show()" << endl;
//	}
//private:
//	int m_d = 0;
//};
//
//void Active(Base* pb)
//{
//	pb->fun();
//	//(dynamic_cast<D*>(pb))->show();			//��Ӧ���ʹ��
//	D* pd = dynamic_cast<D*>(pb);				//���ڼ������ת���ĺϷ���
//	if (pd != NULL)
//		pd->show();
//	else
//		cout << "�Ƿ���ת��......." << endl;
//
//}
//
//void main()
//{
//	D d;
//	Base b;
//	Active(&b);
//}

//class A
//{
//private:
//	int m_a = 0;
//};
//class B
//{
//private:
//	int m_b = 0;
//};
//class D : public A, public B
//{
//	int m_d = 0;
//};
//
//void main()
//{
//	D d;
//	printf("%p, %p, %p\n", &d, static_cast<B*>(&d), reinterpret_cast<B*>(&d));		//006FFB70, 006FFB74, 006FFB70
//}

//void main()
//{
//	double d = 3.14;
//	int *p2 = reinterpret_cast<int*>(&d);			//ʹ��reinterpret_cast<>����ȡ�ô�����
//	cout << *p2 << endl;
//}

//int main()
//{
//	const int a = 10;
//	//int *p = &a;
//	int *pa = const_cast<int*>(&a);		//����ȥ��const��volatile
//	cout << *pa << endl;
//
//	volatile int b = 20;
//	//int *p = &b;
//	int *pb = const_cast<int*>(&b);
//	cout << *pb << endl;
//
//	double d = 3.14;
//	//int *pd = const_cast<int*>(&d);			//error
//
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	double d = 3.14;
//	a = static_cast<int>(d);		//�����滻C����ʽת��
//	cout << a << endl;
//	//int *p = static_cast<int*>(&d);		//error
//	//cout << *p << endl;
//}