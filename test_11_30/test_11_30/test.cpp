#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;
// 1 ��������const ��ô��
// �����޸����ݳ�Ա
//GetData(Test * const this)  ==  GetData()��
//GetData()const == GetData(const Test * const this)��
// 2 GetData() �� GetData()const �ܷ񹲴�
//���Թ���
//���ɺ�������
//const Test t��100�������ܵ���GetData() //Test * const this��const Test * const this������
//������ֻ�ܵ���������
// 3 �������캯����const 
//Test��const Test &t��
//const �� ���������t�����ö�������ݳ�Ա����������
// 4 ��ֵ��� 
//	 operator= ����������أ�. �� �� ���� �������أ�
//   Test& operator=(const Test &t)  ��������Test& : �������� const �� �������޸�t�����ö�������ݳ�Ա���������� �� & ������ ����Ч��
//   void  operator=(Test t)  �������� ��t1=t2=t3 ���� t1.operator=(t2.operator=(t3operator=()))


class String
{
public:
	//String(const char *str = NULL)	//˵��str��һ����ָ��
	String(const char *str = "")		//˵��str��һ���մ�
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
	//String(const char *str = NULL)	//˵��str��һ����ָ��
	String(const char *str = "")		//˵��str��һ���մ�
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
	//String(const char *str = NULL)	//˵��str��һ����ָ��
	String(const char *str = "")		//˵��str��һ���մ�
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
//˵����������Ĭ�Ϲ��캯��
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
	//��ͨ���캯��
	Test(int d = 0) : m_data(d)	//�����б� ��ʼ��
	{
		cout << "Create Test Object:" << this << endl;
	}
	//�������캯��   //�����ʼ�������ʱ��
	Test(const Test &t)
	{
		cout << "Copy Create Test Object:" << this << endl;
		//t.m_data = 30;   //��ֵΪָ����const����
		m_data = t.m_data;
	}
	//����������� = . �� : ::
	Test& operator=(const Test&t)
	{
		cout << "Assign:" << this << "=" << &t << endl;
		//1.���Ҹ�ֵ���
		if (this == &t)
			return *this;
		//2.�ͷŵ�ǰ����Ŀռ�

		//3.���¿��ٿռ䲢��ֵ
		m_data = t.m_data;

		//4.���ص�ǰ����
		return *this;
	}
	//��������
	~Test()
	{
		cout << "Free Test Object:" << this << endl;
	}
public:
	//int GetData(Test * const this)
	int GetData()	//����constʱ�����ں����ڸı�m_data
	{
		//m_data = 100;
		return m_data;
	}

	//int GetData(const Test* const this)
	int GetData()const
	{
		//m_data = 100;	//����constʱ�ᱨ�����ʽ�����ǿ��޸ĵ���ֵ	

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
	//��ͨ���캯��
	Test(int d = 0) : m_data(d)	//�����б� ��ʼ��
	{
		cout << "Create Test Object:" << this << endl;
	}
	//�������캯��   //�����ʼ�������ʱ��
	Test(const Test &t)
	{
		cout << "Copy Create Test Object:" << this << endl;
		//t.m_data = 30;   //��ֵΪָ����const����
		m_data = t.m_data;
	}
	//����������� = . �� : ::
	Test& operator=(const Test&t)
	{
		cout << "Assign:" << this << "=" << &t << endl;
		//1 ���Ҹ�ֵ
		if (this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	//��������
	~Test()
	{
		cout << "Free Test Object:" << this << endl;
	}
public:
	//int GetData(Test * const this)
	int GetData()	//����constʱ�����ں����ڸı�m_data
	{
		//m_data = 100;
		return m_data;
	}

	//int GetData(const Test* const this)
	int GetData()const
	{
		//m_data = 100;	//����constʱ�ᱨ�����ʽ�����ǿ��޸ĵ���ֵ	

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
	t1 = t3;			//�൱�����Ҹ�ֵ
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
//	Test t0 = t;	//�������캯��  //��ʼ��
//	Test t1;
//	t1 = t;			//��ֵ���      //��ֵ
//}

/*
void main()
{
	Test t(1);
	Test t1(t);            //1.�����ʼ������
	Test t2 = fun(t);      //2.��������ʱ�൱�ڶ����ʼ������(��t��ʼ�� x) 
	//3.����ֵΪ����ʱ�����Ƿ���tmp����ʱ�ռ�����¿���һ�������ռ�����tmp��ʼ������ʱ���Ƕ����ʼ������
}*/
/*
void main()
{
	Test t(1);
	Test t1(t); //�ȼ��� Test t1 = t;

}*/


/*
class Test
{
public:
	Test(int d = 0) : m_data(d)  //�����б�  ��ʼ��
	{
		//m_data = 0;  //��ֵ
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