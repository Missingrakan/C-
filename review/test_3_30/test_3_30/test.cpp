#include <iostream>
#include <vector>
#include <string>

using namespace std;

//��ʵ��һ����������ƥ�����'. '��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ����ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣



class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size() + 1, n = p.size() + 1;
		vector<vector<bool>> dp(m, vector<bool>(n, false));
		dp[0][0] = true;
		for (int j = 2; j < n; j += 2)
			dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = p[j - 1] == '*' ?
					dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.') :
					dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);

				/*
				if(p[j - 1] == '*') {
					if(dp[i][j - 2]) dp[i][j] = true;                              // 1.
					else if(dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true; // 2.
					else if(dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;      // 3.
				} else {
					if(dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] = true;  // 1.
					else if(dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;  // 2.
				}
				*/
			}
		}
		return dp[m - 1][n - 1];
	}
};


//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
//����ɾ����������ͷ�ڵ㡣

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
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == NULL)
			return NULL;

		if (head->val == val)
			return head->next;

		ListNode* prev = NULL;
		ListNode* cur = head;

		while (cur && cur->val != val)
		{
			prev = cur;
			cur = cur->next;
		}

		prev->next = cur->next;
		return head;
	}
};

//�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

class Solution {
public:
	vector<int> printNumbers(int n) {
		int maximum = 0;
		vector<int> res;
		while (n--) {
			maximum += std::pow(10, n) * 9;
		}
		//int maximum = pow(10,n)-1;
		for (int i = 1; i <= maximum; ++i) {
			res.push_back(i);
		}
		return res;
	}
};

class Solution {
public:
	vector<int> res;

	void dfs(int n, int idx, string path) {
		if (idx == n) {
			int val = std::stoi(path);
			if (val != 0) {
				res.push_back(val);
			}
			return;
		}
		for (int i = 0; i < 10; ++i) {
			path[idx] = i + '0';
			dfs(n, idx + 1, path);
		}
	}

	vector<int> printNumbers(int n) {
		string path(n, '0');
		dfs(n, 0, path);
		return res;
	}
};



/*
int main()
{
	int a = -2147483648;
	a = -a;
	long b = -2147483648;
	b = -b;
	return 0;
}
*/