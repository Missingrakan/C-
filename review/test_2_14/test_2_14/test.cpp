#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

#include<iostream>
using namespace std;

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//����̵��ַ�����Ϊs1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//����и����Ĺ����Ӵ������³���
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max
				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}

//��������ˮƿ���Ի�һƿ��ˮ

/*
int main()
{
int number;
while (cin >> number && number != 0)
{
cout << number/2 << endl;
}
return 0;
}
*/

int calculateNum(int n)
{
	int sum = 0;

	//��ƿ���ڵ���2���ܻ�
	while (n >= 2)
	{
		//���ھ��ܺȵ�
		int res = n / 3;
		//������ʣ���ƿ��
		int remainder = n % 3;
		sum += res;

		//�´ο��ÿ�ƿ
		n = res + remainder;

		if (n == 2)
		{
			++sum;
			break;
		}
	}

	return sum;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		if (num == 0)
			continue;
		cout << calculateNum(num) << endl;
	}
	return 0;
}

//*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
//����ƥ��1���ַ�

//����
//te ? t*.*
//txt12.xls
//���
//false


bool match(const char* model, const char* str)
{
	if (*model == '\0' && *str == '\0')
		return true;
	//�����ַ���һ���Ƚ����򷵻�false
	if (*model == '\0' || *str == '\0')
		return false;

	if (*model == '?')
		//������ʱ��ƥ��һ���ַ�
		return match(model + 1, str + 1);
	else if (*model == '*')
		//����*ʱ������ƥ��0��(str��Ų��)��1��(���߶���ǰŲ��)����(str����)
		return match(model + 1, str) || match(model + 1, str + 1) || match(model, str + 1);
	else if (*model == *str)
		return match(model + 1, str + 1);

	return false;
}

int main()
{
	string model, str;
	while (cin >> model >> str)
	{
		bool ret = match(model.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}


//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�
//С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�

int main()
{
	int month = 0;
	while (cin >> month)
	{
		if (month == 1 || month == 2)
		{
			cout << 1 << endl;
			continue;
		}
		int first = 1;
		int second = 1;
		int res = 0;
		for (int i = 3; i <= month; ++i)
		{
			res = first + second;
			first = second;
			second = res;
		}

		cout << res << endl;
	}
	return 0;
}