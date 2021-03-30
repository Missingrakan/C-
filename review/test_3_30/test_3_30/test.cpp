#include <iostream>
#include <vector>
#include <string>

using namespace std;

//请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。



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


//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//返回删除后的链表的头节点。

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

//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

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