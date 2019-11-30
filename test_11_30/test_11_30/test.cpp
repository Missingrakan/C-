#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
// 1 常方法的const 怎么了
// 不能修改数据成员
//GetData(Test * const this)  ==  GetData()；
//GetData()const == GetData(const Test * const this)；
// 2 GetData() 与 GetData()const 能否共存
//可以共存
//构成函数重载
//const Test t（100）；不能调动GetData() //Test * const this与const Test * const this不兼容
//常对象只能调动常方法
// 3 拷贝构造函数的const 
//Test（const Test &t）
//const ： 不允许更改t所引用对象的数据成员，保护数据
// 4 赋值语句 
//	 operator= ：运算符重载（. ？ ： ：： 不能重载）
//   Test& operator=(const Test &t)  返回类型Test& : 可以连等 const ： 不允许修改t所引用对象的数据成员，保护数据 ； & ：引用 提升效率
//   void  operator=(Test t)  不能连等 ：t1=t2=t3 ：即 t1.operator=(t2.operator=(t3operator=()))


class String
{
public:
	//String(const char *str = NULL)	//说明str是一个空指针
	String(const char *str = "")		//说明str是一个空串
	{
		m_data = (char*)malloc(strlen(str) + 1);
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char*)malloc(strlen(s.m_data) + 1);
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		//1
		if (this != &s)
		{
			//2
			free(m_data);

			//3
			m_data = (char*)malloc(strlen(s.m_data) + 1);
			strcpy(m_data, s.m_data);
		}
		//4
		return *this;
	}
	~String()
	{
		free(m_data);
	}
public:
	void Show()const
	{
		cout << m_data << endl;
	}
private:
	char * m_data;
};

void main()
{
	String s1("Hello");
	//String s2(s1);
	String s2("world");
	s2 = s1;  //s2.m_data = s1.m_data
	s1.Show();
	s2.Show();
}

/*
class String
{
public:
	//String(const char *str = NULL)	//说明str是一个空指针
	String(const char *str = "")		//说明str是一个空串
	{
		m_data = (char*)malloc(strlen(str) + 1);
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char*)malloc(strlen(s.m_data) + 1);
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		//1
		if (this == &s)
			return *this;
		//2
		free(m_data);

		//3
		m_data = (char*)malloc(strlen(s.m_data) + 1);
		strcpy(m_data, s.m_data);

		//4
		return *this;
	}
	~String()
	{
		free(m_data);
	}
public:
	void show()const
	{
		cout << m_data << endl;
	}
private:
	char * m_data;
};

void main()
{
	String s1("hello");
	//String s2(s1);
	String s2("world");
	s2 = s1;
	s1.show();
	s2.show();
}
*/
/*
class String
{
public:
	//String(const char *str = NULL)	//说明str是一个空指针
	String(const char *str = "")		//说明str是一个空串
	{
		m_data = (char*)malloc(strlen(str) + 1);
	}
private:
	char *m_data;
};

void main()
{
	String s1("hello bit.");
}
*/
//说明类里面有默认构造函数
/*
class Test
{
public:
	Test()
	{
		m_data = 0;
	}
private:
	int m_data;
};

void main()
{
	Test t;
	Test t1 = t;
	Test t2;
	t2 = t1;
}
*/
/*
class Test
{
public:
	//普通构造函数
	Test(int d = 0) : m_data(d)	//参数列表 初始化
	{
		cout << "Create Test Object:" << this << endl;
	}
	//拷贝构造函数   //对象初始化对象的时候
	Test(const Test &t)
	{
		cout << "Copy Create Test Object:" << this << endl;
		//t.m_data = 30;   //左值为指定的const对象
		m_data = t.m_data;
	}
	//运算符的重载 = . ？ : ::
	Test& operator=(const Test&t)
	{
		cout << "Assign:" << this << "=" << &t << endl;
		//1.自我赋值检测
		if (this == &t)
			return *this;
		//2.释放当前对象的空间

		//3.重新开辟空间并赋值
		m_data = t.m_data;

		//4.返回当前对象
		return *this;
	}
	//析构函数
	~Test()
	{
		cout << "Free Test Object:" << this << endl;
	}
public:
	//int GetData(Test * const this)
	int GetData()	//不加const时可能在函数内改变m_data
	{
		//m_data = 100;
		return m_data;
	}

	//int GetData(const Test* const this)
	int GetData()const
	{
		//m_data = 100;	//加上const时会报错：表达式必须是可修改的左值	

		return m_data;
		//return (*this).m_data;
	}

	void show()const
	{
		cout << m_data << endl;
	}
private:
	int m_data;
};

void main()
{
	Test t1(10);
	Test &t2 = t1;
	Test &t3 = t2;
	t1 = t3;
}*/
/*
class Test
{
public:
	//普通构造函数
	Test(int d = 0) : m_data(d)	//参数列表 初始化
	{
		cout << "Create Test Object:" << this << endl;
	}
	//拷贝构造函数   //对象初始化对象的时候
	Test(const Test &t)
	{
		cout << "Copy Create Test Object:" << this << endl;
		//t.m_data = 30;   //左值为指定的const对象
		m_data = t.m_data;
	}
	//运算符的重载 = . ？ : ::
	Test& operator=(const Test&t)
	{
		cout << "Assign:" << this << "=" << &t << endl;
		//1 自我赋值
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	//析构函数
	~Test()
	{
		cout << "Free Test Object:" << this << endl;
	}
public:
	//int GetData(Test * const this)
	int GetData()	//不加const时可能在函数内改变m_data
	{
		//m_data = 100;
		return m_data;
	}

	//int GetData(const Test* const this)
	int GetData()const
	{
		//m_data = 100;	//加上const时会报错：表达式必须是可修改的左值	

		return m_data;
		//return (*this).m_data;
	}

	void show()const
	{
		cout << m_data << endl;
	}
private:
	int m_data;
};

Test fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}

void main()
{
	Test t1(10);
	Test &t2 = t1;
	Test &t3 = t2;
	t1 = t3;			//相当于自我赋值
}
*/
/*
void main()
{
	int a, b, c;
	a = b = c = 0;
	Test t0(10);
	Test t1, t2, t3;

	t1 = t2 = t3 = t0;	//t1.operator=(t2.operator=(t3operator=(t0)));
}*/

/*
void main()
{
	Test t(10);
	cout << t.GetData() << endl;
	Test t1;
	t1 = t;		//t1.operator=(t);
	cout << t1.GetData() << endl;
}*/

//void main()
//{
//	//Test t(1);
//	Test t = 1; 
//	Test t0 = t;	//拷贝构造函数  //初始化
//	Test t1;
//	t1 = t;			//赋值语句      //赋值
//}

/*
void main()
{
	Test t(1);
	Test t1(t);            //1.对象初始化对象
	Test t2 = fun(t);      //2.函数传参时相当于对象初始化对象(用t初始化 x) 
	//3.返回值为对象时，不是返回tmp的临时空间而是新开辟一个无名空间再用tmp初始化，此时又是对象初始化对象
}*/
/*
void main()
{
	Test t(1);
	Test t1(t); //等价于 Test t1 = t;

}*/


/*
class Test
{
public:
	Test(int d = 0) : m_data(d)  //参数列表  初始化
	{
		//m_data = 0;  //赋值
	}
public:
	void show()const
	{
		cout << m_data << endl;
	}
private:
	int m_data;
};

void main()
{
	Test t;
	t.show();
}*/