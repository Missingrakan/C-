#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;



//���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.��

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

			//��תһ������
			reverseString(str, j, i - 1);

			while (i < len && isspace(str[i]))
				++i;

			j = i;
		}

		//��ʱ��û��ת���һ������,����ת��
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

////�������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
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