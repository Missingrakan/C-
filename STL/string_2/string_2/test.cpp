#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
		friend istream& operator>>(istream &_cin, bit::string &s);
	public:
		typedef char* iterator;
		static const size_t npos = -1;
	public:
		string(const char *str = "") :m_str(nullptr)
		{
			m_capacity = m_size = strlen(str);
			m_str = new char[m_capacity + 1];		//要放'\0';
			strcpy(m_str, str);
		}
		string(const string &s) :m_str(nullptr), m_capacity(0), m_size(0)
		{
			string tmp(s.m_str);
			_swap(*this, tmp);
		}
		string& operator=(const string &s)
		{
			if (this != &s)
			{
				string tmp(s);
				_swap(*this, tmp);
			}
			return *this;
		}
		~string()
		{
			if (m_str)
			{
				delete[]m_str;
				m_str = nullptr;
			}
			m_capacity = m_size = 0;
		}
	public:
		iterator begin()
		{
			return m_str;
		}
		iterator end()
		{
			return m_str + m_size;
		}
	public:
		size_t size()const
		{
			return m_size;
		}
		size_t capacity()const
		{
			return m_capacity;
		}
		bool empty()const
		{
			return m_size == 0;
		}
		void clear()
		{
			m_size = 0;
			m_str[0] = '\0';
		}
	public:
		const char* c_str()const
		{
			return m_str;
		}
		char& operator[](int i)
		{
			assert(i >= 0 && i < m_size);
			return m_str[i];
		}
		void reserve(size_t new_capacity)
		{
			if (new_capacity > m_capacity)
			{
				char* new_str = new char[new_capacity + 1];
				memcpy(new_str, m_str, m_size);
				m_capacity = new_capacity;
				delete[]m_str;
				m_str = new_str;
			}
		}
		void push_back(char c)
		{
			if (m_size == m_capacity)
				reserve(m_capacity + 2);
			m_str[m_size++] = c;
			m_str[m_size] = '\0';
		}
	public:
		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		void append(const char* str)
		{
			/*while (*str)
			{
				push_back(*str);
				str++;
			}*/
			int str_len = strlen(str);
			if (str_len + m_size > m_capacity)
			{
				reserve((m_capacity + str_len) * 2);
			}
			strcpy(m_str + m_size, str);
			m_size += str_len;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void resize(size_t newSize, char c = '\0')
		{
			if (newSize > m_size)
			{
				if (newSize > m_capacity)
				{
					reserve(newSize*2);
				}
				memset(m_str + m_size, c, newSize - m_size);
			}
			m_size = newSize;
			m_str[newSize] = '\0';
		}
		const char& operator[](size_t index)const
		{
			assert(index < m_size);
			return m_str[index];
		}
	public:
		bool operator<(const string& s)
		{
			return (strcmp(m_str, s.m_str) < 0);
		}
		bool operator>=(const string& s)
		{
			return !(*this<s);
		}
		bool operator>(const string& s)
		{
			return (strcmp(m_str, s.m_str) > 0);
		}
		bool operator<=(const string& s)
		{
			return !(*this > s);
		}
		bool operator==(const string& s)
		{
			return (strcmp(m_str, s.m_str) == 0);
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (int i = pos; i < m_size; ++i)
			{
				if (m_str[i] == c)
					return i;
			}
			return npos;
		}
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			size_t i = pos, j = 0;
			size_t s_len = strlen(s);
			while (i < m_size && j < s_len)
			{
				if (m_str[i] == s[j])
				{
					i++;
					j++;
				}
				else
				{
					i = i - j + 1;
					j = 0;
				}
			}
			if (j >= s_len)
			{
				return i - j;
			}
			return npos;
		}
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			if (m_size + 1 > m_capacity)
			{
				reserve(((m_size + 1) * 2));
			}
			for (size_t i = m_size; i > pos; --i)
			{
				m_str[i] = m_str[i - 1];
			}
			m_str[pos] = c;
			m_size++;
			m_str[m_size] = '\0';
			return *this;
		}
		string& insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len)
		{
			memcpy(m_str + pos, m_str + pos + len, m_size - pos - len + 1);
			m_size -= len;
			return *this;
		}
	protected:
		static void _swap(string &s1, string &s2)
		{
			std::swap(s1.m_str, s2.m_str);
			std::swap(s1.m_capacity, s2.m_capacity);
			std::swap(s1.m_size, s2.m_size);
		}
	private:
		char * m_str;
		size_t m_capacity;
		size_t m_size;
	};

	ostream& operator<<(ostream &out, const string &s)
	{
		out << s.m_str;
		return out;
	}

	istream& operator>>(istream &_cin, bit::string &s)
	{
		static const size_t default_buf_size = 10;
		int capacity = default_buf_size;
		//char *str = (char*)malloc(sizeof(char)*default_buf_size);
		char *str = new char[capacity];
		char *buf = str;
		size_t count = 1;//字符个数

		//跳过字符串起始位置的空格或者换行
		while ((*buf = getchar()) == ' ' || (*buf == '\n'))
		{}
		for (;;)
		{
			if (*buf == '\n' || *buf == ' ')
			{
				*buf = '\0';
				break;
			}
			else if (count >= capacity)
			{
				capacity *= 2;
				//str = (char*)realloc(str, capacity);
				char *new_str = new char[capacity];		//申请空间
				memcpy(new_str, str, count);
				delete []str;
				str = new_str;
				//重新定位buf的位置
				buf = str + count - 1;
			}
			*++buf = getchar();
			count++;
		}

		s.m_str = str;
		s.m_capacity = capacity;
		s.m_size = count;
		return _cin;
	}
};

int main()
{
	bit::string str;
	cin >> str;
	cout << str << endl;
	//bit::string str("abcABCxyzXYZ@qq.com");
	//cout << "size = " << str.size() << endl;
	//cout << "capacity = " << str.capacity() << endl;
	//str.erase(3, 3);
	//cout << "size = " << str.size() << endl;
	//cout << "capacity = " << str.capacity() << endl;
	//cout << str << endl;
	//return 0;
}

//int main()
//{
//	
//	bit::string str("365692697690203@qq.com");
//	cout << "size = " << str.size() << endl;
//	cout << "capacity = " << str.capacity() << endl;
//	str.insert(6, '@');
//	cout << "size = " << str.size() << endl;
//	cout << "capacity = " << str.capacity() << endl;
//	cout << str << endl; //("365692 @ 697690203@qq.com");
//	return 0;
//}

//int main()
//{
//	bit::string str = "hello world";
//	string str1 = "Hello linux!";
//	cout << "str = " << str << endl;
//	str += '!';
//	cout << "str = " << str << endl;
//	str.append("Hello C++!");
//	cout << "str = " << str << endl;
//	str += "Hello C++!";
//	cout << "str = " << str << endl;
//	str.resize(50,'x');
//	cout << "str = " << str << endl;
//
//	return 0;
//}

//int main()
//{
//	bit::string str("hello C++");
//	cout << "str = " << str << endl;
//	str.push_back('x');
//	cout << "str = " << str << endl;
//
//	return 0;
//}

//int main()
//{
//	bit::string str("Hello C++");
//	cout << "str = " << str << endl;
//	const char *res = str.c_str();
//	cout << "res = " << res << endl;
//
//	return 0;
//}

//int main()
//{
//	bit::string str("Hello C++");
//	cout << "str = "<<str<<endl;
//	for (int i = 0; i<str.size(); ++i)
//	{
//		cout << str[i];
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	bit::string str("C++");
//	cout << "str = " << str << endl;
//
//	bit::string str1 = str;
//	cout << "str1 = " << str1 << endl;
//
//	bit::string str2;
//	str2 = str1;
//	cout << "str2 = " << str2 << endl;
//
//	bit::string::iterator it = str2.begin();
//	while (it != str2.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//class String
//{
//	friend ostream& operator<<(ostream &out,const String &s);
//
//public:
//	String(const char *str = "")
//	{
//		m_str = new char[strlen(str) + 1];
//		strcpy(m_str, str);
//	}
//	String(const String &s) :m_str(nullptr)
//	{
//		String tmp(s.m_str);
//		std::swap(this->m_str, tmp.m_str);
//	}
//	String& operator=(const String &s)
//	{
//		if (this != &s)
//		{
//			String tmp(s.m_str);
//			std::swap(m_str, tmp.m_str);
//		}
//		return *this;
//	}
//	~String()
//	{
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
//int main()
//{
//	String str1("Bit.");
//	cout << "str1 = " << str1 << endl;
//
//	String str2 = str1;
//	cout << "str2 = " << str2 << endl;
//
//	String str3("Hello");
//	str3 = str2;
//	cout << "str3 = " << str3 << endl;
//
//	return 0;
//}

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
