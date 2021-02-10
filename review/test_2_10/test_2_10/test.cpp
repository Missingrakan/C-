#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

class Solution {
public:
	vector<int> t;
	vector<vector<int>> ans;

	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		for (int mask = 0; mask < (1 << n); ++mask) {
			t.clear();
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					t.push_back(nums[i]);
				}
			}
			ans.push_back(t);
		}
		return ans;
	}
};

class Solution {
public:
	vector<int> t;
	vector<vector<int>> ans;

	void dfs(int cur, vector<int>& nums) {
		if (cur == nums.size()) {
			ans.push_back(t);
			return;
		}
		t.push_back(nums[cur]);
		dfs(cur + 1, nums);
		t.pop_back();
		dfs(cur + 1, nums);
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		dfs(0, nums);
		return ans;
	}
};

//根据 逆波兰表示法，求表达式的值。
//有效的运算符包括? + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

//说明：
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况

class Solution 
{
public:
	int evalRPN(vector<string>& tokens) 
	{
		vector<int> v;
		for (auto s : tokens)
		{
			if (s == "+" || s == "-" || s == "*" || s == "/")
			{
				int second = v.back(); v.pop_back();
				int first = v.back(); v.pop_back();
				if (s == "+"){ v.push_back(first + second); }
				if (s == "-"){ v.push_back(first - second); }
				if (s == "*"){ v.push_back(first * second); }
				if (s == "/"){ v.push_back(first / second); }
			}
			else
			{
				v.push_back(stoi(s));
			}
		}
		return v.back();
	}
};

class Solution 
{
public:
	int evalRPN(vector<string>& tokens) 
	{
		stack<int> st;
		for (int i = 0; i < tokens.size(); i++) 
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") 
			{
				int num1 = st.top();
				st.pop();
				int num2 = st.top();
				st.pop();
				if (tokens[i] == "+") st.push(num2 + num1);
				if (tokens[i] == "-") st.push(num2 - num1);
				if (tokens[i] == "*") st.push(num2 * num1);
				if (tokens[i] == "/") st.push(num2 / num1);
			}
			else 
			{
				st.push(stoi(tokens[i]));
			}
		}
		int result = st.top();
		st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
		return result;
	}
};

//给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//请你找出符合题意的 最短 子数组，并输出它的长度。

//示例 1：
//输入：nums = [2, 6, 4, 8, 10, 9, 15]
//输出：5
//解释：你只需要对[6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> v(nums.begin(), nums.end());
		sort(v.begin(), v.end());
		int start = v.size();
		int end = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] != nums[i])
			{
				start = min(start, i);
				end = max(end, i);
			}
		}

		return (end - start) >= 0 ? end - start + 1 : 0;
	}
}; 

int FindUnsortedSubarray(vector<int>& nums) {
	//此解法参考英文官方LeetCode上的讨论
	//从左到右扫描（或从右到左）找局部极大值（或局部极小值），若位置放置不正确，找到其应该存在的地方
	int n = nums.size();
	//赋初始开始和结束值
	int start = -1;
	int end = -2;
	//结束值赋为-2是考虑在数组本身就是有序时,return也可以给出正确值
	int minnum = nums[n - 1];
	int maxnum = nums[0];
	for (int i = 0, pos = 0; i < n; i++) {
		pos = n - 1 - i;
		//找出局部极大、极小值
		maxnum = max(maxnum, nums[i]);
		minnum = min(minnum, nums[pos]);
		//如果当前值小于局部极大值，用end记录该位置，找到该max的合适位置，
		if (nums[i] < maxnum)
			end = i;
		//如果当前值大于局部极小值，用star记录该位置，找到该star的合适位置
		if (nums[pos] > minnum)
			start = pos;
	}
	//返回开始和结束的索引差
	return end - start + 1;
}

void main()
{
	vector<int> v = { 2, 6, 4, 8, 10, 9, 15 };
	FindUnsortedSubarray(v);
}