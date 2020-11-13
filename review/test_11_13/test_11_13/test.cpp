#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


#include <queue>
#include <vector>
#include <functional>

#include "priority_queue.h"

int main()
{
	// 注意：默认按照小于进行比较
	//      大堆
	priority_queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	q1.pop();
	cout << q1.top() << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());

	cout << q2.top() << endl;
	return 0;
}

#if 0
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return _day < d._day;
	}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}


	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2020, 11, 12);
	Date d0(2020, 11, 11);
	Date d2(2020, 11, 13);

	priority_queue<Date> q1;
	q1.push(d1);
	q1.push(d0);
	q1.push(d2);

	return 0;
}
#endif
/*
int main()
{
	vector<int> v{ 3, 2, 5, 1, 4 };
	bit::priority_queue<int> q{ v.begin(), v.end() };
	q.push(0);
	return 0;
}
*/