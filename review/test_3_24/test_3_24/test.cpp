#include <iostream>

using namespace std;

namespace bit
{
	template<class _Ty>
	class auto_ptr
	{
		typedef auto_ptr<_Ty> _Myt;
	public:
		auto_ptr(_Ty* _Ptr = 0) : _Myptr(_Ptr)
		{}

		auto_ptr(_Myt& _Right) : _Myptr(_Right.release())
		{}

		_Myt& operator=(_Myt& _Right)
		{
			reset(_Right.release());
			return *this;
		}

		~auto_ptr()
		{
			delete _Myptr;
		}
	public:
		_Ty operator*()const
		{
			return *_Myptr;
		}

		_Ty* operator->()const
		{
			return _Myptr;
		}

		_Ty* release()
		{
			_Ty* tmp = _Myptr;
			_Myptr = 0;
			return tmp;
		}

		_Ty* get()const
		{
			return _Myptr;
		}

		void reset(_Ty* _Ptr = 0)
		{
			if (_Ptr != _Myptr)
				delete _Myptr;
			_Myptr = _Ptr;
		}
	private:
		_Ty* _Myptr;
	};
}

void main()
{
	int *p = new int(10);
	int *q = new int(20);
	int *&s = p;
	bit::auto_ptr<int> ap(p);
	cout << *ap << endl;
	ap.reset(s);
	bit::auto_ptr<int> ap1 = ap;
	cout << *ap << endl;			//apΪnullptr���������
}


/*
namespace bit
{
	//vc auto_ptr
	template<class _Ty>
	class auto_ptr
	{
	public:
		auto_ptr(_Ty* _P = 0) : _Owns(_P != 0), _Ptr(_P)
		{}

		auto_ptr(const auto_ptr<_Ty>& _Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
		{}

		auto_ptr<_Ty>& operator=(const auto_ptr<_Ty>& _Y)
		{
			if (this != &_Y)
			{
				if (_Ptr != _Y.get())
				{
					if (_Owns)
						delete _Ptr;
					_Owns = _Y._Owns;
				}
				else if (_Y._Owns)
					_Owns = true;
				_Ptr = _Y.release();
			}

			return *this;
		}

		~auto_ptr()
		{
			if (_Owns)
				delete _Ptr;
		}
	public:
		_Ty operator*()const
		{
			return *_Ptr;
		}

		_Ty* operator->()const
		{
			return _Ptr;
		}
	public:
		_Ty* release()const
		{
			((auto_ptr<_Ty>*)this)->_Owns = false;
			return _Ptr;
		}

		_Ty* get()const
		{
			return _Ptr;
		}
	private:
		bool _Owns;
		_Ty* _Ptr;
	};
}

int main()
{
	int *p = new int(10);
	bit::auto_ptr<int> ap(p);
	cout << *ap << endl;
	bit::auto_ptr<int> ap1 = ap;
	cout << *ap << endl;
	bit::auto_ptr<int> ap2;
	ap2 = ap1;
	return 0;
}
*/