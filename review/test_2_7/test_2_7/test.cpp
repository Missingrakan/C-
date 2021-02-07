#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <functional>

using namespace std;

//给你两个二进制字符串，返回它们的和（用二进制表示）。
//输入为 非空 字符串且只包含数字 1 和 0。
class Solution {
public:
	string addBinary(string a, string b) {
		string ans;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int n = max(a.size(), b.size()), carry = 0;
		for (size_t i = 0; i < n; ++i) {
			carry += i < a.size() ? (a.at(i) == '1') : 0;
			carry += i < b.size() ? (b.at(i) == '1') : 0;
			ans.push_back((carry % 2) ? '1' : '0');
			carry /= 2;
		}

		if (carry) {
			ans.push_back('1');
		}
		reverse(ans.begin(), ans.end());

		return ans;
	}
};

/*
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
		for(int i = 0; i < n; ++i)
		{
			int j;
			for(j = i+1; j < n; ++j)
			{
				if(nums[i] + nums[j] == target)
				return {i, j};
			}
		}
		return {};
	}
};
*/

//给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

/*
int thirdMax(vector<int>& nums) {
	set<int> visited;
	priority_queue<int, vector<int>, greater<int>> topThree;
	for (const auto& num : nums) {
		if (visited.count(num)) {
			continue;
		}
		visited.insert(num);
		topThree.push(num);
		if (topThree.size() > 3) {
			topThree.pop();
		}
	}

	if (topThree.size() == 3) {
		return topThree.top();
	}

	int largest;
	while (!topThree.empty()) {
		largest = topThree.top();
		topThree.pop();
	}

	return largest;
}

void main()
{
	vector<int> v = { 5, 7, 8, 9, 6, 4 };
	int a = thirdMax(v);
}


class Solution3 {
public:
	int thirdMax(vector<int>& nums) {
		set<int> topThree;
		for (const auto& num : nums) {
			topThree.insert(num);
			if (topThree.size() > 3) {
				topThree.erase(topThree.begin());
			}
		}

		assert(!topThree.empty());
		return topThree.size() < 3 ? *topThree.rbegin() : *topThree.begin();
	}
};
*/

/*
//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int sz = digits.size();
		for (int i = sz - 1; i >= 0; --i)
		{
			digits[i]++;
			//当前位加到10要产生进位，继续循环
			if (digits[i] == 10)
				digits[i] = 0;

			//不产生进位，直接返回
			else
				return digits;
		}

		//出循环都未返回，说明是一直产生进位(999..99+1情况)，在begin()位置插入1即可
		digits.insert(digits.begin(), 1);
		return digits;
	}
};

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//只需在原数组中操作。
		//将数组从个位向高位遍历。当前位值若为9，则令其值为0；若不为9，则值 + 1，break退出循环。
		//最后判断一个特殊情况（即99..9 + 1），若为该特殊情况，经过上述循环遍历后，所有位均为0，只需首位变为1，再将一个0压入数组尾部即可。

		int n = digits.size();
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] == 9){
				digits[i] = 0;
			}
			else{
				digits[i] += 1;
				break;
			}
		}
		if (digits[0] == 0){
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
	}
};
*/