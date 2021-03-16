#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����һ���������� nums?��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ ����?����?���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
//����԰�����˳�򷵻ش𰸡�

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

//��������

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
				//��i����Ʒ��A�ж�Ӧ������Ϊi-1: i��1��ʼ
				//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
				if (A[i - 1] > j) {
					dp[i][j] = dp[i - 1][j];
				}
				//�������װ�£������������װ���߲�װ
				//�����װ����Ϊ(i-1, j)
				//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i-1],װ��֮�������ֵ��Ϊ(i - 1,j - A[i - 1]) + ��i����Ʒ�ļ�ֵV[i - 1]
					//�����װ�벻װ��ѡ�����ļ�ֵ
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