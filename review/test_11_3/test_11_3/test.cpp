
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;

		while (left < right)
		{
			while ((left < right) && (nums[left] & 1) == 1)
				left++;
			while ((left < right) && (nums[right] & 1) == 0)
				right--;
			if (left < right)
			{
				int temp = nums[left];
				nums[left] = nums[right];
				nums[right] = temp;
			}
		}
		return nums;
	}
};

//输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，
//即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，
//它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

//示例：

//给定一个链表 : 1->2->3->4->5, 和 k = 2.
//返回链表 4->5.

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
	ListNode* getKthFromEnd(ListNode* head, int k) {
		if (head == NULL || k == 0)
			return NULL;
		ListNode* fast = head;
		ListNode* slow;

		for (size_t i = 0; i < k - 1; ++i)
		{
			if (fast->next != NULL)
				fast = fast->next;
			else
				return NULL;
		}

		slow = head;
		while (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow;
	}
};

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
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = NULL, *pre = head;
		while (pre != NULL) {
			ListNode* ptr = pre->next;
			pre->next = cur;
			cur = pre;
			pre = ptr;
		}
		return cur;
	}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) { return NULL; }
		ListNode* cur = head;
		while (head->next != NULL) {
			ListNode* ptr = head->next->next;
			head->next->next = cur;
			cur = head->next;
			head->next = ptr;
		}
		return cur;
	}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode* ret = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return ret;
	}
};