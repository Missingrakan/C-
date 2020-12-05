#define _CRT_SECURE_NO_WARNINGS 1

//编写一个函数，检查输入的链表是否是回文的。
//
//示例 1：
//输入： 1->2
//输出： false
//示例 2：
//输入： 1->2->2->1
//输出： true


class Solution
{
public:
	bool isPalindrome(ListNode* head) //快慢指针+翻转链表。对长度为0,1,2的特殊值同样成立，无需另外判断
	{
		ListNode* slow = head, *fast = head, *prev = NULL; //维护prev为slow的前一个元素（在原链表中）
		while (fast && fast->next) //同时进行翻转链表操作。slow前的链表已被翻转，头元素就是prev
		{
			fast = fast->next->next;
			ListNode* temp = slow->next;
			slow->next = prev;
			prev = slow;
			slow = temp;
		} //此循环结束后原链表被分成两段，两段的头分别是prev和slow
		if (fast) //当长度为2n+1时，循环后fast为最后一个元素，slow为第n+1个元素，起始比较点从slow->next开始（第n+2个元素）。当长度为2n时，循环后fast为NULL，slow为第n+1个元素，起始比较点从slow开始，故不操作。
			slow = slow->next;
		while (prev && slow) //比较前半部分（prev）和后半部分（slow）
		{
			if (prev->val != slow->val)
				return false;
			prev = prev->next;
			slow = slow->next;
		}
		return true;
	}
};

//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
//
//注意：本题相对原题稍作改动
//示例：
//输入： 1->2->3->4->5 和 k = 2
//输出： 4

class Solution {
public:
	int kthToLast(ListNode* head, int k) {
		if (head == nullptr)
			return 0;
		ListNode* fast = head;
		ListNode* slow = head;

		while (k--)
		{
			fast = fast->next;
		}

		while (fast != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}

		return slow->val;
	}
};

//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
//
//示例1 :
//输入：[1, 2, 3, 3, 2, 1]
//输出：[1, 2, 3]
//示例2 :
//输入：[1, 1, 1, 1, 2]
//输出：[1, 2]

class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		unordered_set<int> occurred = { head->val };
		ListNode* pos = head;
		// 枚举前驱节点
		while (pos->next != nullptr) {
			// 当前待删除节点
			ListNode* cur = pos->next;
			if (!occurred.count(cur->val)) {
				occurred.insert(cur->val);
				pos = pos->next;
			}
			else {
				pos->next = pos->next->next;
			}
		}
		pos->next = nullptr;
		return head;
	}
};

class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		ListNode* ob = head;
		while (ob != nullptr) {
			ListNode* oc = ob;
			while (oc->next != nullptr) {
				if (oc->next->val == ob->val) {
					oc->next = oc->next->next;
				}
				else {
					oc = oc->next;
				}
			}
			ob = ob->next;
		}
		return head;
	}
};                                                                                                                                            