#include <iostream>
#include <vector>
#include <string>

using namespace std;

//����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊ k[0],
//k[1]...k[m-1] ������ k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�
//Ϊ2��3��3�����Σ���ʱ�õ������˻���18��

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


//������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο�����
//���ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ18ʱ����
//�����ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�


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

		//��ע������ӱ����ʹ�
		visited[i][j] = true;

		//���±���
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

			//��ע��ǰ����
			visited[i][j] = true;
			res++;

			//�������
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

//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
//���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
//���磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ�üӴֱ������

//[["a", "b", "c", "e"],
//["s", "f", "c", "s"],
//["a", "d", "e", "e"]]
//
//�������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��
//·�������ٴ���������ӡ�

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		row = board.size();
		col = board[0].size();

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				//��[i, j]��ʼ����
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
		//Խ����ߵ�ǰ�ַ��Ͳ����ַ���һ�·��ؼ�
		if (i >= row || i < 0 || j >= col || j < 0 || board[i][j] != word[k])
			return false;

		//wordÿ���ַ��������˷�����
		if (k == word.size() - 1)
			return true;

		//�޸ĵ�ǰλ��Ԫ�أ����еݹ����

		//char tmp = board[i][j];
		board[i][j] = '\0';

		//���ĸ�����ݹ���в���
		bool res = dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i, j - 1, k + 1) || dfs(board, word, i, j + 1, k + 1);
		//board[i][j] = tmp;

		//��ԭԪ��
		board[i][j] = word[k];

		return res;
	}
};