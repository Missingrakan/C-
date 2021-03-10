#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

struct pos{ int x; int y; };

int bfs(vector<vector<char>>& map, vector<vector<bool>>& visit, pos& start)
{
	const int choose[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	queue<pos> que;
	int count = 0;
	int m = map.size(), n = map[0].size();

	que.push(start);
	visit[start.x][start.y] = true;
	++count;

	while (!que.empty())
	{
		pos cur = que.front(), next;
		que.pop();

		for (int i = 0; i < 4; ++i)
		{
			next.x = cur.x + choose[i][0];
			next.y = cur.y + choose[i][1];

			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && !visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int m, n;

	while (cin >> m >> n)
	{
		vector<vector<char>> map(m, vector<char>(n));
		vector<vector<bool>> visit(m, vector<bool>(n));

		pos start;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				visit[i][j] = false;
				cin >> map[i][j];
				if (map[i][j] == '@')
				{
					start.x = i;
					start.y = j;
				}
			}
		}

		cout << bfs(map, visit, start) << endl;
	}

	return 0;
}


//现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1, 1), B在(n, m)。现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i, j + 1)或(i + 1, j)这样的路线，在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格), 问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，那么她不碰到蘑菇走到B的家的概率是多少？

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		//地图
		vector<vector<int>> table(n + 1, vector<int>(m + 1));


		int x, y;
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			table[x][y] = 1;
		}

		//概率
		vector<vector<double>> p(n + 1, vector<double>(m + 1));


		p[1][1] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (!(i == 1 && j == 1))
					p[i][j] = p[i - 1][j] * (j == m ? 1 : 0.5) + p[i][j - 1] * (i == n ? 1 : 0.5);

				if (table[i][j] == 1)
					p[i][j] = 0;
			}
		}

		printf("%.2f\n", p[n][m]);
	}

	return 0;
}
