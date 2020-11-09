#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

//题目描述
//“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
//花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。
//现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。
//你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
//例如：
//A = “aba”，B = “b”。这里有4种把B插入A的办法：
//* 在A的第一个字母之前: "baba" 不是回文
//* 在第一个字母‘a’之后 : "abba" 是回文
//* 在字母‘b’之后 : "abba" 是回文
//* 在第二个字母'a'之后 "abab" 不是回文
//所以满足条件的答案为2
//输入描述 :
//每组输入数据共两行。
//第一行为字符串A
//第二行为字符串B
//字符串长度均小于100且只包含小写字母
//输出描述 :
//输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数

bool IsCircle(const string& s)
{
	size_t begin = 0;
	size_t end = s.size() - 1;

	while (begin < end)
	{
		if (s[begin] != s[end])
			return false;

		++begin;
		--end;
	}

	return true;
}

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int count = 0;

	for (size_t i = 0; i <= str1.size(); ++i)
	{
		string str = str1;
		str.insert(i, str2);
		if (IsCircle(str))
			count++;
	}

	cout << count << endl;
	return 0;
}


//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//输入描述 :
//输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
//输出描述 :
//为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）

int main()
{
	string s, table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	bool flag = false;

	//将负数标记一下
	if (m < 0)
	{
		m = 0 - m;
		flag = true;
	}

	while (m)
	{
		s += table[m%n];
		m /= n;
	}

	if (flag)
		s += '-';

	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}

//读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述 :
//个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述 :
//在一行内输出str中里连续最长的数字串。

int main()
{
	string str, cur = "", res = "";
	cin >> str;
	for (int i = 0; i <= str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			cur += str[i];
		else
		{
			if (cur.size() > res.size())
				res = cur;
			else
				cur = "";
		}
	}

	cout << res;

	return 0;
}

//将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
//输入描述 :
//每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
//输出描述 :
//依次输出倒置之后的字符串, 以空格分割

int main()
{
	string s;
	getline(cin, s);

	reverse(s.begin(), s.end());

	auto start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;

		reverse(start, end);

		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}

	cout << s << endl;
	return 0;
}

int main()
{
	string s1, s2;
	cin >> s1;

	while (cin >> s2)
		s2 = s2 + " " + s1;

	cout << s2;
	return 0;
}