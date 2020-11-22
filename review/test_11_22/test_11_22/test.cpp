#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
//回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
//回文串不一定是字典当中的单词。


class Solution {
public:
	bool canPermutePalindrome(string s) {
		//if(s.size()==0)return false;测试出现内部错误。。。

		//记录频数
		int freq[256] = { 0 };
		for (char c : s)
			freq[c]++;

		//记录奇数出现次数
		int res = 0;
		for (int i = 0; i < 256; i++)
		{
			if (freq[i] % 2 != 0) {
				res++;
				if (res == 2) {
					return false;
				}
			}
		}
		return true;
	}
};


//URL化。编写一种方法，将字符串中的空格全部替换为 % 20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）
//示例 1：
//输入："Mr John Smith    ", 13
//输出："Mr%20John%20Smith"

class Solution {
public:
	string replaceSpaces(string S, int length) {
		string ret;

		for (int i = 0; i < length; ++i)
		{
			if (S[i] == ' ')
				ret += "%20";
			else
				ret += S[i];
		}

		return ret;
	}
};

//给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
//示例 1：
//
//输入 : s1 = "abc", s2 = "bca"
//输出 : true

/*
class Solution {
public:
bool CheckPermutation(string s1, string s2) {
		if(s1.size() != s2.size())
			return false;

		int table[256] = {0};
		for(auto e : s1)
			table[e]++;
		for(auto e : s2)
			table[e]--;

		int size = s1.size();
		for(size_t i = 0; i < size; ++i)
		{
			if(table[s1[i]] != 0)
				return false;
		}

		return true;
	}
};
*/
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		return s1 == s2;
	}
};

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	size_t sz1 = s1.size();
	size_t sz2 = s2.size();

	int table[256] = { 0 };
	for (size_t i = 0; i < sz2; ++i)
	{
		table[s2[i]]++;
	}

	string ret;
	for (size_t i = 0; i < sz1; ++i)
	{
		if (table[s1[i]] == 0)
			ret += s1[i];
	}
	cout << ret << endl;

	return 0;
}

int main()
{
	printf("%s, %5.3s\n", "computer", "computer");
	return 0;
}