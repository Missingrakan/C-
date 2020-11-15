#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//������������ڣ���������һ��ĵڼ��졣��
//
//���������ж��飬ע��ѭ������
//
//�������� :
//������У�ÿ�пո�ָ�ֱ����꣬�£���
//
//������� :
//�ɹ� : ����outDay��������ĵڼ���;
//ʧ��:���� - 1

int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,
		243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;

	int sum = 0;

	while (cin >> year >> month >> day)
	{
		sum = 0;
		if (month > 2)
		{
			//�����ȡÿһ�µ�����ʱʹ�������±꿪ʼ�ģ��ʴ���Ӧ��-2
			sum += array[month - 2];
			sum += day;

			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				sum += 1;
		}
		else
			sum += day;
		cout << sum << endl;
	}
	return 0;
}

//��Ŀ����
//�������������������
//xcopy / s c : \ d : \��
//�����������£�
//����1��������xcopy
//����2���ַ��� / s
//����3���ַ���c : \
//����4 : �ַ���d : \
//���дһ��������������ʵ�ֽ������и�����������������
//��������
//
//1.�����ָ���Ϊ�ո�
//2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy / s ��C : \program files�� ��d : \��ʱ��������Ȼ��4������3������Ӧ�����ַ���C : \program files��������C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
//3.����������
//4.������������֤��������ֲ�����Ҫ�������
//
//�������� :
//����һ���ַ����������пո�
//
//������� :
//��������������ֽ��Ĳ�����ÿ����������ռһ��

int main()
{
	string str;
	while (getline(cin, str))
	{
		//��ͳ����������ĸ���
		int count = 0;
		int size = str.size();
		for (int i = 0; i < size; ++i)
		{
			if (str[i] == ' ')
				count++;
			//�ԡ������������⴦��
			if (str[i] == '"')
			{
				do{
					i++;
				} while (str[i] != '"');
			}
		}

		cout << count + 1 << endl;

		//��flag��ʾ�Ƿ�˫���ţ�0��ʾ��˫����
		//ע�⣺˫�����еĿո�Ҫ��ӡ����
		//����������������flag��ֵ�� ����˫���ſ���ʹ�临ԭ
		int flag = 1;
		for (int i = 0; i < size; ++i)
		{
			//��˫���ţ�flagͨ������Ϊ0����һ��������˫����flag��Ϊ1
			if (str[i] == '"')
				flag ^= 1;
			//��ӡ��ЧԪ��
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//��ӡ˫�����ڵĿո��Ƿ���˫��������flag���
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//����˫��������ľͻ���
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}

//��Ŀ����
//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С�������ԡ�
//���⺬�ж����������롣
//�������� :
//����һ��ż��
//
//������� :
//�����������


bool IsPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//���м俪ʼ�ҷ���������������
		for (i = half; i > 0; --i)
		{
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}