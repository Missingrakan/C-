#define _CRT_SECURE_NO_WARNINGS

//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣
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
//����һ����������������е�����k����㡣
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


//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
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