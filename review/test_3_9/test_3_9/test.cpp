#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。

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
		n %= str.size(); //去除重复移动
		ReverseString(str, 0, n - 1); //前半部分逆置
		ReverseString(str, n, str.size() - 1); //后半部分逆置
		ReverseString(str, 0, str.size() - 1); //整体逆置
		return str;
	}
};

//现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。

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
//连接池最多需要创建多少连接

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