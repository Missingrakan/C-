#define _CRT_SECURE_NO_WARNINGS 1

//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

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

//����һ������Сд��ĸ��ɵ��ַ������������ҳ�һ��λ�ã�ɾ���Ǹ���ĸ֮���ַ�����ɻ��ġ�
//������ܻ���һ���Ϸ��Ľ⡣����������ַ����Ѿ���һ�����Ĵ�����ô���-1��

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

////����һ���������飬������������Ҳ�и����������е�һ������������������һ�������顣
////������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�Ϊ O(n).
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