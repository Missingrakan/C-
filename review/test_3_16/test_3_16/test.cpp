#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//给定一个整数数组 nums?和一个整数目标值 target，请你在该数组中找出 和为目标值 的那?两个?整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//你可以按任意顺序返回答案。

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end())
			{
				return{ it->second, i };
			}
			hashtable[nums[i]] = i;
		}
		return{};
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			int j;
			for (j = i + 1; j < n; ++j)
			{
				if (nums[i] + nums[j] == target)
					return{ i, j };
			}
		}
		return{};
	}
};

//背包问题

class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		if (A.empty() || V.empty() || m < 0)
			return 0;

		int N = A.size() + 1;
		int M = m + 1;
		vector<vector<int>> dp;
		dp.resize(N);

		for (int i = 0; i < N; ++i)
		{
			dp[i].resize(M, 0);
		}

		for (int i = 1; i < N; ++i) {
			for (int j = 1; j != M; ++j) {
				//第i个商品在A中对应的索引为i-1: i从1开始
				//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
				if (A[i - 1] > j) {
					dp[i][j] = dp[i - 1][j];
				}
				//如果可以装下，分两种情况，装或者不装
				//如果不装，则即为(i-1, j)
				//如果装，需要腾出放第i个物品大小的空间： j - A[i-1],装入之后的最大价值即为(i - 1,j - A[i - 1]) + 第i个商品的价值V[i - 1]
					//最后在装与不装中选出最大的价值
				else {
					int newValue = dp[i - 1][j - A[i - 1]] + V[i - 1];
					dp[i][j] = max(newValue, dp[i - 1][j]);
				}
			}
		}

		return dp[N - 1][m];
	}
};

int main()
{
	Solution s;
	vector<int> A = { 2, 3, 5, 7 };
	vector<int> V = { 1, 5, 2, 4 };
	s.backPackII(10, A, V);
	return 0;
}

/*
class Date
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	Date* p = NULL;
	p->PrintA();
	p->Show();
}
*/

/*
#define MYOFFSETOF(type, member) (size_t(&((type*)0)->member))

typedef struct Data
{
	int a;
	double b;
	char c;
}Data;

int main()
{
	cout << sizeof(Data) << endl;
	cout << MYOFFSETOF(Data, a) << endl;
	cout << MYOFFSETOF(Data, b) << endl;
	cout << MYOFFSETOF(Data, c) << endl;

	return 0;
}
*/