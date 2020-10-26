#define _CRT_SECURE_NO_WARNINGS 1

//设计你的循环队列实现。

typedef struct {
	int* base;
	int capacity;
	int front;
	int tail;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *pc = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pc->capacity = k + 1;
	pc->base = (int*)malloc(sizeof(int)*pc->capacity);
	pc->front = pc->tail = 0;
	return pc;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	obj->base[obj->tail] = value;
	obj->tail = (obj->tail + 1) % (obj->capacity);
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->front = (obj->front + 1) % (obj->capacity);
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[(obj->tail - 1 + obj->capacity) % obj->capacity];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->tail;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->tail + 1) % (obj->capacity) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->base);
	obj->base = NULL;
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
		return true;
	else if (p == NULL || q == NULL)
		return false;
	else if (p->val != q->val)
		return false;
	else
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
//s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSametree(struct TreeNode* p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)
		return true;
	else if (p == NULL || q == NULL)
		return false;
	else if (p->val != q->val)
		return false;
	else
		return isSametree(p->left, q->left) && isSametree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	if (isSametree(s, t))
		return true;
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}

//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明 : 叶子节点是指没有子节点的节点。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


int maxDepth(struct TreeNode* root){
	if (root == NULL)
		return 0;
	else
	{
		int left_length = maxDepth(root->left);
		int right_length = maxDepth(root->right);
		return ((left_length > right_length) ? left_length : right_length) + 1;
	}
}

int max(int m, int n)
{
	return m>n ? m : n;
}

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}