#define _CRT_SECURE_NO_WARNINGS 1

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& value = T())
		: prev(nullptr)
		, next(nullptr)
		, data(value)
		{}

		ListNode<T>* prev;
		ListNode<T>* next;
		T data;
	};

	template<class T>
	class ListIterator
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T> self;
	public:
		ListIterator(Node* ptr = nullptr)
			: _ptr(ptr)
		{}

		T& operator*()
		{
			return _ptr->data;
		}

		T* operator->()
		{
			return &_ptr->data;
		}
	public:
		self& operator++()
		{
			_ptr = _ptr->next;
			return *this;
		}

		self operator++(int)
		{
			self temp(*this);
			_ptr = _ptr->next;
			return temp;
		}

		self& operator--()
		{
			_ptr = _ptr->prev;
			return *this;
		}

		self operator--(int)
		{
			self temp(*this);
			_ptr = _ptr->prev;
			return temp;
		}
	public:
		bool operator==(const self& s)const
		{
			return _ptr == s._ptr;
		}
		bool operator!=(const self& s)const
		{
			return _ptr != s._ptr;
		}

		Node* _ptr;
	};

	//反向迭代器的++就是正向迭代器的--
	//反向迭代器的--就是正向迭代器的++
	template<class T, class Iterator>
	class ListReverseIterator
	{
		typedef ListNode<T> Node;
		typedef ListReverseIterator<T, Iterator> self;
	public:
		ListReverseIterator(Node* pNode = nullptr)
			: _it(pNode)
		{}

		ListReverseIterator(Iterator it)
			: _it(it)
		{}

		T& operator*()
		{
			Iterator temp(_it);
			--temp;
			return *temp;
		}

		T* operator->()
		{
			return &(*_it);
		}

		self& operator++()
		{
			--_it;
			return *this;
		}

		self operator++(int)
		{
			_it--;
			return *this;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}
		self& operator--(int)
		{
			_it++;
			return *this;
		}
	public: 
		bool operator!=(const self& s)
		{
			return _it != s._it;
		}

		bool operator==(const self& s)
		{
			return _it == s._it;
		}
	private:
		Iterator _it;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T> iterator;
		typedef ListReverseIterator<T, iterator> reverse_iterator;
	public:
		list()
		{
			CreateHead();
		}

		list(int n, const T& data)
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(data);
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(list<T> &L)
		{
			CreateHead();
			auto it = L.begin();
			while (it != L.end())
			{
				push_back(*it);
				++it;
			}
		}

		~list()
		{
			clear();
			delete head;
			head = nullptr;
		}
	public:
		iterator begin()
		{
			//构造一个匿名对象返回
			return iterator(head->next);
		}

		iterator end()
		{
			return iterator(head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
	public:
		size_t size()const
		{
			size_t count = 0;
			Node* cur = head->next;
			while (cur != head)
			{
				++count;
				cur = cur->next;
			}
			return count;
		}

		bool empty()const
		{
			return head->next == head;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				for (size_t i = newsize; i < oldsize ; ++i)
					pop_back();
			}
			else
			{
				for (int i = oldsize; i < newsize; ++i)
					push_back(data);
			}
		}

	public:
		T& front()
		{
			return *begin();
		}

		const T& front()const
		{
			return *begin();
		}

		T& back()
		{
			return head->prev->data;
		}

		const T& back()const
		{
			return head->prev->data;
		}
	public:
		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		void push_back(const T& data)
		{
			insert(end(), data);
		}

		void pop_back()
		{
			erase(--end());
		}

		iterator insert(iterator pos, const T& data)
		{
			Node* newnode = new Node(data);
			newnode->next = pos._ptr;
			newnode->prev = pos._ptr->prev;
			pos._ptr->prev = newnode;
			newnode->prev->next = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			Node* pnode = pos._ptr;
			Node* pret = pnode->next;

			if (pnode != head)
			{
				pnode->prev->next = pnode->next;
				pnode->next->prev = pnode->prev;
				delete pnode;
			}

			return iterator(pret);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
			}

			return end();
		}

		void clear()
		{
			erase(begin(), end());
		}

		void swap(const list<T>& L)
		{
			std::swap(head, L.head);
		}
	private:
		void CreateHead()
		{
			head = new Node;
			head->next = head;
			head->prev = head;
		}
	private:
		ListNode<T>* head;
	};
}

#include <iostream>
using namespace std;

void TestMyList1()
{
	bit::list<int> L1;
	bit::list<int> L2(10, 5);
	cout << L2.size() << endl;
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5 };
	bit::list<int> L3(array, array + 5);
	for (auto e : L3)
	{
		cout << e << " ";
	}
	cout << endl;

	bit::list<int> L4(L3);
}

// size()
// resize()
void TestMyList2()
{
	int array[] = { 1, 2, 3, 4, 5 };
	bit::list<int> L{ array, array + 5 };

	cout << L.size() << endl;

	L.resize(10, 6);
	cout << L.size() << endl;
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;

	L.resize(3);
	cout << L.size() << endl;
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestMyList()
{
	int array[] = { 1, 2, 3, 4, 5 };
	bit::list<int> L{ array, array + 5 };

	auto it = L.rbegin();
	while (it != L.rend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << L.front() << endl;
	cout << L.back() << endl;

	L.clear();
	if (L.empty())
		cout << L.size() << endl;
}


struct A
{
	int a;
	int b;
	int c;
};

void TestMyList3()
{
	bit::list<A> L;
	A a{ 1, 2, 3 };
	L.push_back(a);

	A* pa = &a;
	pa->a = 10;

	auto it = L.begin();
	it->a = 100;
	it.operator->()->a = 200;  // it->->a;错误
	it.operator++();  // ++it;
}

int main()
{
	//TestMyList1();
	//TestMyList2();
	//TestMyList();
	TestMyList3();
	return 0;
}