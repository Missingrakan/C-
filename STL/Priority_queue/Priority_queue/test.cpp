#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <assert.h>

using namespace std;

template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Data<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
//全特化
template<>
class Data<int, int>
{
public:
	Data()
	{
		cout << "Data<int, int>" << endl;
	}
private:
	int _d1;
	int _d2;
};
//偏特化		--》局部特化
template<class T>
class Data<T, T>
{
public:
	Data()
	{
		cout << "Data<T,T>" << endl;
	}
private:
	T _d1;
	T _d2;
};

int main()
{
	Data<int, char> d1;
	Data<double, double> d2;
	Data<int, int> d3;
	return 0;
}


////泛化版本
//template<class T>
//bool IsEqual(T &left, T &right)
//{
//	return left == right;
//}
////特殊化版本		--》特化
//template<>
//bool IsEqual<char *>(char *&left,char *&right)
//{
//	return (strcmp(left, right) == 0);
//}
//
//int main()
//{
//	string s1("abc");
//	string s2("xyz");
//	IsEqual(s1, s2);
//	char p1[] = "hello";
//	char p2[] = "hello";
//	if (IsEqual(p1, p2))
//		cout << "Equal" << endl;
//	else
//		cout << "Not Equal" << endl;
//	return 0;
//}

		//类型参数		//非类型参数
//template<class Type, float _N = 10.0> //error
//class Array
//{
//public:
//private:
//	Type Ar[_n];
//};
//
//int main()
//{
//	Array<string> ar;
//	return 0;
//}

//int main()
//{
//	queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	//1 2 3
//	//q.pop();
//	cout<<q.front()<<endl;
//	deque<int> de;
//	de.push_back(1);
//	de.push_back(2);
//	de.push_back(3);
//	//10 1 2 3
//	de.push_front(10);
//	cout << de.front() << endl;
//}

//namespace bit
//{
//	template<class T>
//	struct less
//	{
//		bool operator()(const T& left, const T& right)
//		{
//			return left < right;
//		}
//	};
//	template<class T>
//	struct greater
//	{
//		bool operator()(const T& left, const T& right)
//		{
//			return left > right;
//		}
//	};
//	template<class T, class Cont = vector<T>, class Pred = less<T>>
//	class priority_queue
//	{
//	public:
//		typedef T      value_type;
//		typedef size_t size_type;
//		explicit priority_queue()
//		{}
//		priority_queue(const value_type *first, const value_type *last)
//		{
//			while (first != last)
//				c.push_back(*first++);
//			int root = (c.size() - 1) / 2;
//			while (root >= 0)
//			{
//				adjustdown(root--);			//根据一堆数据构造一个堆结构要向下调整
//			}
//		}
//		bool empty()const
//		{
//			return c.empty();
//		}
//		size_type size()const
//		{
//			return c.size();
//		}
//		value_type& top()
//		{
//			assert(!empty());
//			return c.front();
//		}
//		const value_type& top()const
//		{
//			assert(!empty());
//			return c.front();
//		}
//		void push(const value_type& x)
//		{
//			c.push_back(x);
//			adjustup(c.size() - 1);			//尾插插入到最后一个位置要向上调整；
//		}
//		void pop()
//		{
//			std::swap(c.front(), c.back());
//			c.pop_back();
//			adjustdown(0);				//	尾删的实际操作上是pop_back这个数据，然后拿最后一个数据与第一个数交换，进而要向下调整
//		}
//	public:
//		void show_heap()
//		{
//			for (int i = 0; i < c.size(); ++i)
//				cout << c[i] << " ";
//			cout << endl；
//		}
//	protected:
//		void adjustdown(int parent)
//		{
//			int child = 2 * parent + 1;
//			while (child < c.size())
//			{
//				//判断左树和右树当中最小的一个，且child始终指向最小的
//				if (child + 1 < c.size() && comp(c[child], c[child + 1]))
//					child += 1;
//				if (comp(c[parent], c[child]))
//				{
//					std::swap(c[parent], c[child]);
//					parent = child;
//					child = 2 * parent + 1;
//				}
//				else
//					break;
//			}
//		}
//		void adjustup(int child)
//		{
//			int parent = (child - 1) / 2;
//			while (child)
//			{
//				if (comp(c[parent], c[child]))		//less(c[parent],c[child])
//				{
//					std::swap(c[parent], c[child]);
//					child = parent;
//					parent = (child - 1) / 2;
//				}
//				else
//					break;
//			}
//		}
//	protected:
//		Cont c;
//		Pred comp;
//	};
//};
//
//int main()
//{
//	int v[] = { 5, 7, 8, 2, 9, 3, 1, 0 };
//	int n = sizeof(v) / sizeof(int);
//	bit::priority_queue<int> pq(v, v + n);
//	while (!pq.empty())
//	{
//		cout << "top = " << pq.top() << endl;  //8  // 7
//		pq.pop();
//	}
//}

//int main()
//{
//	//vector<int> v = { 5, 7, 8, 2, 9, 3, 1, 0 };
//	bit::priority_queue<int> pq;
//	//cout<<"is empty = "<<pq.empty()<<endl;
//	//cout<<"size = "<<pq.size()<<endl;
//	pq.push(5);
//	pq.push(70);
//	pq.push(8);
//	pq.push(2);
//	pq.push(9);
//	pq.push(3);
//	pq.push(1);
//	pq.push(0);
//	pq.push(4);
//
//	//pq.show_heap();
//	while (!pq.empty())
//	{
//		cout << "top = " << pq.top() << endl;  //8  // 7
//		pq.pop();
//	}
//	return 0;
//}

//namespace bit
//{
//	template<class T>
//	struct less
//	{
//		bool operator()(const T& left, const T& right)
//		{
//			return left < right;
//		}
//	};
//	template<class T>
//	struct greater
//	{
//		bool operator()(const T& left, const T& right)
//		{
//			return left > right;
//		}
//	};
//	template<class T, class Cont = vector<T>, class Pred = less<T>>
//	class priority_queue
//	{
//	public:
//		typedef T      value_type;
//		typedef size_t size_type;
//		explicit priority_queue(const Pred& pr = Pred())
//		{
//			make_heap(c.begin(), c.end());
//		}
//		priority_queue(const value_type *first,
//			const value_type *last,
//			const Pred& pr = Pred());
//		bool empty() const
//		{
//			return c.empty();
//		}
//		size_type size() const
//		{
//			return c.size();
//		}
//		value_type& top()
//		{
//			assert(!empty());
//			return c.front();
//		}
//		const value_type& top() const
//		{
//			assert(!empty());
//			return c.front();
//		}
//		void push(const value_type& x)
//		{
//			c.push_back(x);
//			push_heap(c.begin(), c.end());
//		}
//		void pop()
//		{
//			pop_heap(c.begin(), c.end());
//		}
//	protected:
//		Cont c;
//		Pred comp;
//	};
//};
//
//void main()
//{
//	//vector<int> v = {5, 7, 8, 2, 9, 3, 1, 0};
//	bit::priority_queue<int> pq;
//	cout << "is empty = " << pq.empty() << endl;
//	cout << "size = " << pq.size() << endl;
//	pq.push(5);
//	pq.push(7);
//	pq.push(8);
//	pq.push(2);
//	pq.pop();
//	cout << pq.top() << endl;  //8  // 7
//}

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