#include <iostream>
#include <string>
#include <vector>

using namespace std;
//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = 0, maxval = nums[0];
		for (int i = 0; i < nums.size(); ++i)
		{
			ans = max(ans + nums[i], nums[i]);
			maxval = max(maxval, ans);
		}

		return maxval;
	}
};

int myAtoi(string s) {
	size_t i = 0;

	while (i < s.size() && s[i] == ' ')
		i++;

	if (i == s.size())
		return 0;

	int flag = 1;
	if (s[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	else if (!isdigit(s[i]))
		return 0;

	int num = 0;
	while (isdigit(s[i]) && i < s.size())
	{
		if (INT_MAX < 10 * num + (s[i] - '0'))
			return flag == -1 ? flag*INT_MAX - 1 : INT_MAX;
		num = num * 10 + (s[i] - '0');
		i++;
	}

	return flag*num;
}

int main()
{
	string s = "42"; 
	myAtoi(s);
	return 0;
}

/*
//����һ�� 32 λ���з������� x �����ؽ� x �е����ֲ��ַ�ת��Ľ����
//�����ת���������� 32 λ���з��������ķ�Χ?[?2^31, 2^31?? 1] ���ͷ��� 0��

class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}
};

//��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�

class Solution {
public:
	string convert(string s, int numRows) {

		if (numRows == 1) return s;

		vector<string> rows(min(numRows, int(s.size())));
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) {
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) ret += row;
		return ret;
	}
};


//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) {
			return s;
		}

		int maxLen = 1;
		int begin = 0;
		// dp[i][j] ��ʾ s[i..j] �Ƿ��ǻ��Ĵ�
		vector<vector<int>> dp(n, vector<int>(n));
		// ��ʼ�������г���Ϊ 1 ���Ӵ����ǻ��Ĵ�
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		// ���ƿ�ʼ
		// ��ö���Ӵ�����
		for (int L = 2; L <= n; L++) {
			// ö����߽磬��߽���������ÿ��Կ���һЩ
			for (int i = 0; i < n; i++) {
				// �� L �� i ����ȷ���ұ߽磬�� j - i + 1 = L ��
				int j = L + i - 1;
				// ����ұ߽�Խ�磬�Ϳ����˳���ǰѭ��
				if (j >= n) {
					break;
				}

				if (s[i] != s[j]) {
					dp[i][j] = false;
				}
				else {
					if (j - i < 3) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}

				// ֻҪ dp[i][L] == true �������ͱ�ʾ�Ӵ� s[i..L] �ǻ��ģ���ʱ��¼���ĳ��Ⱥ���ʼλ��
				if (dp[i][j] && j - i + 1 > maxLen) {
					maxLen = j - i + 1;
					begin = i;
				}
			}
		}
		return s.substr(begin, maxLen);
	}
};
*/