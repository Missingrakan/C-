#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回?[-1, -1]。

class Solution {
private:
	int findFitstPosition(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right) 
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) 
				left = mid + 1;
			else if (nums[mid] == target)
				right = mid;
			else 
				// nums[mid] > target
				right = mid - 1;
		}
		if (nums[left] != target) 
			return -1;
		return left;
	}

	int findLastPosition(vector<int> &nums, int target) {
		int size = nums.size();
		int left = 0;
		int right = size - 1;
		while (left < right) {
			int mid = left + (right - left + 1) / 2;
			if (nums[mid] > target) {
				right = mid - 1;
			}
			else if (nums[mid] == target){
				left = mid;
			}
			else {
				// nums[mid] < target
				left = mid + 1;
			}
		}
		if (nums[left] != target) {
			return -1;
		}
		return left;
	}


public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int size = nums.size();
		if (size == 0) {
			return{ -1, -1 };
		}
		int fitstPosition = findFitstPosition(nums, target);

		if (fitstPosition == -1) {
			return{ -1, -1 };
		}
		int lastPosition = findLastPosition(nums, target);
		return{ fitstPosition, lastPosition };
	}
};

void main()
{
	vector<int> v = { 5, 7, 7, 8, 8, 10 };
	Solution s;
	s.searchRange(v, 8);
}

/*
class Solution {
public:
	int binarySearch(vector<int>& nums, int target, bool lower) {
		int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
		while (left <= right) 
		{
			int mid = (left + right) / 2;
			if (nums[mid] > target || (lower && nums[mid] >= target)) 
			{
				right = mid - 1;
				ans = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return ans;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int leftIdx = binarySearch(nums, target, true);
		int rightIdx = binarySearch(nums, target, false) - 1;
		if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
			return vector<int>{leftIdx, rightIdx};
		}
		return vector<int>{-1, -1};
	}
};
*/

/*

//请你来实现一个?myAtoi(string s)?函数，使其能将字符串转换成一个 32 位有符号整数（类似 C / C++ 中的 atoi 函数）。
//函数?myAtoi(string s) 的算法如下：
//
//读入字符串并丢弃无用的前导空格
//检查第一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
//读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
//将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
//如果整数数超过 32 位有符号整数范围[?231, 231?? 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 ?231 的整数应该被固定为 ?231 ，大于 231?? 1 的整数应该被固定为 231?? 1 。
//返回整数作为最终结果。

//注意：
//本题中的空白字符只包括空格字符 ' ' 。
//除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
//
//示例?1：
//
//输入：s = "42"
//输出：42
//解释：加粗的字符串为已经读入的字符，插入符号是当前读取的字符。
//第 1 步："42"（当前没有读入字符，因为没有前导空格）
//^
//第 2 步："42"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
//^
//第 3 步："42"（读入 "42"）
//^
//解析得到整数 42 。
//由于 "42" 在范围[-231, 231 - 1] 内，最终结果为 42 。
//示例?2：
//
//输入：s = "   -42"
//输出： - 42
//解释：
//第 1 步："   -42"（读入前导空格，但忽视掉）
//^
//第 2 步："   -42"（读入 '-' 字符，所以结果应该是负数）
//^
//第 3 步："   -42"（读入 "42"）
//^
//解析得到整数 - 42 。
//由于 "-42" 在范围[-231, 231 - 1] 内，最终结果为 - 42 。
//示例?3：
//
//输入：s = "4193 with words"
//输出：4193
//解释：
//第 1 步："4193 with words"（当前没有读入字符，因为没有前导空格）
//			^
//第 2 步："4193 with words"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
//			^
//第 3 步："4193 with words"（读入 "4193"；由于下一个字符不是一个数字，所以读入停止）
//				^
//解析得到整数 4193 。
//由于 "4193" 在范围[-231, 231 - 1] 内，最终结果为 4193 。
//示例?4：
//
//输入：s = "words and 987"
//输出：0
//解释：
//第 1 步："words and 987"（当前没有读入字符，因为没有前导空格）
//			^
//第 2 步："words and 987"（当前没有读入字符，因为这里不存在 '-' 或者 '+'）
//			^
//第 3 步："words and 987"（由于当前字符 'w' 不是一个数字，所以读入停止）
//			^
//解析得到整数 0 ，因为没有读入任何数字。
//由于 0 在范围[-231, 231 - 1] 内，最终结果为 0 。
//示例?5：
//
//输入：s = "-91283472332"
//输出： - 2147483648
//解释：
//第 1 步："-91283472332"（当前没有读入字符，因为没有前导空格）
//^
//第 2 步："-91283472332"（读入 '-' 字符，所以结果应该是负数）
//^
//第 3 步："-91283472332"（读入 "91283472332"）
//^
//解析得到整数 - 91283472332 。
//由于 - 91283472332 小于范围[-231, 231 - 1] 的下界，最终结果被截断为 - 231 = -2147483648 。

class Solution {
public:
	int myAtoi(string s) {
		//跳过空格
		size_t i = 0;
		while (i < s.size() && s[i] == ' ')
			i++;
		if (i == s.size())
			return 0;

		//判断有无符号
		int flag = 1;
		if (s[i] == '-')
		{
			flag = -1;
			i++;
		}
		else if (s[i] == '+')
			i++;

		//不是符号也不是数字，直接返回
		else if (!isdigit(s[i]))
			return 0;

		//到计算有效数字了
		int num = 0;
		while (isdigit(s[i]) && (i < s.size()))
		{
			//INT_MAX < 10*num + (s[i]-'0')  这个判断不行，因为此时计算后num作为int无法保存结果(即产生了溢出)，所以小技巧就是进行移项，INT_MAX：2147483647
			if ((INT_MAX - (s[i] - '0')) / 10 < num)
			{
				return flag == -1 ? flag*INT_MAX - 1 : INT_MAX;
			}
			num = 10 * num + (s[i] - '0');
			i++;
		}

		return flag*num;
	}
};

*/