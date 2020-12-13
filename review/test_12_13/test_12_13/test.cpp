#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>

using namespace std;

//����һ���ַ���A���䳤��n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���ֻ����������ɣ���

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> st;
		for (auto e : A)
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
};

//Fibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
//�������� :
//����Ϊһ��������N(1 �� N �� 1, 000, 000)
//������� :
//���һ����С�Ĳ�����ΪFibonacci��"

int main()
{
	int num;
	int f, f0 = 0, f1 = 1;
	int l, r;

	cin >> num;

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
			r = f - num;
			break;
		}
	}

	cout << (l>r ? r : l) << endl;
	return 0;
}

//��Ŀ����
//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
//�������� :
//����һ���ַ���, ����������ĸ����, ����Ϊ��
//����ֵ���� :
//����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0

class Solution {
public:
	int StrToInt(string str) {
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
		for (size_t i = 0; i < str.size(); ++i)
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
};

//��Ŀ����
//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3
//��������:
//����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn������
//��ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���
//������� :
//���������������к�����ֵ��


//����sum[i-1]���������е�nums[i-1]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
//sum[i]���������е�nums[i]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
//��ôsum[i] = max(sum[i - 1], 0) + nums[i]�����������������������sum1��ʾsum[i - 1]��
//sum2��ʾsum[i]�����������������������򱣴浽result�С����sum[i]����sum2��С��0�ˣ�����Ϊ0��
//��Ϊ������������һ��������������������������

int main()
{
	int size = 0;
	cin >> size;
	vector<int> num(size);
	for (int i = 0; i < size; ++i)
		cin >> num[i];

	int result = num[0];
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < size; ++i)
	{
		sum2 = sum1 >= 0 ? sum1 + num[i] : num[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;

		sum1 = sum2;
	}

	cout << result << endl;
	return 0;
}