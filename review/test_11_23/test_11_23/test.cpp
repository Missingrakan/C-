#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <sstream>

using  namespace std;

#if 0
int main()
{
	int a = 12345678;
	stringstream ss;
	ss << a;
	
	string str;
	ss >> str;
	string ret = ss.str();

	ss.clear();
	ss.str("");
	double d = 12.34;
	ss << d;
	ss >> str;

	ret = ss.str();
	cout << ret << endl;

	return 0;
}

int main()
{
	stringstream ss;
	ss << "hello";
	ss << " ";
	ss << "bit";

	string s;
	ss >> s;
	cout << ss.str() << endl;
	return 0;
}
#endif

#include <string>

#if 0
// 基类/父类
class Person
{
public:
	void Eat()
	{
		cout << "Person::Eat()" << endl;
	}

	void Sleep()
	{
		cout << "Person::Sleeep()" << endl;
	}
private:
	string _name;
	string _gender;
	int _age;
};


class Student : public Person
{
public:
	void Study()
	{
		cout << "Student::Study()" << endl;
	}
private:
	int _stuid;
};

int main()
{
	Student s;
	s.Eat();
	s.Sleep();

	cout << sizeof(Student) << endl;
	return 0;
}
#endif

#if 0
class Person
{
public:
	void Eat()
	{
		cout << "Person::Eat()" << endl;
	}

	void Sleep()
	{
		cout << "Person::Sleeep()" << endl;
	}
private:
	string _name;
	string _gender;
protected:
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		//基类中protected成员在子类中可以直接使用
		//权限：protected
		_age = 18;

		//基类中private修饰的成员在子类中 不可见 (不能直接使用)
		//_name = "lily";
		cout << "Student::Study()" << endl;
	}
private:
	int _stuid;
};

class A : public Student
{
public:
	void Test()
	{
		_age = 10;
	}
};

int main()
{
	Student s;

	// 基类public成员在子类中的访问权限也是public
	s.Eat();
	s.Sleep();

	//s._age = 10;
	cout << sizeof(Student) << endl;
	return 0;
	return 0;
}
#endif

#if 0
//保护继承
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : protected Base
{
public:
	void Test()
	{
		// 基类中public修饰成员在子类中的权限变成protected
		_pub = 10;

		// 基类中protected修饰的成员在子类中的权限也是protected
		_pro = 10;

		// 基类中privage修饰的成员在子类中不可见
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;
		_pro = 30;
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}


//私有继承
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : private Base
{
public:
	void test()
	{
		// 基类中public修饰成员在子类中的权限变成private
		_pub = 10;

		// 基类中protected修饰的成员在子类中的权限也是private
		_pro = 10;

		// 基类中privage修饰的成员在子类中不可见
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;	//err
		_pro = 30;	//err
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}

//默认是私有继承
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : Base
{
public:
	void test()
	{
		// 基类中public修饰成员在子类中的权限变成private
		_pub = 10;

		// 基类中protected修饰的成员在子类中的权限也是private
		_pro = 10;

		// 基类中privage修饰的成员在子类中不可见
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;
		_pro = 30;
	}
};

int main()
{
	Derive d;
	d._pub = 10;
	return 0;
}
#endif


//赋值兼容规则---》 前提：必须是public继承
//1. 子类对象可以向基类对象下行赋值，反过来不行
//2. 基类指针或者引用可以直接指向子类的对象
//3. 子类的指针不能直接指向基类的对象

/*
如果是public的继承方式：
子类和基类的关系：is-a(是一个) 可以将子类对象看成是一个基类对象
对象模型：对象中成员在内存中的分布形式
*/

class Person
{
public:
	void Eat()
	{
		cout << "biajibiaji" << endl;
	}

	void Sleep()
	{
		cout << "huluhulu" << endl;
	}

	string _name;
	string _gender;


private:
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "念书" << endl;
	}


	int _stuid;
};

int main()
{
	/// 1. 子类对象可以给基类对象下行赋值，反过来不行
	Person p;
	Student s;
	p = s;
	//s = p;

	//2.基类指针或引用可以直接指向子类的对象
	Person* pp = &s;
	Person& rp = s;

	// 3. 子类的指针不能直接指向基类的对象,但是强转可以---不安全
	Student* ps = (Student*)&p;
	ps->_name = "lily";
	ps->_gender = "男";
	//ps->_age = 18;
	ps->_stuid = 100;	//err
	return 0;
}