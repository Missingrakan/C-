#define _CRT_SECURE_NO_WARNINGS 1

//用两个栈实现一个队列。队列的声明如下，
//请实现它的两个函数 appendTail 和 deleteHead ，
//分别完成在队列尾部插入整数和在队列头部删除整数的功能。
//(若队列中没有元素，deleteHead 操作返回 - 1)

class CQueue {
public:
	CQueue() {
	}

	void appendTail(int value) {
		st1.push(value);
	}

	int deleteHead() {
		if (st2.size() == 0)
		{
			while (st1.size() > 0)
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
		if (st2.size() == 0)
			return -1;

		int ret = st2.top();
		st2.pop();
		return ret;
	}
private:
	stack<int> st1;
	stack<int> st2;
};
/*
class CQueue {
public:
	CQueue() {
	}

	void appendTail(int value) {
		st1.push(value);
	}

	int deleteHead() {
//	if(CQueueEmpty())
//	{
//		return -1;
//	}

	if(st2.empty())
	{
		while(!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
	}
	if(st2.empty())
		return -1;

	int ret = st2.top();
	st2.pop();
	return ret;
	}
private:
stack<int> st1;
stack<int> st2;

	bool CQueueEmpty()
	{
		return st1.empty() && st2.empty();
	}
};
*/

//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)  //没有节点，返回空
			return nullptr;
		if (preorder.size() == 1)  //仅有一个节点，返回该节点
		{
			TreeNode* root = new TreeNode(preorder[0]);
			return root;
		}
		TreeNode* root = new TreeNode(preorder[0]);  //前序遍历第一个为根节点
		auto itr = inorder.begin();
		while (*itr != preorder[0])  //找到中序遍历根节点，分割左右子树
			++itr;
		//构造左子树前序中序序列
		int left = itr - inorder.begin();  //左子树节点个数
		vector<int> leftpre(preorder.begin() + 1, preorder.begin() + 1 + left);  //左子树前序
		vector<int> leftin(inorder.begin(), itr);  //左子树中序
		//构造右子树前序中序序列
		vector<int> rightpre(preorder.begin() + 1 + left, preorder.end());  //右子树前序
		vector<int> rightin(++itr, inorder.end());  //右子树中序
		//递归调用
		root->left = buildTree(leftpre, leftin);
		root->right = buildTree(rightpre, rightin);

		//返回根节点
		return root;

	}
};


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

struct TreeNode* _buildTree(int *startpreorder, int* endpreorder, int *startinorder, int *endinorder)
{
	int rootvalue = startpreorder[0];
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = rootvalue;
	root->left = root->right = NULL;

	if (startpreorder == endpreorder)
	{
		if (startpreorder == endpreorder && *startpreorder == *endpreorder)
			return root;
		else
			return NULL;
	}

	int* rootinorder = startinorder;
	while (rootinorder <= endinorder && *rootinorder != rootvalue)
		++rootinorder;

	int leftlength = rootinorder - startinorder;
	int* leftpreorderend = startpreorder + leftlength;
	if (leftlength>0)
	{
		//构建左子树
		root->left = _buildTree(startpreorder + 1, leftpreorderend, startinorder, rootinorder - 1);
	}
	if (leftlength < endpreorder - startpreorder)
	{
		root->right = _buildTree(leftpreorderend + 1, endpreorder, rootinorder + 1, endinorder);
	}
	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
	if (preorder == NULL || inorder == NULL || inorderSize <= 0)
		return NULL;
	return _buildTree(preorder, preorder + inorderSize - 1, inorder, inorder + inorderSize + 1);
}