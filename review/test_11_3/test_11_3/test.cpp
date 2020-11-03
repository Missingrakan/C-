
//����һ���������飬ʵ��һ�����������������������ֵ�˳��
//ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

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

//����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ������
//�������β�ڵ��ǵ�����1���ڵ㡣���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ��
//���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣

//ʾ����

//����һ������ : 1->2->3->4->5, �� k = 2.
//�������� 4->5.

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