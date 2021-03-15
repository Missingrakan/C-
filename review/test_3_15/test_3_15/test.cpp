#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

//给定一个由非负整数填充的m x n的二维数组，现在要从二维数组的左上角走到右下角，请找出路径上的所有数字之和最小的路径。
//注意：你每次只能向下或向右移动。

class Solution {
public:
	/**
	*
	* @param grid int整型vector<vector<>>
	* @return int整型
	*/
	int minPathSum(vector<vector<int> >& grid) {
		// write code here

		if (grid.empty())
			return 0;

		int row = grid.size();
		int col = grid[0].size();

		vector<vector<int>> dp(row, vector<int>(col, 0));

		//初始化第0行第0列
		dp[0][0] = grid[0][0];
		for (int i = 1; i < row; ++i)
		{
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		}

		for (int j = 1; j < col; ++j)
		{
			dp[0][j] = grid[0][j] + dp[0][j - 1];
		}

		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return dp[row - 1][col - 1];
	}
};

//一个机器人在m×n大小的地图的左上角（起点）。
//机器人每次向下或向右移动。机器人要到达地图的右下角（终点）。
//可以有多少种不同的路径从起点走到终点？

class Solution {
public:
	/**
	*
	* @param m int整型
	* @param n int整型
	* @return int整型
	*/
	int uniquePaths(int m, int n) {
		// write code here
		if (m < 1 || n < 1)
			return 0;

		vector<vector<int>> dp(m, vector<int>(n, 1));

		//(0,0)为机器人位置
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
};

void main()
{
	Solution s;
	s.uniquePaths(3, 4);
}

/*

//给出一个三角形，计算从三角形顶部到底部的最小路径和，每一步都可以移动到下面一行相邻的数字，
//例如，给出的三角形如下：
//[[20],[30,40],[60,50,70],[40,10,80,30]]
//最小的从顶部到底部的路径和是20 + 30 + 50 + 10 = 110。

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty())
			return 0;

		vector<vector<int>> dp(triangle);
		int line = triangle.size();

		for (int i = line - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}

		return dp[0][0];
	}

	int minimumTotal(vector<vector<int>> &triangle) {
		if (triangle.empty()){
			return 0;
		}
		// F[i][j], F[0][0]初始化
		vector<vector<int>> min_sum(triangle);
		int line = triangle.size();
		for (int i = 1; i < line; i++){
			for (int j = 0; j <= i; j++){
				// 处理左边界和右边界
				if (j == 0){
					min_sum[i][j] = min_sum[i - 1][j];
				}
				else if (j == i){
					min_sum[i][j] = min_sum[i - 1][j - 1];
				}
				else{
					min_sum[i][j] = min(min_sum[i - 1][j], min_sum[i - 1][j - 1]);
				}
				// F(i,j) = min( F(i-1, j-1), F(i-1, j)) + triangle[i][j]
				min_sum[i][j] = min_sum[i][j] + triangle[i][j];
			}
		}
		int result = min_sum[line - 1][0];
		// min(F(n-1, i))
		for (int i = 1; i < line; i++){
			result = min(min_sum[line - 1][i], result);
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> vv = { { 20 }, { 30, 40 }, { 60, 50, 70 }, { 40, 10, 80, 30 } };
	s.minimumTotal(vv);
	return 0;
}
*/

/*

//给定一个字符串s和一组单词dict，判断s是否可以用空格分割成一个单词序列，使得单词序列中所有的单词都是dict中的单词（序列可以包含一个或多个单词）。
//例如:
//给定s = “nowcode”；
//dict = ["now", "code"].

class Solution{
public:
	bool wordBreak(string s, unordered_set<string> &dict){
		if (s.empty()){
			return false;
		}
		if (dict.empty()){
			return false;
		}
		vector<bool> can_break(s.size() + 1, false);
		// 初始化F(0) = true
		can_break[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = i - 1; j >= 0; j--){
				// F(i): true{j <i && F(j) && substr[j+1,i]能在词典中找到} OR false
				// 第j+1个字符的索引为j
				if (can_break[j] && dict.find(s.substr(j, i - j)) != dict.end()){
					can_break[i] = true;
					break;
				}
			}
		}
		return can_break[s.size()];
	}
};

int main()
{
	Solution s;
	string str = "leetcode";
	unordered_set<string> set = { "leet", "code" };
	s.wordBreak(str, set);
	return 0;
}
*/