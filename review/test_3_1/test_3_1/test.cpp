#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> tmp;

		auto it_array = array.begin();

		while (it_array != array.end())
		{
			if (*it_array % 2 == 0)
			{
				tmp.push_back(*it_array);
				it_array = array.erase(it_array);
			}
			else
				it_array++;
		}

		auto it_tmp = tmp.begin();
		while (it_tmp != tmp.end())
		{
			array.push_back(*it_tmp);
			++it_tmp;
		}
	}

	/*
	void reOrderArray(vector<int> &array) {
	int sz = array.size();
	for(int i = 0; i < sz; ++i)
	{
	for(int j = sz-1; j > i; --j)
	{
	if(array[j]%2 == 1 && array[j-1]%2 == 0)
	swap(array[j], array[j-1]);
	}
	}
	}
	*/
};


////����һ���������������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ
//
//class Solution {
//public:
//	int  NumberOf1(int n)
//	{
//		int count = 0;
//		while (n)
//		{
//			n &= (n - 1);
//			count++;
//		}
//
//		return count;
//	}
//};

//
////���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
////����n = 3ʱ��2 * 3�ľ��ο���3�ָ��Ƿ�����
//
//class Solution {
//public:
//	int rectCover(int number) {
//		// 1 2 3 5
//		if (number < 2)
//			return number;
//
//		int *dp = new int[number + 1];
//		dp[1] = 1;
//		dp[2] = 2;
//
//		for (int i = 3; i <= number; ++i)
//		{
//			dp[i] = dp[i - 1] + dp[i - 2];
//		}
//
//		int res = dp[number];
//		delete dp;
//		return res;
//	}
//};
//
////һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
//
//class Solution {
//public:
//	int jumpFloor(int number) {
//		//dp[n] = dp[n-1]+dp[n-2];
//		int *dp = new int[number + 1];
//		dp[0] = 1;
//		dp[1] = 1;
//		for (int i = 2; i <= number; i++){
//			dp[i] = dp[i - 1] + dp[i - 2];
//		}
//		int num = dp[number]; //��number�±꣬���ǵ�number��̨��
//		delete dp;
//		return num;
//	}
//}
//
//class Solution {
//public:
//	int jumpFloor(int number) {
//		if (number == 0 || number == 1)
//			return number;
//
//		int first = 1;
//		int second = 2;
//		int third = 2;
//
//		while (number >= 3)
//		{
//			third = first + second;
//			first = second;
//			second = third;
//			number--;
//		}
//
//		return third;
//	}
//};
//
//
////��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
////����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
////NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
//
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray)
//	{
//		if (rotateArray.empty())
//			return 0;
//
//		int left = 0;
//		int right = rotateArray.size() - 1;
//		int mid = 0;
//
//		while (rotateArray[left] >= rotateArray[right])
//		{
//			if (right - left == 1)
//			{
//				mid = right;
//				break;
//			}
//
//			mid = left + (right - left) / 2;
//
//			if (rotateArray[mid] >= rotateArray[left])
//				left = mid;
//			else
//				right = mid;
//		}
//
//		return rotateArray[mid];
//	}
//	/*
//	int minNumberInRotateArray(vector<int> rotateArray)
//	{
//	if(rotateArray.empty())
//	return 0;
//
//	int n = rotateArray.size();
//
//	for(int i = 0; i < n-1; ++i)
//	{
//	if(rotateArray[i+1] < rotateArray[i])
//	{
//	return rotateArray[i+1];
//	}
//	}
//
//	return rotateArray[0];
//	}
//	*/
//};