#define _CRT_SECURE_NO_WARNINGS 1

//给定一个二叉树，判断它是否是高度平衡的二叉树。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		return (left_depth > right_depth ? left_depth : right_depth) + 1;
	}
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
		return true;
	int left_depth = maxDepth(root->left);
	int right_depth = maxDepth(root->right);

	return (abs(left_depth - right_depth)<2) &&
		isBalanced(root->left) &&
		isBalanced(root->right);
}


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//给定一个二叉树，检查它是否是镜像对称的。

bool _isSymmetric(struct TreeNode* t1, struct TreeNode* t2)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return (t1->val == t2->val) &&
		_isSymmetric(t1->left, t2->right) &&
		_isSymmetric(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}

//编一个程序，读入用户输入的一串先序遍历字符串，
//根据此字符串建立一个二叉树（以指针方式存储）。 
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，
//空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，
//输出遍历结果。
//输入描述 :
//输入包括1行字符串，长度不超过100。
//输出描述 :
//可能有多组测试数据，对于每组数据，
//输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
//每个输出结果占一行。

#include <stdio.h>

typedef struct BinTreeNode{
	char val;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
}BinTreeNode;

typedef BinTreeNode* BinTree;

BinTree BinTreeCreate(char *str, int *i)
{
	if (str[*i] == '#' || str[*i] == '\0')
		return NULL;
	BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	t->val = str[*i];
	(*i)++;
	t->left = BinTreeCreate(str, i);
	(*i)++;
	t->right = BinTreeCreate(str, i);
	return t;
}

void Inorder(BinTree t)
{
	if (t != NULL)
	{
		Inorder(t->left);
		printf("%c ", t->val);
		Inorder(t->right);
	}
}

int main()
{
	BinTree t = NULL;
	char str[100] = { 0 };
	scanf("%s", str);
	int i = 0;
	t = BinTreeCreate(str, &i);
	Inorder(t);
	return 0;
}

//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//空节点则用一对空括号 "()" 表示。
//而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
char buf[10];
void _tree2str(struct TreeNode* t, char *str)
{
	if (t == NULL)
		return;
	sprintf(buf, "%d", t->val);
	strcat(str, buf);

	if (t->left == NULL)
	{
		if (t->right == NULL)
			return;
		else
			strcat(str, "()");
	}
	else
	{
		strcat(str, "(");
		_tree2str(t->left, str);
		strcat(str, ")");
	}

	if (t->right == NULL)
		return;
	else
	{
		strcat(str, "(");
		_tree2str(t->right, str);
		strcat(str, ")");
	}
}

char str[100000];
char * tree2str(struct TreeNode* t){
	str[0] = '\0';
	_tree2str(t, str);
	return str;
}