#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

//根据输入的日期，计算是这一年的第几天。。
//
//测试用例有多组，注意循环输入
//
//输入描述 :
//输入多行，每行空格分割，分别是年，月，日
//
//输出描述 :
//成功 : 返回outDay输出计算后的第几天;
//失败:返回 - 1

int main()
{
	int array[12] = { 31, 59, 90, 120, 151, 181, 212,
		243, 273, 304, 334, 365 };
	int year;
	int month;
	int day;

	int sum = 0;

	while (cin >> year >> month >> day)
	{
		sum = 0;
		if (month > 2)
		{
			//这里获取每一月的天数时使用数组下标开始的，故此数应是-2
			sum += array[month - 2];
			sum += day;

			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				sum += 1;
		}
		else
			sum += day;
		cout << sum << endl;
	}
	return 0;
}

//题目描述
//任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。
//本题含有多组样例输入。
//输入描述 :
//输入一个偶数
//
//输出描述 :
//输出两个素数


bool IsPrime(int num)
{
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; ++i)
	{
		if (num%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//从中间开始找符合条件的素数；
		for (i = half; i > 0; --i)
		{
			if (IsPrime(i) && IsPrime(num - i))
				break;
		}
		cout << i << endl << num - i << endl;
	}
	return 0;
}

//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//示例:
//输入 : [1, 2, 3, null, 5, null, 4]
//输出 : [1, 3, 4]


class Solution 
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<int> result;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = que.front();
				que.pop();
				if (i == (size - 1)) result.push_back(node->val); // 将每一层的最后元素放入result数组中
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}
};

vector<vector<int>> res;
void backtrack(vector<int>& nums, int start, vector<int>& track)
{
	res.push_back(track);
	for (int i = start; i < nums.size(); i++)
	{
		// 做选择
		track.push_back(nums[i]);
		// 回溯
		backtrack(nums, i + 1, track);
		// 撤销选择
		track.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums)
{
	// 记录走过的路径
	vector<int> track;
	backtrack(nums, 0, track);
	return res;
}

void main()
{
	vector<int> v = { 1, 2, 3 };
	subsets(v);
}
