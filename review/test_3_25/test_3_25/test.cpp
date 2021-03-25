#include <iostream>
#include <iomanip>
#include <mutex>

using namespace std;

template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr) : _ptr(ptr), _pRefCount(new int(1)), _pMutex(new mutex)
	{}

	SharedPtr(const SharedPtr<T>& sp) : _ptr(sp._ptr), _pRefCount(sp._pRefCount), _pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	SharedPtr<T>& operator=(const SharedPtr<T> &sp)
	{
		if (_ptr != sp._ptr)
		{
			Release();
			
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

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
		(*_pRefCount)++;
		_pMutex->unlock();
	}

	void Release()
	{
		bool deleteflag = false;
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();

		if (deleteflag)
			delete _pMutex;
	}

	T& operator*()const
	{
		return *_ptr;
	}

	T* operator->()const
	{
		return _ptr;
	}

	int UseCount()
	{
		return *_pRefCount;
	}

	T* get()
	{
		return _ptr;
	}
private:
	int* _pRefCount;
	T* _ptr;
	mutex* _pMutex;
};

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

/*
namespace bit
{
	template<class T>
	class scoped_ptr
	{
	private:
		T* px;
		scoped_ptr(scoped_ptr<T> const &);
		scoped_ptr& operator=(scoped_ptr<T> &);
		typedef scoped_ptr<T> this_type;
		bool operator==(scoped_ptr<T> const&)const;
		bool operator!=(scoped_ptr<T> const&)const;
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

		void swap(scoped_ptr<T>& b)
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
	cout << oct << 15 << endl;
	cout << setw(5) << setprecision(3) << 3.1415926;
	return 0;
}
*/
