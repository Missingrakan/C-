#define _CRT_SECURE_NO_WARNINGS 1

//��дһ���������������������Ƿ��ǻ��ĵġ�
//
//ʾ�� 1��
//���룺 1->2
//����� false
//ʾ�� 2��
//���룺 1->2->2->1
//����� true


class Solution
{
public:
	bool isPalindrome(ListNode* head) //����ָ��+��ת�����Գ���Ϊ0,1,2������ֵͬ�����������������ж�
	{
		ListNode* slow = head, *fast = head, *prev = NULL; //ά��prevΪslow��ǰһ��Ԫ�أ���ԭ�����У�
		while (fast && fast->next) //ͬʱ���з�ת���������slowǰ�������ѱ���ת��ͷԪ�ؾ���prev
		{
			fast = fast->next->next;
			ListNode* temp = slow->next;
			slow->next = prev;
			prev = slow;
			slow = temp;
		} //��ѭ��������ԭ�����ֳ����Σ����ε�ͷ�ֱ���prev��slow
		if (fast) //������Ϊ2n+1ʱ��ѭ����fastΪ���һ��Ԫ�أ�slowΪ��n+1��Ԫ�أ���ʼ�Ƚϵ��slow->next��ʼ����n+2��Ԫ�أ���������Ϊ2nʱ��ѭ����fastΪNULL��slowΪ��n+1��Ԫ�أ���ʼ�Ƚϵ��slow��ʼ���ʲ�������
			slow = slow->next;
		while (prev && slow) //�Ƚ�ǰ�벿�֣�prev���ͺ�벿�֣�slow��
		{
			if (prev->val != slow->val)
				return false;
			prev = prev->next;
			slow = slow->next;
		}
		return true;
	}
};

//ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��
//
//ע�⣺�������ԭ�������Ķ�
//ʾ����
//���룺 1->2->3->4->5 �� k = 2
//����� 4

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

//��д���룬�Ƴ�δ���������е��ظ��ڵ㡣�����ʼ���ֵĽڵ㡣
//
//ʾ��1 :
//���룺[1, 2, 3, 3, 2, 1]
//�����[1, 2, 3]
//ʾ��2 :
//���룺[1, 1, 1, 1, 2]
//�����[1, 2]

class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		unordered_set<int> occurred = { head->val };
		ListNode* pos = head;
		// ö��ǰ���ڵ�
		while (pos->next != nullptr) {
			// ��ǰ��ɾ���ڵ�
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