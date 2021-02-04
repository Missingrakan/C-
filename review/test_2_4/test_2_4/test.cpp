#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <memory>
using namespace std;

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

/*
void main()
{
	int *p = new int(10);
	shared_ptr<int> sp(p);
	cout << *sp << endl;
	cout << "sp use  count = " << sp.use_count() << endl;
	shared_ptr<int> sp1 = sp;
	cout << "sp use  count = " << sp.use_count() << endl;
	{
		shared_ptr<int> sp2;
		sp2 = sp1;
		cout << "sp use  count = " << sp.use_count() << endl;
	}
	cout << "sp use  count = " << sp.use_count() << endl;
}
*/

/*
void main()
{
	int *p = new int(10);
	int *q = new int(20);
	unique_ptr<int> sp(p);		//C++11_unique_ptr 拥有权不允许转移  相当于boost::scoped_ptr
	cout << *sp << endl;
	unique_ptr<string> sp1(new string("bit"));
	cout << sp1->size() << endl;
	unique_ptr<int> sp2;
	//sp1 = sp;
}
*/

/*
//#include <boost/smart_ptr.hpp>
//using namespace boost;

void main()
{
	int *p = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	scoped_array<int> sa(p);  //数组
	cout << sa[2] << endl;
}
*/

//namespace bit
//{
//	template<class T>
//	class scoped_ptr
//	{
//	private:
//		T* px;
//		scoped_ptr(scoped_ptr const &);
//		scoped_ptr& operator=(scoped_ptr const&);
//		typedef scoped_ptr<T> this_type;
//		void operator==(scoped_ptr const&)const;
//		void operator!=(scoped_ptr const&)const;
//	public:
//		typedef T element_type;
//		explicit scoped_ptr(T* p = 0) : px(p)
//		{}
//
//		~scoped_ptr()
//		{
//			delete px;
//		}
//
//		void reset(T* p = 0)
//		{
//			this_type(p).swap(*this);
//		}
//
//		T& operator*()const
//		{
//			return *px;
//		}
//
//		T* operator->()const
//		{
//			return px;
//		}
//
//		T* get()const
//		{
//			return px;
//		}
//
//		void swap(scoped_ptr& b)
//		{
//			T* tmp = b.px;
//			b.px = px;
//			px = tmp;
//		}
//	};
//}
//
//void main()
//{
//	int *p = new int(10);
//	int *q = new int(20);
//	bit::scoped_ptr<int> sp(p);   //拥有权不允许转移
//	cout << *sp << endl;
//	sp.reset(q);
//	cout << *sp << endl;
//}
//
///*
//void main()
//{
//	int *p = new int(10);
//	//int *q = new int(20);
//	scoped_ptr<int> sp(p);   //拥有权不允许转移
//	cout<<*sp<<endl;
//	scoped_ptr<string> sp1(new string("bit"));
//	cout<<sp1->size()<<endl;
//	//scoped_ptr<int> sp2;
//	//sp2 = sp;
//}
//*/

//namespace bit
//{
//	//vs auto_ptr
//	template<class _Ty>
//	class auto_ptr
//	{
//		typedef auto_ptr<_Ty> _Myt;
//	public:
//
//		auto_ptr(_Ty* _Ptr = 0) : _Myptr(_Ptr)
//		{}
//
//		auto_ptr(_Myt& _Right) : _Myptr(_Right.release())
//		{}
//
//		_Myt& operator=(_Myt _Right)
//		{
//			reset(_Right.release());
//			return *this;
//		}
//
//		~auto_ptr()
//		{
//			delete _Myptr;
//		}
//	public:
//		_Ty& operator*()
//		{
//			return *_Myptr;
//		}
//
//		_Ty* operator->()
//		{
//			return _Myptr;
//		}
//	public:
//		_Ty* release()
//		{
//			_Ty* _tmp = _Myptr;
//			_Myptr = 0;
//			return (_tmp);
//		}
//
//		_Ty* get()const
//		{
//			return (_Myptr);
//		}
//
//		void reset(_Ty* _Ptr = 0)
//		{
//			if (_Ptr != _Myptr)
//				delete _Myptr;
//			_Myptr = _Ptr;
//		}
//	private:
//		_Ty* _Myptr;
//	};
//}
//
//void main()
//{
//	int *p = new int(10);
//	int *q = new int(20);
//	int *&s = p;
//	bit::auto_ptr<int> ap(p);
//	cout << *ap << endl;
//	ap.reset(s);
//	//bit::auto_ptr<int> ap1 = ap;
//	cout << *ap << endl;
//}

//namespace bit
//{
//	//vc auto_ptr
//	template<class _Ty>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(_Ty* _P = 0) : _Owns(_P != 0), _Ptr(_P)
//		{}
//
//		auto_ptr(const auto_ptr<_Ty>& _Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
//		{}
//
//		auto_ptr<_Ty>& operator=(const auto_ptr<_Ty>& _Y)
//		{
//			//避免自己给自己赋值
//			if (this != &_Y)
//			{
//				//判断两者所指空间是否相同
//				if (_Ptr != _Y.get())
//				{
//					//不同且拥有权为真，释放自身空间
//					if (_Owns)
//						delete _Ptr;
//
//					//拥有权赋值
//					_Owns = _Y._Owns;
//				}
//				//所指空间相同拥有权为真：当前对象拥有权置为真
//				else if (_Owns)
//					_Owns = true;
//
//				//得到所指空间
//				_Ptr = _Y.release();
//			}
//
//			return *this;
//		}
//
//		~auto_ptr()
//		{
//			if (_Owns)
//				delete _Ptr;
//		}
//	public:
//		_Ty& operator*()const
//		{
//			return *_Ptr;
//		}
//
//		_Ty* operator->()const
//		{
//			return _Ptr;
//		}
//	public:
//		_Ty* release()const
//		{
//			((auto_ptr<_Ty>*)this)->_Owns = false;
//			return _Ptr;
//		}
//
//		_Ty* get()const
//		{
//			return _Ptr;
//		}
//	private:
//		bool _Owns;
//		_Ty *_Ptr;
//	};
//}
//
//void main()
//{
//	int *p = new int(10);
//	bit::auto_ptr<int> ap(p);
//	cout << *ap << endl;
//	bit::auto_ptr<int> ap1 = ap;
//	bit::auto_ptr<int> ap2;
//	ap2 = ap1;
//}
///*
//void main()
//{
//	int *p = new int(10);
//	int *q = new int(20);
//	bit::auto_ptr<int> ap1(p);
//	ap1.release();
//	bit::auto_ptr<int> ap2(p);
//	ap2 = ap1;
//}
///*
//void main()
//{
//	int *p = new int(10);
//	int *q = new int(20);
//	bit::auto_ptr<int> ap1(p);
//	bit::auto_ptr<int> ap2(q);
//	cout<<*ap2<<endl;
//	ap2 = ap1;
//	cout<<*ap2<<endl;
//}
//*/