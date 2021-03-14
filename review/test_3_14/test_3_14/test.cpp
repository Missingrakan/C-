#define _CRT_SECURE_NO_WARNINGS 1

//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����1����1����

class Solution {
public:
	int Fibonacci(int n) {
		//��ʼֵ
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

//����һ�ö��������������ҳ����еĵ�kС��TreeNode��㡣

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

//ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�

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

			//���ı���״̬
			flag = (flag == 1) ? 0 : 1;
			v.clear();
		}

		return res;
	}

};
