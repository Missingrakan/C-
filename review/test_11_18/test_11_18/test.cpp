#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
//比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
//再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
//现在给你一个正整数，输出它的数根。
//
//输入描述 :
//输入包含多组数据。
//每组数据数据包含一个正整数n（1≤n≤10E1000）。
//输出描述 :
//对应每一组数据，输出该正整数的数根。

int numroot(int num)
{
	int root = 0;
	while (num > 0)
	{
		root += num % 10;
		num /= 10;
	}
	while (root > 9)
	{
		root = numroot(root);
	}
	return root;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int sum = 0;
		int size = str.size();
		for (size_t i = 0; i < size; ++i)
			sum += str[i] - '0';

		cout << numroot(sum) << endl;
	}
	return 0;
}

//题目描述
//找出字符串中第一个只出现一次的字符
//
//输入描述:
//输入几个非空字符串
//输出描述 :
//输出第一个只出现一次的字符，如果不存在输出 - 1

int main()
{
	string str;
	while (cin >> str)
	{
		int hashtable[256] = { 0 };
		size_t size = str.size();
		for (size_t i = 0; i < size; ++i)
		{
			hashtable[str[i]]++;
		}
		size_t i = 0;
		for (i = 0; i < size; ++i)
		{
			if (hashtable[str[i]] == 1)
			{
				cout << str[i] << endl;
				break;
			}
		}
		if (i == size)
			cout << -1 << endl;
	}
	return 0;
}

//题目描述
//写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）
//
//输入描述 :
//输入N个字符
//输出描述 :
//输出该字符串反转后的字符串

string reverse_str(string& s)
{
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;

	while (start < end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return s;

}

int main()
{
	string str;
	getline(cin, str);
	cout << reverse_str(str);
	return 0;
}