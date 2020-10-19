#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

//����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
//��дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (pHead == NULL)
			return NULL;
		ListNode *pLessHead, *pLessTail;
		ListNode *pGreatHead, *pGreatTail;

		pLessHead = pLessTail = (ListNode*)malloc(sizeof(ListNode));
		pGreatHead = pGreatTail = (ListNode*)malloc(sizeof(ListNode));

		while (pHead != NULL)
		{
			if (pHead->val < x)
			{
				pLessTail->next = pHead;
				pLessTail = pLessTail->next;
			}
			else
			{
				pGreatTail->next = pHead;
				pGreatTail = pGreatTail->next;
			}
			pHead = pHead->next;
		}

		pLessTail->next = pGreatTail->next = NULL;
		pLessTail->next = pGreatHead->next;
		pHead = pLessHead->next;

		free(pLessHead);
		free(pGreatHead);

		return pHead;
	}
};

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣 
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
		if (pHead == NULL)
			return NULL;
		ListNode* pPre = NULL;
		ListNode* pCur = pHead;
		ListNode* pNext = pHead->next;

		while (pNext != NULL)
		{
			if (pCur->val != pNext->val)
			{
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			}
			else
			{
				while (pNext && pNext->val == pCur->val)
				{
					pNext = pNext->next;
				}
				if (pPre != NULL)
					pPre->next = pNext;
				else
					pHead = pNext;
				while (pCur != pNext)
				{
					ListNode *p = pCur;
					pCur = pCur->next;
					free(p);
				}
				if (pNext != NULL)
					pNext = pNext->next;
			}
		}
		return pHead;
	}
};

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		if (A == NULL)
			return false;

		int ar[10000];
		ListNode *p = A;
		int k;
		while (p != NULL)
		{
			ar[k++] = p->val;
			p = p->next;
		}

		int start = 0;
		int end = k - 1;

		while (start < end)
		{
			if (ar[start] != ar[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
};