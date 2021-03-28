#include <iostream>
#include <vector>
#include <string>

using namespace std;

//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],
//k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别
//为2、3、3的三段，此时得到的最大乘积是18。

class Solution {
public:
	int cuttingRope(int n) {
		if (n == 2 || n == 3)
			return n - 1;

		int res = 1;
		while (n > 4)
		{
			n -= 3;
			res *= 3;
		}

		return n*res;
	}
};

class Solution {
public:
	int cuttingRope(int n) {
		vector<int> dp(n + 1, 1);

		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				dp[i] = max(dp[i], max(j, dp[j])*max(i - j, dp[i - j]));
			}
		}

		return dp[n];
	}
};

class Solution {
public:
	int cuttingRope(int n) {
		vector<int> dp(n + 1, 1);
		for (int i = 3; i <= n; ++i) {
			for (int j = 2; j < i; ++j) {
				dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
			}
		}
		return dp[n];
	}
};


//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向
//左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机
//器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？


//DFS
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> visited(m, vector<bool>(n, 0));
		return dfs(0, 0, 0, 0, visited, m, n, k);
	}
private:
	int dfs(int i, int j, int si, int sj, vector<vector<bool>> &visited, int m, int n, int k) {
		if (i >= m || j >= n || k < si + sj || visited[i][j]) return 0;
		visited[i][j] = true;
		return 1 + dfs(i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj, visited, m, n, k) +
			dfs(i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8, visited, m, n, k);
	}
};

class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> visited(m, vector<bool>(n));
		return dfs(0, 0, m, n, k, visited);
	}

	int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited)
	{
		if (i >= m || j >= n || sum(i, j) > k || visited[i][j])
			return 0;

		//标注这个格子被访问过
		visited[i][j] = true;

		//右下遍历
		return 1 + dfs(i + 1, j, m, n, k, visited) + dfs(i, j + 1, m, n, k, visited);
	}
private:
	int sum(int i, int j)
	{
		int sum = 0;

		while (i)
		{
			sum += i % 10;
			i /= 10;
		}

		while (j)
		{
			sum += j % 10;
			j /= 10;
		}

		return sum;
	}
};

//BFS
class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> visited(m, vector<bool>(n, 0));
		int res = 0;
		queue<vector<int>> que;
		que.push({ 0, 0, 0, 0 });
		while (que.size() > 0) {
			vector<int> x = que.front();
			que.pop();
			int i = x[0], j = x[1], si = x[2], sj = x[3];
			if (i >= m || j >= n || k < si + sj || visited[i][j]) continue;
			visited[i][j] = true;
			res++;
			que.push({ i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj });
			que.push({ i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8 });
		}
		return res;
	}
};

class Solution {
public:
	int movingCount(int m, int n, int k) {
		vector<vector<bool>> visited(m, vector<bool>(n));

		int res = 0;
		queue<vector<int>> que;
		que.push({ 0, 0 });

		while (!que.empty())
		{
			vector<int> tmp = que.front();
			que.pop();
			int i = tmp[0];
			int j = tmp[1];

			if (i >= m || j >= n || sum(i, j) > k || visited[i][j])
				continue;

			//标注当前格子
			visited[i][j] = true;
			res++;

			//添加右下
			que.push({ i + 1, j });
			que.push({ i, j + 1 });
		}

		return res;
	}
private:
	int sum(int i, int j)
	{
		int sum = 0;

		while (i)
		{
			sum += i % 10;
			i /= 10;
		}

		while (j)
		{
			sum += j % 10;
			j /= 10;
		}

		return sum;
	}
};

//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
//如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
//例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

//[["a", "b", "c", "e"],
//["s", "f", "c", "s"],
//["a", "d", "e", "e"]]
//
//但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，
//路径不能再次入这个格子。

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		row = board.size();
		col = board[0].size();

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				//从[i, j]开始查找
				if (dfs(board, word, i, j, 0))
					return true;
			}
		}

		return false;
	}
private:
	int row;
	int col;
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int k)
	{
		//越界或者当前字符和查找字符不一致返回假
		if (i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[k])
			return false;

		//word每个字符都找完了返回真
		if (k == word.size() - 1)
			return true;

		//修改当前位置元素，进行递归查找

		//char tmp = board[i][j];
		board[i][j] = '\0';

		//沿四个方向递归进行查找
		bool res = dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i, j - 1, k + 1) || dfs(board, word, i, j + 1, k + 1);
		//board[i][j] = tmp;

		//复原元素
		board[i][j] = word[k];

		return res;
	}
};