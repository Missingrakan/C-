#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

//更新能力值

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
//最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我
//们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
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

		//洗牌k次
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

//给定两个只包含小写字母的字符串，计算两个字符串的最大公共子串的长度。
//注：子串的定义指一个字符串删掉其部分前缀和后缀（也可以不删）后形成的字符串。

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

//接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串

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