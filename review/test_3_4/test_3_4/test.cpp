#define _CRT_SECURE_NO_WARNINGS 1

//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
//������򷵻�true,���򷵻�false���������������������������ֶ�������ͬ��

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

//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

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

//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

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

//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������

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