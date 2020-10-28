#define _CRT_SECURE_NO_WARNINGS 1

//在一个长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//
//示例 1：
//输入：
//[2, 3, 1, 0, 2, 5, 3]
//输出：2 或 3

//限制：
//2 <= n <= 100000

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		set<int> s;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			auto it = s.insert(nums[i]);
			if (!it.second)
				return nums[i];
		}

		return -1;
	}
};
/*
class Solution {
public:
int findRepeatNumber(vector<int>& nums) {
vector<int> v(nums);
sort(v.begin(), v.end());

for(size_t i=0; i != v.size()-1; ++i)
{
if(v[i] == v[i+1])
return v[i];
}

return -1;
}
};
*/
/*
class Solution {
public:
int findRepeatNumber(vector<int>& nums) {
vector<int> v(nums);
sort(v.begin(), v.end());

for(auto it = v.begin(); it != v.end(); ++it)
{
if(*it == *(it+1))
return *it;
}

return -1;
}
};
*/
/*
class Solution {
public:
int findRepeatNumber(vector<int>& nums) {
vector<int> count;
count.resize(100000);
for(size_t i = 0; i < nums.size(); ++i)
{
count[nums[i]]++;
}

for(size_t i = 0; i < nums.size(); ++i)
{
if(count[i] >= 2)
return i;
}

return -1;
}
};
*/

//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，
//输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int row = matrix.size() - 1;
		int col = 0;
		while (row >= 0 && col < matrix[0].size())
		{
			if (matrix[row][col] < target)
				col++;
			else if (matrix[row][col] > target)
				row--;
			else
				return true;
		}
		return false;
	}
};

//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

//示例 1：
//
//输入：s = "We are happy."
//输出："We%20are%20happy."

class Solution {
public:
	string replaceSpace(string s) {
		int count = 0, len = s.size();
		for (auto e : s)
		{
			if (e == ' ')
				count++;
		}

		s.resize(len + 2 * count);       //' ' 变为 “%20” 相当于增加两个字节

		for (int i = len - 1, j = s.size() - 1; i < j; --i, --j)
		{
			if (s[i] != ' ')
				s[j] = s[i];
			else
			{
				s[j] = '0';
				s[j - 1] = '2';
				s[j - 2] = '%';
				j -= 2;
			}
		}
		return s;
	}
};
/*
class Solution {
public:
	string replaceSpace(string s) {
	if(s.empty())
		return s;
	string str = "";

	for(int i = 0; i != s.size(); ++i)
	{
		if(s[i] == ' ')
			str += "%20";
		else
			str += s[i];
	}

	return str;
	}
};
*/

//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
//
//示例 1：
//
//输入：head = [1, 3, 2]
//输出：[2, 3, 1]

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> v;
		stack<int> st;

		while (head != NULL)
		{
			st.push(head->val);
			head = head->next;
		}

		while (!st.empty())
		{
			v.push_back(st.top());
			st.pop();
		}
		return v;
	}
};

/*
class Solution {
public:
vector<int> reversePrint(ListNode* head) {
	vector<int> v;

	while(head != NULL)
	{
		v.push_back(head->val);
		head = head->next;
	}
	reverse(v.begin(),v.end());
	return v;
	}
};
*/