#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//����һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����

class Solution {
public:
	void ReverseString(string &str, int start, int end){
		while (start < end){
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			start++, end--;
		}
	}
	string LeftRotateString(string str, int n) {
		if (n == 0 || str.empty()){
			return str;
		}
		n %= str.size(); //ȥ���ظ��ƶ�
		ReverseString(str, 0, n - 1); //ǰ�벿������
		ReverseString(str, n, str.size() - 1); //��벿������
		ReverseString(str, 0, str.size() - 1); //��������
		return str;
	}
};

//���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����

int main()
{
	int n;

	while (cin >> n)
	{
		vector<string> data(n);
		vector<bool> flag(n, true);

		for (int i = 0; i < n; ++i)
			cin >> data[i];

		sort(data.begin(), data.end());

		for (int i = 0; i < data.size() - 1; ++i)
		{
			if (data[i] == data[i + 1])
				flag[i] = false;

			if ((data[i].size() < data[i + 1].size()) && (data[i] == data[i + 1].substr(0, data[i].size())) && (data[i + 1][data[i].size()] == '/'))
				flag[i] = false;
		}

		for (int i = 0; i < data.size(); ++i)
		{
			if (flag[i])
				cout << "mkdir -p " << data[i] << endl;
		}
		cout << endl;

	}

	return 0;
}

/*
//���ӳ������Ҫ������������

int main()
{
	int n;

	while (cin >> n)
	{
		string user_id, con;
		vector<string> v;
		int max_size = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> user_id >> con;
			if (con == "connect")
				v.push_back(user_id);
			else if (con == "disconnect")
				v.erase(find(v.begin(), v.end(), user_id));

			int sz = v.size();
			if (sz > max_size)
				max_size = sz;
		}

		cout << max_size << endl;
	}

	return 0;
}
*/