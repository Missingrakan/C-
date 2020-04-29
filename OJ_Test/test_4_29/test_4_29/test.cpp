#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int StrToInt(string str)
{
	if (str.empty())
		return 0;

	int symbol = 1;
	if (str[0] == '-')
	{
		symbol = -1;
		str[0] = '0';
	}
	else if (str[0] == '+')
	{
		symbol = 1;
		str[0] = '0';
	}

	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			sum = 0;
			break;
		}
		sum = sum * 10 + str[i] - '0';
	}
	return symbol * sum;
}

int main()
{
	string str;
	cin >> str;
	cout << StrToInt(str) << endl;

}

////二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
////对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
////((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
////小易想知道最多可以放多少块蛋糕在网格盒子里。
////输入描述 :
////每组数组包含网格长宽W, H，用空格分割.(1 ≤ W、H ≤ 1000)
////输出描述 :
////输出一个最多可以放的蛋糕数
////示例1
////输入
////3 2
////输出
////4
//
//int main()
//{
//	int w = 0, h = 0, res = 0;
//	cin >> w >> h;
//	vector<vector<int>> v;
//	v.resize(w);
//	for (auto &e : v)
//		e.resize(h, 1);
//	for (int i = 0; i < w; ++i)
//	{
//		for (int j = 0; j < h; ++j)
//		{
//			if (v[i][j] == 1)
//			{
//				res++;
//				if ((i + 2) < w)
//					v[i + 2][j] = 0;
//				if ((j + 2) < h)
//					v[i][j + 2] = 0;
//			}
//		}
//	}
//	cout << res << endl;
//	return 0;
//}