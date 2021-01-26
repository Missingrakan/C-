#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
//������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
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

//�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
//������ݳ������ж������ֵ����������"lengths",
//������ַ�ʽ���������"both"���������"none"

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

	//���ճ��ȱȽ�
	for (int i = 1; i < sz; ++i)
	{
		if (v[i].size() < v[i - 1].size())
		{
			lenSystem = false;
			break;
		}
	}

	//�����ֵ�������
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

//����һ���ַ���A���䳤��n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���ֻ����������ɣ���

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
//���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����

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
			//������һ����num��������˳�
			r = f - num;
			break;
		}
	}

	cout << ((l < r) ? l : r) << endl;
	return 0;
}
*/

/*
//����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������

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
			//��(i, j)���Ϊ2�ĵط����ܷŵ���
			if (vv[i][j] == 1)
			{
				res++;

				//��ǲ��ܷŵ����λ��
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