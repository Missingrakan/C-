#define _CRT_SECURE_NO_WARNINGS 1

#include "datetime.h"

Date::Date(int year, int month, int day) :_year(year), _month(month), _day(day)
{}
Date::Date(const Date &d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date &d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

bool Date::operator==(const Date &d)const
{
	return (_year == d._year && _month == d._month && _day == d._day);
}
bool Date::operator!=(const Date &d)const
{
	//return _year != d._year || _month != d._month || _day != d._day;
	return !(*this == d);
}
bool Date::operator>(const Date &d)const
{
	//if (_year > d._year)
	//	return true;
	//else if (_year < d._year)
	//	return false;
	//else if (_month > d._month)
	//	return true;
	//else if (_month < d._month)
	//	return false;
	//else if (_day > d._day)
	//	return true;
	//return false;
	return (_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day);
}
bool Date::operator<=(const Date &d)const
{
	return !(*this > d);
}
bool Date::operator<(const Date& d)const
{
	//if (_year < d._year)
	//	return true;
	//else if (_year > d._year)
	//	return false;
	//else if (_month < d._month)
	//	return true;
	//else if (_month > d._month)
	//	return false;
	//else if (_day < d._day)
	//	return true;
	//return false;
	return (_year < d._year)
		|| (_year == d._year && _month < d._month)
		|| (_year == d._year && _month == d._month && _day < d._day);
}
bool Date::operator>=(const Date &d)const
{
	return !(*this < d);
}

ostream& operator<<(ostream &out, const Date &dt)
{
	out << dt._year << "��" << dt._month << "��" << dt._day << "��";
	return out;
}
////////////////////////////////////////////////
bool Isleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
int GetDayByYearMonth(int year, int month)
{
	int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };		//����ÿ�µ�����
	if (month == 2)
	{
		if (Isleap(year))
			month = 0;
	}
	return days[month];
}
Date Date::operator+(int days)
{
	Date tmp = *this;
	int mdays = GetDayByYearMonth(tmp._year, tmp._month);
	//����������ڱ���������������
	while (days + tmp._day > mdays)
	{
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._month = 1;
			tmp._year++;
		}
		mdays = GetDayByYearMonth(tmp._year, tmp._month);
		days -= mdays;
	}
	//����������º�ı�����
	tmp._day += days;
	return tmp;
}
Date Date::operator-(int days)
{
	int mdays;
	Date tmp = *this;
	//������������ȵ�ǰ����СҪ���е���
	while (tmp._day - days < 1)
	{
		tmp._month--;
		if (tmp._month < 1)
		{
			tmp._month = 12;
			tmp._year--;
		}
		mdays = GetDayByYearMonth(tmp._year, tmp._month);
		days -= mdays;
	}
	tmp._day -= days;
	return tmp;
}
//dt1 - dt2
//int Date::operator-(const Date& d)
//{
//	//
//}
//���չ�ʽ��������
//W=(Y-1)+[(Y-1)/4]-[(Y-1)/100]+[(Y-1)/400]+D��
//return W % 7
//D ����day����һ����ۼ�����
int Date::GetWeek()
{
	int D = 0;
	for(int i = 1; i < _month; i++)
	{
		D += GetDayByYearMonth(_year, i);
	}
	D += _day;
	int w = (_year - 1) + (_year - 1) / 4 - (_year - 1) / 100 + (_year - 1) / 400 + D;
	return w % 7;
}
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	++*this;
	return tmp;
}

///////////////////////////////////////////////////
//ostream& operator<<(ostream& out, const Date dt)
//{
//	out << dt._year << "��" << dt._month << "��" << dt._day << "��";
//	return out;
//}
//
//Date::Date(int year,int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//
//Date::Date(const Date &d)
//{
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}
//
//Date& Date::operator=(const Date &d)
//{
//	if (this != &d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	return *this;
//}