#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;



//例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”

class Solution {
public:
	void reverseString(string& str, int start, int end)
	{
		while (start < end)
		{
			char tmp = str[start];
			str[start] = str[end];
			str[end] = tmp;
			start++;
			end--;
		}
	}

	string ReverseSentence(string str) {
		if (str.size() == 0)
			return str;

		int len = str.size();

		int i = 0;
		int j = i;
		while (i < len)
		{
			while (i < len && !isspace(str[i]))
				++i;

			//翻转一个单词
			reverseString(str, j, i - 1);

			while (i < len && isspace(str[i]))
				++i;

			j = i;
		}

		//此时还没翻转最后一个单词,而且转移
		reverseString(str, j, i - 1);
		reverseString(str, 0, i - 1);

		return str;
	}
};

void main()
{
	Solution s;
	s.ReverseSentence("nowcode. am i");
}

////请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
//
//class Solution {
//public:
//	void leftRotateOneChar(string& str)
//	{
//		char tmp = str[0];
//
//		int i = 0;
//		for (; i < str.size() - 1; ++i)
//		{
//			str[i] = str[i + 1];
//		}
//
//		str[i] = tmp;
//	}
//	string LeftRotateString(string str, int n) {
//		if (n == 0 || str == "")
//			return str;
//
//		n %= str.size();
//
//		while (n)
//		{
//			leftRotateOneChar(str);
//			n--;
//		}
//
//		return str;
//	}
//	void reverseString(string& str, int start, int end){
//		while (start < end)
//		{
//			char tmp = str[start];
//			str[start] = str[end];
//			str[end] = tmp;
//			start++;
//			end--;
//		}
//	}
//	string LeftRotateString(string str, int n) {
//		if (n == 0 || str == "")
//			return str;
//
//		n %= str.size();
//
//		reverseString(str, 0, n - 1);
//		reverseString(str, n, str.size() - 1);
//		reverseString(str, 0, str.size() - 1);
//
//		return str;
//	}
//};