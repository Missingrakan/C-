#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
#include <list>

using namespace std;

namespace bit
{
	template<typename T>
	struct ListNode
	{
		ListNode(const T &val = T())
			:_Next(nullptr), _Prev(nullptr), _Value(val)
		{}
		ListNode<T> *_Next;
		ListNode<T> *_Prev;
		T			_Value;
	};
	template<typename T>
	class ListIterator
	{
		typedef ListIterator slef;
	public:
		ListIterator() :_Ptr(nullptr)
		{}
		ListIterator(ListNode<T> *P) : _Ptr(P)
		{}
		~ListIterator()
		{}
	public:
		T& operator*()
		{
			return _Ptr->_Value;
		}
		const T& operator*()const
		{
			return _Ptr->_Value;
		}
		T* operator->()		//代表指针保存的值即某个变量的地址
		{
			//return &(_Ptr->_Value);
			return &**this;
		}
	public:
		slef& operator++()
		{
			_Ptr = _Ptr->_Next;
			return *this;
		}
		slef operator++(int)
		{
			slef tmp = *this;
			++*this;
			return tmp;
		}
		slef& operator--()
		{
			_Ptr = _Ptr->_Prev;
			return *this;
		}
		slef operator--(int)
		{
			slef tmp = *this;
			--*this;
			return tmp;
		}

		bool operator==(const slef &P)
		{
			return _Ptr == P._Ptr;
		}
		bool operator!=(const slef &P)
		{
			return !(*this == P);
		}
	public:
		ListNode<T>* Mynode()
		{
			return _Ptr;
		}
	private:
		ListNode<T> *_Ptr;
	};
	template<typename T>
	class list
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T> iterator;
		typedef const ListIterator<T> const_iterator;
	public:
		list() :_Head(_Buynode()), _Size(0)
		{}
		list(size_t n, const T&value = T()) :_Head(_Buynode()),_Size(0)
		{
			while (n--)
				push_back(value);
		}
		list(T *first, T *last) :_Head(_Buynode()), _Size(0)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		typedef iterator _It;
		list(_It first, _It last) : _Head(_Buynode()), _Size(0)
		{
			while (first != last)
			{
				push_back(*first);
				first++; 
			}
		}
		list(const list<T> &lt) :_Head(_Buynode()), _Size(0)
		{
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		list<T>& operator=(const list<T> &lt)
		{
			if (this != &lt)
			{
				list<T> tmp(lt);
				swap(tmp);
			}
			return *this;
		}
		~list()
		{
			clear();
			delete _Head;
			_Head = nullptr;
		}
	public:
		size_t size()const
		{
			return _Size;
		}
		bool empty()const
		{
			return _Size == 0;
		}
	public:
		iterator begin()
		{
			return iterator(_Head->_Next);
		}
		const_iterator begin()const
		{
			return const_iterator(_Head->_Next);
		}
		iterator end()
		{
			return iterator(_Head);
		}
		const_iterator end()const
		{
			return const_iterator(_Head);
		}
	public:
		void push_back(const T &val)
		{insert(end(), val);}
		void push_front(const T &val)
		{insert(begin(), val);}
		T& front()
		{
			assert(!empty());
			return *begin();
		}
		const T& front()const
		{
			assert(!empty());
			return *begin();
		}
		T& back()
		{
			assert(!empty());
			return *--end();
		}
		const T& back()const
		{
			assert(!empty());
			return *--end();
		}
		void swap(list<T> &lt)
		{
			std::swap(_Head, lt._Head);
			std::swap(_Size, lt._Size);
		}
		void clear()
		{
			while (size() != 0)
				erase(begin());
			//erase(begin(),end());
		}
	public:
		iterator insert(iterator pos, const T &val)
		{
			PNode _S = new ListNode<int>(val);
			PNode _P = pos.Mynode();

			_S->_Next = _P;
			_S->_Prev = _P->_Prev;
			_S->_Prev->_Next = _S;
			_P->_Prev = _S;

			_Size++;
			return iterator(_S);
		}
		iterator erase(iterator pos)
		{
			PNode p = pos++.Mynode();
			p->_Prev->_Next = p->_Next;
			p->_Next->_Prev = p->_Prev;
			delete p;
			_Size++;
			return pos;
		}
		iterator erase(iterator first, iterator last)
		{
			iterator pos;
			while (first != last)
			{
				pos = erase(first++.Mynode());
			}
			return pos;
		}
	private:
		PNode _Buynode(const T &val = T())
		{
			PNode _S = new ListNode<T>(val);
			_S->_Next = _S->_Prev = _S;
			return _S;
		}
	private:
		ListNode<T> *_Head;
		size_t       _Size;

	};
};

int main()
{
	int ar[] = { 1, 2, 3, 4, 5 };
	bit::list<int> mylist(ar, ar + 5);
	//bit::list<int> youlist(mylist);

	mylist.erase(mylist.begin(), mylist.end());

	for (const auto &e : mylist)
		cout << e << "-->";
	cout << "Over." << endl;
	/*const bit::list<int> mylist;
	for(int i=1; i<=10; ++i)
		mylist.push_back(i);
	mylist.front();
	for(const auto &e : mylist)
		cout<<e<<"-->";
	cout<<"Over."<<endl;
	return 0;*/
}

//int main()
//{
//	bit::list<int> mylist;
//	for (int i = 1; i <= 5; ++i)
//		mylist.push_back(i);
//	//C++11
//	//for(auto &e : mylist)
//	//	cout<<e<<"-->";
//	//cout<<"Over."<<endl;
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it << "-->";
//		it++; //it++
//	}
//	cout << "Over." << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		if (*it == 5)
//			it = mylist.erase(it);			//不影响后面迭代器的使用
//		else
//			it++;
//	}
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//	auto first = find(mylist.begin(), mylist.end(), 3);
//	auto last = find(mylist.begin(), mylist.end(), 8); 
//	auto it = mylist.erase(first, last);				//删除一个区间
//	cout << "it = " << *it << endl;
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Obver." << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto pos = find(mylist.begin(), mylist.end(), 4);
//	auto pos1 = find(mylist.begin(), mylist.end(), 1); 
//	auto pos2 = find(mylist.begin(), mylist.end(), 8); 
//	cout << "pos = " << *pos << endl;
//	cout << "pos1 = " << *pos1 << endl;
//	cout << "pos2 = " << *pos2 << endl;
//	//mylist.push_front(100);		//此时迭代器不会失效
//	pos = mylist.erase(pos);
//	cout << "pos = " << *pos << endl;
//	cout << "pos1 = " << *pos1 << endl;
//	cout << "pos2 = " << *pos2 << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	cout << "size = " << mylist.size() << endl;
//	//cout << "capacity = " >> mylist.capacity << endl;		//error
//	cout << "front = " << mylist.front() << endl;
//	cout << "back = " << mylist.back() << endl;
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	mylist.push_front(100);
//	mylist.push_back(100);
//	mylist.pop_front();
//	mylist.pop_back();
//
//	auto pos = find(mylist.begin(), mylist.end(), 4);
//	mylist.insert(pos, 100);
//	//mylist.clear();
//	cout << "pos = " << *pos << endl;
//	pos = mylist.erase(pos);			//迭代器未更新可能导致迭代器失效
//	cout << "pos = " << *pos << endl;
//
//
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto it1 = mylist.begin();
//	cout << typeid(it1).name() << endl;			//List_iterator
//	*it1 = 100;
//	const list<int> mylist1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto it2 = mylist1.begin();
//	cout << typeid(it2).name() << endl;			//List_const_iterator
//	//*it2 = 100;			//error
//
//	return 0;
//}

//int main()
//{
//	list<int> mylist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	for (const auto &e : mylist)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	list<int>::iterator it = mylist.begin();
//	while (it != mylist.end())
//	{
//		cout << *it << "-->";
//		++it;
//	}
//	cout << "Over." << endl;
//
//	auto it1 = mylist.begin();
//	while (it1 != mylist.end())
//	{
//		cout << *it1 << "-->";
//		++it1;
//	}
//	cout << "Over." <<endl;
//
//	auto rit = mylist.rbegin();
//	while (rit != mylist.rend())
//	{
//		cout << *rit << "-->";
//		++rit;
//	}
//	cout << "Over." << endl;
//
//	list<int>::reverse_iterator rit1 = mylist.rbegin();
//	while (rit1 != mylist.rend())
//	{
//		cout << *rit1 << "-->";
//		++rit1;
//	}
//	cout << "Over." << endl;
//
//	return 0;
//}

//int main()
//{
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	list<int> mylist;
//	list<int> mylist1(10, 2);
//	list<int> mylist2(mylist1);
//	list<int> mylist3(ar, ar + 10);
//	list<int> mylist4(mylist3.begin(), mylist3.end());
//	list<int> mylist5 = { 1, 2, 3, 4, 5 };
//
//	for (const auto &e : mylist5)
//		cout << e << "-->";
//	cout << "Over." << endl;
//
//	return 0;
//}