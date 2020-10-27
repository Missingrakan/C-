#define _CRT_SECURE_NO_WARNINGS 1

//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

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

//����һ����������������Ƿ��Ǿ���ԳƵġ�

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

//��һ�����򣬶����û������һ����������ַ�����
//���ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո�
//�ո��ַ����������������˶������Ժ��ٶԶ������������������
//������������
//�������� :
//�������1���ַ��������Ȳ�����100��
//������� :
//�����ж���������ݣ�����ÿ�����ݣ�
//����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
//ÿ��������ռһ�С�

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

//����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����
//�սڵ�����һ�Կ����� "()" ��ʾ��
//��������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�

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