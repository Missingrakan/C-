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
	// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
	int result = numbers[0];
	int times = 1; // 次数
	for (int i = 1; i<numbers.size(); ++i)
	{
		if (times == 0)
		{
			// 更新result的值为当前元素，并置次数为1
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			++times; // 相同则加1
		}
		else
		{
			--times; // 不同则减1
		}
	}
	// 判断result是否符合条件，即出现次数大于数组长度的一半
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

////题目描述
////读入一个字符串str，输出字符串str中的连续最长的数字串
////输入描述 :
////个测试输入包含1个测试用例，一个字符串str，长度不超过255。
////输出描述 :
////在一行内输出str中里连续最长的数字串。
////示例1
////输入
////abcd12345ed125ss123456789
////输出
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

////题目描述
////将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
////输入描述 :
////每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
////输出描述 :
////依次输出倒置之后的字符串, 以空格分割
////示例1
////输入
////I like beijing.
////输出
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

////输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
////输入描述 :
////每个测试输入包含2个字符串
////输出描述 :
////输出删除后的字符串
////示例1
////输入
////They are students.
////aeiou
////输出
////Thy r stdnts.
//int main()
//{
//	string s1,s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	//使用哈希表的映射统计s2中的字符
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