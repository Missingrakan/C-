#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

//使用队列实现栈的下列操作：
//
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :
//
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。


typedef struct Queue{
	int *base;
	int front;
	int tail;
}Queue;

void QueueInit(Queue *Q)
{
	int n = 10000;
	Q->base = (int*)malloc(sizeof(int)*n);
	Q->front = Q->tail = 0;
}

void QueuePush(Queue *Q, int x)
{
	Q->base[Q->tail++] = x;
}
void QueuePop(Queue *Q)
{
	Q->front++;
}
int QueueFront(Queue *Q)
{
	return Q->base[Q->front];
}
int QueueBack(Queue *Q)
{
	return Q->base[Q->tail - 1];
}
bool QueueEmpty(Queue *Q)
{
	return Q->front == Q->tail;
}


typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *res = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(res->q1));
	QueueInit(&(res->q2));
	return res;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	Queue *pnoempty;
	if (QueueEmpty(&(obj->q1)))
	{
		pnoempty = &(obj->q2);
	}
	else
	{
		pnoempty = &(obj->q1);
	}
	QueuePush(pnoempty, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue *pnoempty, *pempty;
	if (QueueEmpty(&(obj->q1)))
	{
		pempty = &(obj->q1);
		pnoempty = &(obj->q2);
	}
	else
	{
		pempty = &(obj->q2);
		pnoempty = &(obj->q1);
	}

	int val;
	while (!QueueEmpty(pnoempty))
	{
		val = QueueFront(pnoempty);
		QueuePop(pnoempty);
		if (QueueEmpty(pnoempty))
			break;
		QueuePush(pempty, val);
	}
	return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	Queue *pnoempty;
	if (QueueEmpty(&(obj->q1)))
	{
		pnoempty = &(obj->q2);
	}
	else
	{
		pnoempty = &(obj->q1);
	}
	return QueueBack(pnoempty);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj) {
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

//给定一个二叉树，返回它的 前序 遍历。
//
//示例 :
//
//输入 : [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//输出:[1, 2, 3]


int size(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return size(root->left) + size(root->right) + 1;
}
void _preorderTraversal(struct TreeNode *root, int *preorder, int *i)
{
	if (root != NULL)
	{
		preorder[*i] = root->val;
		(*i)++;
		_preorderTraversal(root->left, preorder, i);
		_preorderTraversal(root->right, preorder, i);
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int n = size(root);
	int *preorder = (int*)malloc(sizeof(int)*n);
	*returnSize = n;

	int i = 0;
	_preorderTraversal(root, preorder, &i);
	return preorder;
}