#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

//现有一链表的头指针 ListNode* pHead，给一定值x，
//编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

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

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
//重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

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

//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

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