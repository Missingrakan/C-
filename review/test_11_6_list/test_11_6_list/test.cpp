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

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef ListIterator<T> iterator;
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
	public:
		size_t size()
		{
			size_t count = 0;
			auto it = begin();
			while (it != end())
			{
				++count;
				++it;
			}
			return count;
		}

		bool empty()const
		{
			return head->next == head;
		}

		void resize(size_t newsize, const T& data)
		{
			size_t oldsize = size();
			if (newsize < oldsize)
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

			if (pret != head)
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

	int array[] = { 1, 2, 3, 4, 5 };
	bit::list<int> L3(array, array + 5);

	bit::list<int> L4(L3);
}