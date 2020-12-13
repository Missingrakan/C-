#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

//给定一个字符串A和其长度n，请返回一个bool值代表它是否为一个合法的括号串（只能由括号组成）。

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> st;
		for (auto e : A)
		{
			switch (e)
			{
			case '(':
				st.push(e);
				break;
			case ')':
			{
						if (st.empty() || st.top() != '(')
							return false;
						else
							st.pop();
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};

//Fibonacci数列是这样定义的：
//F[0] = 0
//F[1] = 1
//for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
//因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
//输入描述 :
//输入为一个正整数N(1 ≤ N ≤ 1, 000, 000)
//输出描述 :
//输出一个最小的步数变为Fibonacci数"

int main()
{
	int num;
	int f, f0 = 0, f1 = 1;
	int l, r;

	cin >> num;

	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;

		if (f < num)
		{
			l = num - f;
		}
		else
		{
			r = f - num;
			break;
		}
	}

	cout << (l>r ? r : l) << endl;
	return 0;
}

//题目描述
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
//输入描述 :
//输入一个字符串, 包括数字字母符号, 可以为空
//返回值描述 :
//如果是合法的数值表达则返回该数字，否则返回0

class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;

		int symbol = 1;
		if (str[0] == '-')
		{
			symbol = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			symbol = 1;
			str[0] = '0';
		}

		int sum = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}

			sum = sum * 10 + str[i] - '0';
		}

		return symbol * sum;
	}
};

//题目描述
//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1, 2, 1]，和最大的连续子数组为[2, 1]，其和为 3
//输入描述:
//输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，
//即每个元素, 每个整数都在32位int范围内。以空格分隔。
//输出描述 :
//所有连续子数组中和最大的值。


//假设sum[i-1]是以数组中第nums[i-1]为最后一个元素的一段子数组最大和，
//sum[i]是以数组中第nums[i]为最后一个元素的一段子数组最大和，
//那么sum[i] = max(sum[i - 1], 0) + nums[i]，理解了这个，下面代码中用sum1表示sum[i - 1]，
//sum2表示sum[i]，如果计算出更大的子数组和则保存到result中。如果sum[i]，及sum2都小于0了，则置为0，
//因为他加上数组下一个数，不会计算出更大的子数组和

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