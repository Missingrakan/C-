#define _CRT_SECURE_NO_WARNINGS 1

//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr)
			return pHead2;

		if (pHead2 == nullptr)
			return pHead1;

		ListNode* new_head = nullptr;

		if (pHead1->val < pHead2->val)
		{
			new_head = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			new_head = pHead2;
			pHead2 = pHead2->next;
		}

		new_head->next = Merge(pHead1, pHead2);

		return new_head;
	}
	/*
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	if(pHead1 == nullptr)
	return pHead2;

	if(pHead2 == nullptr)
	return pHead1;

	ListNode* new_head = nullptr;
	ListNode* new_tail = nullptr;

	while(pHead1 && pHead2)
	{
	ListNode* p = pHead1->val < pHead2->val ? pHead1 : pHead2;

	if(p == pHead1)
	pHead1 = pHead1->next;
	else
	pHead2 = pHead2->next;

	if(new_head == nullptr)
	{
	new_head = p;
	new_tail = p;
	}
	else
	{
	new_tail->next = p;
	new_tail = p;
	}
	}

	if(pHead1 == nullptr)
	new_tail->next = pHead2;
	else if(pHead2 == nullptr)
	new_tail->next = pHead1;

	return new_head;
	}
	*/
};

//����һ��������ת��������������ı�ͷ��

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		ListNode* new_head = nullptr;

		while (pHead != nullptr)
		{
			ListNode* p = pHead;
			pHead = pHead->next;

			p->next = new_head;
			new_head = p;
		}

		pHead = new_head;
		return pHead;
	}
	/*
	ListNode* ReverseList(ListNode* pHead) {
	if(pHead == nullptr || pHead->next == nullptr)
	return pHead;

	ListNode* first = pHead;
	ListNode* second = first->next;
	ListNode* third = second->next;

	while(third != nullptr)
	{
	second->next = first;
	first = second;
	second = third;
	third = third->next;
	}

	//�������һ���ڵ���µ�ͷ���
	second->next = first;
	pHead->next = nullptr;
	pHead = second;

	return pHead;
	}
	*/
};

//����һ����������������е�����k����㡣

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
			return nullptr;

		ListNode* fast = pListHead;
		ListNode* slow = pListHead;

		while (k-- > 0)
		{
			if (fast == NULL)
				return NULL;
			fast = fast->next;
		}

		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow;
	}
};