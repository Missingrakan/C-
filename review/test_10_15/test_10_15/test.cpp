#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//
//ʾ�� :
//
//���� : 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
		return NULL;

	struct ListNode *p = head;
	struct ListNode *prev = NULL;

	while (p != NULL)
	{
		if (p->val == val)
		{
			if (prev == NULL)
			{
				head = head->next;
				free(p);
				p = head;
			}
			else
			{
				prev->next = p->next;
				free(p);
				p = prev->next;
			}
		}
		else
		{
			prev = p;
			p = p->next;
		}
	}
	return head;
}

//��תһ��������
//
//ʾ�� :
//
//���� : 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL
// ���� :
//����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* reverseList(struct ListNode* head){
	if (head == NULL)
		return NULL;

	struct ListNode* p = head;
	head = NULL;

	while (p != NULL)
	{
		struct ListNode* q = p->next;
		p->next = head;
		head = p;
		p = q;
	}
	return head;
}