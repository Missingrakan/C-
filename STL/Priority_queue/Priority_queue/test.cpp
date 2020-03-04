#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <assert.h>

using namespace std;

namespace bit
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};
	template<class T, class Cont = vector<T>, class Pred = less<T>>
	class priority_queue
	{
	public:
		typedef T      value_type;
		typedef size_t size_type;
		explicit priority_queue(const Pred& pr = Pred())
		{
			make_heap(c.begin(), c.end());
		}
		priority_queue(const value_type *first,
			const value_type *last,
			const Pred& pr = Pred());
		bool empty() const
		{
			return c.empty();
		}
		size_type size() const
		{
			return c.size();
		}
		value_type& top()
		{
			assert(!empty());
			return c.front();
		}
		const value_type& top() const
		{
			assert(!empty());
			return c.front();
		}
		void push(const value_type& x)
		{
			c.push_back(x);
			push_heap(c.begin(), c.end());
		}
		void pop()
		{
			pop_heap(c.begin(), c.end());
		}
	protected:
		Cont c;
		Pred comp;
	};
};

void main()
{
	//vector<int> v = {5, 7, 8, 2, 9, 3, 1, 0};
	bit::priority_queue<int> pq;
	cout << "is empty = " << pq.empty() << endl;
	cout << "size = " << pq.size() << endl;
	pq.push(5);
	pq.push(7);
	pq.push(8);
	pq.push(2);
	pq.pop();
	cout << pq.top() << endl;  //8  // 7
}

//int main()
//{
//	vector<int> v = { 5, 7, 8, 2, 9, 3, 1, 0 };
//	for (const auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	sort(v.begin(), v.end(), greater<int>());
//	for (const auto &e : v)
//		cout << e << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 5, 7, 8, 2, 9, 3, 1, 0 };
//	for (const auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	make_heap(v.begin(), v.end());			//制作一个堆
//	for (const auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	v.push_back(6);
//	push_heap(v.begin(), v.end());
//	for (const auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	pop_heap(v.begin(), v.end());
//	for (const auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	pop_heap(v.begin(), --v.end());
//	for (const auto &e : v)
//		cout << e << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 5, 7, 8, 2, 9, 3, 1, 0 };
//	priority_queue<int, vector<int>, greater<int>> pq;			//大堆结构
//	for (const auto &e : v)
//		pq.push(e);
//	cout << "top = " << pq.top() << endl;;
//
//	return 0;
//}