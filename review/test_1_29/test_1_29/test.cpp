#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



//���дһ��������������ʵ�ֽ������и�����������������
//��������
//
//1.�����ָ���Ϊ�ո�
//2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy / s ��C : \program files�� ��d : \��ʱ��������Ȼ��4������3������Ӧ�����ַ���C : \program files��������C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
//3.����������
//4.������������֤��������ֲ�����Ҫ�������


int main()
{
	string str;
	while (getline(cin, str))
	{
		//ͳ�Ʋ�������
		int count = 0;
		int sz = str.size();
		for (int i = 0; i < sz; ++i)
		{
			if (str[i] == ' ')
				count++;
			//�ԡ����е��ַ����⴦��
			if (str[i] == '"')
			{
				do{
					i++;
				} while (str[i] != '"');
			}
		}

		cout << count + 1 << endl;

		int flag = 1;
		for (int i = 0; i < sz; ++i)
		{
			if (str[i] == '"')
				flag ^= 1;
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//˫�����ڵĿո��ӡ
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//˫������Ŀո���
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}

//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������
//����ĿҪ��������ָ��ż��������������ֵ��С�������ԡ����⺬�ж����������롣

bool isPrime(int n)
{
	int sq = sqrt(n);
	for (int i = 2; i <= sq; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int half = num / 2;
		int i = 0;
		for (i = half; i > 2; ++i)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		}

		cout << num - i << endl << i << endl;
	}
	return 0;
}

//��������32λ����n��m��ͬʱ����i��j����m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ, 
//��֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i - j + 1�����ж����Ƶ�λ����0��ʼ�ɵ͵��ߡ�

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		return n | m;
	}
};

//��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;;
		while (n)
		{
			if (n & 1)
			{
				count++;
				maxcount = max(count, maxcount);
			}
			else
				count = 0;

			n >>= 1;
		}

		cout << maxcount << endl;
	}
	return 0;
}

//��һ����������������Ľ�㰴�����һ��һ��ش������ұ�ţ��������Ϊ1��
//�ָ���a��bΪ������㡣���һ���㷨������a��b����Ĺ������ȵı�š�ע��������Ҳ�����ǽ�㱾��

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}

		return b;
	}
};