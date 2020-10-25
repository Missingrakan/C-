#define _CRT_SECURE_NO_WARNINGS 1

//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) —— 将元素 x 推入栈中。
//pop() —— 删除栈顶的元素。
//top() —— 获取栈顶元素。
//getMin() —— 检索栈中的最小元素。

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
	pst->top = pst->capacity = 0;
}
void StackPush(Stack *pst, int x)
{
	if (!StackFull(pst))
		pst->base[pst->top++] = x;
}
void StackPop(Stack *pst)
{
	if (!StackEmpty(pst))
		pst->top--;
}
int StackTop(Stack *pst)
{
	assert(pst->top != 0);
	return pst->base[pst->top - 1];
}

typedef struct {
	Stack *st;
	Stack *min_st;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	int n = 1000;
	MinStack* pst = (MinStack*)malloc(sizeof(MinStack));
	pst->st = StackCreate(n);
	pst->min_st = StackCreate(n);
	return pst;
}

void minStackPush(MinStack* obj, int x) {
	StackPush(obj->st, x);
	if (StackEmpty(obj->min_st) || x <= StackTop(obj->min_st))
	{
		StackPush(obj->min_st, x);
	}
}

void minStackPop(MinStack* obj) {
	int val = StackTop(obj->st);
	StackPop(obj->st);

	if (val == StackTop(obj->min_st))
	{
		StackPop(obj->min_st);
	}
}

int minStackTop(MinStack* obj) {
	return StackTop(obj->st);
}

int minStackGetMin(MinStack* obj) {
	return StackTop(obj->min_st);
}

void minStackFree(MinStack* obj) {
	free(obj->st);
	free(obj->min_st);
	free(obj);
}

/**
* Your MinStack struct will be instantiated and called as such:
* MinStack* obj = minStackCreate();
* minStackPush(obj, x);

* minStackPop(obj);

* int param_3 = minStackTop(obj);

* int param_4 = minStackGetMin(obj);

* minStackFree(obj);
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//给定一个二叉树，返回它的 后序 遍历。


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int Size(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return Size(root->left) + Size(root->right) + 1;
}
void _postorderTraversal(struct TreeNode* root, int* postorder, int *i)
{
	if (root != NULL)
	{
		_postorderTraversal(root->left, postorder, i);
		_postorderTraversal(root->right, postorder, i);
		postorder[*i] = root->val;
		(*i)++;
	}
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int n = Size(root);
	*returnSize = n;
	int *postorder = (int*)malloc(sizeof(int)*n);

	int index = 0;
	_postorderTraversal(root, postorder, &index);

	return postorder;
}