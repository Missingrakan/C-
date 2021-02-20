#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1, 2, 4, 7, 3, 5, 6, 8 }和中序遍历序列{ 4, 7, 2, 1, 5, 3, 8, 6 }，则重建二叉树并返回。

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
	TreeNode* reConstructBinaryTree(vector<int> pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd)
	{
		if (preStart > preEnd || vinStart > vinEnd)
			return NULL;

		TreeNode* root = new TreeNode(pre[preStart]);
		for (int i = vinStart; i <= vinEnd; ++i)
		{
			//1 2 3 4 5 6 7
			//3 2 4 1 6 5 7
			//前序的第一个节点，是root，能将中序划分为两部分
			//一棵树，无论前，中，后怎么遍历，元素的个数是不变的
			//在实际遍历的时候，前，中，后序遍历，各种遍历方式左右子树的节点都是在一起的
			//所以这里重点是要想清楚下标问题
			//根据中序，我们能确认左子树的节点个数是：i - vinStart (没有从0开始哦)
			//所以，需要从preStart+1，连续i - vinStart个元素，就是左子树的前序序列

			if (pre[preStart] == vin[i])
			{
				root->left = reConstructBinaryTree(pre, preStart + 1, i - vinStart + preStart, vin, vinStart, i - 1);
				root->right = reConstructBinaryTree(pre, i - vinStart + preStart + 1, preEnd, vin, i + 1, vinEnd);
				break;
			}
		}
		return root;
	}
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return NULL;
		return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
};


//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		stack<int> st;

		while (head)
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
vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		while(head)
		{
			v.push_back(head->val);
			head = head->next;
		}

		reverse(v.begin(), v.end());

		return v;
	}
};
*/

//请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
//则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; ++i)
		{
			if (isspace(str[i]))
				count++;
		}

		char* old_end = str + length;
		char* new_end = str + length + 2 * count;
		while (old_end >= str && new_end >= str)
		{
			if (!isspace(*old_end))
			{
				//第一次进来就将'\0'拷贝进去了，不用特殊处理
				*new_end = *old_end;
				old_end--;
				new_end--;
			}
			else
			{
				*new_end-- = '0';
				*new_end-- = '2';
				*new_end-- = '%';
				old_end--;
			}
		}
	}
};


//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		// 1 2 3 4
		// 2 3 4 5
		// 3 4 5 6
		int i = 0;
		int j = array[0].size() - 1;

		while (i < array.size() && j >= 0)
		{
			if (target < array[i][j])
				j--;
			else if (target > array[i][j])
				i++;
			else
				return true;
		}

		return false;
	}
};