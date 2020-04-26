#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.empty()) 
		return 0;
	// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
	int result = numbers[0];
	int times = 1; // ����
	for (int i = 1; i<numbers.size(); ++i)
	{
		if (times == 0)
		{
			// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			++times; // ��ͬ���1
		}
		else
		{
			--times; // ��ͬ���1
		}
	}
	// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
	times = 0;
	for (int i = 0; i<numbers.size(); ++i)
	{
		if (numbers[i] == result) ++times;
	}
	return (times > numbers.size() / 2) ? result : 0;
}

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	if (numbers.size() == 0)
		return 0;
	sort(numbers.begin(), numbers.end());
	int mid = numbers[numbers.size() / 2];

	int count = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == mid)
			count++;
	}
	return (count > numbers.size() / 2) ? mid : 0;
}

int main()
{
	vector<int> v = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	cout << MoreThanHalfNum_Solution(v) << endl;
	
	return 0;
}

////��Ŀ����
////����һ���ַ���str������ַ���str�е�����������ִ�
////�������� :
////�������������1������������һ���ַ���str�����Ȳ�����255��
////������� :
////��һ�������str��������������ִ���
////ʾ��1
////����
////abcd12345ed125ss123456789
////���
////123456789
//int main()
//{
//	string str, tmp, res;
//	cin >> str;
//
//	for (int i = 0; i <= str.length(); ++i)
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//			tmp += str[i];
//		else
//		{
//			if (res.size() < tmp.size())
//				res = tmp;
//			else
//				tmp.clear();
//		}
//	}
//	cout << res << endl;
//	return 0;
//}

////��Ŀ����
////��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
////�������� :
////ÿ�������������1������������ I like beijing.�����������Ȳ�����100
////������� :
////�����������֮����ַ���, �Կո�ָ�
////ʾ��1
////����
////I like beijing.
////���
////beijing.like I
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	reverse(str.begin(), str.end());
//	auto start = str.begin();
//	while (start != str.end())
//	{
//		auto end = start;
//		while (end != str.end() && *end != ' ')
//			end++;
//		reverse(start, end);
//
//		if (end != str.end())
//			start = end + 1;
//		else
//			start = end;
//	}
//	cout << str << endl;
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2;
//	cin >> s2;
//	while(cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2;
//	return 0;
//}

////���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
////�������� :
////ÿ�������������2���ַ���
////������� :
////���ɾ������ַ���
////ʾ��1
////����
////They are students.
////aeiou
////���
////Thy r stdnts.
//int main()
//{
//	string s1,s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	//ʹ�ù�ϣ���ӳ��ͳ��s2�е��ַ�
//	int table[256] = { 0 };
//	for (size_t i = 0; i < s2.size(); ++i)
//	{
//		table[s2[i]]++;
//	}
//	string ret;
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		if (table[s1[i]] == 0)
//			ret += s1[i];
//	}
//	cout << ret << endl;
//	return 0;
//}