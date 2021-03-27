#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

/*
int main()
{
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i)
		cin >> num[i];
	
	vector<int> help(n + 1);
	help[0] = 0;
	
	int maxsum = 0;
	int tmp = 0;
	for (int i = 1; i <= n; ++i)
	{
		help[i] = help[i - 1] + num[i - 1];
	}
	
	cout << maxsum << endl;
	
	return 0;
}
*/


bool isCycle(const string& str)
{
	int begin = 0;
	int end = str.size() - 1;

	while (begin < end)
	{
		if (str[begin] != str[end])
			return false;
		begin++;
		end--;
	}

	return true;
}

int main()
{
	string start, end;
	cin >> start >> end;

	long long i_start = atoi(start.c_str());
	long long i_end = atoi(end.c_str());



	for (int i = i_start; i <= i_end; ++i)
	{
		if (isCycle(to_string(i)) && isCycle(to_string(i*i*i)))
			cout << i << endl;
	}

	return 0;
}


/*
typedef struct Position
{
	int x;
	int y;
}Position;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> fact(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> fact[i][j];
	}

	//计算工厂位置
	queue<Position> tmp;
	Position pos;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (fact[i][j] == 1)
			{
				pos.x = i, pos.y = j;
				tmp.push(pos);
			}
		}
	}
	
	vector<Position> help;
	
	while (!tmp.empty())
	{
		help.push_back(tmp.front());
		tmp.pop();
	}
	
	queue<Position> res;
	vector<vector<int>> vv;
	
	//计算每一个点到工厂的距离
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int len = 0;
			for (int k = 0; k < help.size(); ++i)
			{
				max();
			}
			vv[i][j] = len;
		}
	}
	
	sort(vv.begin(), vv.end());
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
	
		}
	}
	return 0;
}
*/

/*
int main(void)
{
	http://www.taobao.com
	cout << "welcome to taobao" << endl;
	return 0;
}
*/