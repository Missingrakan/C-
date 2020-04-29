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

////����С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
////����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:
////((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
////С����֪�������ԷŶ��ٿ鵰������������
////�������� :
////ÿ������������񳤿�W, H���ÿո�ָ�.(1 �� W��H �� 1000)
////������� :
////���һ�������Էŵĵ�����
////ʾ��1
////����
////3 2
////���
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