#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <vld.h>

using namespace std;

namespace bit
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector() :start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{}
		vector(size_t n, const T&value = T()) :start(nullptr), finish(nullptr), end_of_storage(nullptr) //const T&value = T()    零初始化
		{
			reserve(n);
			while (n-- != 0)
				push_back(value);
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:start(nullptr), finish(nullptr), end_of_storage(nullptr)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		~vector()
		{
			delete []start;
			start = finish = end_of_storage = nullptr;
		}
	public:
		size_t size()const
		{return finish - start;}
		size_t capacity()const
		{return end_of_storage - start;}
		bool empty()const
		{return finish == start;}
	public:
		iterator begin()
		{return start;}
		iterator end()
		{return finish;}
	public:
		void push_back(const T &x)
		{insert(end(), x);}
		iterator insert(iterator pos, const T &x)
		{
			if (finish >= end_of_storage)
			{
				size_t oldpos = pos - start;
				size_t new_cpy = capacity() ? capacity() * 2 : 1;		//capacity()可能一开始为0，容易引发错误
				reserve(new_cpy);

				//重新定位迭代器
				pos = start + oldpos;
			}

			iterator p = finish;
			while (p != pos)
			{
				*p = *(p - 1);
				--p;
			}
			*p = x;
			finish++;
			return pos;
		}
	public:
		void swap(vector &v)
		{
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(end_of_storage, v.end_of_storage);
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T *new_start = new T[n];
				if (start)
				{
					for (int i = 0; i < oldsize; ++i)
					{
						new_start[i] = start[i];
					}
				}

				//释放原有空间
				if (start)
					delete []start;

				start = new_start;
				finish = start + oldsize;
				end_of_storage = start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n <= size())
			{
				finish = start + n;
				return;
			}

			if (n > capacity())
				reserve(n * 2);

			iterator p = finish;
			finish = start + n;
			while (p != finish)
			{
				*p = value;
				p++;
			}
		}
		iterator erase(iterator pos)
		{
			iterator p = pos;
			while (p != finish - 1)
			{
				*p = *(p + 1);
				p++;
			}
			finish--;
			return pos;
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
};

int main()
{
	bit::vector<int> v;
	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;
	v.reserve(2);
	//v.resize(15,1);

	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.begin(), 4);

	//4 100 1 2 3
	auto p = find(v.begin(), v.end(), 1);
	v.insert(p, 100);

	v.push_back(200);

	cout << "size = " << v.size() << endl;
	cout << "capacity = " << v.capacity() << endl;

	p = find(v.begin(), v.end(), 1);
	v.erase(p);

	for (auto &e : v)
		cout << e << " ";
	cout << endl;
	//int ar[] = { 1, 2, 3 };
	//int br[] = { 4, 5, 6 };
	//bit::vector<int> v(ar, ar + 3);
	//bit::vector<int> v1(br, br + 3);
	//for (auto &e : v)
	//	cout << e << " ";
	//cout << endl;
	//for (auto &e : v1)
	//	cout << e << " ";
	//cout << endl;
	//v.swap(v1);
	//for (auto &e : v)
	//	cout << e << " ";
	//cout << endl;
	//for (auto &e : v1)
	//	cout << e << " ";
	//cout << endl;
	//int ar[] = { 1, 2, 3, 4, 5 };
	//bit::vector<int> v(ar, ar + 5);  //int *p1,  int *p2
	//cout << "size = " << v.size() << endl;
	//cout << "capacity = " << v.capacity() << endl;
	//for (auto &e : v)
	//	cout << e << " ";
	//cout << endl;
	return 0;
}

//int main()
//{
//	bit::vector<int> v;
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(2);
//	//v.resize(15,1);
//	v.insert(v.end(), 1);
//	v.insert(v.end(), 2);
//	v.insert(v.end(), 3);
//	v.insert(v.begin(), 4);
//	//4 100 1 2 3
//	auto p = find(v.begin(), v.end(), 1);
//	v.insert(p, 100);
//	v.push_back(200);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	for (auto &e : v)
//		cout << e << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	bit::vector<int> v;
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(10);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(50);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(20);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v{ 1, 2, 3, 4 };
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			it = v.erase(it);
//		else
//			++it;
//	}
//	for (auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	auto p = find(v.begin(), v.end(), 10);
//	auto it = find(v.begin(), v.end(), 3);
//
//	//1 it在删除数据的后面，此时数据会往前移动，迭代器失效
//	//2 it在删除数据的前面，此时迭代器所直数据不会发生变化，迭代器依然有效
//	v.erase(v.begin());//程序崩溃
//	//v.erase(p);	   //程序正常
//	cout << "*it = " << *it << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	auto it = v.begin();
//	cout << "it = " << *it << endl;
//	//v.push_back();
//	v.resize(10);
//	//v.reserve(10);
//	it = v.begin();
//	cout << "it = " << *it << endl;//由于预留空间开辟了新空间导致的迭代器失效
//	return 0;
//}

//int main()
//{
//	vector<int> v = { 1, 2, 3, 4, 5, 6 };
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//
//	auto it = find(v.begin(), v.end(), 3);
//	cout << "it = " << *it << endl;
//	v.push_back(10);
//	it = find(v.begin(), v.end(), 3);
//	cout << "it = " << *it << endl;//此时迭代器未失效
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v2 = { 20, 21, 22, 23, 34, 35 };
//	for (auto &e : v1)
//		cout << e << " ";
//	cout << endl;
//	for (auto &e : v2)
//		cout << e << " ";
//	cout << endl;
//	v1.swap(v2);
//	for (auto &e : v1)
//		cout << e << " ";
//	cout << endl;
//	for (auto &e : v2)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	auto p = find(v1.begin(), v1.end(), 5);
//	auto p1 = find(v1.begin(), v1.end(), 10);
//	//auto it = v1.erase(p, p1);		//[5 6 7 8 9)
//	auto it = v1.erase(p);
//	for (auto &ele : v1)
//		cout << ele << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//
//	//C++11
//	vector<int> v1 = { 1, 2, 3, 4, 5, 67, 8, 9, 10 };
//	auto p = find(v1.begin(), v1.end(), 5);
//	v1.insert(v1.begin(), 100);
//	v1.insert(v1.end(), 200);
//	for (auto &ele : v1)
//		cout << ele << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	for (int i = 1; i <= 10; ++i)
//	{
//		v.push_back(i);
//	}
//	auto it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	v.pop_back();
//
//	for (auto &ele : v)
//		cout << ele << " ";
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	vector<int> v; //动态数组
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(1);  //插入
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//}

//int main()
//{
//	vector<int> v;
//	for (int i = 1; i <= 10; ++i)
//	{
//		v.push_back(i);
//		//v.push_front(i);//error,向量不支持头插但有insert()函数
//	}
//	for (auto &e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	//v.reserve(100);		//如果事先知道需要多少空间，则认为预留空间，减少系统开销
//	for (int i = 0; i<100; ++i)
//	{
//		cout << "capacity = " << v.capacity() << endl;
//		v.push_back(i);
//	}
//}


//void Print(vector<int> &v)
//{
//	for (int i = 0; i<v.size(); ++i)
//		cout << v[i] << " ";
//	cout << endl;
//}
//int main()
//{
//	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v(ar, ar + 10);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//
//	v.resize(15);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//
//	return 0;
//}

//int main()
//{
//	int ar[3] = { 1, 2, 3 };
//	vector<int> v(ar, ar + 3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//	v.reserve(10);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(100);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.reserve(50);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	Print(v);
//
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(1);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(2);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(3);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(4);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(5);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(6);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//	v.push_back(7);
//	cout << "size = " << v.size() << endl;
//	cout << "capacity = " << v.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v4(ar, ar + 10);
//
//	//利用下标[]  operator[]
//	for (int i = 0; i < v4.size(); ++i)
//		cout << v4[i] << " ";
//	cout << endl;
//
//	//利用at() 会检查小标是否越界
//	for (int i = 0; i < v4.size(); ++i)
//		cout << v4.at(i) << " ";
//	cout << endl;
//
//	//利用迭代器
//	vector<int>::iterator it = v4.begin();
//	while (it != v4.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	//利用反向迭代器
//	vector<int>::reverse_iterator rit = v4.rbegin();
//	while (rit != v4.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	//默认构造  veator()
//	vector<int> v1;
//
//	//vector（size_type n, const value_type& val = value_type()） 构造并初始化n个val
//	vector<int> v2(10, 5);
//	for (int i = 0; i < v2.size(); i++)
//		cout << v2[i] << " ";
//	cout << endl;
//	//vector(const vector& x); （重点） 拷贝构造
//	vector<int> v3(v2);
//	for (int i = 0; i < v3.size(); i++)
//		cout << v3[i] << " ";
//	cout << endl;
//
//	//vector( value_type *first, value_type *last);
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	vector<int> v4(ar, ar + 10);
//	for (int i = 0; i<v4.size(); ++i)
//		cout << v4[i] << " ";
//	cout << endl;
//
//	//vector (InputIterator first, InputIterator last);
//	vector<int> v5(v4.begin(), v4.end());
//	for (int i = 0; i<v5.size(); ++i)
//		cout << v5[i] << " ";
//	cout << endl;
//
//	return 0;
//}