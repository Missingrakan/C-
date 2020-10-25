#define _CRT_SECURE_NO_WARNINGS 1


//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//
//说明：
//你只能使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

typedef struct Stack{
	int *base;
	int top;
	int capacity;
}Stack;
bool StackFull(Stack *pst)
{
	return pst->top >= pst->capacity;
}
bool StackEmpty(Stack *pst)
{
	return pst->top == 0;
}
Stack* StackCreate(int k)
{
	Stack *pst = (Stack*)malloc(sizeof(Stack));
	pst->capacity = k;
	pst->base = (int*)malloc(sizeof(int)*pst->capacity);
	pst->top = 0;
	return pst;
}
void StackFree(Stack *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}
void StackPush(Stack *pst, int x)
{
	if (StackFull(pst))
		return;
	pst->base[pst->top++] = x;
}
void StackPop(Stack *pst)
{
	if (StackEmpty(pst))
		return;
	pst->top--;
}
int StackTop(Stack *pst)
{
	assert(pst->top != 0);
	return pst->base[pst->top - 1];
}

typedef struct {
	Stack *st1;
	Stack *st2;
} MyQueue;
/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
	int n = 100;
	MyQueue *queue = (MyQueue*)malloc(sizeof(MyQueue));
	queue->st1 = StackCreate(n);
	queue->st2 = StackCreate(n);
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(obj->st1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(obj->st2))
	{
		while (!StackEmpty(obj->st1))
		{
			StackPush(obj->st2, StackTop(obj->st1));
			StackPop(obj->st1);
		}
	}
	int val = StackTop(obj->st2);
	StackPop(obj->st2);
	return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(obj->st2))
	{
		while (!StackEmpty(obj->st1))
		{
			StackPush(obj->st2, StackTop(obj->st1));
			StackPop(obj->st1);
		}
	}
	int val = StackTop(obj->st2);
	return val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(obj->st1) && StackEmpty(obj->st2);
}

void myQueueFree(MyQueue* obj) {
	free(obj->st1);
	free(obj->st2);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//给定一个二叉树，返回它的中序 遍历。

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int size(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return size(root->left) + size(root->right) + 1;
}
void _inorderTraversal(struct TreeNode* root, int *inorder, int *i)
{
	if (root != NULL)
	{
		_inorderTraversal(root->left, inorder, i);
		inorder[*i] = root->val;
		(*i)++;
		_inorderTraversal(root->right, inorder, i);
	}
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int n = size(root);
	*returnSize = n;
	int *inorder = (int*)malloc(sizeof(int)*n);

	int index = 0;
	_inorderTraversal(root, inorder, &index);

	return inorder;
}