#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

#include <vld.h>

using namespace std;

#if 0
//����ȡ��String��ģ��ʵ��
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

	//���������ɵ�Ĭ�Ͽ������캯��Ϊ ǳ����
	String(const String& s)
		: _str(s._str)
	{}

	//���������ɵ�Ĭ�ϸ�ֵ������������� ǳ����
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

//	�������漰����Դ(���ڴ�ռ䣬�ļ�ָ���)����ʱ
//	�û�����Ҫ��ʾʵ�ֿ������캯������ֵ��������أ���������

//���ǳ����

//	1.	���----��ͳ��

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
//	2. ���ʵ�ֶ��������/�ִ���
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

//������ ͳ��ͬһ����Դ��ʹ�õĶ���ĸ���
//��������static��Ա��������ͨ���͵ĳ�Ա����--����

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

//	ǳ���� + ���ü��� ----> ���ǳ�������´�������ĺ��
//	���ǲ����ô��ַ�ʽģ��ʵ��string��
//	����������ʽ��ʵ��string��---> ����String���ж���д����ʱ������ö�����������������Դ�ˣ���Ӧ�ø��ö������һ����Դ
//	COPY ON WRITE	COW��дʱ����

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
		//�����ǰ������������������Դ��
		//�ͱ������ǰ���󵥶�����һ����Դ
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

	// ��Ϊs1��s2��s3���������ڵײ㹲�õ���ͬһ���ڴ�ռ�
	// ���s1��0��λ�õ��ַ��޸�֮��s2��s3Ҳ�ᱻ�޸�
	// ����s1��s2��s3��������ͬ�Ķ���
	// ����Ҫ��s1����ȥ����һ����Դ
	s1[0] = 'H';
	char ch = s1[0];

	return 0;
}

#endif

//��֤��vs�е�string���ǰ�������ķ�ʽʵ�ֵ�

int main()
{
	string s1(20, '#');
	string s2(s1);

	printf("%p\n", s1.c_str());
	printf("%p\n", s2.c_str());
	return 0;
}