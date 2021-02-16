#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

//��������ֵ

int gcd(int a, int b)
{
	int c;
	while (c = a%b)
	{
		a = b;
		b = c;
	}

	return b;
}

int main()
{
	gcd(25, 15);
	int n = 0, power = 0;
	vector<int> num;
	while (cin >> n >> power)
	{
		num.resize(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> num[i];

		for (int k = 0; k < n; k++)
		{
			if (num[k] < power)
				power += num[k];
			else
				power += gcd(power, num[k]);
		}

		cout << power << endl;
	}
	return 0;
}

/*
//�ʼ�Ƶ�������1,2,3,4,5,6�����ȷֳ����飬��������1,2,3����������4,5,6����ϴ�ƹ����а�˳�������6,3,5,2,4,1�������������ٴκϳ�һ����֮����
//�ǰ��մ������µ�˳�������ƣ��ͱ��������1,4,2,5,3,6�� ���ڸ���һ��ԭʼ���飬������⸱��ϴ��k��֮��������µ����С�
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; ++i)
			cin >> table[i];

		//ϴ��k��
		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			for (int i = 0; i < n; ++i)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];
			}
		}

		for (int i = 0; i < num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
}

//��������ֻ����Сд��ĸ���ַ��������������ַ�������󹫹��Ӵ��ĳ��ȡ�
//ע���Ӵ��Ķ���ָһ���ַ���ɾ���䲿��ǰ׺�ͺ�׺��Ҳ���Բ�ɾ�����γɵ��ַ�����

int main()
{

	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0;
		vector<vector<int>> dp(len1, vector<int>(len2, 0));

		for (int i = 0; i < len1; ++i)
		{
			for (int j = 0; j < len2; ++j)
			{
				if (str1[i] == str2[j])
				{
					if (i >= 1 && j >= 1)
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						dp[i][j] = 1;
				}
				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		cout << max << endl;
	}
	return 0;
}

//����һ��ֻ����Сд��ĸ���ַ�����Ȼ��������ַ�����ת����ַ���

string reverse_str(string str)
{
	if (str.empty())
		return str;

	size_t start = 0;
	size_t end = str.size() - 1;

	while (start <= end)
	{
		swap(str[start], str[end]);
		start++;
		end--;
	}

	return str;
}

int main()
{
	string str;
	while (getline(cin, str))
		cout << reverse_str(str) << endl;
	return 0;
}
*/