#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
//���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
//�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
//���ڸ���һ�����������������������
//
//�������� :
//��������������ݡ�
//ÿ���������ݰ���һ��������n��1��n��10E1000����
//������� :
//��Ӧÿһ�����ݣ��������������������

int numroot(int num)
{
	int root = 0;
	while (num > 0)
	{
		root += num % 10;
		num /= 10;
	}
	while (root > 9)
	{
		root = numroot(root);
	}
	return root;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int sum = 0;
		int size = str.size();
		for (size_t i = 0; i < size; ++i)
			sum += str[i] - '0';

		cout << numroot(sum) << endl;
	}
	return 0;
}

//��Ŀ����
//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
//
//��������:
//���뼸���ǿ��ַ���
//������� :
//�����һ��ֻ����һ�ε��ַ��������������� - 1

int main()
{
	string str;
	while (cin >> str)
	{
		int hashtable[256] = { 0 };
		size_t size = str.size();
		for (size_t i = 0; i < size; ++i)
		{
			hashtable[str[i]]++;
		}
		size_t i = 0;
		for (i = 0; i < size; ++i)
		{
			if (hashtable[str[i]] == 1)
			{
				cout << str[i] << endl;
				break;
			}
		}
		if (i == size)
			cout << -1 << endl;
	}
	return 0;
}

//��Ŀ����
//д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������ַ������Ȳ�����1000��
//
//�������� :
//����N���ַ�
//������� :
//������ַ�����ת����ַ���

string reverse_str(string& s)
{
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;

	while (start < end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return s;

}

int main()
{
	string str;
	getline(cin, str);
	cout << reverse_str(str);
	return 0;
}