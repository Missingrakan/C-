#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <stack>

using namespace std;

//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
//
//输入描述 :
//输入两个正整数A和B。
//
//输出描述 :
//输出A和B的最小公倍数。
//
//示例1
//输入
//5 7
//输出
//35
int GetValue(int a, int b)
{
	int res;
	while (res = a%b)
	{
		a = b;
		b = res;
	}
	return b;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
		cout << (a*b) / GetValue(a, b) << endl;
	return 0;
}

////题目描述
////考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
////"car" < "carriage" < "cats" < "doggies < "koala"
////2.根据字符串的长度排序。例如：
////"car" < "cats" < "koala" < "doggies" < "carriage"
////考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
////输入描述 :
////输入第一行为字符串个数n(n ≤ 100)
////接下来的n行, 每行一个字符串, 字符串长度均小于100，均由小写字母组成
////输出描述 :
////如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
////
////如果根据长度排列而不是字典序排列输出"lengths",
////
////如果两种方式都符合输出"both"，否则输出"none"
////示例1
////输入
////3
////a
////aa
////bbb
////输出
////both
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (auto &ele : v)
//		cin >> ele;
//	bool lensystem = true, lexsystem = true;
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1].size() >= v[i].size())
//		{
//			lensystem = false;
//			break;
//		}
//	}
//
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1] >= v[i])
//		{
//			lexsystem = false;
//			break;
//		}
//	}
//
//	if (lensystem && lexsystem)
//		cout << "both" << endl;
//	else if (!lensystem && lexsystem)
//		cout << "lexicographically" << endl;
//	else if (lensystem && !lexsystem)
//		cout << "lengths" << endl;
//	else
//		cout << "none" << endl;
//	//    if(lensystem && lexsystem)
//	//        cout << "both" << endl;
//	//    else if(lensystem == false && lexsystem == true)
//	//        cout << "lexicographically" << endl;
//	//    else if(lensystem == true && lexsystem == false)
//	//        cout << "lengths" << endl;
//	//    else
//	//        cout << "none" << endl;
//	return 0;
//}

////对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
////
////给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
////
////测试样例：
////"(()())", 6
////返回：true
////测试样例：
////"()a()()", 7
////返回：false
////测试样例：
////"()(()()", 7
////返回：false
//bool chkParenthesis(string A, int n)
//{
//	stack<char> s;
//	for (auto ele : A)
//	{
//		switch (ele)
//		{
//		case '(':
//			s.push(ele);
//			break;
//		case ')':
//		{
//			if (s.empty() || s.top() != '(')
//				return false;
//			else
//				s.pop();
//		}
//			break;
//		default:
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	string s = "(((())))";
//	cout << chkParenthesis(s, s.size()) << endl;
//	return 0;
//}

////Fibonacci数列是这样定义的：
////F[0] = 0
////F[1] = 1
////for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
////因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
////输入描述 :
////输入为一个正整数N(1 ≤ N ≤ 1, 000, 000)
////输出描述 :
////输出一个最小的步数变为Fibonacci数"
////示例1
////输入
////15
////输出
////2
//int main()
//{
//	int f = 0, f0 = 0, f1 = 1;
//	int N = 0;
//	cin >> N;
//	int left = 0,right = 0;
//	while (1)
//	{
//		f = f0 + f1;
//		f0 = f1;
//		f1 = f;
//		if (f < N)
//			left = N - f;
//		else
//		{
//			right = f - N;
//			break;
//		}
//	}
//	cout << min(left, right) << endl;
//	return 0;
//}