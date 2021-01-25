#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
int StrToInt(string str) {
	if (str.empty())
		return 0;
	int symbol = 1;
	if (str[0] == '+')
	{
		symbol = 1;
		str[0] = '0';
	}
	else if (str[0] == '-')
	{
		symbol = -1;
		str[0] = '0';
	}

	int sum = 0;
	int sz = str.size();
	for (int i = 0; i < sz; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			sum = 0;
			break;
		}

		sum += sum * 10 + str[i] - '0';
	}

	return symbol*sum;
}

int main()
{
	StrToInt("123");
	return 0;
}

/*
//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3

int main()
{
	int size = 0;
	cin >> size;
	vector<int> num(size);
	for (int i = 0; i < size; ++i)
		cin >> num[i];

	int result = num[0];
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < size; ++i)
	{
		sum2 = sum1 >= 0 ? sum1 + num[i] : num[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;

		sum1 = sum2;
	}

	cout << result << endl;
	return 0;
}
*/

/*
//���Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
//�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
//�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��

bool isCircle(string str)
{
	size_t start = 0;
	size_t end = str.size() - 1;
	while (start <= end)
	{
		if (str[start] != str[end])
			return false;

		start++;
		end--;
	}

	return true;
}

int main()
{
	string str1, str2;
	int count = 0;
	while (cin >> str1 >> str2)
	{
		int sz = str1.size();
		for (size_t i = 0; i <= sz; ++i)
		{
			string tmp = str1;
			tmp.insert(i, str2);
			if (isCircle(tmp))
				count++;
		}
		cout << count << endl;
	}

	return 0;
}
*/


/*
//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������

int main()
{
	string table = "0123456789ABCDEF", res;
	int m, n;
	cin >> m >> n;

	//��Ǹ�����������ת��Ϊ����ͳһ���������ݱ���������ʱ���ϡ�-����
	bool flag = false;
	if (m < 0)
	{
		flag = true;
		m = 0 - m;
	}

	while (m)
	{
		res += table[m%n];
		m /= n;
	}

	if (flag)
		res += '-';

	reverse(res.begin(), res.end());

	cout << res << endl;

	return 0;
}
*/