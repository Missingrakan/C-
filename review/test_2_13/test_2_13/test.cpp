#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//超长字符串相加

string addString(string num1, string num2)
{
	//从低位开始运算
	int i = num1.size() - 1;
	int j = num2.size() - 1;

	string res = "";
	int carry = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			carry += num1[i] - '0';
		if (j >= 0)
			carry += num2[i] - '0';

		res += (char)(carry % 10 + '0');
		carry /= 10;

		i--;
		j--;
	}

	if (carry == 1)
		res += '1';

	reverse(res.begin(), res.end());

	return res;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addString(s1, s2) << endl;
	}
}


//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。
int main()
{
	int n = 0, num = 0;
	while (cin >> n)
	{
		//第n行的元素个数
		num = 2 * n - 1;
		vector<vector<int>> vv(n, vector<int>(num, 0));

		//初始化
		vv[0][0] = 1;
		for (int i = 1; i < n; ++i)
		{
			vv[i][0] = vv[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; ++j)
			{
				//对每一行第二个元素特殊处理
				if (j == 1)
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				else
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j - 2];
			}
		}

		int k = 0;
		for (k = 0; k < num; ++k)
		{
			if ((vv[n - 1][k] % 2 == 0) && (vv[n - 1][k] != 0))
			{
				cout << k + 1 << endl;
				break;
			}
		}

		if (k == num)
			cout << -1 << endl;
	}

	return 0;
}

//28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。s
//输入n，请输出n以内(含n)完全数的个数。计算范围, 0 < n <= 500000

int count(int n)
{
	int cnt = 0;
	for (int i = 2; i <= n; ++i)
	{
		int sum = 0;
		int sq = sqrt(i);
		for (int j = 2; j <= sq; ++j)
		{
			if (i%j == 0)
			{
				if (i / j == j)
					sum += j;
				else
					sum += j + i / j;
			}
		}

		if (sum + 1 == i)
			cnt++;
	}

	return cnt;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << count(n) << endl;
	return 0;
}
//在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
//然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，
//才能保证一定能选出一双颜色相同的手套。
//给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组left, right, 
//分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

class Gloves
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		// write code here
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;

		for (int i = 0; i < n; ++i)
		{
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];

			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}

		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

//计算整数二进制中1的个数
int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		while (num)
		{
			if (num & 1)
				count++;
			num >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}