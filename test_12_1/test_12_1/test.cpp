#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Int
{
	friend ostream& operator<<(ostream& out,const Int i);
	friend istream& operator>>(istream& in, Int i);

public:
	Int(int i = 0) : m_i(i)
	{
	}
	~Int()
	{}
public:
	Int operator+(const Int &x)
	{
		Int tmp(m_i + x.m_i);
		return tmp;
	}
	Int operator-(const Int &x)
	{
		Int tmp(m_i - x.m_i);
		return tmp;
		//return Int(m_i - x.m_i);
	}
	Int operator*(const Int &x)
	{
		Int tmp(m_i * x.m_i);
		return tmp;
	}
	Int operator/(const Int &x)
	{
		if (x.m_i != 0)
		{
			Int tmp(m_i / x.m_i);
			return tmp;
		}
		return *this;
	}
	Int operator%(const Int &x)
	{
		Int tmp(m_i % x.m_i);
		return tmp;
	}
public:
	//a+=b;
	Int& operator+=(const Int &x)
	{
		m_i += x.m_i;
		return *this;
	}
	Int& operator-=(const Int &x)
	{
		m_i -= x.m_i;
		return *this;
	}
	Int& operator*=(const Int &x)
	{
		m_i *= x.m_i;
		return *this;
	}
	Int& operator/=(const Int &x)
	{
		m_i /= x.m_i;
		return *this;
	}
	Int& operator%=(const Int &x)
	{
		m_i %= x.m_i;
		return *this;
	}
public:
	Int& operator++()		//++i
	{
		m_i++;
		return *this;
	}
	Int operator++(int)		//i++	tmp为临时对象,不能以引用返回.
	{
		/*Int tmp(m_i);
		m_i++;
		return tmp;*/
		Int tmp(*this);
		++*this;
		return tmp;
	}
	Int& operator--();		//++i
	Int operator--(int);	//++i

private:
	int m_i;
};

ostream& operator<<(ostream& out, const Int i)
{
	out<< i.m_i;
	return out;
}

void main()
{
	Int i1(10);
	Int i2(20);
	Int i3 = i1 + i2;
	Int i4 = i1 - i2;
	Int i5 = i1 * i2;
	Int i6 = i1 / i2;
	Int i7 = i1 % i2;

	i1 += i2;
	i1 -= i2;
	i1 *= i2;
	i1 /= i2;
	i1 %= i2;

	cout << i1 << endl;
	cout << i2 << endl;
	cout << i3 << endl;
	cout << i4 << endl;
	cout << i5 << endl;
	cout << i6 << endl;
	cout << i7 << endl;
	
	cout << i1 << endl;

}
