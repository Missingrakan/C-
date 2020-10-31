#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

#include <vld.h>

using namespace std;

#if 0
//不可取的String类模拟实现
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	//编译器生成的默认拷贝构造函数为 浅拷贝
	String(const String& s)
		: _str(s._str)
	{}

	//编译器生成的默认赋值运算符的重载是 浅拷贝
	String& operator=(const String& s)
	{
		_str = s._str;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};

int main()
{
	String s1("hello world!");
	String s2(s1);

	return 0;
}
#endif

//	当类中涉及到资源(堆内存空间，文件指针等)管理时
//	用户必须要显示实现拷贝构造函数，赋值运算符重载，析构函数

//解决浅拷贝

//	1.	深拷贝----传统版

#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (&s != this)
		{
			char *temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this; 
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};

#endif


#if 0
//	2. 深拷贝实现二：简洁阪/现代版
class String
{
public:
	String(const char* str)
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		: _str(nullptr)
	{
		String temp(s._str);
		swap(_str, temp._str);
	}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char *_str;
};

void TestString()
{
	String s1("hello 0");
	String s2(s1);

	String s3("world");
	s1 = s3;
}

int main()
{
	TestString();
	return 0;
}
#endif

#if 0

//计数： 统计同一份资源被使用的对象的个数
//计数给成static成员变量，普通类型的成员变量--不行

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_pcount = new int(1);
	}

	String(const String& s)
		:_str(s._str), _pcount(s._pcount)
	{
		++*_pcount;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			if (--*_pcount == 0 && _str)
			{
				delete[] _str;
				delete[] _pcount;
			}

			_str = s._str;
			_pcount = s._pcount;

			++*_pcount;
		}

		return *this;
	}

	~String()
	{
		if (--*_pcount == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;

			delete _pcount;
			_pcount = nullptr;
		}
	}
private:
	char* _str;
	int* _pcount;
};

void TestString()
{
	String s1("hello");
	String s2(s1);

	String s3("world");
	String s4(s3);

	s1 = s3;
	s2 = s4;
}

int main()
{
	TestString();
	return 0;
}

#endif

#if 0

//	浅拷贝 + 引用计数 ----> 解决浅拷贝导致代码崩溃的后果
//	但是不能用此种方式模拟实现string类
//	借助上述方式来实现string类---> 当向String类中对象写内容时，如果该对象与其他对象共享资源了，就应该给该对象独立一份资源
//	COPY ON WRITE	COW：写时拷贝

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		_pcount = new int(1);
	}

	String(const String& s)
		:_str(s._str), _pcount(s._pcount)
	{
		AddRef();
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			Release();

			_str = s._str;
			_pcount = s._pcount;

			AddRef();
		}

		return *this;
	}

	~String()
	{
		Release();
	}

	char& operator[](size_t index)
	{
		//如果当前对象与其他对象共享资源了
		//就必须给当前对象单独开辟一份资源
		if (GetRef() > 1)
		{
			SubRef();
			char* tmp = new char[strlen(_str) + 1];
			strcpy(tmp, _str);

			_pcount = new int(1);
			_str = tmp;
		}

		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		return _str[index];
	}
private:
	void AddRef()
	{
		++*_pcount;
	}
	int& SubRef()
	{
		--*_pcount;
		return *_pcount;
	}
	int& GetRef()
	{
		return *_pcount;
	}
	void Release()
	{
		if (SubRef() == 0 && _str)
		{
			delete[] _str;
			_str = nullptr;

			delete[] _pcount;
			_pcount = nullptr;
		}
	}
private:
	char* _str;
	int* _pcount;
};

int main()
{
	String s1("hello");
	String s2(s1);
	String s3(s2);

	// 因为s1、s2、s3三个对象在底层共用的是同一块内存空间
	// 因此s1将0号位置的字符修改之后，s2、s3也会被修改
	// 但是s1、s2、s3是三个不同的对象
	// 所以要让s1单独去管理一份资源
	s1[0] = 'H';
	char ch = s1[0];

	return 0;
}



//验证：vs中的string类是按照深拷贝的方式实现的

int main()
{
	string s1(20, '#');
	string s2(s1);

	printf("%p\n", s1.c_str());
	printf("%p\n", s2.c_str());
	return 0;
}

#endif

#include <assert.h>

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";

			_capacity = strlen(str);
			_size = _capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		string(const string& s)
			: _str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string strtmp(s._str);
			this->swap(strtmp);
		}

		string(size_t n, char ch = char())
			: _str(nullptr)
			, _capacity(n)
			, _size(n)
		{
			memset(_str, ch, n);
			_str[n] = '\0';
		}

		string& operator=(string& s)
		{
			swap(s);
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_capacity = 0;
				_size = 0;
			}
		}

	public:
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + size();
		}

	public:
		size_t size()const

		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		size_t empty()const
		{
			return 0 == _size;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		void resize(size_t newsize, char ch=char())
		{
			size_t oldsize = _size;
			if (newsize > oldsize)
			{
				if (newsize > _capacity)
					reserve(_capacity*2);

				memset(_str + oldsize, ch, newsize - oldsize);
			}

			_str[newsize] = '\0';
			_size = newsize;
		}

		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;
			}
		}

	public:
			char& operator[](size_t index)
			{
				assert(index < _size);
				return _str[index];
			}

			const char& operator[](size_t index)const
			{
				assert(index < _size);
				return _str[index];
			}
	public:
		string& operator+=(char ch)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);

			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}

		string& operator+=(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve((_capacity + len) * 2);
			}
			strcpy(_str + _size, str);
			_size += len;

			return *this;
		}

		string& operator+=(const string& s)
		{
			*this += s._str;
			return *this;
		}

		void push_back(char ch)
		{
			*this += ch;
		}

		string& append(const string& s)
		{
			*this += s;
			return *this;
		}
	public:
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
	public:
		const char* c_str()const
		{
			return _str;
		}
		size_t find(char ch, size_t pos = 0)
		{
			if (pos >= _size)
				return npos;

			for (size_t index = pos; index < _size; ++index)
			{
				if (_str[index] == ch)
					return index;
			}
			return npos;
		}

		size_t rfind(char ch, size_t pos = npos)
		{
			if (pos == npos)
				pos = _size - 1;

			for (int index = pos; index >= 0; --index)
			{
				if (_str[index] == ch)
					return pos;
			}
			return npos;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t string::npos = 1;
}
