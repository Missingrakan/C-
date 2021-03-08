#define _CRT_SECURE_NO_WARNINGS 1

//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int n = 0, m = 1;

		//整体异或
		for (int num : data)
			n ^= num;

		//统计两个数哪个比特位不同
		while ((n&m) == 0)
			m <<= 1;

		for (int num : data)
		{
			if (num&m)
				*num1 ^= num;
			else
				*num2 ^= num;
		}
	}
};

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		map<int, int> match;

		int sz = data.size();
		for (int i = 0; i < sz; ++i)
		{
			match[data[i]]++;
		}

		bool flag = true;
		for (int i = 0; i < sz; ++i)
		{
			if (match[data[i]] == 1 && flag)
			{
				*num1 = data[i];
				flag = false;
			}

			if (match[data[i]] == 1 && !flag)
			{
				*num2 = data[i];
			}
		}
	}
};

//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot) {
		if (pRoot == nullptr)
			return 0;

		queue<TreeNode*> q;
		q.push(pRoot);
		int depth = 0;

		while (!q.empty())
		{
			int sz = q.size();
			depth++;

			for (int i = 0; i < sz; ++i)
			{
				TreeNode* node = q.front();
				q.pop();
				if (node->left)
					q.push(node->left);

				if (node->right)
					q.push(node->right);
			}
		}

		return depth;
	}


	/*
	int TreeDepth(TreeNode* pRoot) {
		if(pRoot == nullptr)
			return 0;

		//最大的子树深度就是整个树的深度
		return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
	}
	*/
};

//输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/

class Solution {
public:
	ListNode* getListEnd(ListNode* list, int& len)
	{
		if (list == nullptr)
			return list;

		ListNode* end = list;
		while (end != nullptr)
		{
			end = end->next;
			len++;
		}

		return end;
	}

	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;
		int len1 = 0;
		int len2 = 0;

		ListNode* end1 = getListEnd(pHead1, len1);
		ListNode* end2 = getListEnd(pHead2, len2);

		if (end1 != end2)
			return nullptr;

		int step = abs(len1 - len2);

		if (len1 > len2)
		{
			while (step)
			{
				pHead1 = pHead1->next;
				step--;
			}
		}
		else
		{
			while (step)
			{
				pHead2 = pHead2->next;
				step--;
			}
		}

		while (pHead1 && pHead2)
		{
			if (pHead1 == pHead2)
				return pHead1;
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}

		return nullptr;
	}
};


class Solution {
public:
	ListNode* getListEnd(ListNode* list)
	{
		if (list == nullptr)
			return nullptr;

		ListNode* end = list;
		while (end != nullptr)
			end = end->next;

		return end;
	}

	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;

		ListNode* node1 = pHead1;
		ListNode* node2 = pHead2;

		ListNode* end1 = getListEnd(pHead1);
		ListNode* end2 = getListEnd(pHead2);

		if (end1 != end2)
			return nullptr;

		while (node1 != node2)
		{
			node1 = (node1 != nullptr ? node1->next : pHead1);
			node2 = (node2 != nullptr ? node2->next : pHead2);
		}

		return node1;
	}
};
