#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

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


////输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示
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
////我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
////比如n = 3时，2 * 3的矩形块有3种覆盖方法：
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
////一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
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
//		int num = dp[number]; //第number下标，就是第number阶台阶
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
////把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
////输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
////NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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