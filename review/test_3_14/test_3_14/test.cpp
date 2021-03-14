#define _CRT_SECURE_NO_WARNINGS 1

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。

class Solution {
public:
	int Fibonacci(int n) {
		//初始值
		if (n <= 0)
			return 0;

		if (n == 1 || n == 2)
			return 1;

		int *dp = new int[n + 1];
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
	/*
	int Fibonacci(int n) {
	if(n == 0)
	return 0;

	int f1 = 1;
	int f2 = 1;
	int f3 = 1;

	while(n >= 3)
	{
	f3 = f1 + f2;
	f1 = f2;
	f2 = f3;
	n--;
	}

	return f3;
	}
	*/
};

//给定一棵二叉搜索树，请找出其中的第k小的TreeNode结点。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k) {
		if (pRoot == nullptr || k <= 0)
			return nullptr;

		TreeNode* cur = pRoot;
		stack<TreeNode*> st;

		do
		{
			while (cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}

			if (!st.empty())
			{
				cur = st.top();
				st.pop();
				k--;
				if (k == 0)
					return cur;

				cur = cur->right;
			}
		} while (cur != nullptr || !st.empty());

		return nullptr;
	}
};

//实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;

		if (pRoot == nullptr)
			return res;

		stack<TreeNode*> st;
		queue<TreeNode*> que;
		st.push(pRoot);

		int flag = 1;
		vector<int> v;

		while (!st.empty())
		{
			int sz = st.size();
			for (int i = 0; i < sz; ++i)
			{
				TreeNode* cur = st.top();
				st.pop();
				v.push_back(cur->val);

				TreeNode* first = (flag == 1) ? cur->left : cur->right;
				TreeNode* second = (flag == 1) ? cur->right : cur->left;

				if (first) que.push(first);
				if (second) que.push(second);
			}

			res.push_back(v);

			while (!que.empty())
			{
				st.push(que.front());
				que.pop();
			}

			//更改本次状态
			flag = (flag == 1) ? 0 : 1;
			v.clear();
		}

		return res;
	}

};
