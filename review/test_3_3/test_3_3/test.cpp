#define _CRT_SECURE_NO_WARNINGS 1

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (NULL == pHead)
			return pHead;

		ListNode* head = new ListNode(0);
		head->next = pHead;

		ListNode* prev = head;
		ListNode* last = prev->next;

		while (last != NULL)
		{
			while (last->next != NULL && last->val != last->next->val)
			{
				prev = prev->next;
				last = last->next;
			}

			while (last->next != NULL && last->val == last->next->val)
				last = last->next;

			if (prev->next != last)
				prev->next = last->next;

			last = last->next;
		}

		return head->next;
	}
	/*
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if(pHead == NULL)
			return NULL;

		ListNode* pPre = NULL;
		ListNode* pCur = pHead;
		ListNode* pNext = pHead->next;

		while(pNext != NULL)
		{
			if(pCur->val != pNext->val)
			{
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			}
			else
			{
				while(pNext && pNext->val == pCur->val)
					pNext = pNext->next;

				if(pPre != NULL)
					pPre->next = pNext;
				else
					pHead = pNext;

				while(pCur != pNext)
				{
					ListNode* p = pCur;
					pCur = pCur->next;
					free(p);
				}

				if(pNext != NULL)
				pNext = pNext->next;
			}
		}

		return pHead;
	}
	*/
};

//���������Ķ�����������任ΪԴ�������ľ���

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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;

		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;

		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��

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
	bool IsSame(TreeNode* begin, TreeNode* beginsub)
	{
		if (nullptr == beginsub)
			return true;

		if (nullptr == begin)
			return false;

		if (begin->val != beginsub->val)
			return false;

		return IsSame(begin->left, beginsub->left) && IsSame(begin->right, beginsub->right);
	}


	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;

		bool res = false;

		if (pRoot1->val == pRoot2->val)
			res = IsSame(pRoot1, pRoot2);

		if (!res)
			res = HasSubtree(pRoot1->left, pRoot2);

		if (!res)
			res = HasSubtree(pRoot1->right, pRoot2);

		return res;
	}
};