#pragma once

#include <assert.h>

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
	public:
		vector()
			: start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{}

		vector(int n, const T& data = T())
			: start(new T[n])
			, finish(start+n)
			, endofstorage(finish)
		{
			for (int i = 0; i < n; ++i)
			{
				start[i] = data;
			}
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			//确定该区间有多少个元素
			Iterator it = first;
			size_t count = 0;
			while (it != last)
			{
				++count;
				++it;
			}

			//给当前对象开辟空间，并初始化成员变量
			start = new[count];
			finish = start;
			endofstorage = start + count;

			//赋值
			while (first != last);
			{
				*finish++ = *first++;
			}
		}

		vector(const vector<T>& v)
		{
			size_t vsize = v.size();
			start = new T[vsize];
			finish = endofstorage = start + vsize;
			for (size_t i = 0; i < vsize; ++i)
				start[i] = v[i];
		}

		vector<T>& vector(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			if (start)
			{
				delete[] start;
				start = finish = endofstorage = nullptr;
			}
		}
	public:
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
	public:
		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return endofstorage - start;
		}

		bool empty()const
		{
			return start == finish;
		}

		void resize(size_t newsize, const T& data = T())
		{

		}

		void reserve(size_t newcapacity)
		{

		}
	public:
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return start[0];
		}

		const T& front()const
		{
			return start[0];
		}

		T& back()
		{
			return start[size() - 1];
		}

		const T& back()const
		{
			return start[size() - 1];
		}
	public:
		void push_back(const T& data)
		{
			if (size() == capacity())
				reserve(capacity() * 2 + 3);

			*finish++ = data;
		}
		void pop_back()
		{
			if (empty())
				return;
			finish--;
		}
	private:
		iterator start;
		iterator finish;
		iterator endofstorage;
	};
}