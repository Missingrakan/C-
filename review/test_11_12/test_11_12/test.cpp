#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

#include <iostream>

using namespace std;

//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//
//输入 : 一个byte型的数字
//输出 : 无
//返回 : 对应的二进制数字中1的最大连续数
//
//输入描述 :
//输入一个byte数字
//输出描述 :
//输出转成二进制之后连续1的个数

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;
		while (n)
		{
			//判断当前位是否为1
			if (n & 1)
			{
				count++;
				maxcount = max(count, maxcount);
			}
			else
			{
				count = 0;
			}
			n >>= 1;
		}
		cout << maxcount << endl;
	}
	return 0;
}

//将一棵无穷大满二叉树的结点按根结点一层一层地从左往右编号，根结点编号为1。现给定a，b为两个结点。
//设计一个算法，返回a、b最近的公共祖先的编号。注意其祖先也可能是结点本身。
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};

int numChar(string str, int k)
{
	int small = 0;
	int big = 0;
	for (size_t i = 0; i < k; ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)
			big++;
		else if (str[i] >= 97 && str[i] <= 122)
			small++;
	}

	if ((small + big) == 0)
		return 0;
	else if (((small == 0) && big>0) || ((big == 0) && small>0))
		return 10;
	else
		return 20;

	return 0;
}

int numNumber(string str, int k)
{
	int count = 0;
	for (int i = 0; i < k; ++i)
	{
		if ((str[i] - '0') >= 0 && (str[i] - '0') <= 9)
			count++;
	}

	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else
		return 20;
}

int numSymbol(string str, int k)
{
	int count = 0;
	for (int i = 0; i < k; ++i)
	{
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			count++;
	}

	if (count == 0)
		return 0;
	else if (count == 1)
		return 10;
	else
		return 25;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int k = str.size();
		if (k <= 4)
			sum1 = 5;
		else if (k >= 8)
			sum1 = 25;
		else
			sum1 = 10;
		sum2 = numChar(str, k);
		sum3 = numNumber(str, k);
		sum4 = numSymbol(str, k);

		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5;
		}
		else if ((sum2 > 0) && (sum3 > 0) && (sum4 == 0))
			sum5 = 2;

		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}

//给定一个二维数组board，代表棋盘，其中元素为1的代表是当前玩家的棋子，0表示没有棋子， - 1代表是对方玩家的棋子。当一方棋子在横竖斜方向上有连成排的及获胜（及井字棋规则），返回当前玩家是否胜出。
//
//测试样例：
//[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
//返回：true

class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		// write code here
		int row = board.size();
		int i, j, sum;

		//检查每一行的和是否为row
		for (i = 0; i < row; ++i)
		{
			sum = 0;
			for (j = 0; j < row; ++j)
			{
				sum += board[i][j];
			}
			if (sum == row)
				return true;
		}

		//检查每一列的和是否为row
		for (i = 0; i < row; ++i)
		{
			sum = 0;
			for (j = 0; j < row; ++j)
			{
				sum += board[j][i];
			}
			if (sum == row)
				return true;
		}

		//检查对角线之和是否为row
		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][i];
		}
		if (sum == row)
			return true;

		sum = 0;
		for (int i = 0; i < row; ++i)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
			return true;

		//到这一步还未返回说明未获胜，返回false
		return false;
	}
};