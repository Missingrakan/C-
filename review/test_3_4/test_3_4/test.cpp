#define _CRT_SECURE_NO_WARNINGS 1

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
	bool VerifySquenceOfBST_(vector<int> &sequence, int start, int end)
	{
		if (start >= end)
		{
			return true;
		}

		int i = 0;
		int root = sequence[end];
		while (i < end && sequence[i] < root)
			i++;

		for (int j = i; j < end; ++j)
		{
			if (sequence[j] < root)
				return false;
		}

		return VerifySquenceOfBST_(sequence, 0, i - 1) && VerifySquenceOfBST_(sequence, i, end - 1);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;

		return VerifySquenceOfBST_(sequence, 0, sequence.size() - 1);
	}
};

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		if (nullptr == root)
			return vector<int>();

		vector<int> res;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode* father = q.front();
			q.pop();
			res.push_back(father->val);

			if (father->left)
				q.push(father->left);

			if (father->right)
				q.push(father->right);

		}

		return res;
	}
};

//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
//但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0 || popV.size() == 0)
			return false;

		stack<int> st;
		int i = 0;
		int j = 0;

		for (i = 0; i < pushV.size(); ++i)
		{
			st.push(pushV[i]);

			while (!st.empty() && st.top() == popV[j])
			{
				st.pop();
				j++;
			}
		}

		return st.empty();
	}
};

//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

class Solution {
private:
	stack<int> data_stack;
	stack<int> min_stack;
public:
	void push(int value) {
		data_stack.push(value);

		if (min_stack.size() == 0 || min_stack.top() > value)
			min_stack.push(value);
		else
			min_stack.push(min_stack.top());
	}
	void pop() {
		if (data_stack.size() == 0 || min_stack.size() == 0)
			return;

		data_stack.pop();
		min_stack.pop();
	}
	int top() {
		if (!data_stack.empty())
			return data_stack.top();

		return 0;
	}
	int min() {
		if (!min_stack.empty())
			return min_stack.top();

		return 0;
	}
};