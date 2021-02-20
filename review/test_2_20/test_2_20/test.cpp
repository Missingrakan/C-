#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{ 1, 2, 4, 7, 3, 5, 6, 8 }�������������{ 4, 7, 2, 1, 5, 3, 8, 6 }�����ؽ������������ء�

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
	TreeNode* reConstructBinaryTree(vector<int> pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd)
	{
		if (preStart > preEnd || vinStart > vinEnd)
			return NULL;

		TreeNode* root = new TreeNode(pre[preStart]);
		for (int i = vinStart; i <= vinEnd; ++i)
		{
			//1 2 3 4 5 6 7
			//3 2 4 1 6 5 7
			//ǰ��ĵ�һ���ڵ㣬��root���ܽ����򻮷�Ϊ������
			//һ����������ǰ���У�����ô������Ԫ�صĸ����ǲ����
			//��ʵ�ʱ�����ʱ��ǰ���У�������������ֱ�����ʽ���������Ľڵ㶼����һ���
			//���������ص���Ҫ������±�����
			//��������������ȷ���������Ľڵ�����ǣ�i - vinStart (û�д�0��ʼŶ)
			//���ԣ���Ҫ��preStart+1������i - vinStart��Ԫ�أ�������������ǰ������

			if (pre[preStart] == vin[i])
			{
				root->left = reConstructBinaryTree(pre, preStart + 1, i - vinStart + preStart, vin, vinStart, i - 1);
				root->right = reConstructBinaryTree(pre, i - vinStart + preStart + 1, preEnd, vin, i + 1, vinEnd);
				break;
			}
		}
		return root;
	}
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return NULL;
		return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
};


//����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		stack<int> st;

		while (head)
		{
			st.push(head->val);
			head = head->next;
		}

		while (!st.empty())
		{
			v.push_back(st.top());
			st.pop();
		}

		return v;
	}
};

/*
class Solution {
public:
vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		while(head)
		{
			v.push_back(head->val);
			head = head->next;
		}

		reverse(v.begin(), v.end());

		return v;
	}
};
*/

//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.
//�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; ++i)
		{
			if (isspace(str[i]))
				count++;
		}

		char* old_end = str + length;
		char* new_end = str + length + 2 * count;
		while (old_end >= str && new_end >= str)
		{
			if (!isspace(*old_end))
			{
				//��һ�ν����ͽ�'\0'������ȥ�ˣ��������⴦��
				*new_end = *old_end;
				old_end--;
				new_end--;
			}
			else
			{
				*new_end-- = '0';
				*new_end-- = '2';
				*new_end-- = '%';
				old_end--;
			}
		}
	}
};


//��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		// 1 2 3 4
		// 2 3 4 5
		// 3 4 5 6
		int i = 0;
		int j = array[0].size() - 1;

		while (i < array.size() && j >= 0)
		{
			if (target < array[i][j])
				j--;
			else if (target > array[i][j])
				i++;
			else
				return true;
		}

		return false;
	}
};