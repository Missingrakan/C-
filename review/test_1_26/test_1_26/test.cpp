#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
int func(int a, int b)
{
	int c = 0;
	while (c = a%b)
	{
		a = b;
		b = c;
	}

	return b;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
		cout << (a*b) / func(a, b) << endl;

	return 0;
}

//如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
//如果根据长度排列而不是字典序排列输出"lengths",
//如果两种方式都符合输出"both"，否则输出"none"

int main()
{
	int sz = 0;
	cin >> sz;
	vector<string> v;
	v.resize(sz);
	for (auto &e : v)
		cin >> e;

	bool lenSystem = true;
	bool lexSystem = true;

	//按照长度比较
	for (int i = 1; i < sz; ++i)
	{
		if (v[i].size() < v[i - 1].size())
		{
			lenSystem = false;
			break;
		}
	}

	//按照字典序排列
	for (int i = 0; i < sz; ++i)
	{
		if (v[i] < v[i - 1])
		{
			lexSystem = false;
			break;
		}
	}

	if (lenSystem && !lexSystem)
		cout << "lengths" << endl;
	else if (!lenSystem && lexSystem)
		cout << "lexicographically" << endl;
	else if (lenSystem && lexSystem)
		cout << "both" << endl;
	else
		cout << "none" << endl;
	return 0;
}

//给定一个字符串A和其长度n，请返回一个bool值代表它是否为一个合法的括号串（只能由括号组成）。

bool chkParenthesis(string A, int n) {
	// write code here
	stack<char> st;
	for (const auto& e : A)
	{
		switch (e)
		{
		case '(':
			st.push(e);
			break;
		case ')':
		{
					if (st.empty() || st.top() != '(')
						return false;
						else
							st.pop();
			}
				break;
			default:
				return false;
			}
		}

		return true;
}

int main()
{
	chkParenthesis("()(()()", 7);
	return 0;
}

/*
//现在给你一个数N求最少需要多少步可以变为Fibonacci数。

int main()
{
	int num;
	cin >> num;
	int f, f0 = 0, f1 = 1;
	int l = 0, r = 0;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;

		if (f < num)
		{
			l = num - f;
		}
		else
		{
			//遇见第一个比num大的数就退出
			r = f - num;
			break;
		}
	}

	cout << ((l < r) ? l : r) << endl;
	return 0;
}
*/

/*
//二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。

int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> vv;
	vv.resize(w);
	for (auto&e : vv)
		e.resize(h, 1);

	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			//与(i, j)相距为2的地方不能放蛋糕
			if (vv[i][j] == 1)
			{
				res++;

				//标记不能放蛋糕的位置
				if (i + 2 < w)
					vv[i + 2][j] = 0;
				if (j + 2 < h)
					vv[i][j + 2] = 0;
			}
		}
	}

	cout << res << endl;
	return 0;
}
*/