#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//编写一个程序，找到两个单链表相交的起始节点。
//注意：
//
//如果两个链表没有交点，返回 null.
//在返回结果后，两个链表仍须保持原有的结构。
//可假定整个链表结构中没有循环。
//程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

int getLength(struct ListNode *head)
{
	if (head == NULL)
		return 0;
	int len = 0;
	while (head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL)
		return NULL;

	int lenA = getLength(headA);
	int lenB = getLength(headB);

	int gap = abs(lenA - lenB);
	struct ListNode* shortlist, *longlist;

	if (lenA > lenB)
	{
		longlist = headA;
		shortlist = headB;
	}
	else
	{
		longlist = headB;
		shortlist = headA;
	}

	while (gap-- != 0)
		longlist = longlist->next;
	while (shortlist != NULL && longlist != NULL)
	{
		if (shortlist == longlist)
			return shortlist;
		shortlist = shortlist->next;
		longlist = longlist->next;
	}
	return NULL;
}

//给定一个链表，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//如果链表中存在环，则返回true。 否则，返回false。

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool hasCycle(struct ListNode *head) {
	if (head == NULL)
		return NULL;
	struct ListNode *fast, *slow;
	fast = slow = head;
	while (fast && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
//如果 pos 是 - 1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
//说明：不允许修改给定的链表。

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return NULL;
	struct ListNode *fast, *slow;
	fast = slow = head;
	while (fast && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (fast != slow)
		return NULL;
	fast = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}