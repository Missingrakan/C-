#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��

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

//���� �沨����ʾ��������ʽ��ֵ��
//��Ч�����������? + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��

//˵����
//��������ֻ�����������֡�
//�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �����

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
		st.pop(); // ��ջ�����һ��Ԫ�ص�������ʵ������Ҳû�£�
		return result;
	}
};

//����һ���������� nums ������Ҫ�ҳ�һ�� ���������� �����������������������������ô�������鶼���Ϊ��������
//�����ҳ���������� ��� �����飬��������ĳ��ȡ�

//ʾ�� 1��
//���룺nums = [2, 6, 4, 8, 10, 9, 15]
//�����5
//���ͣ���ֻ��Ҫ��[6, 4, 8, 10, 9] ��������������ô���������Ϊ��������

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
	//�˽ⷨ�ο�Ӣ�Ĺٷ�LeetCode�ϵ�����
	//������ɨ�裨����ҵ����Ҿֲ�����ֵ����ֲ���Сֵ������λ�÷��ò���ȷ���ҵ���Ӧ�ô��ڵĵط�
	int n = nums.size();
	//����ʼ��ʼ�ͽ���ֵ
	int start = -1;
	int end = -2;
	//����ֵ��Ϊ-2�ǿ��������鱾���������ʱ,returnҲ���Ը�����ȷֵ
	int minnum = nums[n - 1];
	int maxnum = nums[0];
	for (int i = 0, pos = 0; i < n; i++) {
		pos = n - 1 - i;
		//�ҳ��ֲ����󡢼�Сֵ
		maxnum = max(maxnum, nums[i]);
		minnum = min(minnum, nums[pos]);
		//�����ǰֵС�ھֲ�����ֵ����end��¼��λ�ã��ҵ���max�ĺ���λ�ã�
		if (nums[i] < maxnum)
			end = i;
		//�����ǰֵ���ھֲ���Сֵ����star��¼��λ�ã��ҵ���star�ĺ���λ��
		if (nums[pos] > minnum)
			start = pos;
	}
	//���ؿ�ʼ�ͽ�����������
	return end - start + 1;
}

void main()
{
	vector<int> v = { 2, 6, 4, 8, 10, 9, 15 };
	FindUnsortedSubarray(v);
}