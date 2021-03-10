#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��

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


//��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1, 1), B��(n, m)������A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i, j + 1)��(i + 1, j)������·�ߣ��ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����), �ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)����ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		//��ͼ
		vector<vector<int>> table(n + 1, vector<int>(m + 1));


		int x, y;
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			table[x][y] = 1;
		}

		//����
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
