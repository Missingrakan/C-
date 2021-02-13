#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//�����ַ������

string addString(string num1, string num2)
{
	//�ӵ�λ��ʼ����
	int i = num1.size() - 1;
	int j = num2.size() - 1;

	string res = "";
	int carry = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			carry += num1[i] - '0';
		if (j >= 0)
			carry += num2[i] - '0';

		res += (char)(carry % 10 + '0');
		carry /= 10;

		i--;
		j--;
	}

	if (carry == 1)
		res += '1';

	reverse(res.begin(), res.end());

	return res;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addString(s1, s2) << endl;
	}
}


//���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����
//���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��
int main()
{
	int n = 0, num = 0;
	while (cin >> n)
	{
		//��n�е�Ԫ�ظ���
		num = 2 * n - 1;
		vector<vector<int>> vv(n, vector<int>(num, 0));

		//��ʼ��
		vv[0][0] = 1;
		for (int i = 1; i < n; ++i)
		{
			vv[i][0] = vv[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; ++j)
			{
				//��ÿһ�еڶ���Ԫ�����⴦��
				if (j == 1)
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
				else
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j - 2];
			}
		}

		int k = 0;
		for (k = 0; k < num; ++k)
		{
			if ((vv[n - 1][k] % 2 == 0) && (vv[n - 1][k] != 0))
			{
				cout << k + 1 << endl;
				break;
			}
		}

		if (k == num)
			cout << -1 << endl;
	}

	return 0;
}

//28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��s
//����n�������n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000

int count(int n)
{
	int cnt = 0;
	for (int i = 2; i <= n; ++i)
	{
		int sum = 0;
		int sq = sqrt(i);
		for (int j = 2; j <= sq; ++j)
		{
			if (i%j == 0)
			{
				if (i / j == j)
					sum += j;
				else
					sum += j + i / j;
			}
		}

		if (sum + 1 == i)
			cnt++;
	}

	return cnt;
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << count(n) << endl;
	return 0;
}
//�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��
//Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)��
//���ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
//������ɫ����n(1��n��13), ͬʱ������������Ϊn������left, right, 
//�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

class Gloves
{
public:
	int findMinimum(int n, vector<int> left, vector<int> right)
	{
		// write code here
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;

		for (int i = 0; i < n; ++i)
		{
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];

			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}

		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

//����������������1�ĸ���
int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 0;
		while (num)
		{
			if (num & 1)
				count++;
			num >>= 1;
		}
		cout << count << endl;
	}
	return 0;
}