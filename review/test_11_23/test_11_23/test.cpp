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
// ����/����
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
		//������protected��Ա�������п���ֱ��ʹ��
		//Ȩ�ޣ�protected
		_age = 18;

		//������private���εĳ�Ա�������� ���ɼ� (����ֱ��ʹ��)
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

	// ����public��Ա�������еķ���Ȩ��Ҳ��public
	s.Eat();
	s.Sleep();

	//s._age = 10;
	cout << sizeof(Student) << endl;
	return 0;
	return 0;
}
#endif

#if 0
//�����̳�
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
		// ������public���γ�Ա�������е�Ȩ�ޱ��protected
		_pub = 10;

		// ������protected���εĳ�Ա�������е�Ȩ��Ҳ��protected
		_pro = 10;

		// ������privage���εĳ�Ա�������в��ɼ�
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


//˽�м̳�
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
		// ������public���γ�Ա�������е�Ȩ�ޱ��private
		_pub = 10;

		// ������protected���εĳ�Ա�������е�Ȩ��Ҳ��private
		_pro = 10;

		// ������privage���εĳ�Ա�������в��ɼ�
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

//Ĭ����˽�м̳�
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
		// ������public���γ�Ա�������е�Ȩ�ޱ��private
		_pub = 10;

		// ������protected���εĳ�Ա�������е�Ȩ��Ҳ��private
		_pro = 10;

		// ������privage���εĳ�Ա�������в��ɼ�
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


//��ֵ���ݹ���---�� ǰ�᣺������public�̳�
//1. ���������������������и�ֵ������������
//2. ����ָ��������ÿ���ֱ��ָ������Ķ���
//3. �����ָ�벻��ֱ��ָ�����Ķ���

/*
�����public�ļ̳з�ʽ��
����ͻ���Ĺ�ϵ��is-a(��һ��) ���Խ�������󿴳���һ���������
����ģ�ͣ������г�Ա���ڴ��еķֲ���ʽ
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
		cout << "����" << endl;
	}


	int _stuid;
};

int main()
{
	/// 1. ���������Ը�����������и�ֵ������������
	Person p;
	Student s;
	p = s;
	//s = p;

	//2.����ָ������ÿ���ֱ��ָ������Ķ���
	Person* pp = &s;
	Person& rp = s;

	// 3. �����ָ�벻��ֱ��ָ�����Ķ���,����ǿת����---����ȫ
	Student* ps = (Student*)&p;
	ps->_name = "lily";
	ps->_gender = "��";
	//ps->_age = 18;
	ps->_stuid = 100;	//err
	return 0;
}