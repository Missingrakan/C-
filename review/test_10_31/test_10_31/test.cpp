#define _CRT_SECURE_NO_WARNINGS 1

//写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：
//
//F(0) = 0, F(1) = 1
//F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
//斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。
//
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。

class Solution {
public:
	int fib(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;

		int  f0 = 1;
		int  f1 = 1;
		int  f2 = 2;

		while (n >= 3)
		{
			f2 = (f0 + f1) % 1000000007;
			f0 = f1;
			f1 = f2;

			n--;
		}
		return f2;
	}
};

//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。

class Solution {
public:
	int numWays(int n) {
		if (n == 0 || n == 1)
			return 1;
		int num0 = 1;
		int num1 = 1;
		int num2 = 2;

		while (n >= 2)
		{
			num2 = (num0 + num1) % 1000000007;
			num0 = num1;
			num1 = num2;
			n--;
		}
		return num2;
	}
};

//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
//例如，数组 [3, 4, 5, 1, 2] 为[1, 2, 3, 4, 5] 的一个旋转，该数组的最小值为1。  
//
//示例 1：
//
//输入：[3, 4, 5, 1, 2]
//输出：1
//示例 2：
//
//输入：[2, 2, 2, 0, 1]
//输出：0


class Solution {
public:
	int minArray(vector<int>& numbers) {
		if (numbers.empty())
			return -1;
		if (numbers.size() == 1)
			return numbers[0];

		for (int i = 0; i < numbers.size(); ++i)
		{
			if (i + 1 < numbers.size())
			{
				if (numbers[i + 1] < numbers[i])
					return numbers[i + 1];
			}
			else
				break;
		}
		return numbers[0];
	}
};

/*
class Solution {
public:
	int minArray(vector<int>& numbers) {
		sort(numbers.begin(),numbers.end());
		return numbers[0];
	}
};
*/
