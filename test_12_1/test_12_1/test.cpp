#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
class Int
{
	friend ostream& operator<<(ostream& out,const Int x);
	friend istream& operator>>(istream& in,Int x);

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
		//Int tmp(m_i);
		//m_i++;
		//return tmp;
		Int tmp(*this);
		++*this;
		return tmp;
	}
	Int& operator--()		//--i
	{
		m_i--;
		return *this;
	}
	Int operator--(int)		//--i
	{
		Int tmp(*this);
		--*this;
		return tmp;
	}
public:
	bool operator==(const Int &x)
	{
		return m_i == x.m_i;
	}
	bool operator!=(const Int &x)
	{
		//return m_i != x.m_i;
		return !(*this == x);
	}
	bool operator>(const Int &x)
	{
		return m_i > x.m_i;
	}
	bool operator<=(const Int &x)
	{
		//return m_i <= x.m_i;
		return !(*this > x);
	}
	bool operator<(const Int &x)
	{
		return m_i < x.m_i;
	}
	bool operator>=(const Int &x)
	{
		//return m_i >= x.m_i;
		return !(*this < x);
	}
private:
	int m_i;
};

ostream& operator<<(ostream& out, const Int x)
{
	out<< x.m_i;
	return out;
}

istream& operator>>(istream& in, Int x)
{
	in >> x.m_i;
	return in;
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
*/

class Complex
{
	friend ostream& operator<<(ostream &out, const Complex &c);
	friend Complex operator+(int x, const Complex &c);
public:
	Complex(int real = 0, int imag = 0) : m_real(real), m_imag(imag)
	{}
	~Complex()
	{}
public:
	int GetReal()const
	{return m_real;}
	int  GetImag()const
	{return m_imag;}
public:
	//a + b		a.operator(b) ==>operate+(&a,b);
	Complex operator+(const Complex &c)
	{
		Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
		return tmp;
		//无名临时对象的语法
		//return Complex(m_real+c.m_real,m_imag+c.m_imag);
	}
	Complex operator-(const Complex &c)
	{
		Complex tmp(m_real - c.m_real, m_imag - c.m_imag);
		return tmp;
		//无名临时对象的语法
		//return Complex(m_real-c.m_real,m_imag-c.m_imag);
	}
	//c + x
	Complex operator+(int x)
	{
		Complex tmp(m_real+x, m_imag);
		return tmp;
	}
	//a += b
	Complex& operator+=(const Complex &c)
	{
		m_real += c.m_real;
		m_imag += c.m_imag;
		return *this;
	}
private:
	int m_real;
	int m_imag;
};

//ostream cout
ostream& operator<<(ostream &out, const Complex &c)
{
	out << "(" << c.GetReal() << ":" << c.GetImag() << ")";
	return out;
}
Complex operator+(int x, const Complex &c)
{
	Complex tmp(c.m_real + x, c.m_imag);
	return tmp;
}
void main()
{
	Complex c1(1, 2);
	Complex c2(2, 3);
	Complex c(0, 0);
	c = c1 + c2;
	cout << c << endl;
	c1 += c2;
	cout << c1 << endl;
	//c = c2 + 3;  // c + c
	c = 3 + c2;
	cout << c << endl;
}