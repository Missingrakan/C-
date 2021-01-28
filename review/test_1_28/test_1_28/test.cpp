#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//��������:
//���⺬�ж�������������
//ÿ����������һ��string������
//
//������� :
//ÿ�������������ȼ�

int numChar(string str, int k)
{
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++)
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
}
int numNumber(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
			num++;
	}
	if (num == 0)
		return 0;
	else if (num == 1)
		return 10;
	else
		return 20;
}
int numSymbal(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		//��ȥ��ĸ�����֣�������Ϊ����
		if (!(str[i] >= 65 && str[i] <= 90)
			&& !(str[i] >= 97 && str[i] <= 122)
			&& !(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			num++;
	}
	if (num == 0)
		return 0;
	else if (num == 1)
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
		sum4 = numSymbal(str, k);
		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 0))
		{
			if (sum2 == 10)
				sum5 = 3;
			else
				sum5 = 5;
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
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

//����һ����ά����board���������̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�0��ʾû�����ӣ� - 1�����ǶԷ���ҵ����ӡ�
//��һ�������ں���б�������������ŵļ���ʤ������������򣩣����ص�ǰ����Ƿ�ʤ����
//
//����������
//[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
//���أ�true

class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		// write code here
		int row = board.size();
		int i, j, sum;

		//��
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

		//��
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

		//�Խ���
		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][i];
		}
		if (sum == row)
			return true;

		sum = 0;
		for (i = 0; i < row; ++i)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
			return true;

		return false;
	}
};

//�����n*m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���
//Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�
//���⺬�ж����������롣

int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		return n + m;
	else
		return 0;
}

int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
	return 0;
}

/*
//��������int A��B����дһ����������A + B��ֵ��������ʹ�� + �����������������

int addAB(int a, int b)
{
	int sum = 0, carry = 0;
	while (b != 0)
	{
		sum = a ^ b;
		carry = (a&b) << 1;
		a = sum;
		b = carry;
	}

	return sum;
}

int main()
{
	cout << addAB(2, 30) << endl;
	return 0;
}
*/