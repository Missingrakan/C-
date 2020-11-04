#define _CRT_SECURE_NO_WARNINGS 1

//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
//
//示例1：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l2 == NULL)
			return l1;
		if (l1 == NULL)
			return l2;
		if (l1 == NULL && l2 == NULL)
			return NULL;

		ListNode* head = new ListNode(INT_MAX);
		ListNode* res = head;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				res->next = l1;
				l1 = l1->next;
			}
			else
			{
				res->next = l2;
				l2 = l2->next;
			}
			res = res->next;
		}

		res->next = (l1 != NULL) ? l1 : l2;

		return head->next;
	}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l2 == NULL)
			return l1;
		if (l1 == NULL)
			return l2;
		if (l1 == NULL && l2 == NULL)
			return NULL;

		ListNode* head = NULL;
		if (l1->val < l2->val)
		{
			head = l1;
			head->next = mergeTwoLists(l1->next, l2);
		}
		else
		{
			head = l2;
			head->next = mergeTwoLists(l1, l2->next);
		}

		return head;
	}
};

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> match;
		int len = nums.size(), res = 10086;
		if (len == 1 || len == 2){
			return nums[0];
		}

		for (int i = 0; i < len; ++i){
			match[nums[i]] ++;
			if (match[nums[i]] >(len / 2)){
				res = nums[i];
				break;
			}
		}
		return res;
	}
};

