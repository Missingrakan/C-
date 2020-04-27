#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1, 2, 1]，和最大的连续子数组为[2, 1]，其和为 3
//输入描述:
//输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素, 每个整数都在32位int范围内。以空格分隔。
//输出描述 :
//所有连续子数组中和最大的值。
//示例1
//输入
//3 - 1 2 1
//输出
//3
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0; 
	int sum2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}

	cout << result << endl;
	return 0;
}

////“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
////例如：
////A = “aba”，B = “b”。这里有4种把B插入A的办法：
////* 在A的第一个字母之前: "baba" 不是回文
////* 在第一个字母‘a’之后 : "abba" 是回文
////* 在字母‘b’之后 : "abba" 是回文
////* 在第二个字母'a'之后 "abab" 不是回文
////所以满足条件的答案为2
////输入描述 :
////每组输入数据共两行。
////第一行为字符串A
////第二行为字符串B
////字符串长度均小于100且只包含小写字母
////输出描述 :
////输出一个数字，表示把字符串B插入字符串A之后构成一个回文串的方法数
////示例1
////输入
////aba
////b
////输出
////2
//bool IsCircle(const string& str)
//{
//	size_t begin = 0;
//	size_t end = str.size() - 1;
//	while (begin < end)
//	{
//		if (str[begin] != str[end])
//			return false;
//		++begin;
//		--end;
//	}
//	return true;
//}
//
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	size_t count = 0;
//	for (size_t i = 0; i <= str1.size(); ++i)
//	{
//		string str = str1;
//		str.insert(i, str2);
//		if (IsCircle(str))
//			++count;
//	}
//	cout << count << endl;
//	return 0;
//}

////给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
////输入描述 :
////输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
////输出描述 :
////为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
////示例1
////输入
////7 2
////输出
////111
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	string res;
//	string table = "0123456789ABCDEF";
//	bool flag = false;
//	if (m < 0)
//	{
//		m = 0 - m;
//		flag = true;
//	}
//	while (m)
//	{
//		res += table[m%n];
//		m /= n;
//	}
//	if (flag)
//		res += '-';
//	reverse(res.begin(), res.end());
//	cout << res << endl;
//	return 0;
//}

////A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下的信息：
////A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
////现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。
////输入描述 :
////输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在 - 30到30之间(闭区间)。
////输出描述 :
////输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
////示例1
////输入
////1 - 2 3 4
////输出
////2 1 3
//int main()
//{
//	int num1, num2, num3, num4;
//	cin >> num1 >> num2 >> num3 >> num4;
//	if ((num2 + num4) / 2 == (num3 - num1) / 2)
//		cout << (num1 + num3) / 2 << " " << (num2 + num4) / 2 << " " << (num4 - num2) / 2 << endl;
//	else
//		cout << "No" << endl;
//	return 0;
//}