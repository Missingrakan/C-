#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
using namespace std;

template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr) : _ptr(ptr), _pRefcount(new int(1)), _pMutex(new mutex)
	{}
	SharedPtr(const SharedPtr<T>& sp) : _ptr(sp._ptr), _pRefcount(sp._pRefcount), _pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	SharedPtr<T>& operator=(SharedPtr<T>& sp)
	{
		if (this != &sp)
		{
			Release();
			_ptr = sp._ptr;
			_pRefcount = sp._pRefcount;
			AddRefCount();
		}
		return *this;
	}
	~SharedPtr()
	{
		Release();
	}
public:
	void AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefcount);
		_pMutex->unlock();
	}
	void Release()
	{
		int deleteflag = false;
		_pMutex->lock();
		if (--(*_pRefcount) == 0)
		{
			delete _ptr;
			delete _pRefcount;
			deleteflag = true;
		}
		_pMutex->unlock();
		if (deleteflag)
			delete _pMutex;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int UseCount()
	{
		return *_pRefCount;
	}
	T* Get()
	{
		return _ptr;
	}
private:
	int* _pRefcount;
	T* _ptr;
	mutex* _pMutex;
};

class Date
{
public:
	Date(){ cout << "Date::Date()" << endl; }
	~Date(){ cout << "Date::~Date()" << endl; }
	int _year = 0;
	int _month = 0;
	int _day = 0;
};

mutex mt;
void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	SharedPtr<Date> copy(sp);
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		//SharedPtr<Date> copy(sp);
		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但
		//是最终看到的结果，并一定是加了2n
		mt.lock();   //把异步进行顺序-->同步机制
		copy->_year++;
		copy->_month++;
		copy->_day++;
		mt.unlock();
	}
}

int main()
{
	SharedPtr<Date> p(new Date);
	cout << p.Get() << endl;
	const size_t n = 10000000;

	thread t1(SharePtrFunc, p, n);   //t1
	thread t2(SharePtrFunc, p, n);   //t2

	t1.join();
	t2.join();

	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	return 0;
}

/*
void main()
{
	SharedPtr<int> sp(new int(10));
	SharedPtr<int> sp1 = sp;
	SharedPtr<int> sp2(new int(20));
	SharedPtr<int> sp3 = sp2;
	sp1 = sp3;
	//SharedPtr<int> sp1(new int(20));
	//SharedPtr<int> sp2 = sp1;
}
*/

/*
//#include <boost/smart_ptr.hpp>
//using namespace boost;

void main()
{
	int *p = new int(10);
	int *q = new int(20);
	shared_ptr<int> sp(p);
	cout << *sp << endl;
	cout << "sp use  count = " << sp.use_count() << endl;
	sp.reset(q);
	cout << *sp << endl;
	cout << "sp use  count = " << sp.use_count() << endl;
	shared_ptr<int> sp1 = sp;
	cout << sp.unique() << endl;
}
*/

/*
void main()
{
	int* p = new int(10);
	shared_ptr<int> sp(p);
	cout << *sp << endl;
	cout << "sp use count = " << sp.use_count() << endl;
	shared_ptr<int> sp1 = sp;
	cout << "sp use count = " << sp.use_count() << endl;
	{
		shared_ptr<int> sp2;
		sp2 = sp1;
		cout << "sp use count = " << sp.use_count() << endl;
	}
	cout << "sp use count = " << sp.use_count() << endl;

}
*/

/*
void main()
{
	int *p = new int(10);
	int *q = new int(20);
	unique_ptr<int> sp(p);   //拥有权不允许转移 相当于boost库scoped_ptr
	cout << *sp << endl;
	unique_ptr<int> sp1;
	sp1 = sp;
}
*/

/*
namespace bit
{
	template<class T>
	class scoped_ptr
	{
	private:
		T* px;
		scoped_ptr(scoped_ptr const &);
		scoped_ptr& operator=(scoped_ptr const &);
		typedef scoped_ptr<T> this_type;
		void operator==(scoped_ptr const&) const;
		void operator!=(scoped_ptr const&) const;
	public:
		typedef T element_type;
		explicit scoped_ptr(T* p = 0) : px(p)
		{}
		~scoped_ptr()
		{
			delete px;
		}
		void reset(T* p = 0)
		{
			this_type(p).swap(*this);
		}
		T& operator*()const
		{
			return *px;
		}
		T* operator->()const
		{
			return px;
		}
		T* Get()const
		{
			return px;
		}
		void swap(scoped_ptr& b)
		{
			T* tmp = b.px;
			b.px = px;
			px = tmp;
		}
	};
}

void main()
{
	int *p = new int(10);
	int *q = new int(20);
	bit::scoped_ptr<int> sp(p);   //拥有权不允许转移
	cout << *sp << endl;
	sp.reset(q);
	cout << *sp << endl;
}
*/

/*
int main()
{
	int *p = new int(10);
	//int *q = new int(20);
	scoped_ptr<int> sp(p);   //拥有权不允许转移
	cout << *sp << endl;
	scoped_ptr<string> sp1(new string("bit"));
	cout << sp1->size() << endl;
	//scoped_ptr<int> sp2;
	//sp2 = sp;

	int *p = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	scoped_array<int> sa(p);  //数组
	cout << sa[0] << endl;

	return 0;
}
*/