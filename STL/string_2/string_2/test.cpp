#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class String
{
public:
	String(const char *str = "")
	{
		m_str = new char[strlen(str) + 1];
		strcpy(m_str, str);
	}
	String(const String &s)
	{
		String tmp(s.m_str);
		std::swap(this->m_str, tmp.m_str);
	}
	String& operator=(const String &s)
	{
		if (this == &s)
		{

		}
		return *this;
	}
	~String()
	{
		if (m_str)
		{
			delete []m_str;
			m_str = nullptr;
		}
	}
private:
	char *m_str;
};

int main()
{

	return 0;
}

//传统写法
//class String
//{
//	friend ostream& operator<<(ostream &out, const String &s);
//public:
//	String(const char *str ="")
//	{
//		m_str = new char[strlen(str) + 1];
//		strcpy(m_str, str);
//	}
//	String(const String &s)
//	{
//		m_str = new char[strlen(s.m_str) + 1];
//		strcpy(m_str, s.m_str);
//	}
//	String& operator=(const String &s)
//	{
//		if (this != &s)
//		{
//			delete []m_str;
//			m_str = new char[strlen(s.m_str) + 1];
//			strcpy(m_str, s.m_str);
//		}
//		return *this;
//	}
//	~String()
//	{
//		//delete[]m_str;
//		if (m_str)
//		{
//			delete []m_str;
//			m_str = nullptr;
//		}
//	}
//private:
//	char *m_str;
//};
//
//ostream& operator<<(ostream &out, const String &s)
//{
//	out << s.m_str;
//	return out;
//}
//
//
//int main()
//{
//	String s;
//	String s1("Bit.");
//	cout << "s1 = " << s1 << endl;
//	String s2 = s1;		//String s2(s1)
//	cout << "s2 = " << s2 << endl;
//	s = s2;
//	cout << "s = " << s << endl;
//
//	return 0;
//}

//int main()
//{
//	string str = "Hello bit.";
//
//	//直接输出
//	cout << str << endl;
//
//	//operator[]
//	for (int i = 0; i < str.size(); ++i)
//	{
//		cout << str[i];
//	}
//	cout << endl;
//	
//	//c++11
//	for (auto &ele : str)
//	{
//		cout << ele;
//	}
//	cout << endl;
//
//	//at()
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << str.at(i);
//	}
//	cout << endl;
//
//	//iterator ++ --
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//	//reverse_iterator
//	string::reverse_iterator rit = str.rbegin();
//	while (rit != str.rend())
//	{
//		cout << *rit;
//		++rit;
//	}
//	cout << endl;
//	string::iterator it1 = str.end()-1;//不减一会访问非法空间
//	while (it1 != str.begin())
//	{
//		cout << *it1;
//		--it1;
//	}
//	cout << *it1;
//	cout << endl;
//
//	return 0;
//}

//size_t find(const string& str, size_t pos = 0)const;
//size_t find(const char *s, size_t pos = 0)const;
//size_t find(const char *s,size_t pos,size_t n)const;
//size_t find(char c, size_t pos = 0)const;

//int main()
//{
//	string email = "178@7035879@qq.com";
//	string substr("86.f");
//	cout << substr << endl;
//	size_t pos = email.find_first_of(substr);
//	cout << pos << endl;
//
//	return 0;
//}

//int main()
//{
//	string email = "178@7035879@qq.com";
//	size_t pos = email.find('@', 3);
//	cout << "pos = " << pos << endl;
//	pos = email.find("569", 4);
//	if (pos == string::npos)
//		cout << "find not." << endl;
//	else
//		cout << "pos = " << pos << endl;
//	string str = "qq";
//	pos = email.find(str);
//	cout << "pos = " << pos << endl;
//
//	return 0;
//}
