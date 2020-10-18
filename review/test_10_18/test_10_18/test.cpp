#define _CRT_SECURE_NO_WARNINGS

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
struct ListNode* middleNode(struct ListNode* head){
	if (head == NULL && head->next == NULL)
		return NULL;
	struct ListNode *fast, *slow;
	fast = slow = head;
	while (fast && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//输入一个链表，输出该链表中倒数第k个结点。
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	// write code here
	if (pListHead == NULL)
		return NULL;
	struct ListNode *fast, *slow;
	fast = slow = pListHead;
	while (k-- > 0)
	{
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL&&l2 == NULL)
		return NULL;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	struct ListNode* pHead;
	if (l1->val < l2->val)
	{
		pHead = l1;
		l1 = l1->next;
	}
	else
	{
		pHead = l2;
		l2 = l2->next;
	}

	struct ListNode *pTail = pHead;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			pTail->next = l1;
			l1 = l1->next;
		}
		else
		{
			pTail->next = l2;
			l2 = l2->next;
		}
		pTail = pTail->next;
	}
	if (l1 != NULL)
		pTail->next = l1;
	if (l2 != NULL)
		pTail->next = l2;

	return pHead;
}