#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <list>
#include <map>

using namespace std;

class String
{
public:
	String(char *str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(String &&s) : _str(s._str)
	{
		s._str = nullptr;
	}
	String(const String &s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char *ptmp = new char[strlen(s._str) + 1];
			strcpy(ptmp, s._str);
			delete[] _str;
			_str = ptmp;
		}
		return *this;
	}
	String operator+(const String& s)
	{
		char *ptmp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(ptmp, _str);
		strcpy(ptmp + strlen(_str), s._str);
		String strRet(ptmp);
		return strRet;
	}
	~String()
	{
		if (_str)
			delete[] _str;
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);
	return 0;
}

//class Test
//{
//	friend Test Add(Test &a, Test &b);
//public:
//	Test(int data) : m_data(data)
//	{
//		cout << "Create Test Obj :" << this << endl;
//	}
//	Test(const Test &t)
//	{
//		cout << "Copy Create Test Obj :" << this << endl;
//		m_data = t.m_data;
//	}
//private:
//	int m_data = 0;
//};
//
//Test Add(Test &a, Test&b)
//{
//	//Test tmp(a.m_data + b.m_data);
//	//return tmp;
//	return (a.m_data + b.m_data);
//}
//
//void main()
//{
//	const int a = 10;
//	const int &b = a;
//	int &&c = 10;
//	Test t1(10);
//	Test t2(20);
//	Test &&v = Add(t1, t2);
//}

//class Test
//{
//public:
//	Test() = default;
//	Test(int data) : m_data(data)
//	{}
//	Test(const Test &t) = delete;
//private:
//	//Test(const Test &t);
//private:
//	int m_data = 0;
//};
//
//void main()
//{
//	Test t;
//	Test t1 = t;
//}

//void main()
//{
//	map<int, string> ismap;
//	ismap.insert(make_pair(1, "abc"));
//	ismap.insert(make_pair(2, "cyz"));
//	ismap[3] = "lsp";
//	ismap[2] = "str";
//	auto it = ismap.begin();
//	while (it != ismap.end())
//	{
//		cout << it->first << " : " << it->second << endl;
//		++it;
//	}
//	cout << typeid(it).name() << endl;
//
//	decltype(it) it1;
//	it1 = ismap.begin();
//	while (it1 != ismap.end())
//	{
//		cout << it1->first << " : " << it1->second << endl;
//		++it1;
//	}
//}

//template<class Type>
//class MyVector
//{
//public:
//	MyVector(initializer_list<Type> list) :size(0)
//	{
//		capacity = list.size();
//		base = new Type[capacity];
//		for (const auto &e : list)
//			base[size++] = e;
//	}
//private:
//	Type* base;
//	size_t capacity;
//	size_t size;
//};
//
//void main()
//{
//	MyVector<int> mv = { 1, 2, 3, 4, 5 };
//	list<int> mylist = { 1, 2, 3 };
//}

//class Pointer
//{
//public:
//	Pointer(int x,int y) :m_x(x), m_y(y)
//	{}
//private:
//	int m_x;
//	int m_y;
//};
//
//void main()
//{
//	Pointer p1(1, 2);
//	Pointer p2 = { 2, 3 };
//	Pointer pa[]{{ 1, 2 }, { 2, 3 }, { 3, 4 }};
//}

//int main()
//{
//	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	vector<int> v = { 1, 2, 3, 4, 5, 6 };		//c++11
//	list<int> mylist = { 1, 2, 3, 4, 5 };
//	int *ptr = new int[10]{1, 2, 3, 4, 5};
//	return 0;
//}

//struct StrToInt1
//{
//	size_t BKDRHash(const char *str)
//	{
//		register size_t hash = 0;
//		while (size_t ch = (size_t)*str++)
//		{
//			hash = hash * 131 + ch;
//		}
//		return hash;
//	}
//	size_t operator()(const string &str)
//	{
//		return BKDRHash(str.c_str());
//	}
//};
//
//struct StrToInt2
//{
//	size_t SDBMHash(const char *str)
//	{
//		register size_t hash = 0;
//		while (size_t ch = (size_t)*str++)
//		{
//			hash = 65599 * hash + ch;
//		}
//		return hash;
//	}
//	size_t operator()(const string &str)
//	{
//		return SDBMHash(str.c_str());
//	}
//};
//
//struct StrToInt3
//{
//	size_t RSHash(const char *str)
//	{
//		register size_t hash = 0;
//		size_t magic = 63689;
//		while (size_t ch = (size_t)*str++)
//		{
//			hash = hash * magic + ch;
//			magic *= 378551;
//		}
//		return hash;
//	}
//	size_t operator()(const string &str)
//	{
//		return RSHash(str.c_str());
//	}
//};
//
//#define _N 1000
//
//template<class K, class HashFunc1 = StrToInt1,
//				  class HashFunc2 = StrToInt2,
//				  class HashFunc3 = StrToInt3>
//class BloomFilter
//{
//public:
//	BloomFilter() :m_size(0)
//	{}
//public:
//	void Insert(const string &str)
//	{
//		size_t bit_capacity = m_bmp.size();
//		size_t index1 = HashFunc1()(str) % bit_capacity;
//		m_bmp.set(index1);
//		size_t index2 = HashFunc2()(str) % bit_capacity;
//		m_bmp.set(index2);
//		size_t index3 = HashFunc3()(str) % bit_capacity;
//		m_bmp.set(index3);
//		m_size++;
//	}
//	bool Test(const string &str)
//	{
//		size_t bit_capacity = m_bmp.size();
//		size_t index1 = HashFunc1()(str) % bit_capacity;
//		if (!m_bmp.test(index1))
//			return false;
//		size_t index2 = HashFunc2()(str) % bit_capacity;
//		if (!m_bmp.test(index2))
//			return false;
//		size_t index3 = HashFunc3()(str) % bit_capacity;
//		if (!m_bmp.test(index3))
//			return false;
//		return true; //¿ÉÄÜ´æÔÚ
//	}
//private:
//	bitset<_N * 5> m_bmp;
//	size_t		   m_size;
//};
//
//void main()
//{
//	BloomFilter<string> bf;
//	string str0 = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
//	string str1 = "ttps://www.cnb";
//	string str2 = "https://www.cnblogs";
//	string str3 = "https://www.cnblogs.com/clq/archive/2012/05/31/2528153.html";
//
//	bf.Insert(str0);
//	bf.Insert(str1);
//	bf.Insert(str2);
//	bf.Insert(str3);
//
//	cout << bf.Test(str2) << endl;
//	string str = "https://www.cnblogs.com/.clq/archive/2012/05/31/2528153.html";
//	cout << bf.Test(str) << endl;
//	string str4 = "baodu.com";
//	cout << bf.Test(str4) << endl;
//}