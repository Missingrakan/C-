#pragma once

#include <vector>

namespace bit
{
	template<class T>
	class stack
	{
	public:
		stack()
		{}

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top()const
		{
			return _con.back();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}
	private:
		std::vector<T> _con;
	};
}