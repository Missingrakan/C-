#define _CRT_SECURE_NO_WARNINGS 1

//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

class Solution {
public:
	static bool cmp(int x, int y)
	{
		string x_s = to_string(x);
		string y_s = to_string(y);

		string A = x_s;
		A += y_s;
		string B = y_s;
		B += x_s;

		return A < B;
	}

	string PrintMinNumber(vector<int> numbers) {
		sort(numbers.begin(), numbers.end(), cmp);

		string res = "";
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			res += to_string(numbers[i]);
		}

		return res;
	}
};

//给定一个仅由小写字母组成的字符串。现在请找出一个位置，删掉那个字母之后，字符串变成回文。
//请放心总会有一个合法的解。如果给定的字符串已经是一个回文串，那么输出-1。

#include <iostream>
#include <string>

using namespace std;

bool isCycle(string str)
{
	int i = 0;
	int j = str.size() - 1;

	while (i <= j)
	{
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}

	return true;
}

int main()
{
	int num = 0;
	cin >> num;

	while (num)
	{
		string s;
		cin >> s;

		if (isCycle(s))
		{
			cout << -1 << endl;
			num--;
			continue;
		}

		for (size_t i = 0; i < s.size(); ++i)
		{
			string tmp = s;
			tmp.erase(i, 1);
			if (isCycle(tmp))
			{
				cout << i << endl;
				break;
			}
		}

		num--;
	}


	return 0;
}

////输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
////求所有子数组的和的最大值。要求时间复杂度为 O(n).
//
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		int max_value = array[0];
//		int total = array[0];
//
//		for (int i = 1; i < array.size(); ++i)
//		{
//			if (total >= 0)
//				total += array[i];
//			else
//				total = array[i];
//
//			if (max_value < total)
//				max_value = total;
//		}
//
//		return max_value;
//	}
//	/*
//	int FindGreatestSumOfSubArray(vector<int> array) {
//	int max_value = array[0];
//	int *dp = new int[array.size()];
//	dp[0] = array[0];
//
//	for(int i = 1; i < array.size(); ++i)
//	{
//	dp[i] = max(dp[i-1]+array[i], array[i]);
//
//	if(max_value < dp[i])
//	max_value = dp[i];
//	}
//
//	delete dp;
//	return max_value;
//	}
//	*/
//};