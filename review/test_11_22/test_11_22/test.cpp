#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

//����һ���ַ�������дһ�������ж����Ƿ�Ϊĳ�����Ĵ�������֮һ��
//���Ĵ���ָ������������һ���ĵ��ʻ���������ָ��ĸ���������С�
//���Ĵ���һ�����ֵ䵱�еĵ��ʡ�


class Solution {
public:
	bool canPermutePalindrome(string s) {
		//if(s.size()==0)return false;���Գ����ڲ����󡣡���

		//��¼Ƶ��
		int freq[256] = { 0 };
		for (char c : s)
			freq[c]++;

		//��¼�������ִ���
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


//URL������дһ�ַ��������ַ����еĿո�ȫ���滻Ϊ % 20���ٶ����ַ���β�����㹻�Ŀռ��������ַ�������֪���ַ����ġ���ʵ�����ȡ���ע����Javaʵ�ֵĻ�����ʹ���ַ�����ʵ�֣��Ա�ֱ���������ϲ�������
//ʾ�� 1��
//���룺"Mr John Smith    ", 13
//�����"Mr%20John%20Smith"

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

//���������ַ��� s1 �� s2�����дһ������ȷ������һ���ַ������ַ��������к��ܷ�����һ���ַ�����
//ʾ�� 1��
//
//���� : s1 = "abc", s2 = "bca"
//��� : true

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