#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//在这个特殊的假期里，由于牛牛在家特别无聊，于是他发明了一个小游戏，游戏规则为：
//将字符串数字中为偶数位的数字进行翻转，将翻转后的结果进行输出。
//输入
//"1234"
//输出
//"1432"
//说明
//第2、4位为偶数，所以将其翻转后，得到 1432

class Solution {
public:
	/*
	* @param number string字符串
	* @return string字符串
	*/
	string change(string number) {
		// write code here
		int len = number.size();
		int i = 0, j = len - 1;
		while (i < j) {
			while (i < j && (number[i] - '0') & 1) 
				i++;
			while (i < j && (number[j] - '0') & 1) 
				j--;
			if (i < j) 
				swap(number[i++], number[j--]);
		}
		return number;
	}
};

//请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
//沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，
//即：只能往右和往下走，不能往左和往上走。

//输入描述 :
//输入两个正整数
//输出描述 :
//返回结果

//a.如果n或者m为1，则只有一行或者一列，从左上角走到右下角的路径数为n + m
//比如： 1 * 1格子，可以先向下走，再向右走，到达右下角；或者先向右走，
//再向下走，到达右下角，共两条，即 1 + 1 = 2，对于1 * m和 n * m的
//情况同学们自己画一下

//b.如果n, m都大于1，那么走到[n][m]格子的右下角只有两条路径，
//<1>: 从[n - 1][m]格子的右下角向下走，到达
//<2> : 从[n][m - 1]格子的右下角向右走，到达
//所以走到[n][m]格子的右下角的数量为[n - 1][m] + [n][m - 1], 可以通过递归实现，情况a为递归的终止条件。

int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		return n + m;
	else
		return 0;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	}
	return 0;
}

//给定两个int A和B。编写一个函数返回A+B的值，但不得使用+或其他算数运算符。

//1. 二进制位异或运算相当于对应位相加，不考虑进位
//比如： 1 ^ 1 = 0 ---> 1 + 1 = 0 (当前位值为0，进一位)
//1 ^ 0 = 1 ---> 1 + 0 = 1 (当前位值为1)
//0 ^ 0 = 0 ---> 0 + 0 = 0 (当前位值为0)

//2. 二进制位与运算相当于对应位相加之后的进位
//比如： 1 & 1 = 1 ---> 1 + 1 = 0 (当前位的值进一位)
//1 & 0 = 0 ---> 1 + 0 = 1 (当前位的值不进位)
//0 & 0 = 0 ---> 0 + 0 = 0 (当前位的值不进位)

//3. 两个数相加：对应二进制位相加的结果 + 进位的结果
//比如：3 + 2 --> 0011 + 0010 --> 0011 ^ 0010 + ((0011 & 0010) << 1)
//---> (0011 ^ 0010) ^ ((0011 & 0010) << 1)， 当进位之后的结果为0时，相加结束

class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		int sum, carry;

		while (B != 0)
		{
			sum = A ^ B;
			carry = (A & B) << 1;
			A = sum;
			B = carry;
		}
		return sum;
	}
};

//题目描述
//正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
//
//输入描述 :
//输入两个正整数A和B。
//
//输出描述 :
//输出A和B的最小公倍数。

//最小公倍数 = 两数之积除以最大公约数，这里使用碾转相除法进行最大公约数的求解：即a与b的最大公约数
//可以转化为a、b之间的余数为两者之间最小的数之间的公约数。所以对于输入的两个数进行连续求余，直到
//余数为0，求余的分母即为结果。

int gcd(int a, int b)
{
	int r = 0;

	while (r = a%b)
	{
		a = b;
		b = r;
	}

	return b;
}

int main()
{
	int A, B;
	while (cin >> A >> B)
		cout << A*B / gcd(A, B) << endl;

	return 0;
}

//题目描述
//考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.根据字符串的长度排序。例如：
//"car" < "cats" < "koala" < "doggies" < "carriage"
//考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。

//输入描述 :
//输入第一行为字符串个数n(n ≤ 100)
//接下来的n行, 每行一个字符串, 字符串长度均小于100，均由小写字母组成
//输出描述 :
//如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically",
//如果根据长度排列而不是字典序排列输出"lengths",
//如果两种方式都符合输出"both"，否则输出"none"


int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto &e : v)
		cin >> e;

	size_t size = v.size();
	bool lenSym = true, lexSym = true;

	//按照长度比较
	for (size_t i = 1; i < size; ++i)
	{
		if (v[i].size() < v[i - 1].size())
		{
			lenSym = false;
			break;
		}
	}

	//按照字典序比较
	for (size_t i = 1; i < size; ++i)
	{
		if (v[i] < v[i - 1])
		{
			lexSym = false;
			break;
		}
	}

	if (lenSym && lexSym)
		cout << "both" << endl;
	else if (!lenSym && lexSym)
		cout << "lexicographically" << endl;
	else if (lenSym && !lexSym)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
	return 0;
}