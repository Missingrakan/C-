#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int sumr = 0, suml = 0, n = nums.size();
		if (n == 0 || n == 2)    return -1;
		if (n == 1)  return 0;

		for (const auto num : nums)  sumr += num;
		for (int i = 0; i<n; i++) {
			if (suml == sumr - nums[i])
				return i;
			suml += nums[i];
			sumr -= nums[i];
		}
		return -1;
	}
};

//给定一个非负整数数组 A，返回一个数组，在该数组中，?A 的所有偶数元素之后跟着所有奇数元素。
//你可以返回满足此条件的任何数组作为答案。

//示例：
//
//输入：[3, 1, 2, 4]
//输出：[2, 4, 3, 1]
//输出[4, 2, 3, 1]，[2, 4, 1, 3] 和[4, 2, 1, 3] 也会被接受。

vector<int> sortArrayByParity(vector<int>& A) {
	int start = 0;
	int end = A.size() - 1;

	while (start <= end)
	{
		//找奇数
		if (start < A.size() - 1 && (A[start] & 1) == 0)
			start++;

		//找偶数
		else if (end >= 0 && (A[end] & 1) == 1)
			end--;

		else
			swap(A[start++], A[end--]);
	}

	return A;
}

void main()
{
	vector<int> v = { 3, 1, 2, 4 };
	sortArrayByParity(v);
}

/*
//给定一个字符串?S，返回?“反转后的”?字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//
//输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
//
//输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"


class Solution {
public:
	string reverseOnlyLetters(string S) {
		int begin = 0, end = S.length() - 1;
		while (begin<end)
		{
			if (!isalpha(S[begin]))
				begin++;
			if (!isalpha(S[end]))
				end--;
			if (isalpha(S[begin]) && isalpha(S[end]))
				swap(S[begin++], S[end--]);
		}
		return S;
	}
};
*/

/*
//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> tmp;
		for (auto e : nums)
			tmp.push_back(e*e);

		sort(tmp.begin(), tmp.end());

		return tmp;
	}
};

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> res;
		res.resize(nums.size());
		int k = nums.size() - 1;
		int i = 0, j = k;
		while (i <= j)
		{
			//确定负数平方所处位置
			if (nums[i] * nums[i] < nums[j] * nums[j])
			{
				res[k--] = nums[j] * nums[j];
				j--;;
			}
			else
			{
				res[k--] = nums[i] * nums[i];
				i++;
			}
		}

		return res;
	}
};
*/

/*
//你的朋友正在使用键盘输入他的名字?name。偶尔，在键入字符?c?时，按键可能会被长按，而字符可能被输入 1 次或多次。
//你将会检查键盘输入的字符?typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回?True。

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0, j = 0;
		while (j < typed.length()) {
			if (i < name.length() && name[i] == typed[j]) {
				i++;
				j++;
			}
			else if (j > 0 && typed[j] == typed[j - 1]) {
				j++;
			}
			else {
				return false;
			}
		}
		return i == name.length();
	}
};
*/

/*
//给定一个整数数组，判断是否存在重复元素。
//如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {
			if (nums[i] == nums[i + 1]) {
				return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (int x : nums) {
			if (s.find(x) != s.end()) {
				return true;
			}
			s.insert(x);
		}
		return false;
	}

	bool containsDuplicate(vector<int>& nums) {

		return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
		//如果原数组的大小>集合的大小，则说明存在重复元素
	}
};

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> map;

		for (auto&e : nums)
		{
			if (map[e]++)
				return true;
		}
		return false;
	}
};
*/