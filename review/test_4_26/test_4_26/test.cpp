#include <iostream>
#include <string>
#include <vector>

using namespace std;
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
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
//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//如果反转后整数超过 32 位的有符号整数的范围?[?2^31, 2^31?? 1] ，就返回 0。

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

//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

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


//给你一个字符串 s，找到 s 中最长的回文子串。

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) {
			return s;
		}

		int maxLen = 1;
		int begin = 0;
		// dp[i][j] 表示 s[i..j] 是否是回文串
		vector<vector<int>> dp(n, vector<int>(n));
		// 初始化：所有长度为 1 的子串都是回文串
		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		// 递推开始
		// 先枚举子串长度
		for (int L = 2; L <= n; L++) {
			// 枚举左边界，左边界的上限设置可以宽松一些
			for (int i = 0; i < n; i++) {
				// 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
				int j = L + i - 1;
				// 如果右边界越界，就可以退出当前循环
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

				// 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
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