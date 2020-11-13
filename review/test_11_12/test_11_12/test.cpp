#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

#include <iostream>

using namespace std;

//����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//
//���� : һ��byte�͵�����
//��� : ��
//���� : ��Ӧ�Ķ�����������1�����������
//
//�������� :
//����һ��byte����
//������� :
//���ת�ɶ�����֮������1�ĸ���

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxcount = 0;
		while (n)
		{
			//�жϵ�ǰλ�Ƿ�Ϊ1
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

//��һ����������������Ľ�㰴�����һ��һ��ش������ұ�ţ��������Ϊ1���ָ���a��bΪ������㡣
//���һ���㷨������a��b����Ĺ������ȵı�š�ע��������Ҳ�����ǽ�㱾��
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

//����һ����ά����board���������̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�0��ʾû�����ӣ� - 1�����ǶԷ���ҵ����ӡ���һ�������ں���б�������������ŵļ���ʤ������������򣩣����ص�ǰ����Ƿ�ʤ����
//
//����������
//[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
//���أ�true

class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		// write code here
		int row = board.size();
		int i, j, sum;

		//���ÿһ�еĺ��Ƿ�Ϊrow
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

		//���ÿһ�еĺ��Ƿ�Ϊrow
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

		//���Խ���֮���Ƿ�Ϊrow
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

		//����һ����δ����˵��δ��ʤ������false
		return false;
	}
};